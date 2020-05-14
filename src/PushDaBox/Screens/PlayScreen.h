#ifndef PUSHDABOX_PLAYSCREEN_H
#define PUSHDABOX_PLAYSCREEN_H

#include <fstream>
#include <sstream>
#include <memory>
#include <cstdlib>

#include "../../BaseEngine.h"
#include "../Domain/GameLevels.h"
#include "../../JsonLib/JsonLib.h"

#include "../Components/GameGrid.h"
#include "../Components/Player.h"
#include "../Components/Enemy.h"
#include "../Components/Box.h"

#include "../States/StartState.h"
#include "../States/GameOverState.h"
#include "../States/VictoryState.h"

#include "../Domain/Highscores.h"
#include "../Domain/PlayerData.h"

#include "GameScreen.h"

namespace PushDaBox {

class PlayScreen : public GameScreen {
public:
    constexpr static int MAP_WIDTH = 800;
    constexpr static int MAP_HEIGHT = 700;
    constexpr static int N_LIVES = 3;

    static int CURRENT_LEVEL;
    static int CURRENT_LIVES;
    static int CURRENT_SCORE;

    static bool NEEDS_RELOAD;

    PlayScreen(BaseEngine* e, StateTransition t, std::string gameLevelsFileLocation,
               std::string highscoreFileLocation, std::string playerDataFileLocation)
    : GameScreen(e, t), levels(gameLevelsFileLocation), level(levels.getLevel(PlayScreen::CURRENT_LEVEL)),
      grid(MAP_HEIGHT/level.height, MAP_WIDTH/level.width), levelNumber(PlayScreen::CURRENT_LEVEL),
      score(0), lives(N_LIVES), highscores(highscoreFileLocation), playerData(playerDataFileLocation),
        player(nullptr) {
    }

    void initialiseBackground() override {
        this->getEngine()->fillBackground(0x000000);
        this->grid.setMapSize(this->level.width, this->level.height);

        for (int i = 0; i < this->level.height * this->level.width; i++) {
            int row = i/(this->level.width);
            int col = i%(this->level.width);

            if (this->level.map[i] == '#') {
                this->grid.setMapValue(col, row, 0xff0000);
            } else if (this->level.map[i] == 'E') {
                this->grid.setMapValue(col, row, 0xff00ff);
            } else if (this->level.map[i] == 'G') {
                this->grid.setMapValue(col, row, 0x00ff00);
            } else {
                this->grid.setMapValue(col, row, 0x000000);
            }
        }

        this->grid.setTopLeftPositionOnScreen(0, 100);

        this->grid.drawAllTiles(this->getEngine(), this->getEngine()->getBackgroundSurface());
        
        if (PlayScreen::NEEDS_RELOAD) {
            PlayScreen::NEEDS_RELOAD = false;
            this->reload();
        }
    }
    
    int initialiseObjects() override {
        int playerPosition = this->getPlayerPosition();
        int playerRow = playerPosition/(this->level.width);
        int playerCol = playerPosition%(this->level.width);

        int boxPosition = this->getBoxPosition();
        int boxRow = boxPosition/(this->level.width);
        int boxCol = boxPosition%(this->level.width);

        int windowWidth = this->getEngine()->getWindowWidth();  
        int windowHeight = this->getEngine()->getWindowHeight();

        int blockWidth = this->grid.getTileWidth();
        int blockHeight = this->grid.getTileHeight();

        Box* box = new Box(this->getEngine(), blockWidth,
            blockHeight, boxCol * blockWidth + blockWidth/2,
            100 + boxRow * blockHeight + blockHeight/2, &this->grid);

        auto levelUp = [&](){ PlayScreen::CURRENT_SCORE += 100; PlayScreen::CURRENT_LEVEL++; this->reload(); };

        this->player = new Player(this->getEngine(), blockWidth,
            blockHeight, playerCol * blockWidth + blockWidth/2,
            100 + playerRow * blockHeight + blockHeight/2, &this->grid, box, levelUp);
        
        this->getEngine()->drawableObjectsChanged();
        this->getEngine()->destroyOldObjects(true);
        this->getEngine()->createObjectArray(2);

        this->getEngine()->storeObjectInArray(0, this->player);
        this->getEngine()->storeObjectInArray(1, box);

        this->spawnEnemy();

        return 1;
    }

    void spawnEnemy() {
        if (this->getRandomEnemyPosition() == -1 || player == nullptr) {
            return;
        }

        int enemyPosition = this->getRandomEnemyPosition();
        int enemyRow = enemyPosition/(this->level.width);
        int enemyCol = enemyPosition%(this->level.width);

        int blockWidth = this->grid.getTileWidth();
        int blockHeight = this->grid.getTileHeight();

        auto levelReset = [&](){ this->resetLevel(); };
        auto removeEnemy = [&](DisplayableObject* d) {
            this->getEngine()->removeDisplayableObject(d);
            this->spawnEnemy();
        };

        Enemy* enemy = new Enemy(this->getEngine(), blockWidth,
            blockHeight, enemyCol * blockWidth + blockWidth/2,
            100 + enemyRow * blockHeight + blockHeight/2, &this->grid, this->player,
            levelReset, removeEnemy);

        this->getEngine()->appendObjectToArray(enemy);
    }

    void drawStringsOnTop() override {
        int windowWidth = this->getEngine()->getWindowWidth();  
        int windowHeight = this->getEngine()->getWindowHeight();
        std::stringstream livesStr, levelStr, scoreStr, asteriskStr;
        livesStr << "Lives: ";

        this->getEngine()->drawForegroundString(20, 40,
            livesStr.str().c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 28));

        for (int i = 0; i < PlayScreen::CURRENT_LIVES; i++) asteriskStr << "*";
        this->getEngine()->drawForegroundString(120, 40,
            asteriskStr.str().c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 64));

        levelStr << "Level: " << this->levelNumber;
        this->getEngine()->drawForegroundString(windowWidth/2 - 75, 40,
            levelStr.str().c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 28));

        scoreStr << "Score: " << PlayScreen::CURRENT_SCORE;
        this->getEngine()->drawForegroundString(windowWidth - 225, 40,
            scoreStr.str().c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 28));
    }

    void keyboardHandler(int keyCode) override {
        switch (keyCode) {
            case SDLK_ESCAPE: // exit
                PlayScreen::CURRENT_LEVEL = 1;
                PlayScreen::CURRENT_SCORE = 0;
                PlayScreen::CURRENT_LIVES = PlayScreen::N_LIVES;
                this->reload();
                this->stateTransition(std::make_unique<StartState>());
                break;
            case SDLK_r: // reload level
                this->resetLevel();
                break;
            case SDLK_p: // save game
                this->playerData.setPlayerLevel(PlayScreen::CURRENT_LEVEL);
                this->playerData.setPlayerScore(PlayScreen::CURRENT_SCORE);
                this->playerData.setPlayerLives(PlayScreen::CURRENT_LIVES);
                break;
        }
    }

    void resetLevel() {
        if (PlayScreen::CURRENT_LIVES > 1) {
            PlayScreen::CURRENT_LIVES--;
            this->reload();
        } else {
            PlayScreen::CURRENT_LEVEL = 1;
            PlayScreen::CURRENT_SCORE = 0;
            PlayScreen::CURRENT_LIVES = PlayScreen::N_LIVES;
            this->reload();
            this->stateTransition(std::make_unique<GameOverState>());
            this->highscores.addHighscore(this->playerData.getPlayerName(), PlayScreen::CURRENT_SCORE);
        }
    }

    void reload() {
        if (this->levels.getNumberOfLevels() < PlayScreen::CURRENT_LEVEL) {
            PlayScreen::CURRENT_LEVEL = 1;
            this->stateTransition(std::make_unique<VictoryState>());
            this->highscores.addHighscore(this->playerData.getPlayerName(), PlayScreen::CURRENT_SCORE);
        } else {
            this->level = this->levels.getLevel(PlayScreen::CURRENT_LEVEL);
            this->grid = GameGrid(MAP_HEIGHT/level.height, MAP_WIDTH/level.width);
            this->levelNumber = PlayScreen::CURRENT_LEVEL;
            this->stateTransition(std::make_unique<RunningState>());
        }
    }
private:
    GameLevels levels;
    Level level;
    GameGrid grid;
    Highscores highscores;
    PlayerData playerData;
    Player* player;
    int lives;
    int score;
    int levelNumber;

    int getPlayerPosition() {
        for (int i = 0; i < this->level.height * this->level.width; i++) {
            if (this->level.map[i] == 'P') {
                return i;
            }
        }

        return -1; // error
    }

    int getRandomEnemyPosition() {
        std::vector<int> positions;
        for (int i = 0; i < this->level.height * this->level.width; i++) {
            if (this->level.map[i] == 'E') {
                positions.push_back(i);
            }
        }

        if (positions.size() == 0) {
            return -1; // error
        }

        return positions[(rand() * 100) % positions.size()];
    }

    int getBoxPosition() {
        for (int i = 0; i < this->level.height * this->level.width; i++) {
            if (this->level.map[i] == 'S') {
                return i;
            }
        }

        return -1; // error
    }
};

int PlayScreen::CURRENT_LEVEL = 1;
int PlayScreen::CURRENT_LIVES = PlayScreen::N_LIVES;
int PlayScreen::CURRENT_SCORE = 0;

bool PlayScreen::NEEDS_RELOAD = false;

} // namespace PushDaBox

#endif
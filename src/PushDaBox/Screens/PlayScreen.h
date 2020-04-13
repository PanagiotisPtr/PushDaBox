#ifndef PUSHDABOX_PLAYSCREEN_H
#define PUSHDABOX_PLAYSCREEN_H

#include <fstream>
#include <sstream>
#include <memory>

#include "../../BaseEngine.h"
#include "../GameLevels.h"
#include "../../JsonLib/JsonLib.h"
#include "../Components/GameGrid.h"
#include "../Components/Player.h"
#include "../States/StartState.h"
#include "GameScreen.h"

namespace PushDaBox {

class PlayScreen : public GameScreen {
public:
    constexpr static int MAP_WIDTH = 800;
    constexpr static int MAP_HEIGHT = 700;
    constexpr static int N_LIVES = 3;

    PlayScreen(BaseEngine* e, StateTransition t, Level l)
    : GameScreen(e, t), level(l), grid(MAP_HEIGHT/l.height, MAP_WIDTH/l.width),
      levelNumber(5), score(8888), lives(N_LIVES) {
    }

    void initialiseBackground() override {
        this->getEngine()->fillBackground(0x000000);
        this->grid.setMapSize(this->level.width, this->level.height);

        for (int i = 0; i < this->level.height * this->level.width; i++) {
            int row = i/(this->level.width);
            int col = i%(this->level.width);

            if (this->level.map[i] == '#') {
                this->grid.setMapValue(col, row, 0xff0000);
            } else if (this->level.map[i] == 'S') {
                this->grid.setMapValue(col, row, 0xffff00);
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
    }
    
    int initialiseObjects() override {
        int playerPosition = this->getPlayerPosition();
        int playerRow = playerPosition/(this->level.width);
        int playerCol = playerPosition%(this->level.width);

        std::cout << playerRow << std::endl;
        std::cout << playerCol << std::endl;

        int windowWidth = this->getEngine()->getWindowWidth();  
        int windowHeight = this->getEngine()->getWindowHeight();

        int blockWidth = this->grid.getTileWidth();
        int blockHeight = this->grid.getTileHeight();

        Player* player = new Player(this->getEngine(), blockWidth,
            blockHeight, playerCol * blockWidth + blockWidth/2,
            100 + playerRow * blockHeight + blockHeight/2, &this->grid);
        
        this->getEngine()->drawableObjectsChanged();
        this->getEngine()->destroyOldObjects(true);
        this->getEngine()->createObjectArray(1);

        this->getEngine()->storeObjectInArray(0, player);

        return 1;
    }

    void drawStringsOnTop() override {
        int windowWidth = this->getEngine()->getWindowWidth();  
        int windowHeight = this->getEngine()->getWindowHeight();
        std::stringstream livesStr, levelStr, scoreStr, asteriskStr;
        livesStr << "Lives: ";

        this->getEngine()->drawForegroundString(20, 40,
            livesStr.str().c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 28));

        for (int i = 0; i < this->lives; i++) asteriskStr << "*";
        this->getEngine()->drawForegroundString(120, 40,
            asteriskStr.str().c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 64));

        levelStr << "Level: " << this->levelNumber;
        this->getEngine()->drawForegroundString(windowWidth/2 - 75, 40,
            levelStr.str().c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 28));

        scoreStr << "Score: " << this->score;
        this->getEngine()->drawForegroundString(windowWidth - 225, 40,
            scoreStr.str().c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 28));
    }

    void keyboardHandler(int keyCode) override {
        switch (keyCode) {
            case SDLK_ESCAPE:
                this->stateTransition(std::make_unique<StartState>());
                break;
        }
    }
private:
    GameGrid grid;
    Level level;
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
};

} // namespace PushDaBox

#endif
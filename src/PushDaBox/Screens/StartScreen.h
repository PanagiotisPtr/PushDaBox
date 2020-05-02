#ifndef PUSHDABOX_STARTSCREEN_H
#define PUSHDABOX_STARTSCREEN_H

#include <fstream>

#include "../../BaseEngine.h"
#include "../States/HighscoreState.h"
#include "../States/RunningState.h"
#include "../../JsonLib/JsonLib.h"
#include "../Components/Button.h"
#include "GameScreen.h"
#include "../Domain/PlayerData.h"

namespace PushDaBox {

class StartScreen : public GameScreen {
public:
    StartScreen(BaseEngine* e, StateTransition t, std::string playerDataFileLocation)
    : GameScreen(e, t), playerData(playerDataFileLocation), changingName(false) {
        this->playerName = this->playerData.getPlayerName();
    }

    void initialiseBackground() override {
        this->getEngine()->fillBackground(0x000000);
        SimpleImage image(this->getEngine()->loadImage("assets/Background.png", false));
	    image.renderImageWithMask(this->getEngine()->getBackgroundSurface(), 0, 0, 0, 0, image.getHeight(), image.getWidth());
    }
    
    int initialiseObjects() override {
        int windowWidth = this->getEngine()->getWindowWidth();
        int windowHeight = this->getEngine()->getWindowHeight();
        Button* startGameButton = new Button(this->getEngine(), "assets/buttons/StartGameButton.png",
            windowWidth/2 - 150, windowHeight/2 - 100, [&](){
                this->stateTransition(std::make_unique<RunningState>());
            });
        
        Button* loadGameButton = new Button(this->getEngine(), "assets/buttons/LoadGameButton.png",
            windowWidth/2 - 150, windowHeight/2, [&](){
                this->stateTransition(std::make_unique<RunningState>());
            });

        Button* highscoreButton = new Button(this->getEngine(), "assets/buttons/HighscoreListButton.png",
            windowWidth/2 - 150, windowHeight/2 + 100, [&](){
                this->stateTransition(std::make_unique<HighscoreState>());
            });

        Button* exitGameButton = new Button(this->getEngine(), "assets/buttons/ExitGameButton.png",
            windowWidth/2 - 150, windowHeight/2 + 200, [&](){
                this->getEngine()->setExitWithCode(0);
            });

        Button* changeNameButton = new Button(this->getEngine(), "assets/buttons/ChangeNameButton.png",
            windowWidth/2 + 175, 160, [&](){
                this->changingName = true;
            });

        this->getEngine()->drawableObjectsChanged();
        this->getEngine()->destroyOldObjects(true);
        this->getEngine()->createObjectArray(5);

        this->getEngine()->storeObjectInArray(0, startGameButton);
        this->getEngine()->storeObjectInArray(1, loadGameButton);
        this->getEngine()->storeObjectInArray(2, highscoreButton);
        this->getEngine()->storeObjectInArray(3, exitGameButton);
        this->getEngine()->storeObjectInArray(4, changeNameButton);

        return 5;
    }

    void drawStringsOnTop() override {
        int windowWidth = this->getEngine()->getWindowWidth();
        int windowHeight = this->getEngine()->getWindowHeight();
        this->getEngine()->drawForegroundString(windowWidth/2 - 175, 40,
            "PushDaBox!", 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 48));
        std::string playerNameLabel = "Player name: ";
        if (this->playerName.size() <= 12) {
            playerNameLabel += this->playerName;
        } else {
            playerNameLabel += std::string(std::begin(this->playerName), std::begin(this->playerName) + 12);
        }
        this->getEngine()->drawForegroundString(windowWidth/2 - 250, 160,
            playerNameLabel.c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 26));
    }

    void keyboardHandler(int keyCode) override {
        if (this->changingName == false) {
            return;
        }
        if (keyCode >= SDLK_a && keyCode <= SDLK_z) {
            this->playerName += ('a' + (keyCode - SDLK_a));
        }
        if (this->playerName.size() && keyCode == SDLK_BACKSPACE) {
            this->playerName.erase(std::begin(this->playerName) + this->playerName.size() - 1);
        }
        if (keyCode == SDLK_KP_ENTER || keyCode == 13) { // edge case for Macbook Keyboard
            this->changingName = false;
            this->playerData.setPlayerName(this->playerName);
        }
        this->getEngine()->redrawDisplay();
    }
private:
    PlayerData playerData;
    std::string playerName;
    bool changingName;
};

} // namespace PushDaBox

#endif
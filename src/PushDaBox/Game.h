#ifndef PUSHDABOX_GAME_H
#define PUSHDABOX_GAME_H

#include <memory>
#include <unordered_map>

// Debugging
#include <iostream>
#include <chrono>
#include <thread>

#include "../BaseEngine.h"
#include "GameLevels.h"
#include "States/BaseState.h"
#include "States/LoadingState.h"
#include "States/RunningState.h"
#include "States/StartState.h"
#include "Screens/GameScreen.h"
#include "Screens/StartScreen.h"
#include "Components/Button.h"

namespace PushDaBox {

class Game : public BaseEngine {
public:
    using StatePointer = std::unique_ptr<BaseState>;
    using ScreenPointer = std::unique_ptr<GameScreen>;

    Game(std::string gameLevelsFileLocation, std::string playerDataFileLocation,
         size_t sWidth, size_t sHeight)
    : gameState(std::make_unique<LoadingState>()), levels(gameLevelsFileLocation),
      screenWidth(sWidth), screenHeight(sHeight) {
          this->gameState = std::make_unique<StartState>();
          ScreenPointer startScreen = std::make_unique<StartScreen>(this, playerDataFileLocation);

          this->screens.insert({GameScreens::START, std::move(startScreen)});
      }
	~Game() {}

	void virtSetupBackgroundBuffer() override {
        fillBackground(0x000000);
        if (this->gameState->currentScreen() == GameScreens::LOADING) {
            return;
        }

        SimpleImage image(loadImage("assets/Background.png", false));
	    image.renderImageWithMask(this->getBackgroundSurface(), 0, 0, 0, 0, image.getHeight(), image.getWidth());
    }

    void virtDrawStringsOnTop() override {
        int currentScreen = this->gameState->currentScreen();
        if (currentScreen == GameScreens::LOADING) {
            this->drawForegroundString(this->screenWidth/2 - 75, this->screenHeight/2,
                                 "Loading...", 0xff0000, NULL);
            return;
        } else {
            this->screens[currentScreen]->drawStringsOnTop();
        }
    }

    int virtInitialiseObjects() override {
        int currentScreen = this->gameState->currentScreen();
        if (this->screens.find(currentScreen) == std::end(this->screens)) {
            return 0;
        }
        int initialisedObjects = this->screens[this->gameState->currentScreen()]->initialiseObjects();
        this->setAllObjectsVisible(true);

        return initialisedObjects;
    }

	void virtMouseDown(int button, int x, int y) override {
        if (this->gameState->acceptUserInput() == false) {
            std::cout << "Loading!" << std::endl;
            return;
        }
    }

	void virtKeyDown(int keyCode) override {
        if (this->gameState->acceptUserInput() == false) {
            std::cout << "Loading!" << std::endl;
            return;
        }
        
        int currentScreen = this->gameState->currentScreen();
        this->screens[currentScreen]->keyboardHandler(keyCode);
    }
private:
    GameLevels levels;
    StatePointer gameState;
    std::unordered_map<int, ScreenPointer> screens;
    size_t screenWidth;
    size_t screenHeight;
};

} // namespace PushDaBox

#endif
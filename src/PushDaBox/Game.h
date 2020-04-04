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
#include "Screens/LoadingScreen.h"

namespace PushDaBox {

class Game : public BaseEngine {
public:
    using StatePointer = std::unique_ptr<BaseState>;
    using ScreenPointer = std::unique_ptr<GameScreen>;

    Game(std::string gameLevelsFileLocation, std::string playerDataFileLocation,
         size_t sWidth, size_t sHeight)
    : gameState(std::make_unique<LoadingState>()), levels(gameLevelsFileLocation),
      screenWidth(sWidth), screenHeight(sHeight) {
          ScreenPointer startScreen = std::make_unique<StartScreen>(this, playerDataFileLocation);
          ScreenPointer loadingScreen = std::make_unique<LoadingScreen>(this);

          this->screens.insert({GameScreens::START, std::move(startScreen)});
          this->screens.insert({GameScreens::LOADING, std::move(loadingScreen)});
          this->gameState = std::make_unique<StartState>();
      }
	~Game() {}

	void virtSetupBackgroundBuffer() override {
        int currentScreen = this->gameState->currentScreen();
        this->screens[currentScreen]->initialiseBackground();
    }

    void virtDrawStringsOnTop() override {
        int currentScreen = this->gameState->currentScreen();
        this->screens[currentScreen]->drawStringsOnTop();
    }

    int virtInitialiseObjects() override {
        int currentScreen = this->gameState->currentScreen();
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
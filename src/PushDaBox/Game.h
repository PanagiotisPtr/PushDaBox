#ifndef PUSHDABOX_GAME_H
#define PUSHDABOX_GAME_H

#include <memory>

// Debugging
#include <iostream>
#include <chrono>
#include <thread>

#include "../BaseEngine.h"
#include "GameLevels.h"
#include "States/BaseState.h"
#include "States/LoadingState.h"
#include "States/RunningState.h"

namespace PushDaBox {

class Game : public BaseEngine {
public:
    using StatePointer = std::unique_ptr<BaseState>;

    Game(std::string gameLevelsFilename)
    : gameState(std::make_unique<LoadingState>()), levels(gameLevelsFilename) {}
	~Game() {}

	void virtSetupBackgroundBuffer() override {

    }

    int virtInitialiseObjects() override {
        this->gameState = std::make_unique<RunningState>();
        return 0;
    }

	void virtMouseDown(int iButton, int iX, int iY) override {
        if (this->gameState->acceptUserInput() == false) {
            std::cout << "Loading!" << std::endl;
            return;
        }

        std::cout << "Mouse Down!" << std::endl;
    }

	void virtKeyDown(int iKeyCode) override {
        if (this->gameState->acceptUserInput() == false) {
            std::cout << "Loading!" << std::endl;
            return;
        }

        std::cout << "Key Down!" << std::endl;
    }
private:
    GameLevels levels;
    StatePointer gameState;
};

} // namespace PushDaBox

#endif
#ifndef PUSHDABOX_GAMEOVERSCREEN_H
#define PUSHDABOX_GAMEOVERSCREEN_H

#include <memory>

#include "../../BaseEngine.h"
#include "../States/StartState.h"
#include "GameScreen.h"

namespace PushDaBox {

class GameOverScreen : public GameScreen {
public:
    GameOverScreen(BaseEngine* e, StateTransition t) : GameScreen(e, t) {}

    void initialiseBackground() override {
        this->getEngine()->fillBackground(0x000000);
    }

    int initialiseObjects() override {
        return 0;
    }

    void drawStringsOnTop() override {
        int windowWidth = this->getEngine()->getWindowWidth();
        int windowHeight = this->getEngine()->getWindowHeight();
        this->getEngine()->drawForegroundString(windowWidth/2 - 75, windowHeight/2,
            "Game Over", 0xff0000, this->getEngine()->getFont("Cornerstone Regular.ttf", 34));
    }

    void keyboardHandler(int keyCode) override {
        this->stateTransition(std::make_unique<StartState>());
    }

};

} // namespace PushDaBox

#endif
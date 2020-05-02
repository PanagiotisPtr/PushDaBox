#ifndef PUSHDABOX_VICTORYSCREEN_H
#define PUSHDABOX_VICTORYSCREEN_H

#include <memory>

#include "../../BaseEngine.h"
#include "../States/StartState.h"
#include "GameScreen.h"

namespace PushDaBox {

class VictoryScreen : public GameScreen {
public:
    VictoryScreen(BaseEngine* e, StateTransition t) : GameScreen(e, t) {}

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
            "You win!", 0x00ff00, this->getEngine()->getFont("Cornerstone Regular.ttf", 34));
    }

    void keyboardHandler(int keyCode) override {
        this->stateTransition(std::make_unique<StartState>());
    }

};

} // namespace PushDaBox

#endif
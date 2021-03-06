#ifndef PUSHDABOX_LOADINGSCREEN_H
#define PUSHDABOX_LOADINGSCREEN_H

#include <chrono>
#include <thread>
#include <memory>

#include "../../BaseEngine.h"
#include "../States/StartState.h"
#include "GameScreen.h"

namespace PushDaBox {

class LoadingScreen : public GameScreen {
public:
    LoadingScreen(BaseEngine* e, StateTransition t) : GameScreen(e, t) {}

    void initialiseBackground() override {
        this->getEngine()->fillBackground(0x000000);
    }

    int initialiseObjects() override {
        std::thread([&](){
            // Everything loads extremely quickly so you never get to see
            // the loading screen. I added a time dealy so that you can 
            // see this screen in the demo
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            this->stateTransition(std::make_unique<StartState>());
        }).detach();

        return 0;
    }

    void drawStringsOnTop() override {
        int windowWidth = this->getEngine()->getWindowWidth();
        int windowHeight = this->getEngine()->getWindowHeight();
        this->getEngine()->drawForegroundString(windowWidth/2 - 75, windowHeight/2,
            "Loading...", 0xff0000, this->getEngine()->getFont("Cornerstone Regular.ttf", 34));
    }

    void keyboardHandler(int keyCode) override {}

};

} // namespace PushDaBox

#endif
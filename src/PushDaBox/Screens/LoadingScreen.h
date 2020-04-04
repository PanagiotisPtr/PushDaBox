#ifndef PUSHDABOX_LOADINGSCREEN_H
#define PUSHDABOX_LOADINGSCREEN_H

#include "../../BaseEngine.h"
#include "GameScreen.h"

namespace PushDaBox {

class LoadingScreen : public GameScreen {
public:
    LoadingScreen(BaseEngine* e) : GameScreen(e) {}

    void initialiseBackground() override {
        this->getEngine()->fillBackground(0x000000);
    }

    int initialiseObjects() override {}

    void drawStringsOnTop() override {
        int windowWidth = this->getEngine()->getWindowWidth();
        int windowHeight = this->getEngine()->getWindowHeight();
        this->getEngine()->drawForegroundString(windowWidth/2 - 75, windowHeight/2,
                                                "Loading...", 0xff0000, NULL);
    }

    void keyboardHandler(int keyCode) override {}

};

} // namespace PushDaBox

#endif
#ifndef PUSHDABOX_HIGHSCORESCREEN_H
#define PUSHDABOX_HIGHSCORESCREEN_H

#include <memory>
#include <map>

#include "../../BaseEngine.h"
#include "../../JsonLib/JsonLib.h"
#include "../States/BaseState.h"
#include "../States/StartState.h"
#include "../Components/Button.h"
#include "GameScreen.h"
#include "../Domain/Highscores.h"

namespace PushDaBox {

class HighscoreScreen : public GameScreen {
public:
    HighscoreScreen(BaseEngine* e, StateTransition t, std::string highscoreFileLocation)
    : GameScreen(e, t), highscores(highscoreFileLocation) {}

    void initialiseBackground() override {
        this->getEngine()->fillBackground(0x000000);
        SimpleImage image(this->getEngine()->loadImage("assets/HighscoreScreen.png", false));
	    image.renderImageWithMask(this->getEngine()->getBackgroundSurface(), 0, 0, 0, 0, image.getHeight(), image.getWidth());
    }

    int initialiseObjects() override {
        int windowWidth = this->getEngine()->getWindowWidth();
        int windowHeight = this->getEngine()->getWindowHeight();
        Button* backButton = new Button(this->getEngine(), "assets/buttons/BackButton.png",
            windowWidth/2 - 150, windowHeight - 100, [&](){
                this->stateTransition(std::make_unique<StartState>());
            });

        this->getEngine()->drawableObjectsChanged();
        this->getEngine()->destroyOldObjects(true);
        this->getEngine()->createObjectArray(1);

        this->getEngine()->storeObjectInArray(0, backButton);

        return 1;
    }

    void drawStringsOnTop() override {
        int windowWidth = this->getEngine()->getWindowWidth();
        int windowHeight = this->getEngine()->getWindowHeight();
        int padding = 200;
        int offset = 0;

        int count = 0;
        auto highscoreMap = this->highscores.getHighscores();
        for (auto it = highscoreMap.rbegin(); it != highscoreMap.rend(); it++) {
            auto p = *it;
            if (count++ >= 7) break;
            std::stringstream ss;
            ss << p.second << "        " << p.first;
            this->getEngine()->drawForegroundString(windowWidth/2 - 150, offset + padding,
                ss.str().c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 28));
            padding += 60;
        }
    }

    void keyboardHandler(int keyCode) override {}
private:
    Highscores highscores;
};

} // namespace PushDaBox

#endif
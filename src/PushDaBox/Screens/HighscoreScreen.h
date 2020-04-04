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

namespace PushDaBox {

class HighscoreScreen : public GameScreen {
public:
    HighscoreScreen(BaseEngine* e, StateTransition t, std::string highscoreFileLocation)
    : GameScreen(e, t) {
        std::string str;
        {
            std::ifstream f(highscoreFileLocation);
            std::stringstream ss;
            ss << f.rdbuf();
            str = ss.str();
            f.close();
        }
        str.erase(remove_if(std::begin(str), std::end(str), isspace), std::end(str));

        size_t pos = 0;
        highscoreData.deserialise(str, pos);

        size_t scoreIdx = 1;
        std::string scoreIdxStr;
        while (true) {
            try {
                size_t score;
                std::string name;
                std::stringstream ss;

                ss << scoreIdx++;
                ss >> scoreIdxStr;
                ss.clear();

                ss << highscoreData[scoreIdxStr]["name"].getValue() << " ";
                ss << highscoreData[scoreIdxStr]["score"].getValue();

                ss >> name;
                ss >> score;

                this->highscores.insert({score, name});
            } catch (const std::exception& e) {
                break;
            }
        }
    }

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
        int padding = 500;
        int offset = 0;
        for (auto p : this->highscores) {
            std::stringstream ss;
            ss << p.second << "        " << p.first;
            this->getEngine()->drawForegroundString(windowWidth/2 - 150, offset + padding,
                ss.str().c_str(), 0xffffff, this->getEngine()->getFont("Cornerstone Regular.ttf", 28));
            padding -= 60;
        }
    }

    void keyboardHandler(int keyCode) override {}
private:
    std::map<int, std::string> highscores;
    JsonLib::JsonObject highscoreData;
};

} // namespace PushDaBox

#endif
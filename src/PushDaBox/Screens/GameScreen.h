#ifndef PUSHDABOX_SCREEN_H
#define PUSHDABOX_SCREEN_H

#include "../../BaseEngine.h"

namespace PushDaBox {

class GameScreen {
public:
    GameScreen(BaseEngine* e) : engine(e) {}
    virtual ~GameScreen() {}
    virtual int initialiseObjects() = 0;
    virtual void drawStringsOnTop() = 0;
    virtual void keyboardHandler(int keyCode) = 0;
    virtual void initialiseBackground() = 0;
protected:
    BaseEngine* getEngine() { return this->engine; }
private:
    BaseEngine* engine;
};

} // namespace PushDaBox

#endif
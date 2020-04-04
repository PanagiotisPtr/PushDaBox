#ifndef PUSHDABOX_SCREEN_H
#define PUSHDABOX_SCREEN_H

#include "../../BaseEngine.h"

namespace PushDaBox {

class GameScreen {
public:
    using StatePointer = std::unique_ptr<BaseState>;
    using StateTransition = std::function<void(StatePointer&&)>;

    GameScreen(BaseEngine* e, StateTransition t) : engine(e), stateTransition(t) {}
    virtual ~GameScreen() {}
    virtual int initialiseObjects() = 0;
    virtual void drawStringsOnTop() = 0;
    virtual void keyboardHandler(int keyCode) = 0;
    virtual void initialiseBackground() = 0;
protected:
    StateTransition stateTransition;

    BaseEngine* getEngine() { return this->engine; }
private:
    BaseEngine* engine;
};

} // namespace PushDaBox

#endif
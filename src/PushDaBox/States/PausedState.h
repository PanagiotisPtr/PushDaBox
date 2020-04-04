#ifndef PUSHDABOX_STATES_PAUSEDSTATE_H
#define PUSHDABOX_STATES_PAUSEDSTATE_H

#include "BaseState.h"

namespace PushDaBox {

class PausedState : public BaseState {
public:
    bool acceptUserInput() override { return true; };
    int currentScreen() override { return GameScreens::PAUSED; };
};

}

#endif
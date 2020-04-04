#ifndef PUSHDABOX_STATES_STARTSTATE_H
#define PUSHDABOX_STATES_STARTSTATE_H

#include "BaseState.h"

namespace PushDaBox {

class StartState : public BaseState {
public:
    bool acceptUserInput() override { return true; };
    int currentScreen() override { return GameScreens::START; };
};

}

#endif
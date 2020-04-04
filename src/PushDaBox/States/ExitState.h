#ifndef PUSHDABOX_STATES_EXITSTATE_H
#define PUSHDABOX_STATES_EXITSTATE_H

#include "BaseState.h"

namespace PushDaBox {

class ExitState : public BaseState {
public:
    bool acceptUserInput() override { return false; };
    int currentScreen() override { return GameScreens::EXIT; };
};

}

#endif
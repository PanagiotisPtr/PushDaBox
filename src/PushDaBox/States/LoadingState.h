#ifndef PUSHDABOX_STATES_LOADINGSTATE_H
#define PUSHDABOX_STATES_LOADINGSTATE_H

#include "BaseState.h"

namespace PushDaBox {

class LoadingState : public BaseState {
public:
    bool acceptUserInput() override { return false; };
    int currentScreen() override { return GameScreens::LOADING; };
};

}

#endif
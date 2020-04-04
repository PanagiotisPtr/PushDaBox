#ifndef PUSHDABOX_STATES_RUNNINGSTATE_H
#define PUSHDABOX_STATES_RUNNINGSTATE_H

#include "BaseState.h"

namespace PushDaBox {

class RunningState : public BaseState {
public:
    bool acceptUserInput() override { return true; };
    int currentScreen() override { return GameScreens::RUNNING; };
};

}

#endif
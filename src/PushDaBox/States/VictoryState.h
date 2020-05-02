#ifndef PUSHDABOX_STATES_VICTORYSTATE_H
#define PUSHDABOX_STATES_VICTORYSTATE_H

#include "BaseState.h"

namespace PushDaBox {

class VictoryState : public BaseState {
public:
    bool acceptUserInput() override { return true; };
    int currentScreen() override { return GameScreens::VICTORY; };
};

}

#endif
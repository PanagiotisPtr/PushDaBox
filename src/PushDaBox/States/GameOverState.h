#ifndef PUSHDABOX_STATES_GAMEOVERSTATE_H
#define PUSHDABOX_STATES_GAMEOVERSTATE_H

#include "BaseState.h"

namespace PushDaBox {

class GameOverState : public BaseState {
public:
    bool acceptUserInput() override { return true; };
    int currentScreen() override { return GameScreens::GAMEOVER; };
};

}

#endif
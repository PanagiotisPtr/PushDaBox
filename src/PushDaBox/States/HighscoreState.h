#ifndef PUSHDABOX_STATES_HIGHSCORESTATE_H
#define PUSHDABOX_STATES_HIGHSCORESTATE_H

#include "BaseState.h"

namespace PushDaBox {

class HighscoreState : public BaseState {
public:
    bool acceptUserInput() override { return true; };
    int currentScreen() override { return GameScreens::HIGHSCORE; };
};

}

#endif
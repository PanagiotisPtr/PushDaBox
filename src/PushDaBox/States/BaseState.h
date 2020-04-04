#ifndef PUSHDABOX_STATES_BASESTATE_H
#define PUSHDABOX_STATES_BASESTATE_H

namespace PushDaBox {

enum GameScreens {
    START,     // Start Screen
    LOADING,   // Frozen. Performing I/O
    RUNNING,   // Game is running
    PAUSED,    // Game is paused
    HIGHSCORE, // Highscore screen
    EXIT       // Exiting. Cleaning up
};

class BaseState {
public:
    BaseState() {}
    virtual ~BaseState() {}

    virtual bool acceptUserInput() = 0;
    virtual int currentScreen() = 0;
};

}

#endif
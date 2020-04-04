#ifndef PUSHDABOX_GAME_H
#define PUSHDABOX_GAME_H

#include "../BaseEngine.h"
#include "../JsonLib/JsonLib.h"

namespace PushDaBox {

class Game : public BaseEngine {
public:
    Game() {}
	~Game() {}
	void virtSetupBackgroundBuffer() {}
	void virtMouseDown(int iButton, int iX, int iY) {}
	void virtKeyDown(int iKeyCode) {}
private:
    JsonLib::JsonObject obj;
};

} // namespace PushDaBox

#endif
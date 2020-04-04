#ifndef PUSHDABOX_COMPONENTS_BUTTON_H
#define PUSHDABOX_COMPONENTS_BUTTON_H

#include <functional>

#include "../../DisplayableObject.h"
#include "../../ImageObject.h"

namespace PushDaBox {

class Button : public ImageObject {
public:
    using EventHandler = std::function<void()>;

    Button(BaseEngine* engine, std::string imgUrl, int posX, int posY, EventHandler h)
    : ImageObject(engine, imgUrl), handler(h), isLarge(false) {
        this->getEngine()->notifyObjectsAboutMouse(true);
        this->m_iCurrentScreenX = posX;
        this->m_iCurrentScreenY = posY;
    }

    void virtMouseDown(int button, int x, int y) override {
		if (virtIsPositionWithinObject(x, y)) {
            handler();
        }
	}
private:
    EventHandler handler;
    bool isLarge;
};

}

#endif
#ifndef PUSHDABOX_COMPONENTS_BOX_H
#define PUSHDABOX_COMPONENTS_BOX_H

#include "../../DisplayableObject.h"
#include "../../TileManager.h"
#include "../../BaseEngine.h"

namespace PushDaBox {

class Box : public DisplayableObject {
public:
    Box(BaseEngine* e, int w, int h, int startX, int startY,
    TileManager* tm)
    : DisplayableObject(e, w, h, false), tileManager(tm){
        this->m_iCurrentScreenX = startX;
        this->m_iCurrentScreenY = startY;
    }

    void virtDraw() override {
        getEngine()->drawForegroundRectangle(
            m_iCurrentScreenX - m_iDrawWidth / 2 + 1,
            m_iCurrentScreenY - m_iDrawHeight / 2 + 1,
            m_iCurrentScreenX + m_iDrawWidth / 2 - 1,
            m_iCurrentScreenY + m_iDrawHeight / 2 - 1,
            0xffff00);
    }
private:

    TileManager* tileManager;
};

} // namespace PushDaBox


#endif
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
    : DisplayableObject(e, w, h, false), tileManager(tm),
      image(e->loadImage("assets/Box.png", false)) {
        this->m_iCurrentScreenX = startX;
        this->m_iCurrentScreenY = startY;
        this->image = this->image.resizeTo(m_iDrawWidth, m_iDrawHeight);
    }

    void virtDraw() override {
        getEngine()->drawForegroundRectangle(
            m_iCurrentScreenX - m_iDrawWidth / 2 + 1,
            m_iCurrentScreenY - m_iDrawHeight / 2 + 1,
            m_iCurrentScreenX + m_iDrawWidth / 2 - 1,
            m_iCurrentScreenY + m_iDrawHeight / 2 - 1,
            0xffff00);
        this->image.renderImage(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX + m_iStartDrawPosX, m_iCurrentScreenY + m_iStartDrawPosY, m_iDrawWidth, m_iDrawHeight);
    }
private:
    TileManager* tileManager;
    SimpleImage image;
};

} // namespace PushDaBox


#endif
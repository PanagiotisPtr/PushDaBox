#ifndef PUSHDABOX_COMPONENTS_PLAYER_H
#define PUSHDABOX_COMPONENTS_PLAYER_H

#include "../../DisplayableObject.h"
#include "../../TileManager.h"
#include "../../BaseEngine.h"

class Player : public DisplayableObject {
public:
    Player(BaseEngine* e, int width, int height, int startX, int startY,
           TileManager* tm)
    : DisplayableObject(e, width, height, false), tileManager(tm) {
        this->m_iCurrentScreenX = startX;
        this->m_iCurrentScreenY = startY;
        e->notifyObjectsAboutKeys(true);
    }

    void virtDraw() override {
		getEngine()->drawForegroundRectangle(
			m_iCurrentScreenX - m_iDrawWidth / 2 + 1,
			m_iCurrentScreenY - m_iDrawHeight / 2 + 1,
			m_iCurrentScreenX + m_iDrawWidth / 2 - 1,
			m_iCurrentScreenY + m_iDrawHeight / 2 - 1,
			0x0000ff);
	}

    void virtKeyDown(int keyCode) override {
        int prevX = m_iCurrentScreenX;
        int prevY = m_iCurrentScreenY;

        switch (keyCode) {
            case SDLK_w:
                this->m_iCurrentScreenY-=this->getDrawHeight();
                break;
            case SDLK_s:
                this->m_iCurrentScreenY+=this->getDrawHeight();
                break;
            case SDLK_a:
                this->m_iCurrentScreenX-=this->getDrawWidth();
                break;
            case SDLK_d:
                this->m_iCurrentScreenX+=this->getDrawWidth();
                break;
        }
        int mapX = this->tileManager->getMapXForScreenX(this->m_iCurrentScreenX);
        int mapY = this->tileManager->getMapYForScreenY(this->m_iCurrentScreenY);
        int mapValue = this->tileManager->getMapValue(mapX, mapY);
        if (mapValue == 0xff0000) {
            m_iCurrentScreenX = prevX;
            m_iCurrentScreenY = prevY;
        }
    }

    void virtDoUpdate(int iCurrentTime) override {
		redrawDisplay();
	}
private:
    TileManager* tileManager;
};

#endif
#ifndef PUSHDABOX_COMPONENTS_PLAYER_H
#define PUSHDABOX_COMPONENTS_PLAYER_H

#include "../../DisplayableObject.h"
#include "../../TileManager.h"
#include "../../BaseEngine.h"
#include "../../CollisionDetection.h"

#include <iostream>
#include <functional>

namespace PushDaBox {

class Player : public DisplayableObject {
public:
    using LevelTransition = std::function<void()>;

    Player(BaseEngine* e, int width, int height, int startX, int startY,
           TileManager* tm, DisplayableObject* b, LevelTransition transition)
    : DisplayableObject(e, width, height, false), tileManager(tm), box(b),
      nextLevel(transition) {
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
        if (mapValue != 0x000000) {
            m_iCurrentScreenX = prevX;
            m_iCurrentScreenY = prevY;
        }
        if (box->virtIsPositionWithinObject(this->m_iCurrentScreenX, this->m_iCurrentScreenY)) {
            int deltaX = 0;
            int deltaY = 0;
            switch (keyCode) {
            case SDLK_w:
                deltaY-=this->getDrawHeight();
                break;
            case SDLK_s:
                deltaY+=this->getDrawHeight();
                break;
            case SDLK_a:
                deltaX-=this->getDrawWidth();
                break;
            case SDLK_d:
                deltaX+=this->getDrawWidth();
                break;
            }
            int newBoxX = box->getDrawingRegionLeft() + deltaX;
            int newBoxY = box->getDrawingRegionTop() + deltaY;
            int mapX = this->tileManager->getMapXForScreenX(newBoxX);
            int mapY = this->tileManager->getMapYForScreenY(newBoxY);
            int mapValue = this->tileManager->getMapValue(mapX, mapY);
            if (mapValue != 0xff0000) {
                box->setPosition(newBoxX, newBoxY);
            } else {
                m_iCurrentScreenX = prevX;
                m_iCurrentScreenY = prevY;
            }

            if (mapValue == 0x00ff00) {
                this->nextLevel();
            }
        }
    }

    void virtDoUpdate(int iCurrentTime) override {
		redrawDisplay();
	}
private:
    TileManager* tileManager;
    DisplayableObject* box;
    LevelTransition nextLevel;
};

} // namespace PushDaBox

#endif
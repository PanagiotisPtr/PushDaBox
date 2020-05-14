#ifndef PUSHDABOX_COMPONENTS_ENEMY_H
#define PUSHDABOX_COMPONENTS_ENEMY_H

#include "../../DisplayableObject.h"
#include "../../TileManager.h"
#include "../../BaseEngine.h"
#include "../../CollisionDetection.h"
#include "../../SimpleImage.h"

#include <iostream>
#include <functional>
#include <thread>
#include <chrono>
#include <queue>
#include <limits>
#include <unordered_set>

namespace PushDaBox {

class Enemy : public DisplayableObject {
public:
    using resetFunction = std::function<void()>;
    using deleteEnemyFunction = std::function<void(DisplayableObject*)>;

    Enemy(BaseEngine* e, int width, int height, int startX, int startY,
           TileManager* tm, DisplayableObject* p, resetFunction r, deleteEnemyFunction d)
    : DisplayableObject(e, width, height, false), tileManager(tm), player(p),
      image(e->loadImage("assets/Enemy.png", false)), resetLevel(r), makeMove(true),
      deleteEnemy(d) {
        this->m_iCurrentScreenX = startX;
        this->m_iCurrentScreenY = startY;
        e->notifyObjectsAboutMouse(true);
        this->image = this->image.resizeTo(m_iDrawWidth, m_iDrawHeight);
    }

    void virtDraw() override {
		getEngine()->drawForegroundRectangle(
			m_iCurrentScreenX - m_iDrawWidth / 2 + 1,
			m_iCurrentScreenY - m_iDrawHeight / 2 + 1,
			m_iCurrentScreenX + m_iDrawWidth / 2 - 1,
			m_iCurrentScreenY + m_iDrawHeight / 2 - 1,
			0x0000ff);
        this->image.renderImage(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX + m_iStartDrawPosX, m_iCurrentScreenY + m_iStartDrawPosY, m_iDrawWidth, m_iDrawHeight);
	}

  void virtMouseDown(int button, int x, int y) override {
    if (!virtIsPositionWithinObject(x,y)) {
      return;
    }

    this->deleteEnemy(this);
  }

  struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);
    }
  };

  std::pair<int,int> getNextMove() {
    int mapX = this->tileManager->getMapXForScreenX(this->m_iCurrentScreenX);
    int mapY = this->tileManager->getMapYForScreenY(this->m_iCurrentScreenY);

    int playerX = this->tileManager->getMapXForScreenX(player->getDrawingRegionLeft());
    int playerY = this->tileManager->getMapYForScreenY(player->getDrawingRegionTop());

    if (playerX == mapX && playerY == mapY) {
      return {0,0};
    }

    std::queue<std::pair<std::pair<int,int>, std::vector<std::pair<int,int> > > > q;

    q.push({{mapX + 1, mapY}, {{1, 0}}});
    q.push({{mapX - 1, mapY}, {{-1, 0}}});
    q.push({{mapX, mapY + 1}, {{0, 1}}});
    q.push({{mapX, mapY - 1}, {{0, -1}}});

    int bestMoves = std::numeric_limits<int>::max();
    std::vector<std::pair<int,int> > rv = {};
    std::unordered_set<std::pair<int,int>, pair_hash> visited;
    while (!q.empty()) {
      std::pair<int,int> pos = q.front().first;
      std::vector<std::pair<int,int> > moves = q.front().second;
      q.pop();
      if (visited.find(pos) != std::end(visited)) {
        continue;
      }
      visited.insert(pos);
      int mapValue = this->tileManager->getMapValue(pos.first, pos.second);
      if (mapValue == 0xff0000) {
        continue;
      }
      if (pos.first == playerX && pos.second == playerY) {
        if (moves.size() < bestMoves) {
          bestMoves = moves.size();
          rv = moves;
        }
      }

      moves.push_back({1, 0});
      q.push({{pos.first + 1, pos.second}, moves});
      moves.pop_back();
      moves.push_back({-1, 0});
      q.push({{pos.first - 1, pos.second}, moves});
      moves.pop_back();
      moves.push_back({0, 1});
      q.push({{pos.first, pos.second + 1}, moves});
      moves.pop_back();
      moves.push_back({0, -1});
      q.push({{pos.first, pos.second - 1}, moves});
    }

    return rv.front();
  }

  bool onPlayer() {
    int mapX = this->tileManager->getMapXForScreenX(this->m_iCurrentScreenX);
    int mapY = this->tileManager->getMapYForScreenY(this->m_iCurrentScreenY);

    int playerX = this->tileManager->getMapXForScreenX(player->getDrawingRegionLeft());
    int playerY = this->tileManager->getMapYForScreenY(player->getDrawingRegionTop());

    return playerX == mapX && playerY == mapY;
  }

  void virtDoUpdate(int iCurrentTime) override {
    if (this->makeMove) {
      this->makeMove = false;
      std::pair<int,int> nextMove = this->getNextMove();
      this->m_iCurrentScreenY += this->getDrawHeight() * nextMove.second;
      this->m_iCurrentScreenX += this->getDrawWidth() * nextMove.first;

      if (this->onPlayer()) {
        this->resetLevel();
        return;
      }

      std::thread callback([](bool& makeMove){
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
        makeMove = true;
      }, std::ref(this->makeMove));
      callback.detach();
    }
		redrawDisplay();
	}
private:
    TileManager* tileManager;
    DisplayableObject* player;
    SimpleImage image;
    resetFunction resetLevel;
    deleteEnemyFunction deleteEnemy;
    bool makeMove;
};

} // namespace PushDaBox

#endif
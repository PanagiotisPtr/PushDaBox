#ifndef PUSHDABOX_COMPONENTS_GAMEGRID_H
#define PUSHDABOX_COMPONENTS_GAMEGRID_H

// Simple tile manager used in the MazeDemo

#include "../../TileManager.h"

namespace PushDaBox {

class GameGrid : public TileManager {
public:
	GameGrid(BaseEngine* e, int tileHeight, int tileWidth)
	: TileManager(tileHeight, tileWidth), image(e->loadImage("assets/Star.png", false)) {
		this->image = this->image.resizeTo(getTileWidth(), getTileHeight());
	}

	~GameGrid() {
	}

	virtual void virtDrawTileAt(BaseEngine* e, DrawingSurface* s, int mx, int my, int sx, int sy) const override {
        if (getMapValue(mx,my) == 0x00ff00) {
			std::cout << sx << " " << sy << " " << getTileWidth() << " " << getTileHeight() << std::endl;
			this->image.renderImage(s, 0, 0, sx, sy, getTileWidth(), getTileHeight());
			return;
		}
		if (getMapValue(mx, my) == 0xff00ff) {
			return; // enemy spawn locations are hidden
		}
		s->drawRectangle(
			sx,
			sy, 
			sx + getTileWidth() - 1,
			sy + getTileHeight() - 1,
			getMapValue(mx,my));
		if (getMapValue(mx, my) == 0x010101) {
			// easter egg features
		}
	}
private:
	SimpleImage image;
};

} // namespace PushDaBox


#endif
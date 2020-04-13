#ifndef PUSHDABOX_COMPONENTS_GAMEGRID_H
#define PUSHDABOX_COMPONENTS_GAMEGRID_H

// Simple tile manager used in the MazeDemo

#include "../../TileManager.h"

class GameGrid : public TileManager {
public:
	GameGrid(int tileHeight, int tileWidth) : TileManager(tileHeight, tileWidth) {
	}

	~GameGrid() {
	}

	virtual void virtDrawTileAt(BaseEngine* e, DrawingSurface* s, int mx, int my, int sx, int sy) const override {
        s->drawRectangle(
			sx,
			sy, 
			sx + getTileWidth() - 1,
			sy + getTileHeight() - 1,
			getMapValue(mx,my));
	}
};

#endif
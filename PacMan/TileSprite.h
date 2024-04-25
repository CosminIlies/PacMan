#pragma once
#include "Sprite.h"

class TileSprite : public Sprite
{
public:

	TileSprite(const char* textureFile, int x, int y, int countX, int countY);
	~TileSprite();

	void setTile(int x, int y);
protected:
	int _x, _y, _countX, _countY;
};


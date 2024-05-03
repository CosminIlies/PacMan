#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "TileSprite.h"
#include "WorldTile.h"
#include "Entity.h"



class WorldGrid : public Entity
{
public:
	WorldGrid(const char*filePath);
	~WorldGrid();

	void update(float deltaTime);
	void draw(sf::RenderWindow* window);

private:
	static const int maxDim = 50;
	int _countX, _countY;
	WorldTile *_map[maxDim][maxDim];

};


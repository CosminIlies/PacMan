#pragma once

#include <vector>

#include "TileSprite.h"
#include "Entity.h"



class WorldGrid : public Entity
{
public:
	WorldGrid(int countX, int countY);
	~WorldGrid();

	void update(float deltaTime);
	void draw(sf::RenderWindow* window);

private:
	static const int maxDim = 50;
	int _countX, _countY;
	Entity *_map[maxDim][maxDim];

};


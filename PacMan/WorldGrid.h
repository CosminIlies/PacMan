#pragma once

#include <iostream>
#include <fstream>

#include "TileSprite.h"
#include "WorldTile.h"
#include "Entity.h"
#include "Enemy.h"
#include "SceneManager.h"


class WorldGrid : public Entity
{
public:
	WorldGrid(const char*filePath, int tileSize = 16);
	~WorldGrid();

	bool update(float deltaTime);
	void draw(sf::RenderWindow* window);

	WorldTile* getTile(int x, int y);
	bool canWalkHorizontal(sf::Vector2f pos);
	bool canWalkVertical(sf::Vector2f pos);
	void resetGrid();
	inline int getTileSize() { return tileSize; }
	inline int getCountX() { return countX; }
	inline int getCountY() { return countY; }


	static const int maxDim = 50;
	WorldTile *map[maxDim][maxDim];
	bool horizontalCollisionMask[maxDim][maxDim];
	bool verticalCollisionMask[maxDim][maxDim];

	int tileSize;
	int countX, countY;
	std::vector<sf::Vector2f> enemies;


};


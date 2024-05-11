#pragma once
#include "Entity.h"
#include "TileSprite.h"

class WorldTile : public Entity
{

public:
	bool isWalkable = false;
	int x, y;

	WorldTile* parent = nullptr;
	int gCost = INT_MAX;
	int hCost = 0;
	int	fCost = 0;

	bool operator<(const WorldTile& w) const
	{
		return this->fCost < w.fCost;
	}


	inline void clear() { gCost = INT_MAX; hCost = 0; fCost = 0; parent = nullptr; }
	inline void calculateFCost() { fCost = gCost + hCost; }
	inline int dist(WorldTile* other) { return abs(x - other->x) + abs(y - other->y); }

	WorldTile(bool isWalkable, int x, int y, TileSprite* tileSprite, std::string name, sf::Vector2f position, sf::Vector2f scale);
	~WorldTile();

};


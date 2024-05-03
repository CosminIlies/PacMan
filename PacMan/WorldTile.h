#pragma once
#include "Entity.h"
#include "TileSprite.h"

class WorldTile : public Entity
{

public:
	bool isWalkable = false;

	WorldTile(bool isWalkable, TileSprite* tileSprite, std::string name, sf::Vector2f position, sf::Vector2f scale);
	~WorldTile();

};


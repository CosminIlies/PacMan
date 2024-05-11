#include "WorldTile.h"

WorldTile::WorldTile(bool isWalkable, int x, int y, TileSprite* tileSprite, std::string name, sf::Vector2f position, sf::Vector2f scale):Entity(tileSprite, name.c_str(), position, 0.0f, scale)
{
	this->x= x;
	this->y = y;
	this->isWalkable = isWalkable;
}

WorldTile::~WorldTile()
{
}



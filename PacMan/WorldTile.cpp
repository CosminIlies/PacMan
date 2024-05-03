#include "WorldTile.h"

WorldTile::WorldTile(bool isWalkable, TileSprite* tileSprite, std::string name, sf::Vector2f position, sf::Vector2f scale):Entity(tileSprite, name.c_str(), position, 0.0f, scale)
{
	this->isWalkable = isWalkable;
}

WorldTile::~WorldTile()
{
}



#pragma once
#include <SFML/Graphics.hpp>
#include "WorldTile.h"
class EnemyAI
{
public:

	virtual void updatePath(sf::Vector2i start, sf::Vector2i dest) = 0;
	virtual sf::Vector2f getNextPoint() = 0;
	virtual sf::Vertex* getPath() = 0;
	virtual int getPathSize() = 0;
};


#pragma once

#include <iostream>

#include "Entity.h"
#include "WorldGrid.h"

class Player : public Entity
{

public:
	Player(WorldGrid* grid, const char* name, Sprite* sprite, float speed, sf::Vector2f position, sf::Vector2f scale);
	~Player();

	bool update(float dt);

	private:
		WorldGrid* grid;
		float _speed;
};


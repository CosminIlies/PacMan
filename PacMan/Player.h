#pragma once

#include <iostream>

#include "Entity.h"
#include "WorldGrid.h"
#include "Camera.h"

class Player : public Entity
{

public:
	Player(WorldGrid* grid, Camera* camera, const char* name, Sprite* sprite, float speed, sf::Vector2f position, sf::Vector2f scale);
	~Player();

	bool update(float dt);

	private:
		WorldGrid* grid;
		Camera* camera;
		float _speed;
};


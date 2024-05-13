#pragma once
#include "Entity.h"
#include "Player.h"
#include "WorldGrid.h"
#include "QuizManager.h"

class Fruit : public Entity
{
public:
	Fruit(WorldGrid* grid, Player* playr, int index, const char* name, Sprite* sprite, sf::Vector2f scale );
	~Fruit();

	void setRandomPosition();
	bool update(float deltaTime);

private:
	int index;
	WorldGrid* grid;
	Player* player;
};


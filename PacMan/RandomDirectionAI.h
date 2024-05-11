#pragma once
#include "EnemyAI.h"


class RandomDirectionAI : public EnemyAI
{
public:

	void updatePath();
	sf::Vector2f getDirection();
private:
	sf::Vector2f _dir;
};


#pragma once

#include "Entity.h"
#include "EnemyAI.h"
#include "SceneManager.h"
//#include "Player.h"

class Enemy : public Entity
{
public:
	EnemyAI* ai;
	sf::Vector2f* target;
	Enemy(EnemyAI* enemyAI, sf::Vector2f* target, const char* name, Sprite* sprite, float speed, sf::Vector2f position, sf::Vector2f scale);
	~Enemy();
	bool update(float dt);
	void draw(sf::RenderWindow* window);
	bool goToPoint(sf::Vector2f point, float dt);



private:

	float speed;
};


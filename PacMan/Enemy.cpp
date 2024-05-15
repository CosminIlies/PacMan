#include "Enemy.h"

Enemy::Enemy(EnemyAI* enemyAI, sf::Vector2f* target, const char* name, Sprite* sprite, float speed, sf::Vector2f position, sf::Vector2f scale):Entity(sprite, name, position, 0, scale)
{
	this->speed = speed;
	this->ai = enemyAI;
	//this->player = player;
	this->target = target;
}

Enemy::~Enemy()
{
	delete ai;
}



bool Enemy::update(float dt)
{
	Entity::update(dt);

	sf::Vector2f dir = *target - position;
	float len = sqrt(dir.x * dir.x + dir.y * dir.y);

	if (len < 16 * 5) {
		SceneManagerInstance->nextScene();
		return true;
	}

	if(goToPoint(ai->getNextPoint(), dt))
		ai->updatePath(sf::Vector2i(position.x / 5.0 / 16.0 + 0.5, position.y / 5.0 / 16.0 + 0.5), sf::Vector2i(target->x / 5.0 / 16.0 + 0.5, target->y / 5.0 / 16.0 + 0.5));

}

void Enemy::draw(sf::RenderWindow* window)
{
	Entity::draw(window);
	window->draw(ai->getPath(), ai->getPathSize(), sf::Lines);
}

bool Enemy::goToPoint(sf::Vector2f point, float dt)
{
	sf::Vector2f dir = point - position;
	float len = sqrt(dir.x * dir.x + dir.y * dir.y);

	if(len > 0)
	{
		dir /= len;
		position += dir * speed * dt;
	}

	return len < 5 && point != sf::Vector2f(0,0);
}

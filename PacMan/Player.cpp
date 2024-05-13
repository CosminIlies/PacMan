#include "Player.h"

Player::Player(WorldGrid* grid, Camera* camera, const char* name, Sprite* sprite, float speed, sf::Vector2f position, sf::Vector2f scale) : Entity(sprite, name, position, 0, scale)
{
		this->_speed = speed;
		this->grid = grid;
		this->camera = camera;
}

Player::~Player()
{
}

bool Player::update(float dt)
{
	Entity::update(dt);
	camera->position = position;
	sf::Vector2f dir = sf::Vector2f(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		dir.y -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		dir.y += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		dir.x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
	{
		dir.x += 1;
	}

	if (dir.x == 0 && dir.y == 0)
	{
		return false;
	}
	if (dir.x > 0) {
		if (!grid->getTile(position.x / 16.0 / 5.0 +   dir.x, position.y / 16.0 / 5.0 +   dir.y)->isWalkable) {
			return false;
		}
	}
	if (dir.x < 0) {
		if (!grid->getTile(position.x / 16.0 / 5.0 +   dir.x + 1, position.y / 16.0 / 5.0 +   dir.y)->isWalkable) {
			return false;
		}
	}

	if (dir.y > 0) {
		if (!grid->getTile(position.x / 16.0 / 5.0 +   dir.x, position.y / 16.0 / 5.0 +   dir.y)->isWalkable) {
			return false;
		}
	}
	if (dir.y < 0) {
		if (!grid->getTile(position.x / 16.0 / 5.0 +   dir.x, position.y / 16.0 / 5.0 +   dir.y + 1)->isWalkable) {
			return false;
		}
	}

	float magnitude = sqrt(dir.x * dir.x + dir.y * dir.y);

	dir.x /= magnitude;
	dir.y /= magnitude;

	dir = dir * _speed * dt;

	position += dir;
	return false;

}

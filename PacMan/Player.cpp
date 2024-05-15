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

	float magnitude = sqrt(dir.x * dir.x + dir.y * dir.y);

	dir.x /= magnitude;
	dir.y /= magnitude;

	dir = dir * _speed * dt;

	position += dir;


	for (int i = 0; i < grid->countX; i++) {
		for (int j = 0; j < grid->countY; j++) {

			WorldTile* tile = grid->getTile(i, j);

			if (tile->isWalkable) {
				continue;
			}

			sf::Vector2f tilePos = sf::Vector2f(i * 16.0 * 5.0, j * 16.0 * 5.0);

			float halfedTileSize = 16 * 5 / 2;

			float deltaX = tilePos.x - position.x;
			float deltaY = tilePos.y - position.y;

			float intersectX = abs(deltaX) - (halfedTileSize - 5 + halfedTileSize);
			float intersectY = abs(deltaY) - (halfedTileSize - 5 + halfedTileSize);

			if (intersectX < 0 && intersectY < 0) {
				if (intersectX > intersectY) {
					if (deltaX > 0) {
						position.x += intersectX;
					}
					else {
						position.x -= intersectX;
					}
				}
				else {
					if (deltaY > 0) {
						position.y += intersectY;
					}
					else {
						position.y -= intersectY;
					}
				}
			}
		}
	}
	return false;

}

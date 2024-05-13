#include "Fruit.h"

Fruit::Fruit(WorldGrid* grid, Player* player, int index, const char* name, Sprite* sprite, sf::Vector2f scale)
	: Entity(sprite, name, sf::Vector2f(), 0, scale)
{
	this->player = player;
	this->grid = grid;
	this->index = index;
	setRandomPosition();
}

Fruit::~Fruit()
{
}

void Fruit::setRandomPosition()
{
	std::cout<< "Setting random position for fruit " << index << std::endl;
	WorldTile* tile;
	do {
		tile = grid->getTile(rand() % 21, rand() % 12);
	} while (!tile->isWalkable);
	
	this->position = sf::Vector2f(tile->x*16*5, tile->y*16*5);
}

bool Fruit::update(float deltaTime)
{
	Entity::update(deltaTime);
	sf::Vector2f direction = this->position - player->position;
	float distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	if (distance < 16 * 2) {
		setRandomPosition();
		if (!QuizManagerInstance->answerQuestion(index)) {
			std::cout << "NOT CORRECT";
			SceneManagerInstance->previousScene();
			return true;
		}
		std::cout << "CORRECT";
	}

	return false;
}

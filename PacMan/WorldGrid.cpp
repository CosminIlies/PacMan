#include "WorldGrid.h"

WorldGrid::WorldGrid(int countX, int countY):Entity(nullptr, "worldGrid")
{
	this->_countX = countX;
	this->_countY = countY;
	
	for (int i = 0; i < countX; i++)
	{
		for (int j = 0; j < countY; j++)
		{
			this->_map[i][j] = new Entity(new TileSprite("./res/testCharacter.png", 0, 0, 7, 2), "ent");
			this->_map[i][j]->position.x = i * _map[i][j]->sprite->sizeX * 5;
			this->_map[i][j]->position.y = j * _map[i][j]->sprite->sizeY * 5;
			this->_map[i][j]->scale.x = 5;
			this->_map[i][j]->scale.y = 5;
		}
	}
}

WorldGrid::~WorldGrid()
{
}

void WorldGrid::update(float deltaTime)
{

	for (int i = 0; i < _countX; i++)
	{
		for (int j = 0; j < _countY; j++)
		{
			_map[i][j]->update(deltaTime);
		}
	}
}

void WorldGrid::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < _countX; i++)
	{
		for (int j = 0; j < _countY; j++)
		{
			_map[i][j]->draw(window);
		}
	}
}

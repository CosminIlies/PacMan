#include "WorldGrid.h"

WorldGrid::WorldGrid(const char* filePath):Entity(nullptr, "worldGrid")
{
	std::ifstream file(filePath);

	file >> _countX >> _countY;
	for (int i = 0; i < _countX; i++)
	{
		for (int j = 0; j < _countY; j++)
		{
			int tile;
			file >> tile;
			std::cout<<tile<<std::endl;

			if (tile == 0)
				this->_map[i][j] = new WorldTile(true, nullptr,"ent", sf::Vector2f(0,0), sf::Vector2f(5,5));
			
			if (tile == 1){
				this->_map[i][j] = new WorldTile(false, new TileSprite("./res/testCharacter.png", 0, 0, 7, 2), "ent", sf::Vector2f(0, 0), sf::Vector2f(5, 5));

				this->_map[i][j]->position.x = i * _map[i][j]->sprite->sizeX * 5;
				this->_map[i][j]->position.y = j * _map[i][j]->sprite->sizeY * 5;

			}
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

#include "WorldGrid.h"


WorldGrid::WorldGrid(const char* filePath, int tileSize):Entity(nullptr, "worldGrid")
{
	this->tileSize = tileSize*5;;

	std::ifstream file(filePath);

	file >> countX >> countY;
	for (int j = 0; j < countY; j++)
	{
		for (int i = 0; i < countX; i++)
		{
			int tile;
			file >> tile;

			if (tile == 0)
				this->map[i][j] = new WorldTile(true, i, j, nullptr,"ent", sf::Vector2f(0,0), sf::Vector2f(5,5));
			
			if (tile == 1){
				this->map[i][j] = new WorldTile(false, i, j, new TileSprite("./res/wallTest1.png", 0, 0, 1, 1), "ent", sf::Vector2f((i) * 5 * tileSize, (j) * 5 * tileSize), sf::Vector2f(5, 5));
			}

			if (tile == 3) {
				this->map[i][j] = new WorldTile(true, i, j, nullptr, "ent", sf::Vector2f(0, 0), sf::Vector2f(5, 5));
				enemies.push_back(sf::Vector2f(i,j));
			}
		}
	}

	file.close();

	std::cout << "HORIZONTAL:\n";
	for (int j = 0; j < countY-1; j++)
	{
		for (int i = 0; i < countX-1; i++)
		{
			if (map[i][j]->isWalkable && map[i+1][j]->isWalkable) {
				horizontalCollisionMask[i][j] = true;
				std::cout<< "1 ";
			}
			else {
				horizontalCollisionMask[i][j] = false;
				std::cout << "0 ";
			}
		}
			std::cout << "\n";
	}
	std::cout << "VERTICAL\n";
	for (int j = 0; j < countY - 1; j++)
	{
		for (int i = 0; i < countX - 1; i++)
		{
			if (map[i][j]->isWalkable && map[i][j+1]->isWalkable) {
				verticalCollisionMask[i][j] = true;
				std::cout << "1 ";
			}
			else {
				verticalCollisionMask[i][j] = false;
				std::cout << "0 ";
			}
		}
			std::cout << "\n";
	}
}

WorldGrid::~WorldGrid()
{
}

bool WorldGrid::update(float deltaTime)
{

	for (int i = 0; i < countX; i++)
	{
		for (int j = 0; j < countY; j++)
		{
			map[i][j]->update(deltaTime);
		}
	}
	return false;
}

void WorldGrid::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < countX; i++)
	{
		for (int j = 0; j < countY; j++)
		{
			map[i][j]->draw(window);
		}
	}
}

WorldTile* WorldGrid::getTile(int x, int y)
{
	return map[x][y];
}

bool WorldGrid::canWalkHorizontal(sf::Vector2f pos)
{
	return horizontalCollisionMask[(int)(pos.x / 16.0 / 5.0)][(int)(pos.y / 16.0 / 5.0)];
}

bool WorldGrid::canWalkVertical(sf::Vector2f pos)
{
	return verticalCollisionMask[(int)(pos.x / 16.0 / 5.0)][(int)(pos.y / 16.0 / 5.0)];
}

void WorldGrid::resetGrid()
{
	for (int i = 0; i < countX; i++)
	{
		for (int j = 0; j < countY; j++)
		{
			map[i][j]->clear();
		}
	}
}

#pragma once

#include <queue>
#include <set>

#include "Heap.h"
#include "WorldGrid.h"
#include "Enemy.h"

class AstarAI : public EnemyAI
{
public:
	AstarAI(WorldGrid* wg);
	~AstarAI();

	void updatePath(sf::Vector2i start, sf::Vector2i dest);
	void processPath();
	void setEnemy(Enemy *enemy);
	sf::Vertex* getPath();
	int getPathSize();

	sf::Vector2f getNextPoint();

private:
	int idx = 0;
	Enemy* enemy;

	WorldGrid* _worldGrid;
	WorldTile* startNode = nullptr;
	WorldTile* endNode = nullptr;

	Heap openList;
	set<WorldTile*> closeList;
	vector<WorldTile*> path;

};


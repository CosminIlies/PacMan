#include "AstarAI.h"

AstarAI::AstarAI(WorldGrid* wg)
{
	_worldGrid = wg;
}

AstarAI::~AstarAI()
{
}

void AstarAI::updatePath(sf::Vector2i start, sf::Vector2i dest)
{
	std::cout << "UPDATE PATH\n";
	_worldGrid->resetGrid();
	closeList.clear();
	openList.clear();

	if (startNode != nullptr && endNode != nullptr)
	{
		//std::cout << start.x << " : " << start.y << " : " << this->startNode->x << " : " << this->startNode->y << std::endl;
		if (start.x == this->startNode->x && start.y == this->startNode->y && dest.x == this->endNode->x && dest.y == this->endNode->y)
		{
			return;
		}
		std::cout << "route recalculated" << std::endl;
	}

	

	this->startNode = _worldGrid->map[start.x][start.y];
	this->endNode = _worldGrid->map[dest.x][dest.y];
	if (startNode == nullptr || endNode == nullptr) {
		return;
	}

	startNode->gCost = 0;
	startNode->hCost = startNode->dist(endNode);
	openList.push(startNode);


	while (!openList.empty()) {
		WorldTile* currentNode = openList.pop();

		closeList.insert(currentNode);

		int x = currentNode->x;
		int y = currentNode->y;

		if (currentNode == endNode) {
			processPath();
			break;
		}

		//TOP

		if (y > 0) {
			WorldTile* topNode = _worldGrid->getTile(x,y - 1);

			if (topNode->isWalkable && closeList.find(topNode) == closeList.end()) {
				int newGCost = currentNode->gCost + 1;

				if (newGCost < topNode->gCost) {
					topNode->gCost = newGCost;
					topNode->hCost = topNode->dist(endNode);
					topNode->calculateFCost();
					topNode->parent = currentNode;
				}

				if (!openList.contains(topNode)) {
					openList.push(topNode);
				}

			}
		}

		//LEFT
		if (x > 0) {
			WorldTile* leftNode = _worldGrid->getTile(x - 1, y);

			if (leftNode->isWalkable && closeList.find(leftNode) == closeList.end()) {
				int newGCost = currentNode->gCost + 1;

				if (newGCost < leftNode->gCost) {
					leftNode->gCost = newGCost;
					leftNode->hCost = leftNode->dist(endNode);
					leftNode->calculateFCost();
					leftNode->parent = currentNode;
				}

				if (!openList.contains(leftNode)) {
					openList.push(leftNode);
				}

			}
		}

		//DOWN
		if (y < _worldGrid->countY - 1) {
			WorldTile* downNode = _worldGrid->getTile(x, y + 1);

			if (downNode->isWalkable && closeList.find(downNode) == closeList.end()) {
				int newGCost = currentNode->gCost + 1;

				if (newGCost < downNode->gCost) {
					downNode->gCost = newGCost;
					downNode->hCost = downNode->dist(endNode);
					downNode->calculateFCost();
					downNode->parent = currentNode;
				}

				if (!openList.contains(downNode)) {
					openList.push(downNode);
				}

			}
		}

		//RIGHT
		if (x < _worldGrid->countX - 1) {
			WorldTile* rightNode = _worldGrid->getTile(x + 1, y);

			if (rightNode->isWalkable && closeList.find(rightNode) == closeList.end()) {
				int newGCost = currentNode->gCost + 1;


				if (newGCost < rightNode->gCost) {
					rightNode->gCost = newGCost;
					rightNode->hCost = rightNode->dist(endNode);
					rightNode->calculateFCost();
					rightNode->parent = currentNode;
				}

				if (!openList.contains(rightNode)) {
					openList.push(rightNode);
				}

			}
		}

	}

	processPath();
}

void AstarAI::processPath()
{
	WorldTile* currentNode = endNode;
	
	path.clear();
	while (currentNode != nullptr) {
		path.push_back(currentNode);
		currentNode = currentNode->parent;
	}
}

void AstarAI::setEnemy(Enemy* enemy)
{
	this->enemy = enemy;
}

sf::Vertex* AstarAI::getPath()
{
	sf::Vertex* vertices = new sf::Vertex[path.size()];
	for (int i = 0; i < path.size(); i++) {
		vertices[i] = sf::Vertex(sf::Vector2f(path[i]->x * 16 *5, path[i]->y * 16 *5), sf::Color::Red);
	}

	return vertices;
}

int AstarAI::getPathSize()
{
	return path.size();
}



sf::Vector2f AstarAI::getNextPoint()
{
	if (path.size() <= 2) return sf::Vector2f(0,0);
	return	sf::Vector2f(path[path.size() - 2]->x * 16 *5, path[path.size() - 2]->y * 16 * 5);
}

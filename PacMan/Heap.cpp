#include "Heap.h"

Heap::Heap()
{
}

Heap::~Heap()
{
}

WorldTile* Heap::pop()
{
	WorldTile* minNode = list[0];
	for (WorldTile* nod : list) {
		if (nod->fCost < minNode->fCost) {
			minNode = nod;
		}
	}
	remove(minNode);
	return minNode;
}

void Heap::push(WorldTile* node)
{
	list.push_back(node);
}

bool Heap::contains(WorldTile* node)
{
	for (WorldTile* n : list) {
		if (n == node)
			return true;
	}

	return false;
}

void Heap::remove(WorldTile* node)
{
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == node) {
			list.erase(list.begin() + i);
			break;
		}
	}
}

void Heap::clear()
{
	list.clear();
}

bool Heap::empty()
{
	return list.size() == 0;
}

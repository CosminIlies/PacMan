#pragma once
#include <vector>
#include "WorldTile.h"

using namespace std;


class Heap
{
public:
	Heap();
	~Heap();

	WorldTile* pop();
	void push(WorldTile* node);
	bool contains(WorldTile* node);
	void remove(WorldTile* node);
	void clear();
	bool empty();


	vector<WorldTile*> list;
};



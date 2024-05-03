#include "TestScene1.h"

#include "AnimatedSprite.h"

void TestScene1::init()
{
	addEntity(new WorldGrid("./res/map.txt"));
}

void TestScene1::cleanUp()
{
	for (int i = 0; i < _entities.size(); i++) { 
		delete _entities[i];
	}
	_entities.clear();
}

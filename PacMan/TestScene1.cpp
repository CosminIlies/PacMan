#include "TestScene1.h"


void TestScene1::init()
{
	addEntity(new Entity("./res/Dirt.tga", "TestEntity"));
}

void TestScene1::cleanUp()
{
	for (int i = 0; i < _entities.size(); i++) {
		delete _entities[i];
	}
	_entities.clear();
}

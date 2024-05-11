#include "TestScene2.h"

void TestScene2::init()
{
	
}

void TestScene2::cleanUp()
{
	for (int i = 0; i < _entities.size(); i++) {
		delete _entities[i];
	}
	_entities.clear();
}

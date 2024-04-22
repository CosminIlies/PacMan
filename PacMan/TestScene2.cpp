#include "TestScene2.h"

void TestScene2::init()
{
	addEntity(new Entity("./res/Dirt.tga", "TestEntity", sf::Vector2f(5, 0), 45, sf::Vector2f(1, 2)));
}

void TestScene2::cleanUp()
{
	for (int i = 0; i < _entities.size(); i++) {
		delete _entities[i];
	}
	_entities.clear();
}

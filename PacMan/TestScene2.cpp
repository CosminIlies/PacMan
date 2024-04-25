#include "TestScene2.h"

void TestScene2::init()
{
	addEntity(new Entity(new Sprite("./res/Dirt.tga"), "TestEntity", sf::Vector2f(0, 0), 0, sf::Vector2f(1, 1)));
	addEntity(new Entity(new Sprite("./res/Dirt.tga"), "TestEntity", sf::Vector2f(500, 0), 0, sf::Vector2f(1, 1)));
	addEntity(new Entity(new Sprite("./res/Dirt.tga"), "TestEntity", sf::Vector2f(1000, 0), 0, sf::Vector2f(1, 1)));
	addEntity(new Entity(new Sprite("./res/Dirt.tga"), "TestEntity", sf::Vector2f(1500, 0), 0, sf::Vector2f(1, 1)));

}

void TestScene2::cleanUp()
{
	for (int i = 0; i < _entities.size(); i++) {
		delete _entities[i];
	}
	_entities.clear();
}

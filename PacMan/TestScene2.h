#pragma once
#include "Scene.h"

class TestScene2 : public Scene
{
public:
	TestScene2(sf::RenderWindow* window) : Scene(window) { }
	void init();
	void cleanUp();

private:

};

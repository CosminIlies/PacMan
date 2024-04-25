#pragma once
#include"Scene.h"
#include "Sprite.h"
#include"WorldGrid.h"

class TestScene1 : public Scene
{
public:
	TestScene1(sf::RenderWindow *window) : Scene(window) { }
	void init();
	void cleanUp();

private:

};


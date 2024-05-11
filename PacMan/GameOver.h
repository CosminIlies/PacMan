#pragma once
#include "Scene.h"
#include "Entity.h"
#include "Button.h"
#include "Text.h"
#include "SceneManager.h"

class GameOver : public Scene
{
public:
	GameOver(sf::RenderWindow* window) : Scene(window) { }
	void init();
	void cleanUp();

private:

};

#pragma once

#include "Scene.h"
#include "Image.h"
#include "Button.h"
#include "SceneManager.h"
#include "Application.h"

class MainMenu : public Scene
{

public:
	MainMenu(sf::RenderWindow* window) : Scene(window) { }
	void init();
	void cleanUp();

};



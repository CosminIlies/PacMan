#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "Entity.h"
#include "SceneManager.h"
#include "TestScene1.h"
#include "TestScene2.h"


class Application
{
public:

	Application(int width, int height, const char* name);
	~Application();

	void start();

private:
	sf::RenderWindow* _window;
	SceneManager* sceneManager;


};


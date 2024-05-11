#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "Entity.h"
#include "SceneManager.h"
#include "MainMenu.h"
#include "TestScene1.h"
#include "GameOver.h"


class Application
{
public:
	sf::RenderWindow* window;

	void init(int width, int height, const char* name);

	static Application* getInstance();

	~Application();

	void start();
	void stop();

private:

	static Application* instance;
	Application(int width, int height, const char* name);


	SceneManager* sceneManager;


};

#define ApplicationInstance Application::getInstance()
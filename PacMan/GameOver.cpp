#include "GameOver.h"

void GameOver::init()
{
	Scene::init();
	Text* text = new Text("Game Over",
		"./res/square-deal.ttf",
		128,
		sf::Color::Red,
		sf::Vector2f(800, 200),
		0, sf::Vector2f(2, 2));

	Button* toMainMenu = new Button("Return To main menu",
				[]() { 
			SceneManagerInstance->previousScene();
			SceneManagerInstance->previousScene(); 
			return true;
		},
				new Sprite("./res/wallTest1.png"),
				sf::Vector2f(800, 500),
				0,
				sf::Vector2f(40, 10));

	addEntity(text);
	addEntity(toMainMenu);
}

void GameOver::cleanUp()
{
	Scene::cleanUp();
}

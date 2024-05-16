#include "GameOver.h"

void GameOver::init()
{
	Scene::init();
	buffer = new sf::SoundBuffer();
	if (buffer->loadFromFile("./res/death.mp3"))
	{
		sound = new sf::Sound();
		sound->setBuffer(*buffer);
		sound->play();
	}
	music = new sf::Music();
	if (music->openFromFile("./res/deathmusic.mp3")) {
		music->play();
	}

	Text* text = new Text("Game Over",
		"./res/square-deal.ttf",
		128,
		sf::Color::Red,
		sf::Vector2f(800, 200),
		0, sf::Vector2f(2, 2));

	Button* toMainMenu = new Button("Return to Main Menu",
				[]() { 
			SceneManagerInstance->previousScene();
			SceneManagerInstance->previousScene(); 
			return true;
		},
				new Sprite("./res/buttonBg.png"),
				sf::Vector2f(800, 500),
				0,
				sf::Vector2f(15, 15));

	addEntity(text);
	addEntity(toMainMenu);
}

void GameOver::cleanUp()
{
	Scene::cleanUp();
	delete buffer;
	delete sound;
	delete music;
}

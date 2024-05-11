#include "MainMenu.h"

void MainMenu::init()
{
	Scene::init();

	//Image* bg = new Image(new Sprite("./res/placeholderMainMenu.png"), "bg", sf::Vector2f(0, 0), 0, sf::Vector2f(10, 10));
	Text* text = new Text("PacMan",
				"./res/BoogieNightsShadowNF.ttf",
				128,
				sf::Color::White  ,
				sf::Vector2f(800, 200),
				0, sf::Vector2f(2, 2));	
	
	Button* playBtn = new Button("Play",
		[]() { SceneManagerInstance->nextScene(); return true; },
		new Sprite("./res/wallTest1.png"),
		sf::Vector2f(800,500),
		0, 
		sf::Vector2f(40, 10));

	Button* quitBtn = new Button("Quit",
		[]() {  ApplicationInstance->stop();  return true;  },
		new Sprite("./res/wallTest1.png"),
		sf::Vector2f(800, 700),
		0,
		sf::Vector2f(40, 10));


	//addEntity(bg);
	addEntity(text);
	addEntity(playBtn);
	addEntity(quitBtn);


}

void MainMenu::cleanUp()
{
	Scene::cleanUp();
}

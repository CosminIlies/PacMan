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
		new Sprite("./res/buttonBg.png"),
		sf::Vector2f(800,500),
		0, 
		sf::Vector2f(15, 15));

	Button* quitBtn = new Button("Quit",
		[]() {  ApplicationInstance->stop();  return true;  },
		new Sprite("./res/buttonBg.png"),
		sf::Vector2f(800, 700),
		0,
		sf::Vector2f(15, 15));

	Text* proj = new Text("This application is part of the following EU project: \"Gender, Digitalization, Green: Ensuring a Sustainable Future for all in Europe\" Ref. Project: 2023-1-RO01- KA220-HED-000154433", "./res/m6x11plus.ttf", 20, sf::Color::White, sf::Vector2f(800, 850), 0, sf::Vector2f(1,1));


	//addEntity(bg);
	addEntity(text);
	addEntity(playBtn);
	addEntity(quitBtn);
	addEntity(proj);


}

void MainMenu::cleanUp()
{
	Scene::cleanUp();
}

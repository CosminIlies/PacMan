#include "MainMenu.h"

void MainMenu::init()
{
	Scene::init();

	//Image* bg = new Image(new Sprite("./res/placeholderMainMenu.png"), "bg", sf::Vector2f(0, 0), 0, sf::Vector2f(10, 10));
	Text* text = new Text("PacMan",
				"./res/BoogieNightsShadowNF.ttf",
				128,
				sf::Color::White  ,
				sf::Vector2f(800, 150),
				0, sf::Vector2f(2, 2));	
	
	Button* playBtn = new Button("Play",
		[]() { SceneManagerInstance->nextScene(); return true; },
		new Sprite("./res/buttonBg.png"),
		sf::Vector2f(800,450),
		0, 
		sf::Vector2f(15, 15));

	Button* quitBtn = new Button("Quit",
		[]() {  ApplicationInstance->stop();  return true;  },
		new Sprite("./res/buttonBg.png"),
		sf::Vector2f(800, 650),
		0,
		sf::Vector2f(15, 15));

	Text* proj = new Text("EU Programme Erasmus+\n Project title : \"Gender, Digitalization, Green: Ensuring a Sustainable Future for all in Europe\"\nProject No : 2023 - 1 - RO01 - KA220 - HED - 000154433\nStudents :\nIlies Eduard Cosmin, eduard_cosmin.ilies@stud.fiir.upb.ro\nGeorgescu Gabriel, gabriel.georgescu04@stud.fiir.upb.ro\nChelu Fabian Catalin, fabian.chelu@stud.fiir.upb.ro\nDaescu Cristian - Narcis, cristian.daescu@stud.fiir.upb.ro\nTeachers : Prof M.Caramihai& D.Chis", "./res/m6x11plus.ttf", 16, sf::Color::White, sf::Vector2f(800, 800), 0, sf::Vector2f(1,1));


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

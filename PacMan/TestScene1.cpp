#include "TestScene1.h"



void TestScene1::init()
{
	Scene::init();
	WorldGrid* wg = new WorldGrid("./res/map.txt");
	Player* player = new Player(wg, _camera, "Player", new AnimatedSprite("./res/pacman.png", 3, 2, 1000.0f), 0.25f, sf::Vector2f(16 * 5, 16 * 5), sf::Vector2f(5, 5));

	Enemy* enemy = new Enemy(new AstarAI(wg), &player->position, "Ghost1", new TileSprite("./res/ghosts.png", 1, 0, 4, 1), 0.1f, sf::Vector2f(0,0), sf::Vector2f(5, 5));
	enemy->position = sf::Vector2f(16 * 5 * wg->enemies[0].x, 16 * 5 * wg->enemies[0].y);
	
	enemy->ai->updatePath(sf::Vector2i(enemy->position.x / 5.0 / 16.0 + 0.5, enemy->position.y / 5.0 / 16.0 + 0.5), sf::Vector2i(1, 1));
	

	Enemy* enemy2 = new Enemy(new AstarAI(wg), &player->position, "Ghost1", new TileSprite("./res/ghosts.png", 0, 0, 4, 1), 0.1f, sf::Vector2f(0, 0), sf::Vector2f(5, 5));
	enemy2->position = sf::Vector2f(16 * 5 * wg->enemies[1].x, 16 * 5 * wg->enemies[1].y);

	enemy2->ai->updatePath(sf::Vector2i(enemy2->position.x / 5.0 / 16.0 + 0.5, enemy2->position.y / 5.0 / 16.0 + 0.5), sf::Vector2i(1, 1));


	Fruit* apple = new Fruit(wg, player, 0, "Apple", new TileSprite("./res/fruits.png", 0, 0, 4, 1), sf::Vector2f(5,5));
	Fruit* orange = new Fruit(wg, player, 1, "Orange", new TileSprite("./res/fruits.png", 1, 0, 4, 1), sf::Vector2f(5, 5));
	Fruit* lemon = new Fruit(wg, player, 2, "Lemon", new TileSprite("./res/fruits.png", 2, 0, 4, 1), sf::Vector2f(5, 5));
	Fruit* melon = new Fruit(wg, player, 3, "Melon", new TileSprite("./res/fruits.png", 3, 0, 4, 1), sf::Vector2f(5, 5));

	//Button* butt = new Button("Button", []() {return false; }, new Sprite("./res/wallTest1.png"), sf::Vector2f(800, 450), 0, sf::Vector2f(56, 5));
	QuizGUI* quiz = new QuizGUI(new Sprite("./res/wallTest1.png"), sf::Vector2f(800, 0), 0, sf::Vector2f(100, 25));

	addEntity(wg);
	addEntity(enemy);
	addEntity(enemy2);
	addEntity(player);

	addEntity(apple);
	addEntity(orange);
	addEntity(lemon);
	addEntity(melon);

	addEntity(quiz);
	QuizManagerInstance->setGUI(quiz);
	QuizManagerInstance->chooseRandomQuestion();
}

void TestScene1::cleanUp()
{
	Scene::cleanUp();
}

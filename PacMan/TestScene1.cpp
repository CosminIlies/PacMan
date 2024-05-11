#include "TestScene1.h"

#include "AnimatedSprite.h"
#include "AstarAI.h"
#include "Enemy.h"
#include "Player.h"

void TestScene1::init()
{
	WorldGrid* wg = new WorldGrid("./res/map.txt");
	Player* player = new Player(wg, "Player", new AnimatedSprite("./res/pacman.png", 3, 2, 1000.0f), 0.25f, sf::Vector2f(16 * 5, 16 * 5), sf::Vector2f(5, 5));

	Enemy* enemy = new Enemy(new AstarAI(wg), &player->position, "Ghost1", new TileSprite("./res/ghosts.png", 1, 0, 4, 1), 0.1f, sf::Vector2f(0,0), sf::Vector2f(5, 5));
	enemy->position = sf::Vector2f(16 * 5 * wg->enemies[0].x, 16 * 5 * wg->enemies[0].y);
	
	enemy->ai->updatePath(sf::Vector2i(enemy->position.x / 5.0 / 16.0 + 0.5, enemy->position.y / 5.0 / 16.0 + 0.5), sf::Vector2i(1, 1));
	

	Enemy* enemy2 = new Enemy(new AstarAI(wg), &player->position, "Ghost1", new TileSprite("./res/ghosts.png", 0, 0, 4, 1), 0.1f, sf::Vector2f(0, 0), sf::Vector2f(5, 5));
	enemy2->position = sf::Vector2f(16 * 5 * wg->enemies[1].x, 16 * 5 * wg->enemies[1].y);

	enemy2->ai->updatePath(sf::Vector2i(enemy2->position.x / 5.0 / 16.0 + 0.5, enemy2->position.y / 5.0 / 16.0 + 0.5), sf::Vector2i(1, 1));

	addEntity(wg);
	addEntity(enemy);
	addEntity(enemy2);
	addEntity(player);


}

void TestScene1::cleanUp()
{
	for (int i = 0; i < _entities.size(); i++) { 
		delete _entities[i];
	}
	_entities.clear();
}

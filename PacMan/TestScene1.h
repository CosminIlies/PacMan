#pragma once
#include <SFML/Audio.hpp>

#include"Scene.h"
#include "Sprite.h"
#include"WorldGrid.h"
#include "Fruit.h"
#include "AnimatedSprite.h"
#include "AstarAI.h"
#include "Enemy.h"
#include "Player.h"
#include "QuizManager.h"
#include "QuizGUI.h"

class TestScene1 : public Scene
{
public:
	TestScene1(sf::RenderWindow *window) : Scene(window) { }
	void init();
	void cleanUp();

private:
	sf::Music* music;
};


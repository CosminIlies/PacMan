#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Sprite.h"


class Entity
{
public:
	std::string name;
	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;
	Sprite* sprite;

	//Entity(Sprite* sprite, const char* name);
	Entity(Sprite* sprite, const char* name, sf::Vector2f position = sf::Vector2f(0, 0), float rot = 0, sf::Vector2f scale = sf::Vector2f(1,1));
	Entity(Entity& entity);

	~Entity();

	virtual bool update(float deltaTime);
	virtual void draw(sf::RenderWindow *window);

private:



};


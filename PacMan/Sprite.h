#pragma once
#include <SFML/Graphics.hpp>
#include "LoggingSystem.h"

class Sprite
{
public:
	int sizeX, sizeY;
	sf::Sprite sprite;

	Sprite(const char* textureFile);
	Sprite(Sprite& sprite);
	~Sprite();

	virtual void updateSprite(sf::Vector2f pos, float rot, sf::Vector2f scale, float deltaTime);

protected:
	sf::Texture _texture;
};

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "LoggingSystem.h"
class Entity
{
public:
	std::string name;
	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;


	Entity(const char* texturePath, const char* name);
	Entity(const char* texturePath, const char* name, sf::Vector2f position, float rot, sf::Vector2f scale);

	~Entity();

	void update(float deltaTime);
	void draw(sf::RenderWindow *window);

private:

	sf::Sprite _sprite;
	sf::Texture _texture;

	inline void updateTransformations() {
		_sprite.setPosition(position);
		_sprite.setRotation(rotation);
		_sprite.setScale(scale);
	}

};


#pragma once

#include<SFML/Graphics.hpp>


class Camera
{
public:
	Camera(sf::RenderWindow *window);
	~Camera();
	void update();

	sf::View view;
	sf::Vector2f position;
	float rotation;
	sf::Vector2f size;

};


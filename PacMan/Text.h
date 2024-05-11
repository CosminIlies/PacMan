#pragma once
#include "Entity.h"
class Text :
    public Entity
{
public:

	Text(const char* text, const char* fontfile, float fontSize, sf::Color color, sf::Vector2f position = sf::Vector2f(0, 0), float rot = 0, sf::Vector2f scale = sf::Vector2f(1, 1));
	~Text();

	bool update(float deltaTime);
	void draw(sf::RenderWindow* window);

private:
    const char* text;
	sf::Text buttonText;
	sf::Font font;

};


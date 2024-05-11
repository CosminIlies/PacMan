#include "Text.h"

Text::Text(const char* text, const char* fontfile, float fontSize, sf::Color color, sf::Vector2f position, float rot, sf::Vector2f scale)
	:Entity(nullptr, text, position, rot, scale)
{
	this->text = text;
	//BoogieNightsShadowNF
	if (font.loadFromFile(fontfile))
	{
		this->buttonText.setFont(font);
		this->buttonText.setString(text);
		this->buttonText.setCharacterSize(fontSize);
		this->buttonText.setFillColor(color);
		this->buttonText.setPosition(position.x, position.y);
		this->buttonText.setOrigin(buttonText.getGlobalBounds().width / 2, buttonText.getGlobalBounds().height / 2);
	}
	else
	{
		std::cout << "Error loading font" << std::endl;
	}
}

Text::~Text()
{
}

bool Text::update(float deltaTime)
{
	return false;
}

void Text::draw(sf::RenderWindow* window)
{
	Entity::draw(window);
	window->draw(buttonText);
}

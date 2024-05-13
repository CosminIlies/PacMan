#include "Button.h"

Button::Button(const char* text, std::function<bool()> onPress, Sprite* sprite, sf::Vector2f position, float rot, sf::Vector2f scale)
    :Entity(sprite, text, position, rot, scale)
{

    this->onPress = onPress;
    this->text = text;


    if (font.loadFromFile("res/square-deal.ttf"))
    {
		this->buttonText.setFont(font);
		this->buttonText.setString(text);
		this->buttonText.setCharacterSize(56);
		this->buttonText.setFillColor(sf::Color::White);
		this->buttonText.setPosition(position.x, position.y);
        this->buttonText.setOrigin(buttonText.getGlobalBounds().width / 2, buttonText.getGlobalBounds().height / 2);
	}
    else
    {
		std::cout << "Error loading font" << std::endl;
	}   

}

Button::~Button()
{
}

bool Button::update(float deltaTime)
{

    Entity::update(deltaTime);


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        hold = true;

    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && hold)
    {
        hold = false;
        sf::Vector2i mousePos = sf::Mouse::getPosition(*this->windowPtr);
        if (sprite->sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            return onPress();
        }
    }


    return false;
}

void Button::draw(sf::RenderWindow* window)
{
    this->windowPtr = window;
  
    Entity::draw(window);
    window->draw(buttonText);
    
}

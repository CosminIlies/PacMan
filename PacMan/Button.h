#pragma once

#include <functional>
#include "Entity.h"



class Button :
    public Entity
{

public:

    Button(const char* text, std::function<bool()> onPress, Sprite* sprite, sf::Vector2f position = sf::Vector2f(0, 0), float rot = 0, sf::Vector2f scale = sf::Vector2f(1, 1));
    ~Button();

    bool update(float deltaTime);
    void draw(sf::RenderWindow* window);


private:
    bool hold = false;
    sf::RenderWindow* windowPtr;
    const char* text;
    sf::Text buttonText;
    sf::Font font;
    std::function<bool()> onPress;
};


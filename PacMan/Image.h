#pragma once
#include "Entity.h"

class Image :
    public Entity
{

public:

    Image(Sprite* sprite, const char* name, sf::Vector2f position = sf::Vector2f(0, 0), float rot = 0, sf::Vector2f scale = sf::Vector2f(1, 1));
    ~Image();

    bool update(float deltaTime);
    void draw(sf::RenderWindow* window);


private:
};


#include "Image.h"

Image::Image(Sprite* sprite, const char* name, sf::Vector2f position, float rot, sf::Vector2f scale)
    :Entity(sprite, name, position, rot, scale)
{
}


Image::~Image()
{
}

bool Image::update(float deltaTime)
{
    return  Entity::update(deltaTime);
}

void Image::draw(sf::RenderWindow* window)
{
    Entity::draw(window);
}

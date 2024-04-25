#include "Sprite.h"

Sprite::Sprite(const char* textureFile)
{
	if (!_texture.loadFromFile(textureFile))
	{
		LOG_ERROR("Texture not loaded");
	}
	else {
		LOG_INFO("Texture loaded");
	}

	sprite.setTexture(_texture);
	sizeX = _texture.getSize().x;
	sizeY = _texture.getSize().y;
	sprite.setOrigin(sizeX / 2, sizeY / 2);
}

Sprite::Sprite(Sprite& sprite)
{
	this->sprite = sprite.sprite;
	this->_texture = sprite._texture;
	sizeX = _texture.getSize().x;
	sizeY = _texture.getSize().y;
}

Sprite::~Sprite()
{
}

void Sprite::updateSprite(sf::Vector2f pos, float rot, sf::Vector2f scale, float deltaTime)
{
	sprite.setPosition(pos);
	sprite.setRotation(rot);
	sprite.setScale(scale);
}

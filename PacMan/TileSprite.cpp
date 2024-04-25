#include "TileSprite.h"

TileSprite::TileSprite(const char* textureFile, int x, int y, int countX, int countY) : Sprite(textureFile), _x(x), _y(y), _countX(countX), _countY(countY)
{

	sizeX = _texture.getSize().x / _countX;
	sizeY = _texture.getSize().y / _countY;

	sprite.setTextureRect(sf::IntRect(x * sizeX, y * sizeY, sizeX, sizeY));
	sprite.setOrigin(sizeX / 2, sizeY / 2);
}

TileSprite::~TileSprite()
{

}

void TileSprite::setTile(int x, int y)
{
	_x = x;
	_y = y;

	sizeX = _texture.getSize().x / _countX;
	sizeY = _texture.getSize().y / _countY;

	sprite.setTextureRect(sf::IntRect(x * sizeX, y * sizeY, sizeX, sizeY));
	sprite.setOrigin(sizeX / 2, sizeY / 2);
}

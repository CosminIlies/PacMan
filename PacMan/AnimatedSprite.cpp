#include "AnimatedSprite.h"



AnimatedSprite::AnimatedSprite(const char* textureFile, int x, int y, int countX, int countY, float speed = 1.0f) :
	TileSprite(textureFile, x, y, countX, countY),
	speed(speed)
{
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::updateSprite(sf::Vector2f pos, float rot, sf::Vector2f scale, float deltaTime)
{
	Sprite::updateSprite(pos, rot, scale, deltaTime);

	timePassed += deltaTime;

	if(timePassed >= speed)
	{
		timePassed = 0;
		
		_x++;

		if(_x >= _countX)
		{
			_x = 0;
			_y++;
			if(_y >= _countY)
			{
				_y = 0;
			}
		}

		
		setTile(_x, _y);
	}
}

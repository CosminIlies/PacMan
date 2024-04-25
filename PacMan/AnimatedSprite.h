#pragma once
#include "TileSprite.h"


class AnimatedSprite : public TileSprite
{
public:

	AnimatedSprite(const char* textureFile, int x, int y, int countX, int countY, float speed);
	~AnimatedSprite();

	void updateSprite(sf::Vector2f pos, float rot, sf::Vector2f scale, float deltaTime);

protected: 
	float speed;
	
private:
	float timePassed = 0.0f;
};

#pragma once
#include "TileSprite.h"


class AnimatedSprite : public TileSprite
{
public:

	AnimatedSprite(const char* textureFile, int countX, int countY, float speed = 1.0f, int x = 0, int y = 0);
	~AnimatedSprite();

	void updateSprite(sf::Vector2f pos, float rot, sf::Vector2f scale, float deltaTime);

protected: 
	float speed;
	
private:
	float timePassed = 0.0f;
};

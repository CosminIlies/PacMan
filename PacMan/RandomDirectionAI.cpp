#include "RandomDirectionAI.h"

void RandomDirectionAI::updatePath()
{
    int random = rand() % 4;
    if (random == 0) {
		_dir = sf::Vector2f(1, 0);
	}
    else if (random == 1) {
		_dir = sf::Vector2f(-1, 0);
	}
    else if (random == 2) {
		_dir = sf::Vector2f(0, 1);
	}
	else if (random == 3) {
		_dir = sf::Vector2f(0, -1);
	}
}

sf::Vector2f RandomDirectionAI::getDirection()
{
    return _dir;
}

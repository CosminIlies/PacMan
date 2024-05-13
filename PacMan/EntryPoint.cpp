#include <SFML/Graphics.hpp>
#include "Application.h"

int main()
{
    srand(time(0));
    //Application app(1600,900, "PacMan");
    ApplicationInstance->init(1600, 900, "Pacman");

    ApplicationInstance->start();

   
    return 0;
}
#include <SFML/Graphics.hpp>
#include "Application.h"

int main()
{

    //Application app(1600,900, "PacMan");
    ApplicationInstance->init(1600, 900, "Pacman");

    ApplicationInstance->start();

   
    return 0;
}
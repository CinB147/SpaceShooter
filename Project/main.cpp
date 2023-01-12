#include <SFML/Graphics.hpp>
#include "game.h"

/**
 * \brief Main.cpp where game class is called.
 * 
 * \return 
 */
int main()
{

    space::Game game(1920, 1080);

    game.play();


    return 0;
}
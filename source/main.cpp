#include <SFML/Graphics.hpp>
#include "core/game.hpp"

#include <iostream>

int main()
{
    try {
        Game game;
        game.run();

    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include "core/application.hpp"

#include <iostream>

int main()
{
    try {
        Application game;
        game.run();

    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }

    return 0;
}
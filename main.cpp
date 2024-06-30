#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Game.h"
#include <time.h>
int main()
{
    //srand(time(static_cast<unsigned>(0)));
    srand(static_cast<unsigned>(time(0)));
    
    Game game;
    
    while (game.running()) {
        game.update();
        game.draw();
    }
    return 0;
}

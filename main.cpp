#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Game.h"
#include "main.h"
int main()
{
    Game game;
    
    while (game.running()) {
        game.update();
        game.draw();
    }
    return 0;
}

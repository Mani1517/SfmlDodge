#include "headers/Game.h"

int main()
{
    Game game;

    while(game.running())
    {
        game.render();
        game.update();
    }
    return 0;
}
#include "game.h"

using namespace baseEngine;

int main(void)
{
    int width = 640;
    int height = 480;

    const char* windowName = "Pinguano-Engine";

    Game* game;

    game = new Game(width, height, windowName);


    game->gameLoop();

    delete game;
    return 0;
}
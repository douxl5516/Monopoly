#include "game.h"

int main()
{
    Game* game = Game::getGame();

    game->init();
    game->run();
    game->term();

    Game::releaseGame();

    return 0;
}

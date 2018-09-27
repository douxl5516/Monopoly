#include <iostream>

using namespace std;
#include "Game.h"

int main()
{
	Game* game = Game::getInstance();
	game->init();
	game->run();
	game->term();
	delete game;
	return 0;
}

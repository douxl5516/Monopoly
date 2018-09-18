#include <iostream>

using namespace std;
#include "game.h"

int main()
{
	Game* game = new Game;
	game->init();
	game->run();
	game->term();
	delete game;
	return 0;
}

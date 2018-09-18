#include "game.h"
#include "menu.h"
#include "MenuMgr.h"

Game* Game::instance = nullptr;

void Game::init()
{
	setCurMenu(MenuID::MAIN_MENU);
}
void Game::run()
{
	while (curMenu->process()) {
	}
}
void Game::term()
{
	MenuMgr::release();
}
void Game::setCurMenu(int menuID)
{
	curMenu = MenuMgr::getInstance()->getMenuInstance(menuID);
}

Game * Game::getInstance()
{
	if (instance == nullptr)
		instance = new Game;
	return instance;
}
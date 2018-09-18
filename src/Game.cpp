#include "game.h"
#include "menu.h"
#include "MenuMgr.h"

void Game::init()
{
	setCurMenu(MenuID::MAIN_MENU);
}
void Game::run()
{
	while (curMenu->process(this)) {
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

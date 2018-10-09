#include "MenuMgr.h"
#include "Global.h"

MenuMgr* MenuMgr::instance = nullptr;
Menu* MenuMgr::curMenu = nullptr;

MenuMgr::~MenuMgr()
{
	release();
	for (int i = 0; i < MenuID::MENU_COUNT; i++) {
		delete menus[i];
		menus[i] = nullptr;
	}
}

MenuMgr* MenuMgr::getInstance() {
	if (instance == nullptr)
		instance = new MenuMgr;
	return instance;
}

Menu * MenuMgr::getCurMenu()
{
	return curMenu;
}

void MenuMgr::release()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

void MenuMgr::setMenuFactory(AbsMenuFactory * pfac)
{
	delete fac;
	fac = pfac;
}

Menu * MenuMgr::getMenu(int menuID)
{
	if (menuID < MenuID::MAIN_MENU || menuID >= MenuID::MENU_COUNT) {
		menuID = MenuID::MAIN_MENU;
	}
	if (menus[menuID] == nullptr) {
		menus[menuID] = fac->createMenu(menuID);
	}
	return menus[menuID];
}

void MenuMgr::setCurMenu(int menuID)
{
	curMenu = getMenu(menuID);
}

#include "MenuMgr.h"

MenuMgr* MenuMgr::instance = nullptr;

MenuMgr::~MenuMgr()
{
	release();
}

MenuMgr* MenuMgr::getInstance() {
	if (instance == nullptr)
		instance = new MenuMgr;
	return instance;
}

Menu * MenuMgr::getMenuInstance(int menuID)
{
	if (menuID <= MenuID::MENU_COUNT&&menuID >= 0)
		return menus[menuID];
	return nullptr;
}

void MenuMgr::release()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}

	for (int i = 0; i < MenuID::MENU_COUNT; i++) {
		if (menus[i] == nullptr)
			continue;
		delete menus[i];
		menus[i] = nullptr;
	}

	if (fac != nullptr) {
		delete fac;
		fac = nullptr;
	}
}

AbstractMenuFactory* MenuMgr::fac = new MenuFactory();

Menu* MenuMgr::menus[] = {
	fac->create(MenuID::MAIN_MENU),
	fac->create(MenuID::PLAYERS_MENU),
	fac->create(MenuID::LOAD_MENU),
	fac->create(MenuID::SAVE_MENU),
	fac->create(MenuID::OPTION_MENU),
	fac->create(MenuID::VOLUME_MENU),
	fac->create(MenuID::RESOLUTION_MENU),
};
#include "MenuMgr.h"

MenuMgr* MenuMgr::instance = nullptr;

MenuMgr::~MenuMgr()
{
	delete instance;
	for (int i = 0; i < MenuID::MENU_COUNT; i++) {
		delete menus[i];
	}
}

MenuMgr* MenuMgr::getInstance() {
	if (instance == nullptr)
		instance = new MenuMgr;
	return instance;
}

Menu * MenuMgr::getMenuInstance(int menuID)
{
	if(menuID<=MenuID::MENU_COUNT&&menuID>=0)
		return menus[menuID];
	return nullptr;
}

Menu* MenuMgr::menus[] = {
	new MainMenu,
	new PlayersMenu,
	new LoadMenu,
	new SaveMenu,
	new OptionMenu,
	new VolumeMenu,
	new ResolutionMenu
};
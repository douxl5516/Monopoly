#include "MenuFactory.h"
#include "Menu.h"
#include "Global.h"

MenuFactory::MenuFactory()
{
	//ctor
}

MenuFactory::~MenuFactory()
{
	//dtor
}
Menu* MenuFactory::createMenu(int menuID)
{
	if (menuID == MenuID::MAIN_MENU) {
		return new MusicMenuDecorator(new MainMenu);
	}
	else if (menuID == MenuID::PLAYERS_MENU) {
		return new PlayersMenu;
	}
	else if (menuID == MenuID::LOAD_MENU) {
		return new LoadRecordMenu;
	}
	else if (menuID == MenuID::SAVE_MENU) {
		return new SaveRecordMenu;
	}
	else if (menuID == MenuID::OPTION_MENU) {
		return new OptionMenu;
	}
	else if (menuID == MenuID::VOLUME_MENU) {
		return new VolumeMenu;
	}
	else if (menuID == MenuID::RESOLUTION_MENU) {
		return new ResolutionMenu;
	}
	else if (menuID==MenuID::PLAY_MENU) {
		return new PlayMenu;
	}
	else {
		return new MainMenu;
	}
}
///-----------------------------------------

MyMenuFactory::MyMenuFactory()
{
	//ctor
}

MyMenuFactory::~MyMenuFactory()
{
	//dtor
}
Menu* MyMenuFactory::createMenu(int menuID)
{
	if (menuID == MenuID::MAIN_MENU) {
		return new MainMenu;
	}
	else if (menuID == MenuID::PLAYERS_MENU) {
		return new PlayersMenu;
	}
	else if (menuID == MenuID::LOAD_MENU) {
		return new LoadRecordMenu;
	}
	else if (menuID == MenuID::SAVE_MENU) {
		return new SaveRecordMenu;
	}
	else if (menuID == MenuID::OPTION_MENU) {
		return new OptionMenu;
	}
	else if (menuID == MenuID::VOLUME_MENU) {
		return new VolumeMenu;
	}
	else if (menuID == MenuID::RESOLUTION_MENU) {
		return new ResolutionMenu;
	}
	else {
		return new MainMenu;
	}
}

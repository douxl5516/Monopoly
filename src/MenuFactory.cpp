#include "MenuFactory.h"
#include "Menu.h"

Menu * MenuFactory::create(int id)
{
	switch (id) {
	case MenuID::MAIN_MENU:return createMainMenu();
	case MenuID::PLAYERS_MENU:return createPlayersMenu();
	case MenuID::LOAD_MENU:return createLoadMenu();
	case MenuID::SAVE_MENU:return createSaveMenu();
	case MenuID::OPTION_MENU:return createOptionMenu();
	case MenuID::VOLUME_MENU:return createVolumeMenu();
	case MenuID::RESOLUTION_MENU:return createResolutionMenu();
	default:return nullptr;
	}
}

Menu * MenuFactory::createMainMenu()
{
	return new MainMenu();
}

Menu * MenuFactory::createPlayersMenu()
{
	return new PlayersMenu();
}

Menu * MenuFactory::createLoadMenu()
{
	return new LoadMenu();
}

Menu * MenuFactory::createSaveMenu()
{
	return new SaveMenu();
}

Menu * MenuFactory::createOptionMenu()
{
	return new OptionMenu();
}

Menu * MenuFactory::createVolumeMenu()
{
	return new VolumeMenu();
}

Menu * MenuFactory::createResolutionMenu()
{
	return new ResolutionMenu();
}

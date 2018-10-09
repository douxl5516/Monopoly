#include <iostream>
using namespace std;

#include "Menu.h"
#include "Game.h"
#include "Global.h"

bool Menu::process()
{
	show();
	int choice = getChoice();
	return doChoice(choice);
}
int  Menu::getChoice() const
{
	int choice = 0;
	cin >> choice;
	return choice;
}
///-----------------------------------------
void MainMenu::show() const
{
	cout << "\n\t" << "主菜单" << endl;
	cout << "1: New" << endl;
	cout << "2: Load" << endl;
	cout << "3: Save" << endl;
	cout << "4: Option" << endl;
	cout << "5: Play..." << endl;
	cout << "0: Exit" << endl;
	cout << " Your selected:";
}

bool MainMenu::doChoice(int choice)
{
	switch (choice) {
	case 1:
		Game::getInstance()->setCurMenu(MenuID::PLAYERS_MENU);
		break;
	case 2:
		Game::getInstance()->setCurMenu(MenuID::LOAD_MENU);
		break;
	case 3:
		Game::getInstance()->setCurMenu(MenuID::SAVE_MENU);
		break;
	case 4:
		Game::getInstance()->setCurMenu(MenuID::OPTION_MENU);
		break;
	case 5:
		Game::getInstance()->play();
		break;
	default:
		return false;
	}
	return true;
}

///------玩家人数菜单--------------------------------
void PlayersMenu::show() const
{
	cout << "\n\tSet number of players(2-8):" << endl;
	cout << "2. 2" << endl;
	cout << "3. 3" << endl;
	cout << "4. 4" << endl;
	cout << "5. 5" << endl;
	cout << "6. 6" << endl;
	cout << "7. 7" << endl;
	cout << "8. 8" << endl;
	cout << "0. Back" << endl;
	cout << " Your selected:";
}
bool PlayersMenu::doChoice(int choice)
{
	if (choice >= 2 && choice <= 8)
		Game::getInstance()->setPlayers(choice);
	Game::getInstance()->setCurMenu(MenuID::MAIN_MENU);
	return true;
}
///-------载入菜单----------------------------------
void LoadMenu::show() const
{
	cout << "\n\tSelect the Record to be loaded(1-5):" << endl;
	cout << "1. 1" << endl;
	cout << "2. 2" << endl;
	cout << "3. 3" << endl;
	cout << "4. 4" << endl;
	cout << "5. 5" << endl;
	cout << "0. Back" << endl;
	cout << " Your selected:";
}
bool LoadMenu::doChoice(int choice)
{
	if (choice >= 1 && choice <= 5)
		Game::getInstance()->loadFrom(choice);
	Game::getInstance()->setCurMenu(MenuID::MAIN_MENU);
	return true;
}
///-------保存菜单----------------------------------
void SaveMenu::show() const
{
	cout << "\n\tSelect the Record to save(1-5):" << endl;
	cout << "1. 1" << endl;
	cout << "2. 2" << endl;
	cout << "3. 3" << endl;
	cout << "4. 4" << endl;
	cout << "5. 5" << endl;
	cout << "0. Back" << endl;
	cout << " Your selected:";
}
bool SaveMenu::doChoice(int choice)
{
	if (choice >= 1 && choice <= 5)
		Game::getInstance()->saveTo(choice);
	Game::getInstance()->setCurMenu(MenuID::MAIN_MENU);
	return true;
}

///-------选项菜单----------------------------------
void OptionMenu::show() const
{
	cout << "\n\tSet options :" << endl;
	cout << "1.Set the value of Volume(0-100)" << endl;
	cout << "2.Set the resolution" << endl;
	cout << "0. Back" << endl;
	cout << " Your selected:";
}
bool OptionMenu::doChoice(int choice)
{
	switch (choice) {
	case 1:
		Game::getInstance()->setCurMenu(MenuID::VOLUME_MENU);
		break;
	case 2:
		Game::getInstance()->setCurMenu(MenuID::RESOLUTION_MENU);
		break;
	default:
		Game::getInstance()->setCurMenu(MenuID::MAIN_MENU);
		break;
	}
	return true;
}
///-------音量选项菜单----------------------------------
void VolumeMenu::show() const
{
	cout << "\n\tSet Volume" << endl;
	cout << "input value(0-100)：";
}
bool VolumeMenu::doChoice(int choice)
{
	if (choice >= 0 && choice <= 100)
		Game::getInstance()->setVolume(choice);
	Game::getInstance()->setCurMenu(MenuID::OPTION_MENU);
	return true;
}
///-------分辨率选项菜单----------------------------------
void ResolutionMenu::show() const
{
	cout << "\n\tSet resolution" << endl;
	cout << "1. 640X320" << endl;
	cout << "2. 800X600" << endl;
	cout << "3. 1024X768" << endl;
	cout << " Your selected:";
}
bool ResolutionMenu::doChoice(int choice)
{
	if (choice >= 1 && choice <= 3)
		Game::getInstance()->setResolution(choice);
	Game::getInstance()->setCurMenu(MenuID::OPTION_MENU);
	return true;
}


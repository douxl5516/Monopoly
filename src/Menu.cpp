#include <iostream>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

#include "Menu.h"
#include "Game.h"
#include "Global.h"
#include "BlockMgr.h"
#include "Block.h"
#include "MapMgr.h"
#include "OutDevice.h"
#include "Map.h"

bool Menu::process()
{
	OutDevice* p=new StreamDeviceTabDecorator(new StreamDevice);
	show(p);
	int choice = getChoice();
	delete p;
	return doChoice(choice);
}
int  Menu::getChoice() const
{
	int choice = 0;
	cin >> choice;
	return choice;
}
///-----------------------------------------
void MainMenu::show(OutDevice* out) const
{
	out->drawLn("\n\t主菜单");
	out->drawLn( "1: New" );
	out->drawLn( "2: Load" );
	out->drawLn( "3: Option" );
	out->drawLn( "4: Play..." );
	out->drawLn( "5: Change To EF" );
	out->drawLn( "0: Exit" );
	out->draw( " Your selected:");
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
		Game::getInstance()->setCurMenu(MenuID::OPTION_MENU);
		break;
	case 4:
		Game::getInstance()->play();
		break;
	case 5:
		BlockMgr::getInstance()->setPrototype(BlockID::MONEY_BLOCK, new EBlock);
		BlockMgr::getInstance()->setPrototype(BlockID::BAR_BLOCK, new FBlock);
		///Game::getGame()->createMap();
		MapMgr::getInstance()->createMap();
		break;
	default:
		return false;
	}
	return true;
}

///------玩家人数菜单--------------------------------
void PlayersMenu::show(OutDevice* out) const
{
	out->drawLn( "\n\tSet number of players(2-8):" );
	out->drawLn( "2. 2" );
	out->drawLn( "3. 3" );
	out->drawLn( "4. 4" );
	out->drawLn( "5. 5" );
	out->drawLn( "6. 6" );
	out->drawLn( "7. 7" );
	out->drawLn( "8. 8" );
	out->drawLn( "0. Back" );
	out->draw( " Your selected:");
}
bool PlayersMenu::doChoice(int choice)
{
	if (choice >= 2 && choice <= 8)
		Game::getInstance()->setPlayers(choice);
	Game::getInstance()->setCurMenu(MenuID::MAIN_MENU);
	return true;
}
///-------载入菜单----------------------------------
void LoadRecordMenu::show(OutDevice* out) const
{
	out->drawLn( "\n\tSelect the Record to be loaded(1-5):" );
	out->drawLn( "1. 1" );
	out->drawLn( "2. 2" );
	out->drawLn( "3. 3" );
	out->drawLn( "4. 4" );
	out->drawLn( "5. 5" );
	out->drawLn( "0. Back" );
	out->draw( " Your selected:");
}
bool LoadRecordMenu::doChoice(int choice)
{
	if (choice >= 1 && choice <= 5)
		Game::getInstance()->loadFrom(choice);
	Game::getInstance()->setCurMenu(MenuID::MAIN_MENU);
	Game::getInstance()->play();
	return true;
}
///-------保存菜单----------------------------------
void SaveRecordMenu::show(OutDevice* out) const
{
	out->drawLn( "\n\tSelect the Record to save(1-5):" );
	out->drawLn( "1. 1" );
	out->drawLn( "2. 2" );
	out->drawLn( "3. 3" );
	out->drawLn( "4. 4" );
	out->drawLn( "5. 5" );
	out->drawLn( "0. Back" );
	out->draw( " Your selected:");
}
bool SaveRecordMenu::doChoice(int choice)
{
	if (choice >= 1 && choice <= 5)
		Game::getInstance()->saveTo(choice);
	Game::getInstance()->setCurMenu(MenuID::MAIN_MENU);
	return true;
}

///-------选项菜单----------------------------------
void OptionMenu::show(OutDevice* out) const
{
	out->drawLn( "\n\tSet options :" );
	out->drawLn( "1.Set the value of Volume(0-100)" );
	out->drawLn( "2.Set the resolution" );
	out->drawLn( "0. Back" );
	out->draw( " Your selected:");
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
void VolumeMenu::show(OutDevice* out) const
{
	out->drawLn( "\n\tSet Volume" );
	out->draw( "input value(0-100)：");
}
bool VolumeMenu::doChoice(int choice)
{
	if (choice >= 0 && choice <= 100)
		Game::getInstance()->setVolume(choice);
	Game::getInstance()->setCurMenu(MenuID::OPTION_MENU);
	return true;
}
///-------分辨率选项菜单----------------------------------
void ResolutionMenu::show(OutDevice* out) const
{
	out->drawLn( "\n\tSet resolution" );
	out->drawLn( "1. 640X320" );
	out->drawLn( "2. 800X600" );
	out->drawLn( "3. 1024X768" );
	out->draw( " Your selected:" );
}
bool ResolutionMenu::doChoice(int choice)
{
	if (choice >= 1 && choice <= 3)
		Game::getInstance()->setResolution(choice);
	Game::getInstance()->setCurMenu(MenuID::OPTION_MENU);
	return true;
}
///-------游戏菜单----------------------------------------
void PlayMenu::show(OutDevice * out) const
{
	out->drawLn("\n\tPlayMenu");
	out->drawLn("1. GO...");
	out->drawLn("2. Load");
	out->drawLn("3. Save");
	out->drawLn("4. Back To MainMenu");
	out->draw(" Your selected:");
}

bool PlayMenu::doChoice(int choice)
{
	switch (choice) {
	case 1:
		MapMgr::getCurMap()->show();
		return true;
	case 2:
		Game::getInstance()->setCurMenu(MenuID::LOAD_MENU);
		break;
	case 3:
		Game::getInstance()->setCurMenu(MenuID::SAVE_MENU);
		break;
	case 4:
		Game::getInstance()->setCurMenu(MenuID::MAIN_MENU);
		break;
	}
	return false;
}


MenuDecorator::~MenuDecorator()
{
	delete menu;
}

MenuDecorator::MenuDecorator(Menu * p):menu(p)
{
}

bool MenuDecorator::process()
{
	return menu->process();
}

void MenuDecorator::show(OutDevice * out) const
{
	menu->show(out);
}

bool MenuDecorator::doChoice(int choice)
{
	return menu->doChoice(choice);
}

MusicMenuDecorator::MusicMenuDecorator(Menu * p):MenuDecorator(p)
{
}

bool MusicMenuDecorator::process()
{
	playMusic();
	bool res= MenuDecorator::process();
	closeMusic();
	return res;
}

void MusicMenuDecorator::playMusic()
{
	PlaySound(TEXT("浮世寻.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void MusicMenuDecorator::closeMusic()
{
	PlaySound(NULL, NULL, SND_FILENAME);
}

HeaderDecorator::HeaderDecorator(Menu * p) :MenuDecorator(p)
{
}

bool HeaderDecorator::process()
{
	drawHeader();
	return MenuDecorator::process();
}

void HeaderDecorator::drawHeader()
{
	cout << "=========================" << endl;
	cout << "=                       =" << endl;
	cout << "=========================" << endl;
}

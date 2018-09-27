#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "Menu.h"
#include "MenuMgr.h"
#include "MapDirector.h"
#include "Map.h"

using namespace std;

Game* Game::instance = nullptr;

void Game::init()
{
	setCurMenu(MenuID::MAIN_MENU);
	players = 2;
	volume = 50;
	resolution = 1;
}
void Game::run()
{
	while (curMenu->process());
}
void Game::term()
{
	MenuMgr::release();
}
void Game::play()
{
	MapDirector* mapDirector = new MapDirectorA();
	curMap = new Map(*mapDirector);
	delete mapDirector;
	curMap->show();
}
void Game::setPlayers(int n)
{
	players = n;
	cout << "Set Players count to " << players << endl;
}
void Game::loadFrom(int n)
{
	cout << "Load Recording from  " << n << endl;
}
void Game::saveTo(int n) {
	cout << "Save Recording to " << n << endl;
}
void Game::setVolume(int n)
{
	volume = n;
	cout << "Set Volume to " << n << endl;
}
void Game::setResolution(int n)
{

	switch (n) {
	case 1:
		cout << "640x320" << endl;
		resolution = 1;
		break;
	case 2:
		cout << "800x600" << endl;
		resolution = 2;
		break;
	case 3:
		cout << "1024x768" << endl;
		resolution = 3;
		break;
	default:
		break;
	}
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

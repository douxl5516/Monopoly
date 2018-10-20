#include <iostream>

#include "Global.h"
#include "Game.h"
#include "Menu.h"
#include "MenuMgr.h"
#include "Map.h"
#include "MapMgr.h"
#include "BlockMgr.h"
#include "Player.h"

using namespace std;

Game* Game::instance = nullptr;

void Game::init()
{
	MenuMgr::getInstance()->setMenuFactory(new MenuFactory);
	MenuMgr::getInstance()->setCurMenu(MenuID::MAIN_MENU);
	MapMgr::getInstance()->createMap();
	players = 3;
	volume = 50;
	resolution = 1;
	playerList.push_back(new HumanPlayer);
	playerList.push_back(new AutoPlayer);
	playerList.push_back(new AutoPlayer);
	playerIdx = 0;
	curPlayer = playerList[playerIdx];
}
void Game::run()
{
	while (MenuMgr::getCurMenu()->process());
}
void Game::term()
{
	MenuMgr::release();
	MapMgr::release();
	BlockMgr::release();
	for (int i = 0; i < playerList.size(); i++) {
		delete playerList[i];
	}
}
void Game::play()
{
	bool running = true;
	while (running) {
		running = curPlayer->play();
		playerIdx = (playerIdx+1) % 3;
		curPlayer = playerList[playerIdx];
	}
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
	MenuMgr::getInstance()->setCurMenu(menuID);
}

Game * Game::getInstance()
{
	if (instance == nullptr)
		instance = new Game;
	return instance;
}

void Game::release()
{
	delete instance;
}

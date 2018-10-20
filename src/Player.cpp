#include "Player.h"
#include "MapMgr.h"
#include "MenuMgr.h"
#include "Map.h"
#include "Game.h"

Player::~Player()
{
}

bool HumanPlayer::play()
{
	Game::getInstance()->setCurMenu(MenuID::PLAY_MENU);
	return MenuMgr::getCurMenu()->process();
}

bool AutoPlayer::play()
{
	MapMgr::getCurMap()->show();
	return true;
}

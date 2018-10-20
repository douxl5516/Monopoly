#include "Player.h"
#include "MapMgr.h"
#include "Map.h"
#include "Game.h"

Player::Player(int playerID):type(playerID)
{
}

int Player::getType()
{
	return type;
}

Player::~Player()
{
}

HumanPlayer::HumanPlayer():Player(PlayerID::HUMAN_PLAYER)
{
}

bool HumanPlayer::play()
{
	Game::getInstance()->setCurMenu(MenuID::PLAY_MENU);
	return false;
}

AutoPlayer::AutoPlayer():Player(PlayerID::AUTO_PLAYER)
{
}

bool AutoPlayer::play()
{
	MapMgr::getCurMap()->show();
	return true;
}

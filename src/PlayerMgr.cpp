#include "PlayerMgr.h"
#include "Player.h"

PlayerMgr* PlayerMgr::instance = nullptr;
Player* PlayerMgr::players[3] = { new HumanPlayer(),new AutoPlayer(),new AutoPlayer() };

PlayerMgr::PlayerMgr()
{
	curPlayerIdx = 0;
	setCurPlayer(players[curPlayerIdx]);
}


PlayerMgr::~PlayerMgr()
{
}

PlayerMgr * PlayerMgr::getInstance()
{
	if (instance == nullptr) {
		instance = new PlayerMgr;
	}
	return instance;
}

void PlayerMgr::release()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

void PlayerMgr::setCurPlayer(Player * player)
{
	curPlayer = player;
}

bool PlayerMgr::Do()
{
	bool flag = curPlayer->play();
	setCurPlayer(players[++curPlayerIdx % 3]);
	if (flag == false) {
		curPlayerIdx = 0;
		curPlayer = players[curPlayerIdx];
	}
	return flag;
}

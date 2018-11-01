///======================================================================
///  Project:   Richer03
/// FileName:	player.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <assert.h>
using namespace std;
#include "player.h"
#include "menumgr.h"
#include "mapmgr.h"
#include "map.h"
#include "block.h"
#include "global.h"
#include "Card.h"
#include "PlayerState.h"


Players& Players::getPlayers()
{
    static Players players;
    return players;
}

Players::Players()
{
	Block* curBlock=MapMgr::getMgr()->getCurMap()->getBlock(0);
    Player* ps[3] = {new HumanPlayer,new AutoPlayer,new TallRichHandsomePlayer};
    ps[0]->setName("HP");
	ps[0]->setPos(make_pair(curBlock->getRow(),curBlock->getCol()));
	ps[0]->setDirection(DirID::DIR_NONE);
	ps[0]->setMoney(100);

    ps[1]->setName("AP");
	ps[1]->setPos(make_pair(curBlock->getRow(), curBlock->getCol()));
	ps[1]->setDirection(DirID::DIR_NONE);
	ps[1]->setMoney(150);

	ps[2]->setName("TRHP");
	ps[2]->setPos(make_pair(curBlock->getRow(), curBlock->getCol()));
	ps[2]->setDirection(DirID::DIR_NONE);
	ps[2]->setMoney(200);

    players.push_back(ps[0]);
	players.push_back(ps[1]);
	players.push_back(ps[2]);
}

Players::~Players()
{
    while(players.size() > 0) {
        Player* player = players.front();
		delete player->getState();
        delete player;
        players.pop_front();
    }
	for (auto item : cppItReleaseList) {
		delete item;
		item = nullptr;
	}
	for (auto item : javaItReleaseList) {
		delete item;
		item = nullptr;
	}
}

void Players::play(bool showed)
{
	CppIterator* it = createCppIterator();
	Player* player=(Player*)it->current();
	curPlayer = player;
    while(player->play(this,showed)) {
		//展示玩家信息
		displayCurInfo();
        showed = true;

		if (player->getMoney() <= 0) {
			player->setDead(true);
			TripBlock::setStrategy(new NervousTripStategy);
			if (!judge());
			else if (judge() == 1) {
				cout << endl << "*****************************" << endl;
				cout << "******Human Player Win!******" << endl;
				cout << "*****************************" << endl << endl;
				MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
				break;
			}
			else if (judge() == 2) {
				cout << endl << "*****************************" << endl;
				cout << "*******Auto Player Win!******" << endl;
				cout << "*****************************" << endl << endl;
				MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
				break;
			}
		}

		it->next();
		if (it->isLast()) {
			it->first();
		}
		player = (Player*)it->current();
		curPlayer = player;
    }
	system("pause");
	system("cls");
}

map<pair<int, int>, int> Players::getPos()
{
	map<pair<int, int>,int> res;//key:position,value:playerID
	
	for (auto s : players) {
		if (dynamic_cast<HumanPlayer*>(s))
			res[s->getPos()]=PlayerID::HUMAN_PLAYER;
		else if (dynamic_cast<AutoPlayer*>(s))
			res[s->getPos()]=PlayerID::AUTO_PLAYER;
	}
	return res;
}

CppIterator * Players::createCppIterator()
{
	CppIterator * it = new PlayersCppIterator(this);
	cppItReleaseList.push_back(it);
	return it;
}

JavaIterator * Players::createJavaIterator()
{
	JavaIterator * it = new PlayersJavaIterator(this);
	javaItReleaseList.push_back(it);
	return it;
}

Player * Players::getPlayerByName(string name)
{
	CppIterator* it = Players::getPlayers().createCppIterator();
	while (!it->isLast()) {
		if (((Player*)it->current())->name() == name) 
			return (Player*)it->current();
		it->next();
	}
	return nullptr;
}

void Players::displayCurInfo()
{
	cout <<"===========CurInfo===========" << endl;
	CppIterator* it = Players::getPlayers().createCppIterator();
	while (!it->isLast()) {
		Player* cur = (Player*)it->current();
		
		cout << "****\tPlayer " << cur->name() << "'s info:" << endl;
		cout << "\tPosition: x: " << cur->getPos().first << " y: " << cur->getPos().second << endl;
		cout << "\tDirection: " << cur->getDirection() <<endl;
		cout << "\tMoney: " << cur->getMoney() << endl<<endl;
		it->next();
	}
	cout << "===========End==============" << endl;
}

int Players::judge()
{
	int allHumanPlayer = 0;
	int allAutoPlayer = 0;
	int deadHumanPlayer = 0;
	int deadAutoPlayer = 0;
	for (auto player : players) {
		if (dynamic_cast<HumanPlayer*>(player)) {
			allHumanPlayer++;
			if (player->isDead())
				deadHumanPlayer++;
		}
		else if (dynamic_cast<AutoPlayer*>(player)) {
			allAutoPlayer++;
			if (player->isDead())
				deadAutoPlayer++;
		}
	}
	if (allAutoPlayer == deadAutoPlayer && allHumanPlayer - deadHumanPlayer == 1)
		return 1;//HumanPlayer胜
	else if (allHumanPlayer == deadHumanPlayer && allAutoPlayer - deadAutoPlayer > 0)
		return 2;//AutoPlayer胜
	else return 0;//未分胜负
}

void Player::setDirection(int dir)
{
	if (dir >= DirID::DIR_NONE&&dir < DirID::DIR_COUNT)
		direction = dir;
}
int Player::getDirection() {
	return direction;
}

void Player::setMoney(int m)
{
	money = m;
}

int Player::getMoney()
{
	return money;
}

PlayerState * Player::getState()
{
	return curState;
}

void Player::setState(PlayerState * state)
{
	curState = state;
}

void Player::setAct(bool act)
{
	actThisRound = act;
}

bool Player::getAct()
{
	return actThisRound;
}

bool Player::isExFly()
{
	return exFly;
}

void Player::setExFly(bool _exFly)
{
	exFly = _exFly;
}

bool Player::isDead()
{
	return dead;
}

void Player::setDead(bool _dead)
{
	dead = _dead;
}

bool Player::go()
{
	setAct(true);
	int idx = MapMgr::getMgr()->getCurMap()->getIndex(curPos);
	Block* block = MapMgr::getMgr()->getCurMap()->getBlock(idx);
	LinkedBlock* curBlock = dynamic_cast<LinkedBlock*>(block);
	assert(curBlock);

	/*if (direction == DirID::DIR_NONE) {
		while (true) {
			int dir = rand() % 4 + 1;
			if (Block* nxtBlk = curBlock->getNeighbor(dir)) {
				curBlock = dynamic_cast<LinkedBlock*>(nxtBlk);
				direction = dir;
				curPos = make_pair(curBlock->getRow(), curBlock->getCol());
				break;
			}
		}
	}
	else {
		bool vis[5] = { false };
		int oppDir;
		if (direction == DirID::DIR_DOWN)
			oppDir = DirID::DIR_UP;
		else if (direction == DirID::DIR_UP)
			oppDir = DirID::DIR_DOWN;
		else if (direction == DirID::DIR_LEFT)
			oppDir = DirID::DIR_RIGHT;
		else if (direction == DirID::DIR_RIGHT)
			oppDir = DirID::DIR_LEFT;

		while (true) {
			int dir = rand() % 4 + 1;
#ifdef  DEBUG_TRACE
			cout << "direction rand:" << dir << endl;
#endif //  DEBUG_TRACE
			Block* nxtBlk = curBlock->getNeighbor(dir);
			bool done = true;
			for (int i = 1; i <= 4; i++) {
				if (i == oppDir)
					continue;
				done &= vis[i];
			}
			if (dir != oppDir && nxtBlk != nullptr) {
				curBlock = dynamic_cast<LinkedBlock*>(nxtBlk);
				direction = dir;
				curPos = make_pair(curBlock->getRow(), curBlock->getCol());
				break;
			}
			else if (done && dir == oppDir) {
				curBlock = dynamic_cast<LinkedBlock*>(nxtBlk);
				direction = dir;
				curPos = make_pair(curBlock->getRow(), curBlock->getCol());
				break;
			}
			vis[dir] = true;
		}
	}*/

	vector<int> availDirs;
	for (int i = 1; i <= 4; i++) {
		if (curBlock->getNeighbor(i)) {
			availDirs.push_back(i);
		}
	}
	if (direction != DirID::DIR_NONE) {
		if (availDirs.size() == 1)
			curStrategy = new DirStrategyIndir1Dir;
		else if(availDirs.size() == 2)
			curStrategy = new DirStrategyIndir2Dirs;
		else if (availDirs.size() == 3)
			curStrategy = new DirStrategyIndir3Dirs;
		else if (availDirs.size() == 4)
			curStrategy = new DirStrategyIndir4Dirs;
	}
	else {
		if (availDirs.size() == 1)
			curStrategy = new DirStrategyNoIndir1Dir;
		else if (availDirs.size() == 2)
			curStrategy = new DirStrategyNoIndir2Dirs;
		else if (availDirs.size() == 3)
			curStrategy = new DirStrategyNoIndir3Dirs;
		else if (availDirs.size() == 4)
			curStrategy = new DirStrategyNoIndir4Dirs;
	}

	int dir = curStrategy->getDir(curBlock,availDirs, direction);
#ifdef DEBUG_TRACE
	cout << "dir:" << dir << endl;
#endif // DEBUG_TRACE
	delete curStrategy;
	curStrategy = nullptr;

	Block* nxtBlk = curBlock->getNeighbor(dir);
	direction = dir;
	return nxtBlk->arrive(this);
	/*curBlock = dynamic_cast<LinkedBlock*>(nxtBlk);
	direction = dir;
	curPos = make_pair(curBlock->getRow(), curBlock->getCol());*/
}

void Player::ApplyRobCard(Player * target)
{
	int diff = target->money / 2;
	this->money += diff;
	target->money -= diff;
}

void Player::ApplyFlyCard(Player * target)
{
	target->setState(new MacroState(target->getState(), new FlyState));
}

void Player::ApplyFreezeSpeel(Player * target)
{
	target->setState(new MacroState(target->getState(), new FreezeState));
}

void Player::ApplyMeanCard()
{
	int sum=0;
	CppIterator* it = Players::getPlayers().createCppIterator();
	while (!it->isLast()) {
		Player* player = (Player*)it->current();
		sum += player->money;
		it->next();
	}
	int avg = sum/it->count();
	it->first();
	while (!it->isLast()) {
		Player* player = (Player*)it->current();
		player->money=avg;
		it->next();
	}
}

void Player::ApplyReturnSpell(Player * target)
{
	Block* blk = MapMgr::getMgr()->getCurMap()->getBlock(0);
	target->setPos(make_pair(blk->getRow(), blk->getCol()));
	target->setDirection(rand() % 5);
}

void Player::ApplyHurtSpell(Player * target)
{
	target->setState(new MacroState(target->getState(), new HurtState()));
}

void Player::ApplyLuckCard(Player * target)
{
	target->setState(new MacroState(target->getState(), new LuckState()));
}

void Player::ApplyExFlyCard(Player * target)
{
	target->setState(new MacroState(target->getState(), new ExFlyState()));
}

void Player::ApplySuperCard(Player * target)
{
	target->setState(new MacroState(new MacroState(target->getState(), new FlyState(1)),new LuckState(1)));
}


Player::~Player()
{
	delete curState;
}

///-----------------------------------------
void Player::setName(const string& str)
{
    strName = str;
}
void Player::setPos(pair<int, int> pos)
{
	curPos = pos;
}
pair<int, int> Player::getPos()
{
	return curPos;
}
AutoPlayer::AutoPlayer()
{
	setName("");
	setPos(make_pair(-1,-1));
	setDirection(DirID::DIR_NONE);
	setMoney(0);
	setState(new AutoCommonState);
}
///-----------------------------------------
bool AutoPlayer::play(Players* p, bool showed)
{
	if (dead)
		return true;
    #ifdef DEBUG_TRACE
    cout<<"AutoPlayer::showed:"<<(showed?"true":"false")<<endl;
    #endif // DEBUG_TRACE
    cout<<"Name = "<<name()<<endl;

	/*for (int i = 0; i < 2; i++) {
		this->go();
	}*/
	curState->execute(this);

    MapMgr::getMgr()->getCurMap()->show(p);
	setAct(false);
    return true;
}

void AutoPlayer::accept(Visitor * vis)
{
	vis->visit(this);
}


HumanPlayer::HumanPlayer()
{
	setName("");
	setPos(make_pair(-1,-1));
	setDirection(DirID::DIR_NONE);
	setMoney(0);
	setState(new HumanCommonState);
}

///-----------------------------------------
bool HumanPlayer::play(Players* p, bool showed)
{
	if (dead)
		return true;
    #ifdef DEBUG_TRACE
    cout<<"HumanPlayer::showed:"<<(showed?"true":"false")<<endl;
    #endif // DEBUG_TRACE
    cout<<"Name = "<<name()<<endl;
    if(showed) {
        MapMgr::getMgr()->getCurMap()->show(p);
        MenuMgr::getMgr()->setCurMenu(MenuID::PLAY_MENU);
		setAct(false);
        return false;
    } else {
		/*for (int i = 0; i < 3; i++) {
			this->go();
		}*/
		curState->execute(this);
        MapMgr::getMgr()->getCurMap()->show(p);
		setAct(false);
        return true;
    }
}

void HumanPlayer::accept(Visitor * vis)
{
	vis->visit(this);
}

PlayersJavaIterator::PlayersJavaIterator(Players* p) :container(p){
	players_cpy = deque<Player*>(p->players);
	players_cpy.push_front(nullptr);
	cnt = p->players.size();
}
void * PlayersJavaIterator::next()
{
	Player* res= players_cpy.front();
	players_cpy.pop_front();
	return res;
}

bool PlayersJavaIterator::hasNext() const
{
	return !players_cpy.empty();
}

int PlayersJavaIterator::count() const
{
	return players_cpy.size()-1;
}

PlayersCppIterator::PlayersCppIterator(Players *p):container(p) {
	players_cpy = deque<Player*>(p->players);
	players_cpy.push_back(nullptr);
	cnt = p->players.size();
}

void PlayersCppIterator::first()
{
	players_cpy= deque<Player*>(container->players);
	players_cpy.push_back(nullptr);
}

void PlayersCppIterator::next()
{
	players_cpy.pop_front();
}

bool PlayersCppIterator::isLast() const
{
	return players_cpy.size()==1;
}

void * PlayersCppIterator::current()
{
	Player* res = players_cpy.front();
	return res;
}

int PlayersCppIterator::count() const
{
	return cnt;
}

int DirStrategyNoIndir4Dirs::getDir(Block* curBlock, vector<int> dirs, int inDir)
{
	return dirs[rand() % 4];
}

int DirStrategyNoIndir3Dirs::getDir(Block* curBlock, vector<int> dirs, int inDir)
{
	return dirs[rand() % 3];
}

int DirStrategyNoIndir2Dirs::getDir(Block* curBlock, vector<int> dirs, int inDir)
{
	return dirs[rand() % 2];
}

int DirStrategyNoIndir1Dir::getDir(Block* curBlock, vector<int> dirs, int inDir)
{
	return dirs[0];
}

int DirStrategyIndir4Dirs::getDir(Block* curBlock, vector<int> dirs, int inDir)
{
	int directions[5][5] = {
		{0,0,0,0,0},
		{0,4,3,1,2},
		{0,3,4,2,1},
		{0,1,2,3,4},
		{0,2,1,4,3}
	};
	int pre[4];
	pre[0] = inDir;
	pre[1] = inDir;
	pre[2] = directions[inDir][DirID::DIR_LEFT];
	pre[3] = directions[inDir][DirID::DIR_RIGHT];
	return pre[rand() % 4];
}

int DirStrategyIndir3Dirs::getDir(Block* curBlock, vector<int> dirs, int inDir)
{
	int directions[5][5] = {
		{0,0,0,0,0},
		{0,4,3,1,2},
		{0,3,4,2,1},
		{0,1,2,3,4},
		{0,2,1,4,3}
	};
	int oppDir = directions[inDir][DirID::DIR_DOWN];
	if (dynamic_cast<LinkedBlock*>(curBlock)->getNeighbor(inDir)) {
		int pre[5];
		int i = 3;
		while (i--) 
			pre[i] = inDir;
		if (dynamic_cast<LinkedBlock*>(curBlock)->getNeighbor(directions[inDir][DirID::DIR_LEFT])!=nullptr)
			pre[3] = pre[4] = directions[inDir][DirID::DIR_LEFT];
		else
			pre[3] = pre[4] = directions[inDir][DirID::DIR_RIGHT];
		return pre[rand() % 5];
	}
	else {
		int pre[2] = { directions[inDir][DirID::DIR_LEFT],directions[inDir][DirID::DIR_RIGHT] };
		return pre[rand() % 2];
	}
}

int DirStrategyIndir2Dirs::getDir(Block* curBlock, vector<int> dirs, int inDir)
{
	/*int directions[5][5] = {
	{0,0,0,0,0},
	{0,4,3,1,2},
	{0,3,4,2,1},
	{0,1,2,3,4},
	{0,2,1,4,3}
	};
	int oppDir = directions[inDir][DirID::DIR_DOWN];
	for (auto dir : dirs) 
		if (dir != inDir&& dir != oppDir)
			return dir;
	for (auto dir : dirs)
		if (dir == inDir)
			return dir;
	return oppDir;*/
	for (auto dir : dirs)
		if (dir != inDir)
			return dir;
	return DirID::DIR_NONE;
}

int DirStrategyIndir1Dir::getDir(Block* curBlock, vector<int> dirs, int inDir)
{
	return dirs[0];
}

TallRichHandsomePlayer::TallRichHandsomePlayer():AutoPlayer()
{
}

void TallRichHandsomePlayer::accept(Visitor * vis)
{
	vis->visit(this);
}

void TallRichHandsomePlayer::ApplyLuckCard(Player * target)
{
	target->setState(new MacroState(target->getState(), new LuckState(3)));
}

WhiteRichBeautifulPlayer::WhiteRichBeautifulPlayer()
{
}

void WhiteRichBeautifulPlayer::accept(Visitor * vis)
{
	vis->visit(this);
}

void WhiteRichBeautifulPlayer::ApplyLuckCard(Player * target)
{
	target->setState(new MacroState(target->getState(), new LuckState(4)));
}

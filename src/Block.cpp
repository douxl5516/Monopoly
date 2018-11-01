///======================================================================
///  Project:   Richer02
/// FileName:	block.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include "block.h"
#include "blockmgr.h"
#include "player.h"
#include <iostream>
using namespace std;

Block::Block()
{
    //ctor
}

Block::~Block()
{
    //dtor
}
MoneyBlock* MoneyBlock::clone()
{
    return new MoneyBlock(*this);
}
bool MoneyBlock::arrive(Player * player)
{
	player->setMoney(player->getMoney() + 5);
	cout << "A money block, got 5 coins!" << endl;
	return true;
}
TripBlock* TripBlock::clone()
{
    return new TripBlock(*this);
}
bool TripBlock::arrive(Player * player)
{
	int lostMoney = player->getMoney() >= 20 ? 20 : player->getMoney();
	player->setMoney(player->getMoney() - lostMoney);
	cout << "A trip block, lost " << lostMoney << " coins!" << endl;
	return true;
}
BarBlock* BarBlock::clone()
{
    return new BarBlock(*this);
}
bool BarBlock::arrive(Player * player)
{
	if (player->isExFly()) {
		cout << "A bar block. ExFly state! Continue!" << endl;
	}
	else {
		cout << "A bar block, halt!" << endl;
		return false;
	}
}
SlideBlock* SlideBlock::clone()
{
    return new SlideBlock(*this);
}

bool SlideBlock::arrive(Player * player)
{
	cout << "A slide block, goes another two steps!" << endl;
	int i = 2;
	while (i--) {
		bool res = player->go();
		if (res == false)
			return false;
	}
	return true;
}


EBlock* EBlock::clone()
{
    return new EBlock(*this);
}

bool EBlock::arrive(Player * player)
{
	return true;
}

FBlock* FBlock::clone()
{
    return new FBlock(*this);
}
bool FBlock::arrive(Player * player)
{
	return true;
}
///--------------------------------

LinkedBlock::LinkedBlock(int kernelID)
{
    kernel = BlockMgr::getMgr()->cloneBlock(kernelID);
    for(int dir = DirID::DIR_NONE; dir < DirID::DIR_COUNT; ++dir) {
        neighbors[dir] = nullptr;
    }
}
LinkedBlock::~LinkedBlock()
{
    delete kernel;
}
const char* LinkedBlock::name() const
{
    return kernel->name();
}

Block* LinkedBlock::clone()
{
    LinkedBlock* newOne = new LinkedBlock(*this);
    newOne->kernel = kernel->clone();
    for(int dir = DirID::DIR_NONE; dir < DirID::DIR_COUNT; ++dir) {
        neighbors[dir] = nullptr;
    }
    return newOne;
}
void LinkedBlock::setNeighbor(int dir, Block* b)
{
    if(dir > DirID::DIR_NONE && dir < DirID::DIR_COUNT) {
        neighbors[dir] = b;
    }
}
Block* LinkedBlock::getNeighbor(int dir)
{
    return neighbors[dir];
}

bool LinkedBlock::arrive(Player * player)
{
	pair<int, int> pos= make_pair(getRow(), getCol());
	cout << "** Player " << player->name() << " arrived at [" << pos.first << "," << pos.second << "]. ";
	player->setPos(pos);
	return kernel->arrive(player);
}
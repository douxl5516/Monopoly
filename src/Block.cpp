#include <iostream>
#include "Block.h"
#include "BlockMgr.h"
using namespace std;

Block::Block()
{
}

Block::~Block()
{
}

void Block::setPosition(int r, int c)
{
	row = r;
	col = c;
}

MoneyBlock* MoneyBlock::clone()
{
	return new MoneyBlock(*this);
}
TripBlock* TripBlock::clone()
{
	return new TripBlock(*this);
}
BarBlock* BarBlock::clone()
{
	return new BarBlock(*this);
}
SlideBlock* SlideBlock::clone()
{
	return new SlideBlock(*this);
}
EBlock* EBlock::clone()
{
	return new EBlock(*this);
}
FBlock* FBlock::clone()
{
	return new FBlock(*this);
}
LinkedBlock::LinkedBlock(int kernelID)
{
	kernel = BlockMgr::getInstance()->cloneBlock(kernelID);
	for (int dir = DirID::DIR_NONE; dir < DirID::DIR_COUNT; ++dir) {
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
	for (int dir = DirID::DIR_NONE; dir < DirID::DIR_COUNT; ++dir) {
		neighbors[dir] = nullptr;
	}
	return newOne;
}
void LinkedBlock::setNeighbor(int dir, Block* b)
{
	if (dir > DirID::DIR_NONE && dir < DirID::DIR_COUNT) {
		neighbors[dir] = b;
	}
}
Block* LinkedBlock::getNeighbor(int dir)
{
	return neighbors[dir];
}
#include "BlockMgr.h"

BlockMgr * BlockMgr::getInstance()
{
	if (instance == nullptr)
		instance = new BlockMgr();
	return instance;
}

Block * BlockMgr::getBlockInstance(int blockID)
{
	if (blockID >= 0 && blockID < BlockID::BLOCK_COUNT)
		return blocks[blockID]->clone();
}

void BlockMgr::release()
{
}

BlockMgr * BlockMgr::instance = nullptr;
Block * BlockMgr::blocks[] = {
	new BlockBlank(),
	new BlockA(),
	new BlockB(),
	new BlockC(),
	new BlockD(),
	new BlockE(),
	new BlockF(),
	new BlockBoundary()
};
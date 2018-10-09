#include "BlockMgr.h"
#include "Block.h"

BlockMgr* BlockMgr::instance = nullptr;

BlockMgr* BlockMgr::getInstance()
{
	if (instance == nullptr) {
		instance = new BlockMgr;
	}
	return instance;
}
void BlockMgr::release()
{
	delete instance;
	instance = nullptr;
}

BlockMgr::BlockMgr()
{
	prototypes[BlockID::NONE_BLOCK] = nullptr;
	prototypes[BlockID::MONEY_BLOCK] = new MoneyBlock;
	prototypes[BlockID::TRIP_BLOCK] = new TripBlock;
	prototypes[BlockID::BAR_BLOCK] = new BarBlock;
	prototypes[BlockID::SLIDE_BLOCK] = new SlideBlock;
}

BlockMgr::~BlockMgr()
{
	for (int i = 0; i < BlockID::BLOCK_COUNT; ++i) {
		delete prototypes[i];
	}
}

Block* BlockMgr::cloneBlock(int blockID)
{
	if (blockID > BlockID::NONE_BLOCK && blockID < BlockID::BLOCK_COUNT) {
		return prototypes[blockID]->clone();
	}
	return nullptr;
}
void BlockMgr::setPrototype(int blockID, Block* proto)
{
	delete prototypes[blockID];
	prototypes[blockID] = proto;

}

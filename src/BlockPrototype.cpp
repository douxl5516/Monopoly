#include "Global.h"
#include "Block.h"
#include "Blockprototype.h"

BlockPrototype::BlockPrototype()
{
	prototypes[BlockID::NONE_BLOCK] = nullptr;
	prototypes[BlockID::MONEY_BLOCK] = new MoneyBlock;
	prototypes[BlockID::TRIP_BLOCK] = new TripBlock;
	prototypes[BlockID::BAR_BLOCK] = new BarBlock;
	prototypes[BlockID::SLIDE_BLOCK] = new SlideBlock;
}

BlockPrototype::~BlockPrototype()
{
	for (int i = 0; i < BlockID::BLOCK_COUNT; ++i) {
		delete prototypes[i];
	}
}
Block* BlockPrototype::cloneBlock(int blockID)
{
	return prototypes[blockID]->clone();
}
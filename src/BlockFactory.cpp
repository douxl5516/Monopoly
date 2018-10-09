#include "BlockFactory.h"
#include "Global.h"
#include "Block.h"

BlockFactory::BlockFactory()
{
}

BlockFactory::~BlockFactory()
{
}
Block* BlockFactory::createBlock(int blockID)
{
	if (blockID == BlockID::MONEY_BLOCK) {
		return new MoneyBlock;
	}
	else if (blockID == BlockID::TRIP_BLOCK) {
		return new TripBlock;
	}
	else if (blockID == BlockID::BAR_BLOCK) {
		return new BarBlock;
	}
	else if (blockID == BlockID::SLIDE_BLOCK) {
		return new SlideBlock;
	}
	else {
		return nullptr;
	}
}

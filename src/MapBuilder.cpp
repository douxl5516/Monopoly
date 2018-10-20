#include "MapBuilder.h"
#include "Block.h"
#include "BlockMgr.h"
#include "Global.h"
MapBuilder::MapBuilder()
{
}

MapBuilder::~MapBuilder()
{
}
Block* MapBuilder::buildBlock(int blockID)
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
Block* EFMapBuilder::buildBlock(int blockID)
{
	return BlockMgr::getInstance()->cloneBlock(blockID);
}
Block* LinkedMapBuilder::buildBlock(int blockID)
{
	return new LinkedBlock(blockID);
	//return BlockMgr::getMgr()->cloneBlock(blockID);
}
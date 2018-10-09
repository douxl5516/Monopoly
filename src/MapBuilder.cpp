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
Block * MapBuilder::buildBlock(int blockID, int blockIndex, int row, int col, int left, int right, int up, int down)
{
	if (blockID == BlockID::MONEY_BLOCK) {
		return new MoneyBlock(blockIndex, row, col, left, right, up, down);
	}
	else if (blockID == BlockID::TRIP_BLOCK) {
		return new TripBlock(blockIndex, row, col, left, right, up, down);
	}
	else if (blockID == BlockID::BAR_BLOCK) {
		return new BarBlock(blockIndex, row, col, left, right, up, down);
	}
	else if (blockID == BlockID::SLIDE_BLOCK) {
		return new SlideBlock(blockIndex, row, col, left, right, up, down);
	}
	else {
		return nullptr;
	}
}

///-----------------------------------------
Block* EFMapBuilder::buildBlock(int blockID)
{
	return BlockMgr::getInstance()->cloneBlock(blockID);
}
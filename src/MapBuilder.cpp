///======================================================================
///  Project:   Richer02
/// FileName:	mapbuilder.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "block.h"
#include "mapbuilder.h"
#include "blockmgr.h"
MapBuilder::MapBuilder()
{
    //ctor
}

MapBuilder::~MapBuilder()
{
    //dtor
}
Block* MapBuilder::buildBlock(int blockID)
{
    if(blockID == BlockID::MONEY_BLOCK) {
        return new MoneyBlock;
    } else if(blockID == BlockID::TRIP_BLOCK) {
        return new TripBlock;
    } else if(blockID == BlockID::BAR_BLOCK) {
        return new BarBlock;
    } else if(blockID == BlockID::SLIDE_BLOCK) {
        return new SlideBlock;
    } else {
        return nullptr;
    }
}
///-----------------------------------------
Block* EFMapBuilder::buildBlock(int blockID)
{
    return BlockMgr::getMgr()->cloneBlock(blockID);
}
///-----------------------------------------
Block* LinkedMapBuilder::buildBlock(int blockID)
{
    return new LinkedBlock(blockID);
    //return BlockMgr::getMgr()->cloneBlock(blockID);
}


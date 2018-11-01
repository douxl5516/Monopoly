///======================================================================
///  Project:   Richer02
/// FileName:	mapdirector.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "map.h"
#include "mapbuilder.h"
#include "mapdirector.h"
#include "mapimp.h"
#include "block.h"
MapDirector::MapDirector(MapBuilder* aBuilder)
    : builder(aBuilder)
{
    //ctor
}

MapDirector::~MapDirector()
{
    //dtor
}

void MapDirector::makeMap()
{
    aMap = new Map(new MapImp);

    int layout[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS] = {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 2},
        {3, 0, 0, 0, 3},
        {4, 0, 0, 0, 4},
        {1, 1, 1, 1, 1}
    };

    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            if(layout[r][c] != BlockID::NONE_BLOCK) {
                Block* block = builder->buildBlock(layout[r][c]);
                block->setPosition(r, c);
                aMap->addBlock(block);
            }
        }
    }
}

Map* MapDirector::getMap()
{
    return aMap;
}
///-----------------------------------------
SunMapDirector::SunMapDirector(MapBuilder* aBuilder)
    : MapDirector(aBuilder)
{
}

void SunMapDirector::makeMap()
{
    aMap = new Map(new MapImp);

    int layout[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS] = {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 2},
        {3, 3, 3, 3, 3},
        {4, 0, 0, 0, 4},
        {1, 1, 1, 1, 1}
    };

    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            if(layout[r][c] != BlockID::NONE_BLOCK) {
                Block* block = builder->buildBlock(layout[r][c]);
                block->setPosition(r, c);
                aMap->addBlock(block);
            }
        }
    }
}
///-----------------------------------------

LinkedMapDirector::LinkedMapDirector(MapBuilder* aBuilder)
    : MapDirector(aBuilder)
{
}

void LinkedMapDirector::makeMap()
{
    aMap = new Map(new MapImp);

	//种类，index，x，y，左，右，上，下
    /*int layout[][8] = {
        {BlockID::MONEY_BLOCK	,  1	, 0	, 0	,  0	,  2	,  0	,  6},
        {BlockID::MONEY_BLOCK	,  2	, 0	, 1	,  1	,  3	,  0	,  0},
        {BlockID::MONEY_BLOCK	,  3	, 0	, 2	,  2	,  4	,  0	,  7},
        {BlockID::MONEY_BLOCK	,  4	, 0	, 3	,  3	,  5	,  0	,  0},
        {BlockID::MONEY_BLOCK	,  5	, 0	, 4	,  4	,  0	,  0	,  8},
        {BlockID::TRIP_BLOCK	,  6	, 1	, 0	,  0	,  0	,  1	,  9},
        {BlockID::TRIP_BLOCK	,  7	, 1	, 2	,  0	,  0	,  3	, 10},
        {BlockID::TRIP_BLOCK	,  8	, 1	, 4	,  0	,  0	,  5	, 12},
        {BlockID::BAR_BLOCK	,  9	, 2	, 0	,  0	,  0	,  6	, 13},
        {BlockID::BAR_BLOCK	, 10	, 2	, 2	,  0	, 11	,  7	, 14},
        {BlockID::BAR_BLOCK	, 11	, 2	, 3	, 10	, 12	,  0	,  0},
        {BlockID::BAR_BLOCK	, 12	, 2	, 4	, 11	,  0	,  8	, 15},
        {BlockID::SLIDE_BLOCK	, 13	, 3	, 0	,  0	,  0	,  9	, 16},
        {BlockID::SLIDE_BLOCK	, 14	, 3	, 2	,  0	,  0	, 10	, 18},
        {BlockID::SLIDE_BLOCK	, 15	, 3	, 4	,  0	,  0	, 12	, 20},
        {BlockID::MONEY_BLOCK	, 16	, 4	, 0	,  0	, 17	, 13	,  0},
        {BlockID::MONEY_BLOCK	, 17	, 4	, 1	, 16	, 18	,  0	,  0},
        {BlockID::MONEY_BLOCK	, 18	, 4	, 2	, 17	, 19	, 14	,  0},
        {BlockID::MONEY_BLOCK	, 19	, 4	, 3	, 18	, 20	,  0	,  0},
        {BlockID::MONEY_BLOCK	, 20	, 4	, 4	, 19	, 21	, 15	,  0},
        {BlockID::TRIP_BLOCK	, 21	, 4	, 5	, 20	, 22	,  0	,  0},
        {BlockID::TRIP_BLOCK	, 22	, 4	, 6	, 21	, 23	,  0	,  0},
        {BlockID::TRIP_BLOCK	, 23	, 4	, 7	, 22	, 00	,  0	,  0}
    };*/
	int layout[][8] = {
		{BlockID::MONEY_BLOCK	,  1	, 0	, 0	,  0	,  2	,  0	,  6},
		{BlockID::MONEY_BLOCK	,  2	, 0	, 1	,  1	,  3	,  0	, 24},
		{BlockID::MONEY_BLOCK	,  3	, 0	, 2	,  2	,  4	,  0	,  7},
		{BlockID::MONEY_BLOCK	,  4	, 0	, 3	,  3	,  5	,  0	,  0},
		{BlockID::MONEY_BLOCK	,  5	, 0	, 4	,  4	,  0	,  0	,  8},
		{BlockID::TRIP_BLOCK	,  6	, 1	, 0	,  0	,  24	,  1	,  9},
		{BlockID::TRIP_BLOCK	,  7	, 1	, 2	,  24	,  0	,  3	, 10},
		{BlockID::TRIP_BLOCK	,  8	, 1	, 4	,  0	,  0	,  5	, 12},
		{BlockID::BAR_BLOCK	,  9	, 2	, 0	,  0	,  25	,  6	, 13},
		{BlockID::BAR_BLOCK	, 10	, 2	, 2	,  25	, 11	,  7	, 14},
		{BlockID::BAR_BLOCK	, 11	, 2	, 3	, 10	, 12	,  0	,  0},
		{BlockID::BAR_BLOCK	, 12	, 2	, 4	, 11	,  0	,  8	, 15},
		{BlockID::SLIDE_BLOCK	, 13	, 3	, 0	,  0	,  26	,  9	, 16},
		{BlockID::SLIDE_BLOCK	, 14	, 3	, 2	,  26	,  0	, 10	, 18},
		{BlockID::SLIDE_BLOCK	, 15	, 3	, 4	,  0	,  0	, 12	, 20},
		{BlockID::MONEY_BLOCK	, 16	, 4	, 0	,  0	, 17	, 13	,  0},
		{BlockID::MONEY_BLOCK	, 17	, 4	, 1	, 16	, 18	, 26	,  0},
		{BlockID::MONEY_BLOCK	, 18	, 4	, 2	, 17	, 19	, 14	,  0},
		{BlockID::MONEY_BLOCK	, 19	, 4	, 3	, 18	, 20	,  0	,  0},
		{BlockID::MONEY_BLOCK	, 20	, 4	, 4	, 19	, 21	, 15	,  0},
		{BlockID::TRIP_BLOCK	, 21	, 4	, 5	, 20	, 22	,  0	,  0},
		{BlockID::TRIP_BLOCK	, 22	, 4	, 6	, 21	, 23	,  0	,  0},
		{BlockID::TRIP_BLOCK	, 23	, 4	, 7	, 22	, 00	,  0	,  0},
		{BlockID::MONEY_BLOCK	, 24	, 1	, 1	,  6	,  7	,  2	,  25},
		{BlockID::MONEY_BLOCK	, 25	, 2	, 1	,  9	,  10	,  24	,  26},
		{BlockID::MONEY_BLOCK	, 26	, 3	, 1	,  13	,  14	,  25	,  17},
	};

    int blockNum = sizeof(layout) / (sizeof(int) * 8);

    for(int r = 0; r < blockNum; ++r) {
        Block* block = builder->buildBlock(layout[r][0]);
        block->setPosition(layout[r][2], layout[r][3]);
        aMap->addBlock(block);
    }

    for(int r = 0; r < blockNum; ++r) {
        LinkedBlock* block = (LinkedBlock*)(aMap->getBlock(r));
        if(layout[r][4] > 0) {
            block->setNeighbor(DirID::DIR_LEFT, aMap->getBlock(layout[r][4] - 1));
        }
        if(layout[r][5] > 0) {
            block->setNeighbor(DirID::DIR_RIGHT, aMap->getBlock(layout[r][5] - 1));
        }
        if(layout[r][6] > 0) {
            block->setNeighbor(DirID::DIR_UP, aMap->getBlock(layout[r][6] - 1));
        }
        if(layout[r][7] > 0) {
            block->setNeighbor(DirID::DIR_DOWN, aMap->getBlock(layout[r][7] - 1));
        }
    }
}

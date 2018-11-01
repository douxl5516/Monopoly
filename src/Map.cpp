///======================================================================
///  Project:   Richer02
/// FileName:	map.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include <iostream>
using namespace std;
#include "global.h"
#include "block.h"

#include "map.h"
#include "mapimp.h"
/**
int layout[][8] = {
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
};
**/
Map::Map(MapImp* aImp)
    : imp(aImp)
{
}

Map::~Map()
{
    delete imp;
}
void Map::addBlock(Block* block)
{
    imp->addBlock(block);
}
Block* Map::getBlock(int index)
{
    return imp->getBlock(index);
}
int Map::getIndex(pair<int, int> pos)
{
	return imp->getIndex(pos);
}
void Map::show() const
{
    imp->show();
    /**
    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        cout << endl;
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            Block* block = blocks[r][c];
            if(block) {
                cout << block->name() << " ";
            } else {
                cout << "  ";
            }
        }
    }
    cout << endl;
    **/
}

void Map::show(Players * p) const
{
	imp->show(p);
}

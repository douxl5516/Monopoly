#include <iostream>
#include "Map.h"
#include "MapImp.h"
#include "MapDirector.h"
#include "Block.h"
using namespace std;

	
Map::Map(MapImp * aImp):imp(aImp)
{
}

Map::~Map()
{
	delete imp;
}
void Map::show() const
{
	imp->show();
}

void Map::addBlock(Block * block)
{
	imp->addBlock(block);
}

Block * Map::getBlock(int index)
{
	return imp->getBlock(index);
}

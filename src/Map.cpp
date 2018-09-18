#include "Map.h"
#include "MapDirector.h"
#include "Block.h"

Map::Map(MapDirector & director)
{
	block = director.buildMap();
}

void Map::create(MapDirector& director)
{
	director.buildMap();
}

void Map::show()
{
	block->show();
}

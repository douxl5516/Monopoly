#include "MapDirector.h"
#include "MapBuilder.h"
#include "Block.h"

Block * MapDirectorA::buildMap()
{
	MapBuilder* mapBuilder = new MapBuilderA();
	Block* temp=mapBuilder->buildContainer();
	delete mapBuilder;
	return temp;
}

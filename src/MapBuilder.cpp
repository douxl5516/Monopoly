#include "MapBuilder.h"
#include "Block.h"
#include "BlockMgr.h"

Block * MapBuilderA::buildContainer()
{
	container = new Block();
	buildWall(5, BlockID::BLOCK_E);
	buildPath(5, BlockID::BLOCK_B);
	buildWall(5, BlockID::BLOCK_F);
	buildPath(5, BlockID::BLOCK_D);
	buildWall(5, BlockID::BLOCK_E);
	return container;
}

void MapBuilderA::buildWall(int n, int blockID)
{
	for (int i = 0; i < n; i++) {
		container->push(BlockMgr::getInstance()->getBlockInstance(blockID));
	}
	container->push(BlockMgr::getInstance()->getBlockInstance(BlockID::BLOCK_BOUNDERY));

}

void MapBuilderA::buildPath(int n, int blockID)
{
	container->push(BlockMgr::getInstance()->getBlockInstance(blockID));
	for (int i = 0; i < n - 2; i++) {
		container->push(BlockMgr::getInstance()->getBlockInstance(BlockID::BLOCK_BLANK));
	}
	container->push(BlockMgr::getInstance()->getBlockInstance(blockID));
	container->push(BlockMgr::getInstance()->getBlockInstance(BlockID::BLOCK_BOUNDERY));
}

void MapBuilderA::buildBlock(int blockID)
{
	container->push(BlockMgr::getInstance()->getBlockInstance(blockID));
}

Block * MapBuilder::getResult()
{
	return container;
}

MapBuilder::~MapBuilder()
{
	
}

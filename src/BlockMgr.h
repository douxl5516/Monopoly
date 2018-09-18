#ifndef BLOCK_MGR_H
#define BLOCK_MGR_H
#include "Block.h"

class BlockMgr
{
public:
	static BlockMgr* getInstance();
	static Block* getBlockInstance(int blockID);
	static void release();
private:
	static Block* blocks[BlockID::BLOCK_COUNT];
	static BlockMgr* instance;
private:
	BlockMgr() {}
	BlockMgr(const BlockMgr&) {}
	BlockMgr& operator=(const BlockMgr&) {}
};

#endif // !BLOCK_MGR_H

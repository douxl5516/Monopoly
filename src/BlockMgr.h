#ifndef BLOCK_MGR_H
#define BLOCK_MGR_H
#include "Global.h"

class Block;
class BlockMgr
{
public:
	static BlockMgr* getInstance();
	static void release();
private:
	static BlockMgr* instance;
private:
	BlockMgr();
	BlockMgr(const BlockMgr&);
	BlockMgr& operator=(const BlockMgr&) = delete;
public:
	virtual ~BlockMgr();
	virtual Block* cloneBlock(int blockID);
	void setPrototype(int blockID, Block * proto);
protected:
	Block* prototypes[BlockID::BLOCK_COUNT];
};

#endif // !BLOCK_MGR_H

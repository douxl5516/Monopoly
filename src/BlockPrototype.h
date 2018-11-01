///======================================================================
///  Project:   Richer02
/// FileName:	blockprototype.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef BLOCKPROTOTYPE_H
#define BLOCKPROTOTYPE_H
#include "global.h"

class Block;
class BlockPrototype
{
public:
    BlockPrototype();
    virtual ~BlockPrototype();
    virtual Block * cloneBlock(int blockID);
protected:
    Block * prototypes[BlockID::BLOCK_COUNT];
private:
};

#endif // BLOCKPROTOTYPE_H

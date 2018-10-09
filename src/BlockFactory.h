#ifndef BLOCKFACTORY_H
#define BLOCKFACTORY_H

class Block;
class BlockFactory
{
public:
	BlockFactory();
	virtual ~BlockFactory();
	virtual Block * createBlock(int blockID);
protected:

private:
};
#endif // BLOCKFACTORY_H

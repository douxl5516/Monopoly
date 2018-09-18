#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

class BlockID {
public:
	static const int BLOCK_BLANK = 0;
	static const int BLOCK_A = 1;
	static const int BLOCK_B = 2;
	static const int BLOCK_C = 3;
	static const int BLOCK_D = 4;
	static const int BLOCK_E = 5;
	static const int BLOCK_F = 6;
	static const int BLOCK_BOUNDERY = 7;

	static const int BLOCK_COUNT = 8;
};

class Block
{
protected:
	std::vector<Block*> contents;
public:
	virtual void push(Block* content);
	virtual void show();
	virtual Block* clone();
};
class BlockA :public Block {
public:
	virtual void show();
	virtual Block* clone();
};
class BlockB :public Block {
public:
	virtual void show();
	virtual Block* clone();
};
class BlockC :public Block {
public:
	virtual void show();
	virtual Block* clone();
};
class BlockD :public Block {
public:
	virtual void show();
	virtual Block* clone();
};
class BlockE :public Block {
public:
	virtual void show();
	virtual Block* clone();
};
class BlockF :public Block {
public:
	virtual void show();
	virtual Block* clone();
};
class BlockBlank :public Block {
public:
	virtual void show();
	virtual Block* clone();
};
class BlockBoundary :public Block {
public:
	virtual void show();
	virtual Block* clone();
};

#endif // !BLOCK_H


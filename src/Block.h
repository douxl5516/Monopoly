#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include "Global.h"

class Block
{
public:
	Block();
	virtual ~Block();
	virtual const char* name() const = 0;
	virtual Block * clone() = 0;
	void setPosition(int r, int c);
	int getRow() const { return row; }
	int getCol() const { return col; }
protected:
	int row;
	int col;
};

class MoneyBlock : public Block
{
public:
	MoneyBlock() {}
	virtual ~MoneyBlock() {}
	virtual const char* name() const { return "A"; }
	virtual MoneyBlock * clone() override;
};
class TripBlock : public Block
{
public:
	TripBlock() {}
	virtual ~TripBlock() {}
	virtual const char* name() const { return "B"; }
	virtual TripBlock * clone() override;
};
class BarBlock : public Block
{
public:
	BarBlock() {}
	virtual ~BarBlock() {}
	virtual const char* name() const { return "C"; }
	virtual BarBlock * clone() override;
};
class SlideBlock : public Block
{
public:
	SlideBlock() {}
	virtual ~SlideBlock() {}
	virtual const char* name() const { return "D"; }
	virtual SlideBlock * clone() override;
};

class EBlock : public Block
{
public:
	EBlock() {}
	virtual ~EBlock() {}
	virtual const char* name() const { return "E"; }
	virtual EBlock * clone() override;
};

class FBlock : public Block
{
public:
	FBlock(){}
	virtual ~FBlock() {}
	virtual const char* name() const { return "F"; }
	virtual FBlock * clone() override;
};

class LinkedBlock :public Block
{
public:
	LinkedBlock(int kernelID);
	virtual ~LinkedBlock();
	virtual const char* name() const;
	virtual Block* clone();
	void setNeighbor(int dir, Block * b);
	Block* getNeighbor(int dir);
protected:
	Block * kernel;
	Block * neighbors[DirID::DIR_COUNT];
};

#endif // !BLOCK_H
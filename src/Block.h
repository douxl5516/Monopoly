#ifndef BLOCK_H
#define BLOCK_H
#include <vector>

class Block
{
public:
	Block() {}
	Block(int i,int r,int c,int left,int right,int up,int down);
	virtual ~Block();
	virtual const char* name() const = 0;
	virtual Block * clone() = 0;
	void setPosition(int r, int c);
	int getRow() const { return row; }
	int getCol() const { return col; }
	int getIndex() const { return index; }
	int getUp() const { return up; }
	int getRight() const { return right; }
	int getDown()const { return down; }
	int getLeft() const { return left; }
protected:
	int index;
	int row;
	int col;
	int up,right,down,left;
};

class MoneyBlock : public Block
{
public:
	MoneyBlock() {}
	MoneyBlock(int i, int r, int c, int left, int right, int up, int down);
	virtual ~MoneyBlock() {}
	virtual const char* name() const { return "A"; }
	virtual MoneyBlock * clone() override;
};
class TripBlock : public Block
{
public:
	TripBlock() {}
	TripBlock(int i, int r, int c, int left, int right, int up, int down);
	virtual ~TripBlock() {}
	virtual const char* name() const { return "B"; }
	virtual TripBlock * clone() override;
};
class BarBlock : public Block
{
public:
	BarBlock() {}
	BarBlock(int i, int r, int c, int left, int right, int up, int down);
	virtual ~BarBlock() {}
	virtual const char* name() const { return "C"; }
	virtual BarBlock * clone() override;
};
class SlideBlock : public Block
{
public:
	SlideBlock() {}
	SlideBlock(int i, int r, int c, int left, int right, int up, int down);
	virtual ~SlideBlock() {}
	virtual const char* name() const { return "D"; }
	virtual SlideBlock * clone() override;
};

class EBlock : public Block
{
public:
	EBlock() {}
	EBlock(int i, int r, int c, int left, int right, int up, int down);
	virtual ~EBlock() {}
	virtual const char* name() const { return "E"; }
	virtual EBlock * clone() override;
};

class FBlock : public Block
{
public:
	FBlock(){}
	FBlock(int i, int r, int c, int left, int right, int up, int down);
	virtual ~FBlock() {}
	virtual const char* name() const { return "F"; }
	virtual FBlock * clone() override;
};

#endif // !BLOCK_H


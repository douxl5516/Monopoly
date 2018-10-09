#include <iostream>
#include "Block.h"
using namespace std;

Block::Block(int i, int r, int c, int left, int right, int up, int down)
	:index(i),row(r),col(c),left(left),right(right),up(up),down(down)
{
}

Block::~Block()
{
}

void Block::setPosition(int r, int c)
{
	row = r;
	col = c;
}

MoneyBlock::MoneyBlock(int i, int r, int c, int left, int right, int up, int down)
	:Block(i,r,c,left,right,up,down)
{
}

MoneyBlock* MoneyBlock::clone()
{
	return new MoneyBlock(*this);
}
TripBlock::TripBlock(int i, int r, int c, int left, int right, int up, int down) 
	:Block(i, r, c, left, right, up, down)
{
}
TripBlock* TripBlock::clone()
{
	return new TripBlock(*this);
}
BarBlock::BarBlock(int i, int r, int c, int left, int right, int up, int down) 
	:Block(i, r, c, left, right, up, down)
{
}
BarBlock* BarBlock::clone()
{
	return new BarBlock(*this);
}
SlideBlock::SlideBlock(int i, int r, int c, int left, int right, int up, int down) 
	:Block(i, r, c, left, right, up, down)
{
}
SlideBlock* SlideBlock::clone()
{
	return new SlideBlock(*this);
}
EBlock::EBlock(int i, int r, int c, int left, int right, int up, int down) 
	:Block(i, r, c, left, right, up, down)
{
}
EBlock* EBlock::clone()
{
	return new EBlock(*this);
}

FBlock::FBlock(int i, int r, int c, int left, int right, int up, int down) 
	:Block(i, r, c, left, right, up, down)
{
}

FBlock* FBlock::clone()
{
	return new FBlock(*this);
}



///======================================================================
///  Project:   Richer02
/// FileName:	block.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef BLOCK_H
#define BLOCK_H

#include "global.h"
class Player;


class TripStrategy {
public:
	virtual bool execute(Player* player) = 0;
};

class CommonTripStategy :public TripStrategy {
public:
	virtual bool execute(Player* player);
};

class NervousTripStategy :public TripStrategy {
public:
	virtual bool execute(Player* player);
};

class Block
{
public:
    Block();
    virtual ~Block();
    virtual const char* name() const = 0;
    virtual Block* clone() = 0;
	virtual bool arrive(Player* player) = 0;
    void setPosition(int r, int c) { row = r; col = c;}
    int getRow() const { return row;}
    int getCol() const { return col;}
protected:
    int row;
    int col;
private:
};

class MoneyBlock: public Block
{
public:
    MoneyBlock() {}
    virtual ~MoneyBlock() {}
    virtual const char* name() const { return "A";}
    virtual MoneyBlock* clone() override;
	virtual bool arrive(Player* player);
};
class TripBlock: public Block
{
private:
	static TripStrategy* strategy;
public:
    TripBlock() {}
	virtual ~TripBlock();
    virtual const char* name() const { return "B";}
    virtual TripBlock* clone() override;
	virtual bool arrive(Player* player);
	static void setStrategy(TripStrategy* s);
};
class BarBlock: public Block
{
public:
    BarBlock() {}
    virtual ~BarBlock() {}
    virtual const char* name() const { return "C";}
    virtual BarBlock* clone() override;
	virtual bool arrive(Player* player);
};
class SlideBlock: public Block
{
public:
    SlideBlock() {}
    virtual ~SlideBlock() {}
    virtual const char* name() const { return "D";}
    virtual SlideBlock* clone() override;
	virtual bool arrive(Player* player);
};

class EBlock: public Block
{
public:
    EBlock() {}
    virtual ~EBlock() {}
    virtual const char* name() const { return "E";}
    virtual EBlock* clone() override;
	virtual bool arrive(Player* player);
};

class FBlock: public Block
{
public:
    FBlock() {}
    virtual ~FBlock() {}
    virtual const char* name() const { return "F";}
    virtual FBlock* clone() override;
	virtual bool arrive(Player* player);
};

///--------------------------------
class LinkedBlock:public Block
{
public:
    LinkedBlock(int kernelID);
    virtual ~LinkedBlock();
    virtual const char* name() const;
    virtual Block* clone();
    void setNeighbor(int dir,Block * b);
    Block* getNeighbor(int dir);
	virtual bool arrive(Player* player);
protected:
    Block * kernel;
    Block * neighbors[DirID::DIR_COUNT];
};

#endif // BLOCK_H

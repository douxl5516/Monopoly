///======================================================================
///  Project:   Richer02
/// FileName:	mapimp.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef MAPIMP_H
#define MAPIMP_H
#include <vector>

class Players;
class Block;
class MapImp
{
public:
    MapImp();
    virtual ~MapImp();
    virtual void    show() const;
	virtual void	show(Players* p) const;
    virtual void    addBlock(Block * block);
    virtual Block * getBlock(int index) const;
	int getIndex(pair<int, int> pos);
protected:
    std::vector<Block *> blocks;
};
#endif // MAPIMP_H

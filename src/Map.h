///======================================================================
///  Project:   Richer02
/// FileName:	map.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef MAP_H
#define MAP_H
#include<utility>
using namespace std;
#include "global.h"


class Players;
class MapImp;
class Block;
class Map
{
public:
    Map(MapImp * aImp);
    virtual ~Map();
    void show() const;
	void show(Players* p)const;
    void    addBlock(Block * block);
    Block * getBlock(int index);
	int getIndex(pair<int,int> pos);
    //void    setBlock(int r,int c,Block * block);
    //Block * getBlock(int r,int c) { return blocks[r][c];}
protected:
    MapImp * imp ;
};


#endif // MAP_H

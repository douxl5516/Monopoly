#ifndef MAP_H
#define MAP_H
#include "Global.h"

class Block;
class MapImp;
class Map
{
public:
	Map(MapImp* aImp);
	virtual ~Map();
	void show() const;
	void addBlock(Block * block);
	Block * getBlock(int index);
protected:
	MapImp* imp;
};

#endif // !MAP_H


#ifndef MAP_IMP_H
#define MAP_IMP_H
#include<vector>

class Block;
class MapImp
{
public:
	MapImp();
	virtual ~MapImp();
	virtual void show() const = 0;
	virtual void addBlock(Block*);
	virtual Block* getBlock(int index);
protected:
	std::vector<Block*> blocks;
};

class IndexMapImp :public MapImp {
public:
	virtual void show() const;
};

#endif // !MAP_IMP_H
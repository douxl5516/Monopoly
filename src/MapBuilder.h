#ifndef MAP_BUILDER_H
#define MAP_BUILDER_H

class Block;
class MapBuilder
{
public:
	MapBuilder();
	virtual ~MapBuilder();
	virtual Block* buildBlock(int blockID,int blockIndex,int row,int col,int left,int right,int up,int down);
protected:

private:
};

class EFMapBuilder :public MapBuilder
{
public:
	EFMapBuilder() {}
	virtual ~EFMapBuilder() {}
	virtual Block* buildBlock(int blockID);
};
#endif // !MAP_BUILDER_H
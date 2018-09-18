#ifndef MAP_BUILDER_H
#define MAP_BUILDER_H

class Block;
class MapBuilder
{
protected:
	Block* container;
public:
	virtual Block* buildContainer()=0;
	virtual void buildWall(int n,int blockID)=0;
	virtual void buildPath(int n, int blockID)=0;
	virtual void buildBlock(int blockID)=0;
public:
	Block* getResult();
	virtual ~MapBuilder();
};

class MapBuilderA :public MapBuilder {
	virtual Block* buildContainer();
	virtual void buildWall(int n, int blockID);
	virtual void buildPath(int n, int blockID);
	virtual void buildBlock(int blockID);
};

#endif // !MAP_BUILDER_H
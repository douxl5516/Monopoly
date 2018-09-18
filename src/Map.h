#ifndef MAP_H
#define MAP_H
#include <vector>

class Block;
class MapDirector;
class Map
{
private:
	Block* block;
public:
	Map(MapDirector& director);
	void create(MapDirector& director);
	void show();
};

#endif // !MAP_H


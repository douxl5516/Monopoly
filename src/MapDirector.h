#ifndef MAP_DIRECTOR_H
#define MAP_DIRECTOR_H

class Block;
class MapDirector
{
public:
	virtual Block* buildMap()=0;
};

class MapDirectorA :public MapDirector {
	virtual Block* buildMap();
};


#endif // !MAP_DIRECTOR_H

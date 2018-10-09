#ifndef MAP_DIRECTOR_H
#define MAP_DIRECTOR_H

class Map;
class MapBuilder;

class MapDirector
{
public:
	MapDirector(MapBuilder* aBuidler);
	virtual ~MapDirector();
	virtual void makeMap();
	Map * getMap();
protected:
	MapBuilder* builder = nullptr;
	Map * aMap = nullptr;
};


#endif // MAP_DIRECTOR_H

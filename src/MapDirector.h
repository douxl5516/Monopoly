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
	Map *  aMap = nullptr;
private:
};


class SunMapDirector :public MapDirector
{
public:
	SunMapDirector(MapBuilder* aBuidler);
	virtual ~SunMapDirector() {}
	virtual void makeMap();
};

class LinkedMapDirector :public MapDirector
{
public:
	LinkedMapDirector(MapBuilder* aBuidler);
	virtual ~LinkedMapDirector() {}
	virtual void makeMap();
};

#endif // MAP_DIRECTOR_H

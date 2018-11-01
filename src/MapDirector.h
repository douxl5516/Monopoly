///======================================================================
///  Project:   Richer02
/// FileName:	mapdirector.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef MAPDIRECTOR_H
#define MAPDIRECTOR_H

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


class SunMapDirector:public MapDirector
{
public:
    SunMapDirector(MapBuilder* aBuidler);
    virtual ~SunMapDirector(){}
    virtual void makeMap();
};

class LinkedMapDirector:public MapDirector
{
public:
    LinkedMapDirector(MapBuilder* aBuidler);
    virtual ~LinkedMapDirector(){}
    virtual void makeMap();
};
#endif // MAPDIRECTOR_H

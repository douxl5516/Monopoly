///======================================================================
///  Project:   Richer02
/// FileName:	mapmgr.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "map.h"
#include "mapmgr.h"
#include "mapbuilder.h"
#include "mapdirector.h"

MapMgr* MapMgr::mgr = nullptr;
MapMgr* MapMgr::getMgr()
{
    if(mgr == nullptr) {
        mgr = new MapMgr;
    }
    return mgr;
}
void  MapMgr::releaseMgr()
{
    delete mgr;
    mgr = nullptr;
}


MapMgr::MapMgr()
{
    //ctor
}

MapMgr::~MapMgr()
{
    //dtor
    delete curMap;
}
void MapMgr::createMap()
{
    delete curMap;
    curMap = nullptr;

    //MapBuilder* builder = new MapBuilder;
    //MapDirector* director = new MapDirector(builder);
    MapBuilder* builder = new LinkedMapBuilder;
    MapDirector* director = new LinkedMapDirector(builder);

    director->makeMap();
    curMap = director->getMap();
    delete director;
    delete builder;
}


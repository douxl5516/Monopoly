///======================================================================
///  Project:   Richer02
/// FileName:	mapmgr.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef MAPMGR_H
#define MAPMGR_H


#include "global.h"

class Map;

class MapMgr
{
public:
    static MapMgr* getMgr();
    static void      releaseMgr();
private:
    static MapMgr* mgr;
private:
    MapMgr();
    MapMgr(const MapMgr&);
    MapMgr& operator=(const MapMgr&);
public:
    ~MapMgr();
    void createMap();
    //void setMenuFactory(AbsMenuFactory* pFac);
    //Menu* getMenu(int menuID);
public:
    //void  setCurMenu(int menuID);
    Map* getCurMap()const {return curMap;}
private:
    //Menu* menus[MenuID::MENU_COUNT];
    //AbsMenuFactory* fac = nullptr;
    Map* curMap = nullptr;
};

#endif // MAPMGR_H

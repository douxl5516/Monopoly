///======================================================================
///  Project:   Richer02
/// FileName:	menumgr.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef MENUMGR_H
#define MENUMGR_H

#include "global.h"

class Menu;
class AbsMenuFactory;

class MenuMgr
{
public:
    static MenuMgr* getMgr();
    static void      releaseMgr();
private:
    static MenuMgr* mgr;
private:
    MenuMgr();
    MenuMgr(const MenuMgr&);
    MenuMgr& operator=(const MenuMgr&);
public:
    ~MenuMgr();
    void setMenuFactory(AbsMenuFactory* pFac);
    Menu* getMenu(int menuID);
public:
    void  setCurMenu(int menuID);
    Menu* getCurMenu() {return curMenu;}
private:
    Menu* menus[MenuID::MENU_COUNT];
    AbsMenuFactory* fac = nullptr;
    Menu* curMenu = nullptr;
};

#endif // MENUMGR_H

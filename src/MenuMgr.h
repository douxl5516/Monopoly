#ifndef MENU_MGR_H
#define MENU_MGR_H
#include "Menu.h"
#include "MenuFactory.h"
#include "AbsMenuFactory.h"
#include "Global.h"

class MenuMgr {
private:
	MenuMgr() {}
	MenuMgr(const MenuMgr&) {}
	MenuMgr& operator=(const MenuMgr&) = delete;
public:
	~MenuMgr();
	static MenuMgr* getInstance();
	static Menu* getCurMenu();
	static void release();
private:
	Menu* getMenu(int menuID);
public:
	void setMenuFactory(AbsMenuFactory* pfac);
	void setCurMenu(int menuID);
private:
	static MenuMgr* instance;
	static Menu* curMenu;
	Menu* menus[MenuID::MENU_COUNT];
	AbsMenuFactory* fac;
};
#endif // !MENU_MGR_H

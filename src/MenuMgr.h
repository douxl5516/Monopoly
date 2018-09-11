#ifndef MENU_MGR_H
#define MENU_MGR_H
#include "Menu.h"
#include <map>

class MenuMgr {
public:
	~MenuMgr();
	static MenuMgr* getInstance();
	static Menu* getMenuInstance(int menuID);
private:
	static MenuMgr* instance;
private:
	static Menu* menus[MenuID::MENU_COUNT];
	MenuMgr() {}
	MenuMgr(const MenuMgr&) {}
	MenuMgr& operator=(const MenuMgr&) {}
};
#endif // !MENU_MGR_H

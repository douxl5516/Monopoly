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
	MenuMgr& operator=(const MenuMgr&) {}
public:
	~MenuMgr();
	static MenuMgr* getInstance();
	static Menu* getCurMenu();//1
	static void release();
private:
	Menu* getMenu(int menuID);
public:
	void setMenuFactory(AbsMenuFactory* pfac);
	void setCurMenu(int menuID);//2
private:
	static MenuMgr* instance;
	static Menu* curMenu;//3,�ͼ����������ϸ���˵�����ǵ���ģʽ
	Menu* menus[MenuID::MENU_COUNT];
	AbsMenuFactory* fac;
};
#endif // !MENU_MGR_H

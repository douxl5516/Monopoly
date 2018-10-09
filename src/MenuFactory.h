#ifndef MENU_FACTORY_H
#define MENU_FACTORY_H
#include "AbsMenuFactory.h"
class Menu;

class MenuFactory :public AbsMenuFactory
{
public:
	MenuFactory();
	virtual ~MenuFactory();
	virtual Menu * createMenu(int menuID);
};

class MyMenuFactory :public AbsMenuFactory
{
public:
	MyMenuFactory();
	virtual ~MyMenuFactory();
	virtual Menu * createMenu(int menuID);
};


#endif // !MENU_FACTORY_H

#ifndef ABS_MENU_FACTORY_H
#define ABS_MENU_FACTORY_H

class Menu;
class AbsMenuFactory
{
public:
	AbsMenuFactory();
	virtual ~AbsMenuFactory();
	virtual Menu* createMenu(int menuID) = 0;
};

#endif // ABS_MENU_FACTORY_H

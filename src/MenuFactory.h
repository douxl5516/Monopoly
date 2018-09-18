#ifndef MENU_FACTORY
#define MENU_FACTORY

class Menu;

class AbstractMenuFactory {
public:
	virtual Menu* create(int id) = 0;
};

class MenuFactory :public AbstractMenuFactory {
public:
	virtual Menu* create(int id);
protected:
	virtual Menu* createMainMenu();
	virtual Menu* createPlayersMenu();
	virtual Menu* createLoadMenu();
	virtual Menu* createSaveMenu();
	virtual Menu* createOptionMenu();
	virtual Menu* createVolumeMenu();
	virtual Menu* createResolutionMenu();
};

#endif // !MENU_FACTORY

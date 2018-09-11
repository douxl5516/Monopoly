#ifndef GAME_H
#define GAME_H

class Menu;
class Game
{
public:
	void init();
	void run();
	void term();
public:
	void setCurMenu(int menuID);
private:
	Menu* curMenu = nullptr;
};

#endif // GAME_H

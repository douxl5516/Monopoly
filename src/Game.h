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
	static Game* getInstance();
private:
	static Game* instance;
	Menu* curMenu = nullptr;
private:
	Game() {}
	Game(const Game&) {}
	Game& operator=(const Game&) {}
};

#endif // GAME_H

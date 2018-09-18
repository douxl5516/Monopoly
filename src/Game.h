#ifndef GAME_H
#define GAME_H

class Menu;
class Map;
class Game
{
public:
	void init();
	void run();
	void term();
	void play();
public:
	void setPlayers(int n);
	void loadFrom(int n);
	void saveTo(int n);
	void setVolume(int n);
	void setResolution(int n);
	void setCurMenu(int menuID);
	static Game* getInstance();
private:
	static Game* instance;
	Map* curMap = nullptr;
	Menu* curMenu = nullptr;
	int players;
	int volume;
	int resolution;
private:
	Game() {}
	Game(const Game&) {}
	Game& operator=(const Game&) {}
};

#endif // GAME_H

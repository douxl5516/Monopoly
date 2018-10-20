#ifndef GAME_H
#define GAME_H
#include <vector>

class Menu;
class Map;
class Player;
class Game
{
public:
	void init();
	void run();
	void term();
	void play();
	static Game* getInstance();
	static void release();
public:
	void setPlayers(int n);
	void loadFrom(int n);
	void saveTo(int n);
	void setVolume(int n);
	void setResolution(int n);

	void setCurMenu(int menuID);
private:
	static Game* instance;
	std::vector<Player*> playerList;
	Player* curPlayer;
	int players;
	int playerIdx;
	int volume;
	int resolution;
private:
	Game() {}
	Game(const Game&) {}
	Game& operator=(const Game&) = delete;
};

#endif // GAME_H

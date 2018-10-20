#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
private:
	int type;
public:
	Player(int playerID);
	int getType();
	virtual ~Player();
	virtual bool play() = 0;
};

class HumanPlayer :public Player {
public:
	HumanPlayer();
	virtual bool play();
};

class AutoPlayer :public Player {
public:
	AutoPlayer();
	virtual bool play();
};


#endif // !PLAYER_H
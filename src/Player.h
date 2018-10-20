#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	virtual ~Player();
	virtual bool play() = 0;
};

class HumanPlayer :public Player {
public:
	virtual bool play();
};

class AutoPlayer :public Player {
public:
	virtual bool play();
};


#endif // !PLAYER_H
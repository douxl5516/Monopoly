#ifndef PLAYER_STATE_H
#define PLAYER_STATE_H

class Player;
class PlayerState
{
public:
	PlayerState(int _round=0);
	virtual ~PlayerState();
	virtual void execute(Player* p)=0;
protected:
	int round;
};

class HumanCommonState :public PlayerState {
public:
	HumanCommonState();
	virtual void execute(Player* p);
};

class AutoCommonState :public PlayerState {
public:
	AutoCommonState();
	virtual void execute(Player* p);
};

class FlyState :public PlayerState {
public:
	FlyState(int round = 2);
	virtual void execute(Player* p);
};

class FreezeState :public PlayerState {
public:
	FreezeState(int round = 3);
	virtual void execute(Player* p);
};

class HurtState :public PlayerState {
public:
	HurtState(int round = 2);
	virtual void execute(Player* p);
};

class LuckState :public PlayerState {
public:
	LuckState(int round = 3);
	virtual void execute(Player* p);
};

class ExFlyState :public PlayerState {
public:
	ExFlyState(int round = 2);
	virtual void execute(Player* p);
};

class MacroState :public PlayerState {
private:
	PlayerState* prevState;
	PlayerState* newState;
public:
	MacroState(PlayerState* _prev,PlayerState* _new);
	virtual ~MacroState();
	virtual void execute(Player* p);
};
#endif // !PLAYER_STATE_H
///======================================================================
///  Project:   Richer03
/// FileName:	player.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <deque>
#include <map>
#include <vector>
#include "Iterator.h"
#include "global.h"
using namespace std;

class Player;
class Players;
class PlayerState;
class DirStrategy;
class Block;
class Iterator;

class PlayersCppIterator :public CppIterator {
private:
	deque<Player*> players_cpy;
	const Players* container;
	int cnt;
public:
	PlayersCppIterator(Players* p);
	virtual void first();
	virtual void next();
	virtual bool isLast() const;
	virtual void * current();
	virtual int count() const;
};
class PlayersJavaIterator :public JavaIterator {
private:
	deque<Player*> players_cpy;
	const Players* container;
	int cnt;
public:
	PlayersJavaIterator(Players* p);
	virtual void* next();
	virtual bool hasNext() const;
	virtual int count() const;
};

class Players
{
public:
    static Players& getPlayers();
private:
    Players();
    Players(const Players&);
    Players& operator=(const Players&) = delete;
public:
    virtual ~Players();
    virtual void play(bool showed = true);
	map<pair<int, int>, int> getPos();
	CppIterator* createCppIterator();
	JavaIterator* createJavaIterator();
	Player* getCurPlayer() { return curPlayer; }
	Player* getPlayerByName(string name);
	void displayCurInfo();
private:
	deque<Player*> players;  
	Player* curPlayer;
	vector<CppIterator*> cppItReleaseList;
	vector<JavaIterator*> javaItReleaseList;
	friend class PlayersCppIterator;
	friend class PlayersJavaIterator;
};


class Player
{
public:
    Player() {}
	virtual ~Player();
	virtual bool play(Players* p, bool showed = true) = 0;
public:
    const string& name() const { return strName;}
    void setName(const string& str);
	void setPos(pair<int, int> pos);
	pair<int, int> getPos();
	void setDirection(int dir);
	int getDirection();
	void setMoney(int m);
	int getMoney();
	PlayerState* getState();
	void setState(PlayerState* state);
	void setAct(bool act);
	bool getAct();
	bool isExFly();
	void setExFly(bool _exFly);
public:
	virtual bool go();
	void ApplyRobCard(Player * target);
	void ApplyFlyCard(Player * target);
	void ApplyFreezeSpeel(Player * target);
	void ApplyMeanCard();
	void ApplyReturnSpell(Player * target);
	void ApplyHurtSpell(Player * target);
	void ApplyLuckCard(Player * target);
	void ApplyExFlyCard(Player * target);
	void ApplySuperCard(Player * target);
protected:
    string strName;
	int money;
	int direction;
	bool actThisRound;
	bool exFly;
	pair<int, int> curPos;
	DirStrategy* curStrategy;
	PlayerState* curState;
};

class AutoPlayer: public Player
{
public:
    AutoPlayer() {}
    virtual ~AutoPlayer() {}
    virtual bool play(Players* p,bool showed = true);
};
class HumanPlayer: public Player
{
public:
    HumanPlayer() {}
    virtual ~HumanPlayer() {}
    virtual bool play(Players* p,bool showed = true);
};

class DirStrategy{
public:
	virtual int getDir(Block* curBlock,vector<int> dirs,int inDir=DirID::DIR_NONE)=0;
};
class DirStrategyIndir4Dirs :public DirStrategy {
public:
	virtual int getDir(Block* curBlock,vector<int> dirs, int inDir = DirID::DIR_NONE);
};
class DirStrategyIndir3Dirs :public DirStrategy {
public:
	virtual int getDir(Block* curBlock,vector<int> dirs, int inDir = DirID::DIR_NONE);
};
class DirStrategyIndir2Dirs :public DirStrategy {
public:
	virtual int getDir(Block* curBlock, vector<int> dirs, int inDir = DirID::DIR_NONE);
};
class DirStrategyIndir1Dir :public DirStrategy {
public:
	virtual int getDir(Block* curBlock, vector<int> dirs, int inDir = DirID::DIR_NONE);
};
class DirStrategyNoIndir4Dirs :public DirStrategy {
public:
	virtual int getDir(Block* curBlock, vector<int> dirs, int inDir = DirID::DIR_NONE);
};
class DirStrategyNoIndir3Dirs :public DirStrategy {
public:
	virtual int getDir(Block* curBlock, vector<int> dirs, int inDir = DirID::DIR_NONE);
};
class DirStrategyNoIndir2Dirs :public DirStrategy {
public:
	virtual int getDir(Block* curBlock, vector<int> dirs, int inDir = DirID::DIR_NONE);
};
class DirStrategyNoIndir1Dir :public DirStrategy {
public:
	virtual int getDir(Block* curBlock, vector<int> dirs, int inDir = DirID::DIR_NONE);
};

#endif // PLAYER_H

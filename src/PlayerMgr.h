#ifndef PLAYER_MGR_H
#define PLAYER_MGR_H


class Player;
class PlayerMgr
{
private:
	PlayerMgr();
	PlayerMgr(const PlayerMgr&) {}
	PlayerMgr& operator=(const PlayerMgr&) = delete;
public:
	~PlayerMgr();
	static PlayerMgr* getInstance();
	static void release();
public:
	void setCurPlayer(Player* player);
	bool Do();
private:
	static PlayerMgr* instance;
	Player* curPlayer;
	int curPlayerIdx;
	static Player* players[3];
};


#endif // !PLAYER_MGR_H
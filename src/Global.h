#ifndef GLOBAL_H
#define GLOBAL_H

class DirID
{
public:
	static const int DIR_NONE = 0;
	static const int DIR_LEFT = 1;
	static const int DIR_RIGHT = 2;
	static const int DIR_UP = 3;
	static const int DIR_DOWN = 4;
	static const int DIR_COUNT = 5;
};

class MenuID
{
public:
	static const int MAIN_MENU = 0;
	static const int PLAYERS_MENU = 1;
	static const int LOAD_MENU = 2;
	static const int SAVE_MENU = 3;
	static const int OPTION_MENU = 4;
	static const int VOLUME_MENU = 5;
	static const int RESOLUTION_MENU = 6;
	static const int PLAY_MENU = 7;

	static const int MENU_COUNT = 8;
};

class PlayerID
{
public:
	static const int HUMAN_PLAYER = 0;
	static const int AUTO_PLAYER = 1;

	static const int PLAYER_COUNT = 2;
};

class BlockID
{
public:
	static const int NONE_BLOCK = 0;
	static const int MONEY_BLOCK = 1;
	static const int TRIP_BLOCK = 2;
	static const int BAR_BLOCK = 3;
	static const int SLIDE_BLOCK = 4;

	static const int BLOCK_COUNT = 5;

	static const int BLOCK_ROWS = 5;
	static const int BLOCK_COLS = 5;
};

#endif // GLOBAL_H
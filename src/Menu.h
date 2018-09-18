#ifndef MENU_H
#define MENU_H

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

	static const int MENU_COUNT = 7;
};

class Game;
class Menu
{
public:
	Menu() {}
	virtual ~Menu() {}
	bool process();
protected:
	virtual void show() const = 0;
	virtual int  getChoice() const;
	virtual bool doChoice(int choice) = 0;
};
///------���˵�--------------------------------
class MainMenu : public Menu
{
protected:
	virtual void show() const;
	virtual bool doChoice(int choice);
};
///------��������˵�--------------------------------
class PlayersMenu : public Menu
{
protected:
	virtual void show() const;
	virtual bool doChoice(int choice);
};
///-------����˵�----------------------------------
class LoadMenu : public Menu
{
protected:
	virtual void show() const;
	virtual bool doChoice(int choice);
};
///-------����˵�----------------------------------
class SaveMenu : public Menu
{
protected:
	virtual void show() const;
	virtual bool doChoice(int choice);
};
///-------ѡ��˵�----------------------------------
class OptionMenu : public Menu
{
protected:
	virtual void show() const;
	virtual bool doChoice(int choice);
};
///-------����ѡ��˵�----------------------------------
class VolumeMenu : public Menu
{
protected:
	virtual void show() const;
	virtual bool doChoice(int choice);
};
///-------�ֱ���ѡ��˵�----------------------------------
class ResolutionMenu : public Menu
{
protected:
	virtual void show() const;
	virtual bool doChoice(int choice);
};
#endif // MENU_H

#ifndef MENU_H
#define MENU_H

class Game;
class OutDevice;
class Menu
{
public:
	Menu() {}
	virtual ~Menu() {}
	virtual bool process();
	virtual void show(OutDevice* out) const = 0;
	virtual int  getChoice() const;
	virtual bool doChoice(int choice) = 0;
};
///------主菜单--------------------------------
class MainMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///------玩家人数菜单--------------------------------
class PlayersMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------载入菜单----------------------------------
class LoadRecordMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------保存菜单----------------------------------
class SaveRecordMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------选项菜单----------------------------------
class OptionMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------音量选项菜单----------------------------------
class VolumeMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------分辨率选项菜单----------------------------------
class ResolutionMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------游戏菜单----------------------------------------
class PlayMenu :public Menu {
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};


class MenuDecorator :public Menu{
public:
	~MenuDecorator();
	MenuDecorator(Menu* p);
	Menu* menu;

	virtual bool process();
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};

class MusicMenuDecorator :public MenuDecorator {
public:
	MusicMenuDecorator(Menu* p);
	virtual bool process();
protected:
	void playMusic();
	void closeMusic();
};
#endif // MENU_H

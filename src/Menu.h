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
///------���˵�--------------------------------
class MainMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///------��������˵�--------------------------------
class PlayersMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------����˵�----------------------------------
class LoadRecordMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------����˵�----------------------------------
class SaveRecordMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------ѡ��˵�----------------------------------
class OptionMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------����ѡ��˵�----------------------------------
class VolumeMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------�ֱ���ѡ��˵�----------------------------------
class ResolutionMenu : public Menu
{
protected:
	virtual void show(OutDevice* out) const;
	virtual bool doChoice(int choice);
};
///-------��Ϸ�˵�----------------------------------------
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

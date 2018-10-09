#ifndef MENU_H
#define MENU_H

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

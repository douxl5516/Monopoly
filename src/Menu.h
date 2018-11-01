///======================================================================
///  Project:   Richer02
/// FileName:	menu.h
///     Desc:
///   Author:	Chen Wei
///  History:
///======================================================================
#ifndef MENU_H
#define MENU_H

class OutDevice;
class Game;
class Menu
{
public:
    Menu() {}
    virtual ~Menu() {}
    virtual bool process(const OutDevice& dev) ;
protected:
    virtual void show(const OutDevice& dev) const = 0;
    virtual int  getChoice() const;
    virtual bool doChoice(int choice, const OutDevice& dev) = 0;
};
///------主菜单--------------------------------
class MainMenu: public Menu
{
protected:
    virtual void show(const OutDevice& dev) const;
    virtual bool doChoice(int choice, const OutDevice& dev);
};
///------玩家人数菜单--------------------------------
class PlayersMenu: public Menu
{
protected:
    virtual void show(const OutDevice& dev) const;
    virtual bool doChoice(int choice, const OutDevice& dev);
};
///-------载入菜单----------------------------------
class LoadingMenu: public Menu
{
protected:
    virtual void show(const OutDevice& dev) const;
    virtual bool doChoice(int choice, const OutDevice& dev);
};
///-------保存菜单----------------------------------
class SaveMenu: public Menu
{
protected:
    virtual void show(const OutDevice& dev) const;
    virtual bool doChoice(int choice, const OutDevice& dev);
};
///-------选项菜单----------------------------------
class OptionMenu: public Menu
{
protected:
    virtual void show(const OutDevice& dev) const;
    virtual bool doChoice(int choice, const OutDevice& dev);
};
///-------音量选项菜单----------------------------------
class VolumeMenu: public Menu
{
protected:
    virtual void show(const OutDevice& dev) const;
    virtual bool doChoice(int choice, const OutDevice& dev);
};
///-------分辨率选项菜单----------------------------------
class ResolutionMenu: public Menu
{
protected:
    virtual void show(const OutDevice& dev) const;
    virtual bool doChoice(int choice, const OutDevice& dev);
};
///-------Play菜单----------------------------------
class PlayMenu: public Menu
{
protected:
    virtual void show(const OutDevice& dev) const;
    virtual bool doChoice(int choice, const OutDevice& dev);
};


///-----------------------------------------
///
///-----------------------------------------
class ProcessDecorator: public Menu
{
public:
    ProcessDecorator(Menu& m): menu(m) {}
    virtual ~ProcessDecorator() { delete &menu;}
    virtual bool process(const OutDevice& dev) ;
protected:
    virtual void show(const OutDevice& dev) const ;
    virtual bool doChoice(int choice, const OutDevice& dev);
private:
    Menu& menu;
};
class SoundDecorator: public ProcessDecorator
{
public:
    SoundDecorator(Menu& m): ProcessDecorator(m) {}
    virtual ~SoundDecorator() {}
    virtual bool process(const OutDevice& dev) ;
private:
    void startSound();
    void endSound();
};
class TitleDecorator: public ProcessDecorator
{
public:
    TitleDecorator(Menu& m): ProcessDecorator(m) {}
    virtual ~TitleDecorator() {}
    virtual bool process(const OutDevice& dev) ;
private:
    void drawTitle(const OutDevice& dev);
};

#endif // MENU_H

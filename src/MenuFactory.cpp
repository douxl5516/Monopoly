///======================================================================
///  Project:   Richer02
/// FileName:	menufactory.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "menu.h"
#include "menufactory.h"

MenuFactory::MenuFactory()
{
    //ctor
}

MenuFactory::~MenuFactory()
{
    //dtor
}
Menu* MenuFactory::createMenu(int menuID)
{
    if(menuID == MenuID::MAIN_MENU) {
        return new TitleDecorator(*new SoundDecorator(*new MainMenu));
    } else if(menuID == MenuID::PLAYERS_MENU) {
        return new SoundDecorator(*new PlayersMenu);
    } else if(menuID == MenuID::LOAD_MENU) {
        return new SoundDecorator(*new LoadingMenu);
    } else if(menuID == MenuID::SAVE_MENU) {
        return new SoundDecorator(*new SaveMenu);
    } else if(menuID == MenuID::OPTION_MENU) {
        return new SoundDecorator(*new OptionMenu);
    } else if(menuID == MenuID::VOLUME_MENU) {
        return new SoundDecorator(*new VolumeMenu);
    } else if(menuID == MenuID::RESOLUTION_MENU) {
        return new SoundDecorator(*new ResolutionMenu);
    } else if(menuID == MenuID::PLAY_MENU) {
        return new SoundDecorator(*new PlayMenu);
    } else {
        return new SoundDecorator(*new MainMenu);
    }
}
///-----------------------------------------

MyMenuFactory::MyMenuFactory()
{
    //ctor
}

MyMenuFactory::~MyMenuFactory()
{
    //dtor
}
Menu* MyMenuFactory::createMenu(int menuID)
{
    if(menuID == MenuID::MAIN_MENU) {
        return new MainMenu;
    } else if(menuID == MenuID::PLAYERS_MENU) {
        return new PlayersMenu;
    } else if(menuID == MenuID::LOAD_MENU) {
        return new LoadingMenu;
    } else if(menuID == MenuID::SAVE_MENU) {
        return new SaveMenu;
    } else if(menuID == MenuID::OPTION_MENU) {
        return new OptionMenu;
    } else if(menuID == MenuID::VOLUME_MENU) {
        return new VolumeMenu;
    } else if(menuID == MenuID::RESOLUTION_MENU) {
        return new ResolutionMenu;
    } else {
        return new MainMenu;
    }
}

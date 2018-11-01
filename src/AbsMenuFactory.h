///======================================================================
///  Project:   Richer02
/// FileName:	absmenufactory.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef ABSMENUFACTORY_H
#define ABSMENUFACTORY_H

class Menu;
class AbsMenuFactory
{
public:
    AbsMenuFactory();
    virtual ~AbsMenuFactory();
    virtual Menu* createMenu(int menuID) = 0;
};

#endif // ABSMENUFACTORY_H

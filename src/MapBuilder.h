///======================================================================
///  Project:   Richer02
/// FileName:	mapbuilder.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef MAPBUILDER_H
#define MAPBUILDER_H

class Block;
class MapBuilder
{
public:
    MapBuilder();
    virtual ~MapBuilder();
    virtual Block* buildBlock(int blockID);
protected:

private:
};

class EFMapBuilder: public MapBuilder
{
public:
    EFMapBuilder() {}
    virtual ~EFMapBuilder() {}
    virtual Block* buildBlock(int blockID);
};

///---------------------------
class LinkedMapBuilder: public MapBuilder
{
public:
    LinkedMapBuilder() {}
    virtual ~LinkedMapBuilder() {}
    virtual Block* buildBlock(int blockID);
};
#endif // MAPBUILDER_H

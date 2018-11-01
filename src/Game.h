///======================================================================
///  Project:   Richer02
/// FileName:	game.h
///     Desc:
///   Author:	Chen Wei
///  History:
///======================================================================
#ifndef GAME_H
#define GAME_H

class Game
{
public:
    static Game* getGame();
    static void  releaseGame();
private:
    static Game* game;
private:
    Game() { }
    Game(const Game&);
    Game& operator=(const Game&);
public:
    void init();
    void run();
    void term();
};

#endif // GAME_H

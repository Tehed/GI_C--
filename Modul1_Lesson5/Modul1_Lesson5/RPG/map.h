#ifndef MAP_H
#define MAP_H

#include "monster.h";


class Map
{
public:
    Map();

    int getPlayerXPos();
    int getPlayerYPos();
    void movePlayer();
    Monster* checkRandomEncounter();
    void printPlayerPos();

private:
    int mPlayerXPos;
    int mPlayerYPos;
};

#endif
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>

#include "Plane.h"

class Player:public Plane
{
public:
    Player();
    void moveup();
    void movedown();
    void moveleft();
    void moveright();
};

#endif // PLAYER_H_INCLUDED

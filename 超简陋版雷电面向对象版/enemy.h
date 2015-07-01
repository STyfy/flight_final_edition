#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Plane.h"

class Enemy:public Plane{
public:
    Enemy();
    void heartBeat();
    void hit();
    bool needClear();
    bool isDead();
private:
    int state=0;
};

#endif // ENEMY_H_INCLUDED

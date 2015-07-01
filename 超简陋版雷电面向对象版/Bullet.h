#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Sprite.h"

class Bullet:public Sprite{
public:
    Bullet(float x,float y);
    void heartBeat();
};


#endif // BULLET_H_INCLUDED

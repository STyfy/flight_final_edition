#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Sprite.h"
#include "Gun.h"

#include <iostream>
using std::cout;
using std::endl;

class Plane:public Sprite
{
protected:
    Gun gun;
public:
    void fire()
    {
       this->gun.fire();
    }

};

#endif // PLANE_H_INCLUDED

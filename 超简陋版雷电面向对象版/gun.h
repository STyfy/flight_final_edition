#ifndef GUN_H_INCLUDED
#define GUN_H_INCLUDED

#include <iostream>

#include <SFML/Graphics.hpp>

class Plane;

class Gun
{
private:
    sf::Vector2f getPosition();
    Plane* owner;
public:
    void setOwner(Plane * owner);
    void fire();

};


#endif // GUN_H_INCLUDED

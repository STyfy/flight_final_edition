#include "Plane.h"
#include "Gun.h"
#include "Sky.h"
#include "Bullet.h"

void Gun::fire()
{
    sf::Vector2f pos=((this->owner)->getPosition());
    Bullet* bullet=new Bullet(pos.x+15,pos.y+30);
    Sky::getInstance()->add(bullet);
    Sky::getInstance()->add_Bullet(bullet);
}

sf::Vector2f Gun::getPosition()
{
    sf::Vector2f ff;
    return ff;
}

void Gun::setOwner(Plane * owner)
{
    this->owner = owner;
}

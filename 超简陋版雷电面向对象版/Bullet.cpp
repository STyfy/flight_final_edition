#include "Bullet.h"
#include "Texture.h"

Bullet::Bullet(float x,float y)
{
    this->setTexture(Texture::bullet_texture);

    this->setPosition(x, y);
}

void Bullet::heartBeat()
{
    this->move(0,-10);
}

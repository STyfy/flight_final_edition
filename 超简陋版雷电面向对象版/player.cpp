#include "player.h"
#include "Texture.h"

Player::Player()
{
    this->setTexture(Texture::player_texture);
    this->setPosition(180, 600);
    this->gun.setOwner(this);
}

void Player::moveleft()
{
    this->move(-10,0);
}

void Player::moveright()
{
    this->move(10,0);
}

void  Player::moveup()
{
    this->move(0,-10);
}

void  Player::movedown()
{
    this->move(0,10);
}

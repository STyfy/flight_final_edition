#include "Enemy.h"

#include "Texture.h"
#include "Sound.h"
#include "going.h"

#include <random>

#include <iostream>
using namespace std;

Enemy::Enemy()
{
    this->setTexture(Texture::enemy_texture);
    uniform_int_distribution<unsigned> u(0,480);
    std::default_random_engine random_engine;
    this->setPosition(u(Game::random_engine), 20);
    this->gun.setOwner(this);
}

void Enemy::heartBeat()
{
    switch(this->state)
    {
        case 0:
            this->move(0,10);
            break;
        case 1:
            this->setTexture(Texture::enemy_down_2);
            this->state++;
            break;
        case 2:
            this->setTexture(Texture::enemy_down_3);
            this->state++;
            break;
        case 3:
            this->setTexture(Texture::enemy_down_4);
            this->state++;
            break;
        default:;
    }
}

void Enemy::hit()
{
    this->state = 1;
    this->setTexture(Texture::enemy_down_1);
    Sound::ENEMY_DOWN.play();
}

bool Enemy::needClear()
{
    return this->state == 4;
}

bool Enemy::isDead()
{
    return this->state != 0;
}

#include "Sprite.h"
#include "Sky.h"

void Sprite::draw(){
    Sky::getInstance()->getWindow()->draw(*this);
}

bool Sprite::intersects(Sprite* other){
    bool t = this->getGlobalBounds().intersects(other->getGlobalBounds());
    return t;
}

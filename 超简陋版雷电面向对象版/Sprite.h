#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <iostream>

#include <SFML/Graphics.hpp>

/*using namespace sf;*/  //������namespace�����

//�ع�Sprite�࣬�����Ҫ�õĺ���
class Sprite:public sf::Sprite{
public:
    virtual void heartBeat(){};
    void draw();
    bool intersects(Sprite* other);
};


#endif // SPRITE_H_INCLUDED

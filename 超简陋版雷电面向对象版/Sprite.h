#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <iostream>

#include <SFML/Graphics.hpp>

/*using namespace sf;*/  //这里用namespace会混淆

//重构Sprite类，添加需要用的函数
class Sprite:public sf::Sprite{
public:
    virtual void heartBeat(){};
    void draw();
    bool intersects(Sprite* other);
};


#endif // SPRITE_H_INCLUDED

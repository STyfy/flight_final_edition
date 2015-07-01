#ifndef SKY_H_INCLUDED
#define SKY_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Sprite.h"
#include "Enemy.h"
#include "Bullet.h"

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Sky
{
private:
    Sky();
    sf::RenderWindow* window;
    unordered_set<Sprite * > sprites;
    unordered_set<Enemy * >  enemies;
    unordered_set<Bullet * > myBullets;
    sf::Sprite* background=nullptr;
    static Sky* instance;
    void clear();
    void collision();
    void createEnemies();

public:
    static Sky* getInstance();
    sf::RenderWindow* getWindow()
    {
        return this->window;
    }
    void add(Sprite *);
    void add_Bullet(Bullet *);
    void refresh();
};

#endif // SKY_H_INCLUDED

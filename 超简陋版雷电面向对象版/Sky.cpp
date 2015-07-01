#include "Sky.h"
#include "Enemy.h"

#include "Texture.h"

Sky* Sky::instance = nullptr;

Sky::Sky()
{
    this->window = new sf::RenderWindow(sf::VideoMode(480, 800), L"fighting");

    // Set the Icon
    sf::Image icon;
    if (icon.loadFromFile("image/shoot.png"))
    {
        this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }

    // create the background
    this->background = new sf::Sprite(Texture::sky_texture);
}

void Sky::add(Sprite* sprite)
{
    this->sprites.insert(sprite);
}

void Sky::add_Bullet(Bullet * bullet)
{
    this->myBullets.insert(bullet);
}

void Sky::refresh()
{
    this->window->draw(*this->background);
    this->clear();
    this->collision();
    this->createEnemies();
    for(auto &sprite : this->sprites)
    {
        sprite->heartBeat();
        this->window->draw(*sprite);
    }
    this->window->display();
}

void Sky::clear()
{
    for(auto it_enemy= this->enemies.begin();it_enemy!=this->enemies.end();)
    {
        if((*it_enemy)->needClear())
        {
            delete *it_enemy;
            this->sprites.erase(*it_enemy);

            it_enemy = (this->enemies).erase(it_enemy);
        }
    else
        {
            ++it_enemy;
        }
    }
}
void Sky::collision()
{
    for(auto it_enemy= this->enemies.begin();it_enemy!=this->enemies.end();++it_enemy)
        {
        if((*it_enemy)->isDead()) continue;

        for(auto it_bullet= this->myBullets.begin();it_bullet!=this->myBullets.end();++it_bullet)
        {
            if((*it_enemy)->intersects(*it_bullet))
            {
                delete *it_bullet;
                this->sprites.erase(*it_bullet);
                (this->myBullets).erase(it_bullet);

                (*it_enemy)->hit();
                break;
            }
        }
    }
}

void Sky::createEnemies()
{
    static int count=0;


    if(++count>=10)
    {
        Enemy* enemy = new Enemy;
        this->sprites.insert(enemy);
        this->enemies.insert(enemy);
        count = 0;
    }
}

Sky* Sky::getInstance()
{
    if(!instance)
    {
        instance = new Sky;
    }
    return instance;
}

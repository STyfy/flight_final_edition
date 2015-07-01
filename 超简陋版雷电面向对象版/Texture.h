#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Texture{
public:
    static sf::Texture player_texture;
    static sf::Texture enemy_texture;
    static sf::Texture enemy_down_1;
    static sf::Texture enemy_down_2;
    static sf::Texture enemy_down_3;
    static sf::Texture enemy_down_4;
    static sf::Texture bullet_texture;
    static sf::Texture sky_texture;
    static void load();
};

#endif // TEXTURE_H_INCLUDED

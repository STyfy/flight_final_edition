#include "Texture.h"

sf::Texture Texture::player_texture;
sf::Texture Texture::enemy_texture;
sf::Texture Texture::enemy_down_1;
sf::Texture Texture::enemy_down_2;
sf::Texture Texture::enemy_down_3;
sf::Texture Texture::enemy_down_4;

sf::Texture Texture::bullet_texture;

sf::Texture Texture::sky_texture;

void Texture::load()
{


    player_texture.loadFromFile("image/shoot.png", sf::IntRect(0, 99, 102, 126));

    enemy_texture.loadFromFile("image/shoot.png", sf::IntRect(534, 612, 57, 43));
    enemy_down_1.loadFromFile("image/shoot.png", sf::IntRect(267, 347, 57, 51));
    enemy_down_2.loadFromFile("image/shoot.png", sf::IntRect(873, 697, 57, 51));
    enemy_down_3.loadFromFile("image/shoot.png", sf::IntRect(267, 296, 57, 51));
    enemy_down_4.loadFromFile("image/shoot.png", sf::IntRect(930, 697, 57, 51));

    bullet_texture.loadFromFile("image/shoot.png", sf::IntRect(1004, 987, 9, 21));

    sky_texture.loadFromFile("image/background.png");
}

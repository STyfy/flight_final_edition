#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Sky.h"
#include "Texture.h"
#include "player.h"
#include "Sound.h"


int main()
{
    Texture::load();
    Sound::load();

    Sky* sky = Sky::getInstance();
    sf::RenderWindow* window = sky->getWindow();

    Sound::BACK_GROUND.play();


    Player  player;
    sky->add(&player);


    while (window->isOpen())
    {

        sf::Event event;
        while (window->pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window->close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
            {
                player.moveleft();
            }


            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            {
                player.moveright();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
            {
                player.movedown();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                player.fire();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            {
                player.moveup();
            }
        }

        sky->refresh();
    }

    return EXIT_SUCCESS;
}

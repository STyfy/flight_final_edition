#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include <SFML/Audio.hpp>


class Sound{
public:
    static sf::Music BACK_GROUND;
    static sf::Music ENEMY_DOWN;

    static void load();
};


#endif // SOUND_H_INCLUDED

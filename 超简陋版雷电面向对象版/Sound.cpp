#include "Sound.h"

sf::Music Sound::BACK_GROUND;
sf::Music Sound::ENEMY_DOWN;

void Sound::load(){
    BACK_GROUND.openFromFile( "sound/game_music.ogg");
    ENEMY_DOWN.openFromFile("sound/enemy1_down.ogg");
}

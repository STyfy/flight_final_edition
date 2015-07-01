#ifndef GOING_H_INCLUDED
#define GOING_H_INCLUDED

#include <random>
#include <ctime>

class Game{
public:
    static Game* getInstance();
    static std::default_random_engine random_engine;
private:
    static Game* instance;
};

#endif // GOING_H_INCLUDED

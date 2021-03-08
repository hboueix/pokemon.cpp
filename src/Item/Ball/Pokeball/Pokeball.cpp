#ifndef POKEBALL_INCLUDED
#define POKEBALL_INCLUDED

#include "pokeball.h"
// #include "../Ball.cpp"

Pokeball::Pokeball():Ball()  {
    name = "Pokeball";
    description = "description for pokeball";
    ballRate = 1;
    prix = 200;
}

Pokeball::~Pokeball() {

}

bool Pokeball::use(Pokemon* pokemon) const {
    int ChanceOfSuccess = (1-(2/3)*(pokemon->getHP() / pokemon->getMaxHP())) * pokemon->getCaptureRate() * ballRate;
    int random = rand() % 256;
    if (random <= ChanceOfSuccess) 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

#endif
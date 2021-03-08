#ifndef SUPERBALL_INCLUDED
#define SUPERBALL_INCLUDED

#include "superball.h"
// #include "../Ball.cpp"

Superball::Superball():Ball() {
    name = "Superball";
    description = "description for superball";
    ballRate = 1.5;
    prix = 600;
}

Superball::~Superball() {

}

bool Superball::use(Pokemon* pokemon) const {
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
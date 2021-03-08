#ifndef HYPERBALL_INCLUDED
#define HYPERBALL_INCLUDED

#include "hyperball.h"
// #include "../Ball.cpp"

Hyperball::Hyperball():Ball() {
    name = "Hyperball";
    description = "description for hyperball";
    ballRate = 2;
}

Hyperball::~Hyperball() {

}

bool Hyperball::use(Pokemon* pokemon) const {
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
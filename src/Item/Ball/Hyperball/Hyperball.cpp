#ifndef HYPERBALL_INCLUDED
#define HYPERBALL_INCLUDED

#include "hyperball.h"
// #include "../Ball.cpp"

Hyperball::Hyperball():Ball() {
    name = "Hyperball";
    description = "description for hyperball";
}

Hyperball::~Hyperball() {

}

bool Hyperball::use(Pokemon* pokemon) const {
    cout << "Ceci est une hyperball." << name << chanceOfSuccess << endl;
    return true;
}

#endif
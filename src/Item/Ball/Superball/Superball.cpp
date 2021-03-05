#ifndef SUPERBALL_INCLUDED
#define SUPERBALL_INCLUDED

#include "superball.h"
// #include "../Ball.cpp"

Superball::Superball():Ball() {
    name = "Superball";
    description = "description for superball";
}

Superball::~Superball() {

}

bool Superball::use(Pokemon* pokemon) const {
    cout << "Ceci est une superball." << name << chanceOfSuccess << endl;
    return true;
}

#endif
#ifndef MASTERBALL_INCLUDED
#define MASTERBALL_INCLUDED

#include "masterball.h"
// #include "../Ball.cpp"

Masterball::Masterball():Ball() {
    name = "Masterball";
    description = "description for masterball";
    prix = 15000;
}

Masterball::~Masterball() {

}

bool Masterball::use(Pokemon* pokemon) const {
    return true;
}

#endif
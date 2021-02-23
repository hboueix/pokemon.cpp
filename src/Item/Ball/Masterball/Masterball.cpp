#ifndef MASTERBALL_INCLUDED
#define MASTERBALL_INCLUDED

#include "masterball.h"
// #include "../Ball.cpp"

Masterball::Masterball():Ball() {
    name = "Masterball";
    description = "description for masterball";
}

Masterball::~Masterball() {

}

void Masterball::use() const {
    cout << "Ceci est une masterball." << name << chanceOfSuccess << endl;
}

#endif
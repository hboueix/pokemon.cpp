#ifndef MASTERBALL_INCLUDED
#define MASTERBALL_INCLUDED

#include "masterball.h"
#include "../Ball.cpp"

Masterball::Masterball() {
    name = "Masterball";
    description = "description for masterball";
}

Masterball::~Masterball() {

}

void Masterball::use() const {
    cout << "Ceci est une masterball." << name << chanceOfSuccess << endl;
}

#endif
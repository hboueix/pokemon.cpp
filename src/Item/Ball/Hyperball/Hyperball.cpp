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

void Hyperball::use() const {
    cout << "Ceci est une hyperball." << name << chanceOfSuccess << endl;
}

#endif
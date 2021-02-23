#ifndef SUPERBALL_INCLUDED
#define SUPERBALL_INCLUDED

#include "superball.h"
#include "../Ball.cpp"

Superball::Superball() {
    name = "Superball";
    description = "description for superball";
}

Superball::~Superball() {

}

void Superball::use() const {
    cout << "Ceci est une superball." << name << chanceOfSuccess << endl;
}

#endif
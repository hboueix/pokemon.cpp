#ifndef SUPERBALL_INCLUDED
#define SUPERBALL_INCLUDED

#include "superball.h"

Superball::Superball() {

}

Superball::~Superball() {

}

void Superball::use() const {
    cout << "Ceci est une superball." << name << chanceOfSuccess << endl;
}

#endif
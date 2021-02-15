#ifndef HYPERBALL_INCLUDED
#define HYPERBALL_INCLUDED

#include "hyperball.h"

Hyperball::Hyperball() {

}

Hyperball::~Hyperball() {

}

void Hyperball::use() const {
    cout << "Ceci est une hyperball." << name << chanceOfSuccess << endl;
}

#endif
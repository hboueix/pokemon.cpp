#ifndef MASTERBALL_INCLUDED
#define MASTERBALL_INCLUDED

#include "masterball.h"

Masterball::Masterball() {

}

Masterball::~Masterball() {

}

void Masterball::use() const {
    cout << "Ceci est une masterball." << name << chanceOfSuccess << endl;
}

#endif
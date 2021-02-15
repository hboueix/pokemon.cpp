#ifndef POKEBALL_INCLUDED
#define POKEBALL_INCLUDED

#include "pokeball.h"

Pokeball::Pokeball() {

}

Pokeball::~Pokeball() {

}

void Pokeball::use() const {
    cout << "Ceci est une pokeball." << name << chanceOfSuccess << endl;
}

#endif
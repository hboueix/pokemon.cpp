#ifndef POKEBALL_INCLUDED
#define POKEBALL_INCLUDED

#include "pokeball.h"
// #include "../Ball.cpp"

Pokeball::Pokeball():Ball()  {
    name = "Pokeball";
    description = "description for pokeball";
}

Pokeball::~Pokeball() {

}

void Pokeball::use() const {
    cout << "Ceci est une pokeball." << name << chanceOfSuccess << endl;
}

#endif
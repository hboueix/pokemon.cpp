#ifndef POTION_INCLUDED
#define POTION_INCLUDED

#include "potion.h"

Potion::Potion() {
    name = "potion";
    description = "description for potion";
}

void Potion::affiche() const {
    cout << "Ceci est une potion." << name << endl;
}

Potion::~Potion() {

}



#endif
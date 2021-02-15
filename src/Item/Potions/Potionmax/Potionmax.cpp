#ifndef POTION_INCLUDED
#define POTION_INCLUDED

#include "potion.h"

Potions::Potions() {
    name = "potion";
    description = "description for potion";
}

void Potions::use() const {
    cout << "Ceci est une potion." << name << endl;
}

Potions::~Potions() {

}



#endif
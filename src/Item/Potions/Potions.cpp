#ifndef POTIONS_INCLUDED
#define POTIONS_INCLUDED

#include "potions.h"

Potions::Potions() {
    name = "potions";
    description = "description for potions";
}

void Potions::use() const {
    cout << "Ceci est une potions." << name << endl;
}

Potions::~Potions() {

}



#endif
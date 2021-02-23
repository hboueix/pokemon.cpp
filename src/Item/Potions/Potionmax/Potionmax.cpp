#ifndef POTIONMAX_INCLUDED
#define POTIONMAX_INCLUDED

#include "potionmax.h"

Potionmax::Potionmax() {
    name = "Potionmax";
    description = "description for potionmax";
}

void Potionmax::use() const {
    cout << "Ceci est une potionmax. pas la meme gestion que autre potions" << name << endl;
}

Potionmax::~Potionmax() {

}



#endif
#ifndef POTIONS_INCLUDED
#define POTIONS_INCLUDED

#include "potions.h"
#include "../Item.cpp"

Potions::Potions():Item() {
    name = "potions";
    type = "potion";
    description = "description for potions";
}

Potions::~Potions() {

}



#endif
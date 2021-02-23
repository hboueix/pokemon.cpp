#ifndef POTIONS_INCLUDED
#define POTIONS_INCLUDED

#include "potions.h"
#include "../Item.cpp"

Potions::Potions():Item() {
    name = "potions";
    description = "description for potions";
}

void Potions::use(Pokemon* Pokemon) const {
    cout << "ceci est uns potions" << endl;
    // int pokeMaxHP = Pokemon.getMaxHP();
    // int pokeHP = Pokemon.getHP();
    // if (pokeHP == pokeMaxHP) {
    //     cout << Pokemon.name << " a toute sa vie, vous ne pouvez pas le soigner." << endl;
    // } else if (pokeHP == 0) {
    //     cout << Pokemon.name << " est K.O. Vous ne pouvez pas le soigner avec "<< this->name << endl; 
    // } else {
    //     Pokemon.setHP(pokeHP + this->pvHeal);
    //     cout << " Vous avez rendu " << this->pvHeal << " HP à " << Pokemon.name << endl;
    // }
}

Potions::~Potions() {

}



#endif
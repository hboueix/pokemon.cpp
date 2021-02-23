#ifndef POTION_INCLUDED
#define POTION_INCLUDED

#include "potion.h"

Potion::Potion() {
    name = "Potion";
    description = "description for potion";
    pvHeal = 20;
}

void Potion::use(Pokemon& Pokemon) const {
    int pokeMaxHP = Pokemon.getMaxHP();
    int pokeHP = Pokemon.getHP();
    if (pokeHP == pokeMaxHP) {
        cout << Pokemon.name << " a toute sa vie, vous ne pouvez pas le soigner." << endl;
    } else if (pokeHP == 0) {
        cout << Pokemon.name << " est K.O. Vous ne pouvez pas le soigner avec "<< this->name << endl; 
    } else {
        Pokemon.setHP(pokeHP + this->pvHeal);
        cout << " Vous avez rendu " << this->pvHeal << " HP à " << Pokemon.name << endl;
    }
}

Potion::~Potion() {

}



#endif
#ifndef HYPERPOTION_INCLUDED
#define HYPERPOTION_INCLUDED

#include "hyperpotion.h"

Hyperpotion::Hyperpotion():Potions() {
    name = "Hyperpotion";
    description = "description for hyperpotion";
    pvHeal = 200;
}

bool Hyperpotion::use(Pokemon* pokemon) const {
    int pokeMaxHP = pokemon->getMaxHP();
    int pokeHP = pokemon->getHP();
    if (pokeHP == pokeMaxHP) {
        cout << pokemon->name << " a toute sa vie, vous ne pouvez pas le soigner." << endl;
    } else if (pokeHP == 0) {
        cout << pokemon->name << " est K.O. Vous ne pouvez pas le soigner avec "<< this->name << endl; 
    } else {
        pokemon->setHP(pokeHP + this->pvHeal);
        cout << " Vous avez rendu " << this->pvHeal << " HP à " << pokemon->name << endl;
    }
    return true;
}

Hyperpotion::~Hyperpotion() {

}



#endif
#ifndef POTIONMAX_INCLUDED
#define POTIONMAX_INCLUDED

#include "potionmax.h"

Potionmax::Potionmax():Potions() {
    name = "Potionmax";
    description = "description for potionmax";
    prix = 2500;
}

bool Potionmax::use(Pokemon* pokemon) const {
    int pokeMaxHP = pokemon->getMaxHP();
    int pokeHP = pokemon->getHP();
    if (pokeHP == pokeMaxHP) {
        cout << pokemon->name << " a toute sa vie, vous ne pouvez pas le soigner." << endl;
    } else if (pokeHP == 0) {
        cout << pokemon->name << " est K.O. Vous ne pouvez pas le soigner avec "<< this->name << endl; 
    } else {
        cout << " Vous avez rendu " << pokeMaxHP - pokeHP << " HP à " << pokemon->name << endl;
        pokemon->setHP(pokeHP + this->pvHeal);
    }
    return true;
}

Potionmax::~Potionmax() {

}



#endif
#ifndef POTIONMAX_INCLUDED
#define POTIONMAX_INCLUDED

#include "potionmax.h"

Potionmax::Potionmax():Potions() {
    name = "Potionmax";
    description = "description for potionmax";
}

bool Potionmax::use(Pokemon* pokemon) const {
    int pokeMaxHP = pokemon->getMaxHP();
    int pokeHP = pokemon->getHP();
    if (pokeHP == pokeMaxHP) {
        cout << pokemon->name << " a toute sa vie, vous ne pouvez pas le soigner." << endl;
    } else if (pokeHP == 0) {
        cout << pokemon->name << " est K.O. Vous ne pouvez pas le soigner avec "<< this->name << endl; 
    } else {
        pokemon->setHP(pokeMaxHP);
        cout << " Vous avez rendu tout ses HP à " << pokemon->name << endl;
    }
    return true;
}

Potionmax::~Potionmax() {

}



#endif
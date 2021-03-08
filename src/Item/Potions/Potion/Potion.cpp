#ifndef POTION_INCLUDED
#define POTION_INCLUDED

#include "potion.h"

Potion::Potion():Potions() {
    name = "Potion";
    description = "description for potion";
    pvHeal = 20;
}

bool Potion::use(Pokemon* pokemon) const {
    int pokeMaxHP = pokemon->getMaxHP();
    int pokeHP = pokemon->getHP();
    if (pokeHP == pokeMaxHP) {
        cout << pokemon->name << " a toute sa vie, vous ne pouvez pas le soigner." << endl;
    } else if (pokeHP == 0) {
        cout << pokemon->name << " est K.O. Vous ne pouvez pas le soigner avec "<< this->name << endl; 
    } else {
        if (this->pvHeal <= pokeMaxHP - pokeHP)
        {
            cout << " Vous avez rendu " << this->pvHeal << " HP à " << pokemon->name << endl;
        } 
        else
        {
            cout << " Vous avez rendu " << pokeMaxHP - pokeHP << " HP à " << pokemon->name << endl;
        }
        pokemon->setHP(pokeHP + this->pvHeal);
    }
    return true;
}

Potion::~Potion() {

}



#endif
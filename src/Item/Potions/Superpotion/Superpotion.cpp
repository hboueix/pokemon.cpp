#ifndef SUPERPOTION_INCLUDED
#define SUPERPOTION_INCLUDED

#include "superpotion.h" 

Superpotion::Superpotion():Potions() {
    name = "Superpotion";
    description = "description for superpotion";
    pvHeal = 50;
}

void Superpotion::use(Pokemon* pokemon) const {
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
}

Superpotion::~Superpotion() {

}



#endif
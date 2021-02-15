#ifndef POTION_INCLUDED
#define POTION_INCLUDED

#include "superpotion.h" 

Superpotion::Superpotion() {
    name = "superpotion";
    description = "description for superpotion";
}

void Superpotion::use() const {
    cout << "Ceci est une superpotion." << name << endl;
}

Superpotion::~Superpotion() {

}



#endif
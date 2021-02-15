#ifndef HYPERPOTION_INCLUDED
#define HYPERPOTION_INCLUDED

#include "hyperpotion.h"

Hyperpotion::Hyperpotion() {
    name = "Hyperpotion";
    description = "description for hyperpotion";
}

void Hyperpotion::use() const {
    cout << "Ceci est une hyperpotion." << name << endl;
}

Hyperpotion::~Hyperpotion() {

}



#endif
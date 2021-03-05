#ifndef POTIONS_HEADERS_INCLUDED
#define POTIONS_HEADERS_INCLUDED

#include <iostream>
#include "../item.h"


using namespace std;

class Potions : public Item {
protected:
    int pvHeal;
    
public:
    Potions();
    ~Potions();

};

#endif
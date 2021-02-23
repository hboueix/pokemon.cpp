#ifndef POTIONS_HEADERS_INCLUDED
#define POTIONS_HEADERS_INCLUDED

#include <iostream>
#include "../item.h"


using namespace std;

class Potions : public Item {
protected:
    int pvHeal;
    
public:
    virtual void use(Pokemon* Pokemon) const;
    Potions();
    ~Potions();

};

#endif
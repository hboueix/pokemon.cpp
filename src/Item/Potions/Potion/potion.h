#ifndef POTION_HEADERS_INCLUDED
#define POTION_HEADERS_INCLUDED

#include <iostream>
#include "../potions.h"


using namespace std;

class Potion : public Potions {
private:

public:
    Potion();
    ~Potion();
    virtual bool use(Pokemon* pokemon) const;
};

#endif
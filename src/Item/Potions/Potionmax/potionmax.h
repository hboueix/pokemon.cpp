#ifndef POTIONMAX_HEADERS_INCLUDED
#define POTIONMAX_HEADERS_INCLUDED

#include <iostream>
#include "../potions.h"


using namespace std;

class Potionmax : public Potions {
private:

public:
    virtual bool use(Pokemon* pokemon) const;
    Potionmax();
    ~Potionmax();

};

#endif
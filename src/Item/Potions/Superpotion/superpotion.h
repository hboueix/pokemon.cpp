#ifndef SUPERPOTION_HEADERS_INCLUDED
#define SUPERPOTION_HEADERS_INCLUDED

#include <iostream>
#include "../potions.h"


using namespace std;

class Superpotion : public Potions {
private:

public:
    virtual bool use(Pokemon* pokemon) const;
    Superpotion();
    ~Superpotion();

};

#endif
#ifndef SUPERPOTION_HEADERS_INCLUDED
#define SUPERPOTION_HEADERS_INCLUDED

#include <iostream>
#include "../potions.h"


using namespace std;

class Superpotion : public Potions {
private:

public:
    virtual void use(Pokemon* Pokemon) const;
    Superpotion();
    ~Superpotion();

};

#endif
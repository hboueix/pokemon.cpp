#ifndef HYPERPOTION_HEADERS_INCLUDED
#define HYPERPOTION_HEADERS_INCLUDED

#include <iostream>
#include "../potions.h"


using namespace std;

class Hyperpotion : public Potions {
private:

public:
    virtual bool use(Pokemon* pokemon) const;
    Hyperpotion();
    ~Hyperpotion();

};

#endif
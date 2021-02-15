#ifndef POTION_HEADERS_INCLUDED
#define POTION_HEADERS_INCLUDED

#include <iostream>
#include "../potions.h"


using namespace std;

class Superpotion : public Item {
private:

public:
    virtual void use() const;
    Superpotion();
    ~Superpotion();

};

#endif
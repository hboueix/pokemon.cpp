#ifndef POTION_HEADERS_INCLUDED
#define POTION_HEADERS_INCLUDED

#include <iostream>
#include "../potions.h"


using namespace std;

class Hyperpotion : public Item {
private:

public:
    virtual void use() const;
    Hyperpotion();
    ~Hyperpotion();

};

#endif
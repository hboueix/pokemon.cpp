#ifndef POTION_HEADERS_INCLUDED
#define POTION_HEADERS_INCLUDED

#include <iostream>
#include "../item.h"


using namespace std;

class Potion : public Item {
private:

public:
    virtual void affiche() const;
    Potion();
    ~Potion();

};

#endif
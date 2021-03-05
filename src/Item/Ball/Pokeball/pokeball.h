#ifndef POKEBALL_HEADERS_INCLUDED
#define POKEBALL_HEADERS_INCLUDED

#include <iostream>
#include "../ball.h"

using namespace std;

class Pokeball : public Ball {
private:
    float chanceOfSuccess;

public:
    virtual bool use(Pokemon* Pokemon) const;
    Pokeball();
    ~Pokeball();
};

#endif
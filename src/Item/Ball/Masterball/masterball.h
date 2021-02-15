#ifndef MASTERBALL_HEADERS_INCLUDED
#define MASTERBALL_HEADERS_INCLUDED

#include <iostream>
#include "../ball.h"

using namespace std;

class Masterball : public Ball {
private:

public:
    virtual void use() const;
    Masterball();
    ~Masterball();
};

#endif
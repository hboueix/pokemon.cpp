#ifndef SUPERBALL_HEADERS_INCLUDED
#define SUPERBALL_HEADERS_INCLUDED

#include <iostream>
#include "../ball.h"

using namespace std;

class Superball : public Ball {
private:

public:
    virtual void use() const;
    Superball();
    ~Superball();
};

#endif
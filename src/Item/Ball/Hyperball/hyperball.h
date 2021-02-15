#ifndef HYPERBALL_HEADERS_INCLUDED
#define HYPERBALL_HEADERS_INCLUDED

#include <iostream>
#include "../ball.h"

using namespace std;

class Hyperball : public Ball {
private:

public:
    virtual void use() const;
    Hyperball();
    ~Hyperball();
};

#endif
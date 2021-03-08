#ifndef BALL_HEADERS_INCLUDED
#define BALL_HEADERS_INCLUDED

#include <iostream>
#include "../item.h"


using namespace std;

class Ball : public Item {
protected:
    float ballRate;
    
public:
    Ball();
    ~Ball();
};

#endif
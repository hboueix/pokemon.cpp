#ifndef BALL_INCLUDED
#define BALL_INCLUDED

#include "ball.h"

Ball::Ball() {

}

Ball::~Ball() {

}

void Ball::use() const {
    cout << "Ceci est une ball." << name << chanceOfSuccess << endl;
}



#endif
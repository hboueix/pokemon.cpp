#ifndef BALL_INCLUDED
#define BALL_INCLUDED

#include "ball.h"

Ball::Ball() {

}

Ball::~Ball() {

}

void Ball::affiche() const {
    cout << "Ceci est une ball." << name << chanceOfSuccess << endl;
}
// void Ball::launch() {
//     cout << "methode ball.cpp" << endl;
// }



#endif
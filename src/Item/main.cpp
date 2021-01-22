#include <iostream>

#include "Item.cpp"
#include "Ball/Ball.cpp"
#include "Potion/Potion.cpp"

using namespace std;

int main() {
	Potion *potion = new Potion();
	Ball *ball = new Ball();
	ball->launch();
}
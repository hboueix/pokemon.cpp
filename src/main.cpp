#include <iostream>

#include "Menu/Menu.cpp"
#include "Player/Player.cpp"
#include "Pokemon/Pokemon.cpp"

using namespace std;

int main() {
	Player *player = new Player();
	Menu *myMenu = new Menu(*player);
	myMenu->mainMenu();
}
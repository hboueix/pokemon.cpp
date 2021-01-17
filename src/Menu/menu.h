#ifndef MENU_HEADERS_INCLUDED
#define MENU_HEADERS_INCLUDED

#include <iostream>
#include "../Player/player.h"

using namespace std;

class Menu {
private:
	Player player;
	int waitForValidUserInput(int maxValid);
	void wildGrass();
	void team();
	void allPCTeam();
public:
	Menu(Player player);
	~Menu();
	void mainMenu();
};

#endif

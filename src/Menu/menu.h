#ifndef MENU_HEADERS_INCLUDED
#define MENU_HEADERS_INCLUDED

#include <iostream>
#include "../Storage/storage.h"
#include "../Player/player.h"

using namespace std;

class Menu {
private:
	Player *player;
	Storage *storage;
	int waitForValidUserInput(int maxValid, string question="Que voulez-vous faire ?", bool canExit=true);
	void wildGrass(Pokemon *pokeSauvage=0, int attackingPokeIdx=0);
	int chooseAttackPoke(int actualPokeIdx);
	void menuItem();
	void team();
	void healTeam();
	void allPCTeam();
	void save();
public:
	Menu(Player *player, Storage *storage);
	~Menu();
	void mainMenu();
};

#endif

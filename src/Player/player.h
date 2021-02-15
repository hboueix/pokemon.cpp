#ifndef PLAYER_HEADERS_INCLUDED
#define PLAYER_HEADERS_INCLUDED

#include <iostream>
#include <vector>
#include "../Pokemon/pokemon.h"
#include "../Item/item.h"
#include "../Item/Potion/potion.h"


using namespace std;

class Player {
private:
	int money;
	vector<Pokemon> team;
	vector<Pokemon> teamPC;
	vector<Item*> backPack;
public:
	string name;
	Player(string name);
	Player(string name, int money, vector<Pokemon> team, vector<Pokemon> teamPC);
	~Player();
	int getMoney();
	vector<Item*> getBackPack();
	vector<Pokemon> getTeam();
	vector<Pokemon> getTeamPC();
	void swapPokemon(int pokemonSelected, int pokemonPCSelected);
	void moveToPC(int toMove);
	void moveToTeam(int toMove);
	void removeFromPC(int toRemove);
};

#endif
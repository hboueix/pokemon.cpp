#ifndef PLAYER_HEADERS_INCLUDED
#define PLAYER_HEADERS_INCLUDED

#include <iostream>
#include <vector>

#include "../Pokemon/pokemon.h"
#include "../Item/item.h"


using namespace std;

class Player {
private:
	int money;
	vector<Pokemon> team;
	vector<Pokemon> teamPC;
	vector<Item*> backpack;
public:
	string name;
	Player(string name);
	Player(string name, int money, vector<Item*> backpack, vector<Pokemon> team, vector<Pokemon> teamPC);
	~Player();
	void healPokemons();
	void removeMoney(int toRemove);
	int getMoney();
	bool validBuyItem(int money);
	void addMoney(int money);
	void setBackpack(vector<Item *> backpack);
	vector<Item*> getBackpack();
	void setTeam(vector<Pokemon> team);
	vector<Pokemon> getTeam();
	vector<Pokemon> getTeamPC();
	void swapPokemon(int pokemonSelected, int pokemonPCSelected);
	void healOnePokemon(Pokemon &Pokemon);
	void moveToPC(int toMove);
	void moveToTeam(int toMove);
	int addPokemon(Pokemon pokemon);
	void removeFromPC(int toRemove);
	int getFirstValidPokemonIndex();
	void buyItem(string item, int howMuch);
};

#endif
#ifndef POKEMON_HEADERS_INCLUDED
#define POKEMON_HEADERS_INCLUDED

#include <iostream>

using namespace std;

class Pokemon {
private:

public:
	string name;
	string type;
	float maxHP;
	float HP;
	float attack;
	float defense;
	Pokemon(string pokemonName);
	Pokemon(string pokemonName, string type, float maxHP, float attack, float defense);
	~Pokemon();
	void showStats();
};

#endif
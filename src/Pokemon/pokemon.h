#ifndef POKEMON_HEADERS_INCLUDED
#define POKEMON_HEADERS_INCLUDED

#include <iostream>

using namespace std;

class Pokemon {
private:

public:
	string name;
	string type;
	float attack;
	float defense;
	Pokemon(string pokemonName);
	~Pokemon();
	void showStats();
};

#endif
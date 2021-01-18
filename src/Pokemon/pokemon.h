#ifndef POKEMON_HEADERS_INCLUDED
#define POKEMON_HEADERS_INCLUDED

#include <iostream>

using namespace std;

class Pokemon {
private:
	string type;
	float maxHP;
	float HP;
	float attack;
	float defense;
public:
	string name;
	Pokemon(string pokemonName);
	Pokemon(string pokemonName, string type, float maxHP, float attack, float defense);
	~Pokemon();
	void showStats();
	void attacking(Pokemon &defender);
	int getHP();
	int getAttack();
	int getDefense();
	void setHP(int PDV);
};

#endif
#ifndef POKEMON_HEADERS_INCLUDED
#define POKEMON_HEADERS_INCLUDED

#include <iostream>
#include "../../libs/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

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
	Pokemon(string pokemonName, string type, float maxHP, float HP, float attack, float defense);
	~Pokemon();
	void showStats();
	void attacking(Pokemon &defender);
	string getType();
	int getHP();
	int getMaxHP();
	int getAttack();
	int getDefense();
	void setHP(int PDV);
	json getJson();
};

#endif
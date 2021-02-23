#ifndef POKEMON_HEADERS_INCLUDED
#define POKEMON_HEADERS_INCLUDED

#include <iostream>
#include "../../libs/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Pokemon {
private:
	string type;
	int maxHP;
	int HP;
	int attack;
	int defense;
	int sp_attack;
	int sp_defense;
	int speed;
public:
	string name;
	// Pokemon(string pokemonName);
	Pokemon(string pokemonName, string type, int maxHP, int HP, int attack, int defense, int sp_attack, int sp_defense, int speed);
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
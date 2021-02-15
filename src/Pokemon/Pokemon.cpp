#ifndef POKEMON_INCLUDED
#define POKEMON_INCLUDED

#include <iostream>
#include "pokemon.h"
#include "../../libs/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

Pokemon::Pokemon(string pokemonName) {
	name = pokemonName;
	type = "Not implemented";
	maxHP = 30.0;
	HP = maxHP;
	attack = 10.0;
	defense = 5.0;
}

Pokemon::Pokemon(string pokemonName, string type, float maxHP, float HP, float attack, float defense) {
	this->name = pokemonName;
	this->type = type;
	this->maxHP = maxHP;
	this->HP = HP;
	this->attack = attack;
	this->defense = defense;
}

Pokemon::~Pokemon() {

}

void Pokemon::showStats() {
	cout << "Nom : " << this->name << endl
		<< "Type : " << this->type << endl
		<< "HP/maxHP : " << this->HP << " / " << this->maxHP << endl
		<< "ATQ : " << this->attack << endl
		<< "DEF : " << this->defense << endl;
}

void Pokemon::attacking(Pokemon &defender) {
	int damage = this->attack-defender.getDefense();
	if (defender.getHP() - damage > 0) {
		defender.setHP(defender.getHP()-damage);
		cout << this->name << " a infligé " << damage << "HP à " << defender.name << endl
			<< "Il reste " << defender.getHP() << "HP à " << defender.name << endl;
	} else {
		defender.setHP(0);
		cout << this->name << " a infligé " << defender.getHP() << "HP à " << defender.name << endl
			<< defender.name << " est KO." << endl;
	}
}

string Pokemon::getType() {
	return this->type;
}

int Pokemon::getHP(){
	return HP;
}

int Pokemon::getMaxHP() {
	return this->maxHP;
}

int Pokemon::getAttack(){
	return attack;
}

int Pokemon::getDefense(){
	return defense;
}

void Pokemon::setHP(int PDV) {
	HP = PDV; 
}

json Pokemon::getJson() {
	return {
				{"name", this->name},
				{"type", this->type},
				{"HP", this->HP},
				{"maxHP", this->maxHP},
				{"ATQ", this->attack},
				{"DEF", this->defense}
			};
}

#endif
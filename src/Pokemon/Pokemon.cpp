#ifndef POKEMON_INCLUDED
#define POKEMON_INCLUDED

#include <iostream>
#include "pokemon.h"
#include "../../libs/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

Pokemon::Pokemon(string pokemonName)
{
	name = pokemonName;
	type = "Not implemented";
	maxHP = 30.0;
	HP = maxHP;
	attack = 10.0;
	defense = 5.0;
}

Pokemon::Pokemon(string pokemonName, string type, int maxHP, int HP, int attack, int defense, int sp_attack, int sp_defense, int speed)
{
	this->name = pokemonName;
	this->type = type;
	this->maxHP = maxHP;
	this->HP = HP;
	this->attack = attack;
	this->defense = defense;
	this->sp_attack = sp_attack;
	this->sp_defense = sp_defense;
	this->speed = speed;
}

Pokemon::~Pokemon()
{
}

void Pokemon::showStats()
{
	cout << "Nom : " << this->name << endl
		 << "Type : " << this->type << endl
		 << "HP/maxHP : " << this->HP << " / " << this->maxHP << endl
		 << "ATQ : " << this->attack << endl
		 << "DEF : " << this->defense << endl
		 << "SP_ATQ : " << this->sp_attack << endl
		 << "SP_DEF : " << this->sp_defense << endl
		 << "Speed : " << this->speed << endl;
}

void Pokemon::attacking(Pokemon &defender)
{
	int damage = this->attack - defender.getDefense(); //TODO: vérifier les max d'att et def | gestion des erreurs
	if (defender.getHP() - damage > 0)
	{
		defender.setHP(defender.getHP() - damage);
		cout << this->name << " a infligé " << damage << "HP à " << defender.name << endl
			 << "Il reste " << defender.getHP() << "HP à " << defender.name << endl;
	}
	else
	{
		defender.setHP(0);
		cout << this->name << " a infligé " << defender.getHP() << "HP à " << defender.name << endl
			 << defender.name << " est KO." << endl;
	}
}

string Pokemon::getType()
{
	return this->type;
}

int Pokemon::getHP()
{
	return this->HP;
}

int Pokemon::getMaxHP()
{
	return this->maxHP;
}

int Pokemon::getAttack()
{
	return this->attack;
}

int Pokemon::getDefense()
{
	return this->defense;
}

void Pokemon::setHP(int HP)
{
	if (HP > this->maxHP) {
		this->HP = this->maxHP;
	} else {
		this->HP = HP;
	}
}

json Pokemon::getJson()
{
	return {
		{"name", this->name},
		{"type", this->type},
		{"HP", this->HP},
		{"maxHP", this->maxHP},
		{"ATQ", this->attack},
		{"DEF", this->defense},
		{"SP_ATQ", this->sp_attack},
		{"SP_DEF", this->sp_defense},
		{"speed", this->speed}};
}

#endif
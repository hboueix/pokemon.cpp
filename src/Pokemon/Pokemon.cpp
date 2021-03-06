#ifndef POKEMON_INCLUDED
#define POKEMON_INCLUDED

#include <iostream>
#include "pokemon.h"
#include "../../libs/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

Pokemon::Pokemon(string pokemonName, string type, int maxHP, int HP, int attack, int defense, int sp_attack, int sp_defense, int speed, int capture_rate)
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
	this->capture_rate = capture_rate;
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
		 << "Vitesse : " << this->speed << endl;
}

void Pokemon::attacking(Pokemon &defender)
{
	int cc = 1;
	srand(time(NULL));
	if (rand() % 255 < this->getSpeed()/2)
	{
		cc = 2;
		cout << this->name << " inflige un coup critique !" << endl;
	}
	int lostPV = ((((1 * 0.4 + 2) * this->attack * this->attack) / (defender.getDefense() * 50)) + 2)*cc;

	if (defender.getHP() - lostPV > 0)
	{
		defender.setHP(defender.getHP() - lostPV);
		cout << this->name << " a infligé " << lostPV << "HP à " << defender.name << endl
			 << "Il reste " << defender.getHP() << "HP à " << defender.name << endl
			 << endl;
	}
	else
	{
		defender.setHP(0);
		cout << this->name << " a infligé " << lostPV << "HP à " << defender.name << endl
			 << defender.name << " est KO." << endl
			 << endl;
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

int Pokemon::getCaptureRate()
{
	return this->capture_rate;
}

int Pokemon::getSpeed()
{
	return this->speed;
}
void Pokemon::setHP(int HP)
{
	if (HP > this->maxHP)
	{
		this->HP = this->maxHP;
	}
	else
	{
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
		{"speed", this->speed},
		{"capture_rate", this->capture_rate}};
}

#endif
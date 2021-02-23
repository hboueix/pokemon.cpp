#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <iostream>
#include "../Pokemon/Pokemon.cpp"
#include "../Item/Potions/Potions.cpp"
#include "../Item/Item.cpp"
#include "player.h"

using namespace std;

Player::Player(string name)
{
	this->name = name;
	this->money = 1000;
	this->backPack.push_back(new Item());
	this->backPack.push_back(new Potions());
}

Player::Player(string name, int money, vector<Pokemon> team, vector<Pokemon> teamPC)
{
	this->name = name;
	this->money = money;
	this->team = team;
	this->teamPC = teamPC;
}

Player::~Player()
{
}

void Player::healPokemons()
{
	for (int i = 0; i < this->team.size(); i++)
	{
		int pokeHP = this->team[i].getHP();
		int pokeMaxHP = this->team[i].getMaxHP();

		if (pokeHP < pokeMaxHP)
		{
			this->team[i].setHP(pokeMaxHP);
		}
	}
}

int Player::getMoney()
{
	return money;
}

void Player::removeMoney(int toRemove)
{
	this->money -= toRemove;
}

vector<Pokemon> Player::getTeam()
{
	return team;
}

vector<Pokemon> Player::getTeamPC()
{
	return teamPC;
}

vector<Item *> Player::getBackPack()
{
	return backPack;
}

void Player::swapPokemon(int pokemonSelected, int pokemonPCSelected)
{
	if (pokemonSelected > this->team.size())
	{
		this->moveToTeam(pokemonPCSelected);
	}
	else
	{
		this->moveToPC(pokemonSelected);
		this->team.insert(this->team.begin() + pokemonSelected - 1, this->teamPC[pokemonPCSelected - 1]);
		this->removeFromPC(pokemonPCSelected);
	}
}

void Player::moveToPC(int toMove)
{
	this->teamPC.push_back(this->team[toMove - 1]);
	this->team.erase(this->team.begin() + toMove - 1);
}

void Player::moveToTeam(int toMove)
{
	this->team.push_back(this->teamPC[toMove - 1]);
	this->teamPC.erase(this->teamPC.begin() + toMove - 1);
}

int Player::addPokemon(Pokemon pokemon)
{
	if (this->team.size() < 6)
	{
		this->team.push_back(pokemon);
		return 1;
	}
	else
	{
		return 0;
	}
}

void Player::removeFromPC(int toRemove)
{
	this->teamPC.erase(this->teamPC.begin() + toRemove - 1);
}

int Player::getFirstValidPokemonIndex()
{
	for (int i = 0; i < this->team.size(); i++)
	{
		if (this->team[i].getHP() > 0)
		{
			return i;
		}
	}
	return -1;
}

#endif
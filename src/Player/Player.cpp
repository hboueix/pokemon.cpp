#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <iostream>
#include "../Pokemon/Pokemon.cpp"
#include "../Item/Item.cpp"
#include "../Item/Potions/Potions.cpp"
#include "../Item/Potions/Potion/Potion.cpp"
#include "../Item/Potions/Superpotion/Superpotion.cpp"
#include "../Item/Potions/Hyperpotion/Hyperpotion.cpp"
#include "../Item/Potions/Potionmax/Potionmax.cpp"
#include "../Item/Ball/Ball.cpp"
#include "../Item/Ball/Pokeball/Pokeball.cpp"
#include "../Item/Ball/Superball/Superball.cpp"
#include "../Item/Ball/Hyperball/Hyperball.cpp"
#include "../Item/Ball/Masterball/Masterball.cpp"
#include "player.h"

using namespace std;

Player::Player(string name)
{
	this->name = name;
	this->money = 1000;
	this->backpack.push_back(new Pokeball());
	this->backpack.push_back(new Potion());
}

Player::Player(string name, int money, vector<Item *> backpack, vector<Pokemon> team, vector<Pokemon> teamPC)
{
	this->name = name;
	this->money = money;
	this->backpack = backpack;
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
void Player::addMoney(int money)
{
	this->money += money;
}

bool Player::validBuyItem(int money)
{
	if (this->money < money)
	{
		return false;
	}
	else
	{
		this->removeMoney(money);
		return true;
	}
}

void Player::removeMoney(int toRemove)
{
	this->money -= toRemove;
}

vector<Pokemon> Player::getTeam()
{
	return team;
}

void Player::setTeam(vector<Pokemon> team)
{
	this->team = team;
}

vector<Pokemon> Player::getTeamPC()
{
	return this->teamPC;
}

void Player::setBackpack(vector<Item *> backpack)
{
	this->backpack = backpack;
}
vector<Item *> Player::getBackpack()
{
	return this->backpack;
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
	cout << "Vous avez capturé " << pokemon.name << " !" << endl;
	if (this->team.size() < 6)
	{
		this->team.push_back(pokemon);
		cout << pokemon.name << " est ajouté a l'équipe !" << endl;
		return 1;
	}
	else
	{
		this->teamPC.push_back(pokemon);
		cout << pokemon.name << " est ajouté au PC !" << endl;
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

void Player::buyItem(string item, int howMuch)
{
	int howMuchMax = howMuch;
	for (int i = 0; i < howMuchMax; i++)
	{
		if (item == "Potion")
		{
			if (this->validBuyItem(300))
			{
				howMuch--;
				this->backpack.push_back(new Potion());
			}
		}
		else if (item == "Superpotion")
		{
			if (this->validBuyItem(600))
			{
				howMuch--;
				this->backpack.push_back(new Superpotion());
			}
		}
		else if (item == "Hyperpotion")
		{
			if (this->validBuyItem(1200))
			{
				howMuch--;
				this->backpack.push_back(new Hyperpotion());
			}
		}
		else if (item == "Potionmax")
		{
			if (this->validBuyItem(2500))
			{
				howMuch--;
				this->backpack.push_back(new Potionmax());
			}
		}
		else if (item == "Pokeball")
		{
			if (this->validBuyItem(200))
			{
				howMuch--;
				this->backpack.push_back(new Pokeball());
			}
		}
		else if (item == "Superball")
		{
			if (this->validBuyItem(600))
			{
				howMuch--;
				this->backpack.push_back(new Superball());
			}
		}
		else if (item == "Hyperball")
		{
			if (this->validBuyItem(1200))
			{
				howMuch--;
				this->backpack.push_back(new Hyperball());
			}
		}
		else if (item == "Masterball")
		{
			if (this->validBuyItem(15000))
			{
				howMuch--;
				this->backpack.push_back(new Masterball());
			}
		}
	}

	if (howMuch < howMuchMax)
	{
		cout << "Vous avez achetez " << howMuchMax - howMuch << " " << item << endl
			 << "Ca vous fera " << this->backpack[backpack.size() - 1]->getPrix() * (howMuchMax - howMuch) << " ¤" << endl;
	}
	else
	{
		cout << "Vous n'avez pas assez d'argent pour acheter " << item << endl;
	}
	sort(this->backpack.begin(), this->backpack.end());
	cout << endl
		 << endl;
}

#endif
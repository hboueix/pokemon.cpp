#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <iostream>
#include "../Pokemon/Pokemon.cpp"
#include "player.h"

using namespace std;

Player::Player() {
	name = "Red";
	money = 1000;
	Pokemon *poke1 = new Pokemon("Salamèche");
	Pokemon *poke2 = new Pokemon("Carapuce");
	Pokemon *poke3 = new Pokemon("Bulbizarre");
	team.push_back(*poke1);
	team.push_back(*poke2);
	team.push_back(*poke3);
	teamPC.push_back(*(new Pokemon("Pikachu")));
}

Player::Player(string name, vector<Pokemon> team, int money) {
	name = name;
	team = team;
	money = money;
}

Player::~Player() {

}

int Player::getMoney() {
	return money;
}

vector<Pokemon> Player::getTeam() {
	return team;
}

vector<Pokemon> Player::getTeamPC() {
	return teamPC;
}

void Player::swapPokemon(int pokemonSelected, int pokemonPCSelected) {
	if (pokemonSelected > this->team.size()) {
		this->team.push_back(this->teamPC[pokemonPCSelected-1]);
		this->teamPC.erase(this->teamPC.begin() + pokemonPCSelected-1);
	} else {
		this->teamPC.push_back(this->team[pokemonSelected-1]);
		this->team.erase(this->team.begin() + pokemonSelected - 1);
		this->team.insert(this->team.begin() + pokemonSelected - 1, this->teamPC[pokemonPCSelected - 1]);
		this->teamPC.erase(this->teamPC.begin() + pokemonPCSelected - 1);
	}
}

#endif
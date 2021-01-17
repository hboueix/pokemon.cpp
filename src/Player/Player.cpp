#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <iostream>
#include "../Pokemon/Pokemon.cpp"
#include "player.h"

using namespace std;

Player::Player() {
	Pokemon *poke1 = new Pokemon("Salamèche");
	Pokemon *poke2 = new Pokemon("Carapuce");
	Pokemon *poke3 = new Pokemon("Bulbizarre");
	team.push_back(*poke1);
	team.push_back(*poke2);
	team.push_back(*poke3);
}

Player::~Player() {

}

vector<Pokemon> Player::getTeam() {
	return team;
}

#endif
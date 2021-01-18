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

#endif
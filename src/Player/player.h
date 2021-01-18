#ifndef PLAYER_HEADERS_INCLUDED
#define PLAYER_HEADERS_INCLUDED

#include <iostream>
#include <vector>
#include "../Pokemon/pokemon.h"

using namespace std;

class Player {
private:
	int money;
	vector<Pokemon> team;
	vector<Pokemon> teamPC;
public:
	string name;
	Player();
	Player(string name, vector<Pokemon> team, int money);
	~Player();
	int getMoney();
	vector<Pokemon> getTeam();
	vector<Pokemon> getTeamPC();
};

#endif
#ifndef PLAYER_HEADERS_INCLUDED
#define PLAYER_HEADERS_INCLUDED

#include <iostream>
#include <vector>
#include "../Pokemon/pokemon.h"

using namespace std;

class Player {
private:
	vector<Pokemon> team;
public:
	string name;
	Player();
	~Player();
	vector<Pokemon> getTeam();
};

#endif
#ifndef STORAGE_HEADERS_INCLUDED
#define STORAGE_HEADERS_INCLUDED

#include <iostream>
# include "../Player/player.h"

using namespace std;

class Storage {
private:
	// string save;
	vector<Pokemon> all_pokemon_templates;
public:
	Storage();
	~Storage();
	string read(string filePath);
	bool write(string filePath, string toWrite);
	void savePlayer(Player *player);
	void saveConfig(Player *player);
	vector<string> loadPlayers();
	string getLastPlayerName();
	Player* loadPlayer(string name);
	void load_pokemons();
	Pokemon getRandomPokemon();
	Pokemon getPokemonTemplate(string name);
};

#endif

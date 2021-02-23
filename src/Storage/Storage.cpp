#ifndef STORAGE_INCLUDED
#define STORAGE_INCLUDED

#include <iostream>
#include <fstream>
#include <time.h>

#include "../../libs/nlohmann/json.hpp"
#include "../Player/Player.cpp"
#include "storage.h"

using namespace std;
using json = nlohmann::json;

Storage::Storage()
{
	// save = "./saves/user.pokepp";
	this->load_pokemons();
}

Storage::~Storage()
{
}

string Storage::read(string filePath)
{
	ifstream flux(filePath.c_str());
	if (flux)
	{
		string lignes;
		string ligne;
		while (getline(flux, ligne))
		{
			lignes += ligne;
		}

		return lignes;
	}
	else
	{
		// cout << "ERREUR: Impossible d'ouvrir le fichier '" << filePath << "'." << endl;
		return "";
	}
}

bool Storage::write(string filePath, string toWrite)
{
	ofstream flux(filePath.c_str());
	if (flux)
	{
		flux << toWrite << endl;
		return true;
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier '" << filePath << "'." << endl;
		return false;
	}
}

void Storage::savePlayer(Player *player)
{
	json dataPlayer = {
		{"name", player->name},
		{"money", player->getMoney()},
		{"team", {}},
		{"teamPC", {}}};
	for (int i = 0; i < player->getTeam().size(); i++)
	{
		Pokemon pokemon = player->getTeam()[i];
		dataPlayer["team"].push_back(pokemon.getJson());
	}

	for (int i = 0; i < player->getTeamPC().size(); i++)
	{
		Pokemon pokemon = player->getTeamPC()[i];
		dataPlayer["teamPC"].push_back(pokemon.getJson());
	}

	this->write("." + player->name + ".pokesave", dataPlayer.dump());
}

void Storage::saveConfig(Player *player) {
	string pokecfgRaw = this->read(".pokecfg");
	json pokecfg;
	if (pokecfgRaw != "") {
		pokecfg = json::parse(pokecfgRaw);
		pokecfg["lastPlayer"] = player->name;
		bool found = false;
		for (int i = 0; i < pokecfg["players"].size(); i++) {
			if (pokecfg["players"][i] == player->name) {
				found = true;
				break;
			}
		}
		
		if (!found) {
			pokecfg["players"].push_back(player->name);
		}
	}
	else {
		pokecfg = {
			{"lastPlayer", player->name},
			{"players", {}}
		};
		pokecfg["players"].push_back(player->name);
	}

	this->write(".pokecfg", pokecfg.dump());
}

vector<string> Storage::loadPlayers() {
	vector<string> players = {};
	string pokecfgRaw = this->read(".pokecfg");
	if (pokecfgRaw != "") {
		json pokecfg = json::parse(pokecfgRaw);
		for (int i = 0; i < pokecfg["players"].size(); i++) {
			players.push_back(pokecfg["players"][i].get<string>());
		}
	}
	return players;
}

string Storage::getLastPlayerName() {
	json pokecfg = json::parse(this->read(".pokecfg"));
	return pokecfg["lastPlayer"].get<string>();
}

Player *Storage::loadPlayer(string namePlayer)
{
	string dataPlayerRaw = this->read("." + namePlayer + ".pokesave");
	if (dataPlayerRaw != "")
	{
		json dataPlayer = json::parse(dataPlayerRaw);
		vector<Pokemon> team = {};
		vector<Pokemon> teamPC = {};
		for (int i = 0; i < dataPlayer["team"].size(); i++)
		{
			json pokemon = dataPlayer["team"][i];
			team.push_back(
				*(new Pokemon(
					pokemon["name"].get<string>(),
					pokemon["type"].get<string>(),
					pokemon["maxHP"].get<int>(),
					pokemon["HP"].get<int>(),
					pokemon["ATQ"].get<int>(),
					pokemon["DEF"].get<int>(),
					pokemon["SP_ATQ"].get<int>(),
					pokemon["SP_DEF"].get<int>(),
					pokemon["speed"].get<int>()
					)
				)
			);
		}

		for (int i = 0; i < dataPlayer["teamPC"].size(); i++)
		{
			json pokemon = dataPlayer["teamPC"][i];
			teamPC.push_back(
				*(new Pokemon(
					pokemon["name"].get<string>(),
					pokemon["type"].get<string>(),
					pokemon["maxHP"].get<float>(),
					pokemon["HP"].get<float>(),
					pokemon["ATQ"].get<float>(),
					pokemon["DEF"].get<float>(),
					pokemon["SP_ATQ"].get<int>(),
					pokemon["SP_DEF"].get<int>(),
					pokemon["speed"].get<int>()
					)
				)
			);
		}

		return new Player(
			dataPlayer["name"].get<string>(),
			dataPlayer["money"].get<int>(),
			team,
			teamPC);
	}
	else
	{
		return new Player(namePlayer);
	}
}

void Storage::load_pokemons()
{
	string dataPokemonsRaw = this->read("pokemon.json");
	if (dataPokemonsRaw != "")
	{
		json dataPokemons = json::parse(dataPokemonsRaw);
		for (int i = 0; i < dataPokemons.size(); i++)
		{
			json pokemon = dataPokemons[i];
			this->all_pokemon_templates.push_back(
				*(new Pokemon(
					pokemon["name_fr"].get<string>(),
					pokemon["type1"].get<string>(),
					pokemon["hp"].get<int>(),
					pokemon["hp"].get<int>(),
					pokemon["attack"].get<int>(),
					pokemon["defense"].get<int>(),
					pokemon["sp_attack"].get<int>(),
					pokemon["sp_defense"].get<int>(),
					pokemon["speed"].get<int>()
					)
				)
			);
		}

		// for (int i = 0; i < this->all_pokemon_templates.size(); i++)
		// {
		// 	this->all_pokemon_templates[i].showStats();
		// }
	}
	else
	{
		cout << "ERROR : missing pokemons data" << endl;
	}
}

Pokemon Storage::getRandomPokemon() {
	srand(time(NULL));
	int randomIndex = rand() % this->all_pokemon_templates.size();
	Pokemon random = this->all_pokemon_templates[randomIndex];
	// random.showStats();
	return random;
}

// Pokemon Storage::getPokemonTemplate(string name) {

// }

#endif
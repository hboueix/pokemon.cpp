#ifndef STORAGE_INCLUDED
#define STORAGE_INCLUDED

#include <iostream>
#include <fstream>
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
					pokemon["maxHP"].get<float>(),
					pokemon["HP"].get<float>(),
					pokemon["ATQ"].get<float>(),
					pokemon["DEF"].get<float>())));
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
					pokemon["DEF"].get<float>())));
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
					pokemon["name"].get<string>(),
					pokemon["type1"].get<string>(),
					pokemon["hp"].get<float>(),
					pokemon["hp"].get<float>(),
					pokemon["attack"].get<float>(),
					pokemon["defense"].get<float>())));
		}

		for (int i = 0; i < this->all_pokemon_templates.size(); i++)
		{
			all_pokemon_templates[i].showStats();
		}
	}
	else
	{
		cout << "ERROR : missing pokemons data" << endl;
	}
}

#endif
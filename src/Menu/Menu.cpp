#ifndef MENU_INCLUDED
#define MENU_INCLUDED

#include <iostream>
#include <unistd.h>

#include "menu.h"
#include "../Storage/Storage.cpp"
#include "../Player/Player.cpp"

using namespace std;

Menu::Menu(Player *player, Storage *storage)
{
	this->storage = storage;
	this->player = player;

	if (this->player->getTeam().size() == 0)
	{
		cout << endl
			 << "=============================" << endl
			 << "| MAISON DU PROFESSEUR CHEN |" << endl
			 << "=============================" << endl;
		sleep(1);
		cout << endl
			 << "'Bienvenue, jeune chasseur de pokémon !'" << endl
			 << "..." << endl;
		sleep(2);
		cout << "'Que dis-tu ?'" << endl
			 << "'Tu as besoin d'avoir un pokémon pour commencer ton aventure !?'" << endl
			 << "'Bon, je vais être serviable..'"
			 << endl;
		sleep(2);
		cout << endl
			 << "'Je te laisse choisir entre ces trois là, au moins !'" << endl
			 << endl
			 << " (っ▀¯▀)つ " << endl
			 << endl
			 << "1 pour Florizarre" << endl
			 << "2 pour Dracaufeu" << endl
			 << "3 pour Tortank" << endl
			 << endl;
		sleep(1);
		int userChoice = waitForValidUserInput(4, false);
		switch (userChoice)
		{
		case 1:
			cout << endl
				 << "'La nature est la plus forte !'" << endl
				 << "Tu as choisi Florizarre !" << endl
				 << " ᕙ(⇀‸↼‶)ᕗ " << endl
				 << endl;
			this->player->addPokemon(this->storage->getPokemonTemplate("Florizarre"));
			sleep(5);
			cout << "\033[2J\033[1;1H";
			break;
		case 2:
			cout << endl
				 << "'Tout feu tout flamme !'" << endl
				 << "Tu as choisi Dracaufeu !" << endl
				 << " ᕙ(⇀‸↼‶)ᕗ " << endl
				 << endl;
			this->player->addPokemon(this->storage->getPokemonTemplate("Dracaufeu"));
			sleep(5);
			cout << "\033[2J\033[1;1H";
			break;
		case 3:
			cout << endl
				 << "'Haha, il est toujours salé !'" << endl
				 << "Tu as choisi Tortank !" << endl
				 << " ᕙ(⇀‸↼‶)ᕗ " << endl
				 << endl;
			this->player->addPokemon(this->storage->getPokemonTemplate("Tortank"));
			sleep(5);
			cout << "\033[2J\033[1;1H";
			break;
		default:
			cout << endl
				 << "'Non ! Tu ne dois pas !!..'" << endl
				 << "Tu as obtenu Mewtwo !!" << endl
				 << " ᕦ(ò_óˇ)ᕤ " << endl
				 << endl;
			this->player->addPokemon(this->storage->getPokemonTemplate("Mewtwo"));
			sleep(5);
			cout << "\033[2J\033[1;1H";
			break;
		}
	}
}

Menu::~Menu() {}

void Menu::mainMenu()
{
	cout << endl
		 << "============================" << endl
		 << "|        POKEMON++         |" << endl
		 << "============================" << endl
		 << endl
		 << "1. Se balader dans les hautes herbes" << endl
		 << "2. Voir son équipe" << endl
		 << "3. Soigner son équipe" << endl
		 << "4. Voir ses pokémons dans le PC" << endl
		 << "5. Rentrer dans le magasin" << endl
		 << "6. Voir ses items dans son sac" << endl
		 << endl
		 << "0. Quitter" << endl
		 << endl;
	this->save();
	int userChoice = waitForValidUserInput(6);
	switch (userChoice)
	{
	case 1:
		cout << "\033[2J\033[1;1H";
		this->wildGrass();
		break;
	case 2:
		cout << "\033[2J\033[1;1H";
		this->team();
		break;
	case 3:
		cout << "\033[2J\033[1;1H";
		this->healTeam();
		break;
	case 4:
		cout << "\033[2J\033[1;1H";
		this->allPCTeam();
		break;
	case 5:
		cout << "\033[2J\033[1;1H";
		this->shop();
		break;
	case 6:
		cout << "\033[2J\033[1;1H";
		this->showBackpack();
		break;
	case 0:
		cout << "\033[2J\033[1;1H";
		this->save();
		cout << "Tu t'endors profondément..." << endl;
		exit(EXIT_SUCCESS);
		break;
	default:
		cout << "Input out of range... This shouldn't be see..." << endl;
		break;
	}
}

int Menu::waitForValidUserInput(int maxValid, bool canExit)
{
	int userChoice;
	while (!(cin >> userChoice) || !(userChoice <= maxValid && userChoice >= !canExit))
	{
		cout << "Choix non valide, réessayez." << endl;
		cin.clear();
		cin.ignore(255, '\n');
	}

	return userChoice;
}

void Menu::wildGrass(Pokemon *pokeSauvage, int attackingPokeIdx)
{
	int userChoice;
	vector<Pokemon> team = this->player->getTeam();
	int myPokemonIdx;
	if (attackingPokeIdx < 0)
	{
		myPokemonIdx = this->player->getFirstValidPokemonIndex();
	}
	else
	{
		myPokemonIdx = attackingPokeIdx;
	}

	if (myPokemonIdx < 0)
	{
		cout << "Vous n'avez aucun pokémon en état de se battre..." << endl;
		this->mainMenu();
		return;
	}
	Pokemon myPokemon = team[myPokemonIdx];
	if (pokeSauvage == 0)
	{
		Pokemon poke = this->storage->getRandomPokemon();
		pokeSauvage = &poke;
		cout << "Un " << pokeSauvage->name << " apparaît !" << endl
			 << endl;
	}
	if (myPokemon.getHP() > 0 && pokeSauvage->getHP() > 0)
	{
		cout << "À toi de jouer " << myPokemon.name << " !" << endl
			 << endl
			 << "Que vas-tu faire ?" << endl
			 << endl
			 << endl
			 << "1. Attaquer" << endl
			 << "2. Changer de pokémon" << endl
			 << "3. Objet" << endl
			 << "4. Fuir" << endl
			 << endl;
	}
	else if (!pokeSauvage->getHP() > 0)
	{
		cout << pokeSauvage->name << " est KO !" << endl
			 << endl
			 << "Tu as battu " << pokeSauvage->name << " !" << endl
			 << endl;
		cout << "\033[2J\033[1;1H";
		srand(time(NULL));
		this->player->addMoney(rand() % 100 + (pokeSauvage->getMaxHP())*2);
		this->save();
		this->mainMenu();
		return;
	}
	else
	{
		int newPokeIdx = this->player->getFirstValidPokemonIndex();
		if (newPokeIdx < 0)
		{
			cout << "Vous n'avez aucun pokémon en état de se battre..." << endl;
			this->save();
			this->mainMenu();
		}
		else
		{
			newPokeIdx = this->chooseAttackPoke(myPokemonIdx, true);
			this->save();
			this->wildGrass(pokeSauvage, newPokeIdx);
		}

		return;
	}

	cout << "Que doit faire " << myPokemon.name << " ?" << endl;
	userChoice = waitForValidUserInput(4, false);

	switch (userChoice)
	{
	case 1:
	{
		cout << "\033[2J\033[1;1H";
		myPokemon.attacking(*pokeSauvage);
		sleep(2.5);
		pokeSauvage->attacking(myPokemon);
		team[myPokemonIdx] = myPokemon;
		sleep(2.5);
		cout << "\033[2J\033[1;1H";
		this->player->setTeam(team);
		this->save();
		this->wildGrass(pokeSauvage, myPokemonIdx);
		break;
	}
	case 2:
	{
		cout << "\033[2J\033[1;1H";
		int newPokeIdx = this->chooseAttackPoke(myPokemonIdx);
		if (myPokemonIdx != newPokeIdx)
		{
			Pokemon *myNewPokemon = &(team[newPokeIdx]);
			pokeSauvage->attacking(*myNewPokemon);
			team[newPokeIdx] = *myNewPokemon;
			this->player->setTeam(team);
		}
		sleep(2.5);
		cout << "\033[2J\033[1;1H";
		this->save();
		this->wildGrass(pokeSauvage, newPokeIdx);
		break;
	}
	case 3:
	{
		sleep(2.5);
		cout << "\033[2J\033[1;1H";
		this->menuItem(pokeSauvage);
		this->save();
		this->wildGrass(pokeSauvage, myPokemonIdx);
		break;
	}
	case 4:
		sleep(2.5);
		cout << "\033[2J\033[1;1H";
		this->save();
		this->mainMenu();
		break;
	default:
		cout << "Input out of range... This shouldn't be see..." << endl;
		break;
	}
}

int Menu::chooseAttackPoke(int actualPokeIdx, bool forced)
{
	vector<Pokemon> team = this->player->getTeam();
	int userChoice;
	cout << "Tu as besoin d'un nouveau pokémon pour attaquer !" << endl
		 << endl;
	for (int i = 0; i < team.size(); i++)
	{
		string pokeName = team[i].name;
		string pokeHP = " (" + to_string(team[i].getHP()) + "/" + to_string(team[i].getMaxHP()) + ") ";
		team[i].getHP() > 0 ? pokeName += pokeHP : pokeName += " (KO)";
		cout << i + 1 << ". " << pokeName << endl;
	}

	if (!forced)
	{
		cout << endl
			 << "0. Retour" << endl
			 << endl
			 << "Quel pokémon choisis-tu donc ?" << endl;
	}
	else
	{
		cout << endl
			 << "Quel pokémon choisis-tu donc ?" << endl;
	}

	userChoice = this->waitForValidUserInput(team.size(), !forced);
	if (userChoice == 0)
	{
		return actualPokeIdx;
	}
	else if (team[userChoice - 1].getHP() == 0)
	{
		cout << "Ce pokémon est déjà KO !" << endl
			 << endl;
		userChoice = this->chooseAttackPoke(actualPokeIdx, forced) + 1;
	}

	return userChoice - 1;
}

void Menu::menuItem(Pokemon *pokeSauvage)
{
	vector<Item *> backpack = this->player->getBackpack();
	cout << endl
		 << "Ton inventaire :" << endl;
	map<Item *, int> inventory;
	for (int i = 0; i < backpack.size(); i++)
	{
		try
		{
			inventory[backpack[i]] += 1;
		}
		catch (exception e)
		{
			inventory[backpack[i]] = 1;
		}
	}

	map<string, int> inventoryName;
	for (int i = 0; i < backpack.size(); i++)
	{
		try
		{
			inventoryName[backpack[i]->name] += 1;
		}
		catch (exception e)
		{
			inventoryName[backpack[i]->name] = 1;
		}
	}

	int i = 0;
	int j = 0;
	map<int, Item *> dictItems;
	string lastItemName = "";
	for (auto item : inventory)
	{
		bool contains = false;
		for (auto dictItem : dictItems) {
			if (dictItem.second->name == item.first->name) 
			{
				contains = true;
			}
		}
		if (!contains) {
			i++;
			dictItems[i] = item.first;
		}
	}
	for (auto item : dictItems) {
		cout << item.first << "- " << item.second->name << " (" << inventoryName[item.second->name] << ")" << endl;
	}

	cout << endl
		 << "0. Retour" << endl
		 << endl;
	int userChoice = waitForValidUserInput(dictItems.size());
	if (userChoice == 0)
	{
		cout << "\033[2J\033[1;1H";
		this->wildGrass(pokeSauvage);
		return;
	}
	else
	{
		vector<Pokemon> team = this->player->getTeam();
		if (dictItems[userChoice]->type == "ball")
		{
			cout << "Tu as lancé une " << dictItems[userChoice]->name << " sur " << pokeSauvage->name << " !" << endl;
			if (dictItems[userChoice]->use(pokeSauvage))
			{
				this->player->addPokemon(*pokeSauvage);
				auto item = find(backpack.begin(), backpack.end(), dictItems[userChoice]);
				int indx = item - backpack.begin();
				backpack.erase(backpack.begin() + indx);
				this->player->setBackpack(backpack);
				this->mainMenu();
				return;
			}
			else
			{
				cout << pokeSauvage->name << " s'est échappé !" << endl;
			auto item = find(backpack.begin(), backpack.end(), dictItems[userChoice]);
			int indx = item - backpack.begin();
			backpack.erase(backpack.begin() + indx);
			this->player->setBackpack(backpack);
			}
		}
		else if (backpack[userChoice - 1]->type == "potion")
		{
			cout << endl
				 << "Ton équipe :" << endl;
			for (int i = 0; i < team.size(); i++)
			{
				string pokeName = team[i].name;
				string pokeHP = " (" + to_string(team[i].getHP()) + "/" + to_string(team[i].getMaxHP()) + ") ";
				team[i].getHP() > 0 ? pokeName += pokeHP : pokeName += " (KO)";
				cout << i + 1 << ". " << pokeName << endl;
			}
			cout << endl
				 << "0. Retour" << endl
				 << endl
				 << "Sur quel pokémon veux-tu utiliser cet objet ?" << endl;
			int userChoice2 = waitForValidUserInput(team.size());
			if (userChoice2 == 0)
			{
				cout << "\033[2J\033[1;1H";
				this->menuItem();
				return;
			}

			backpack[userChoice - 1]->use(&(team[userChoice2 - 1]));
			backpack.erase(backpack.begin() + userChoice - 1);
			this->player->setTeam(team);
			this->player->setBackpack(backpack);
		}
		sleep(3);
	}
}

void Menu::team()
{
	vector<Pokemon> team = this->player->getTeam();
	cout << endl
		 << "Ton équipe :" << endl;
	for (int i = 0; i < team.size(); i++)
	{
		string pokeName = team[i].name;
		string pokeHP = " (" + to_string(team[i].getHP()) + "/" + to_string(team[i].getMaxHP()) + ") ";
		team[i].getHP() > 0 ? pokeName += pokeHP : pokeName += " (KO)";
		cout << i + 1 << ". " << pokeName << endl;
	}

	cout << endl
		 << "0. Retour" << endl
		 << endl
		 << "Quel pokémon voulez-vous inspecter ?" << endl;
	int userChoice = waitForValidUserInput(team.size());
	if (userChoice == 0)
	{
		cout << "\033[2J\033[1;1H";
		this->mainMenu();
	}
	else
	{
		team[userChoice - 1].showStats();
		sleep(3);
		cout << "\033[2J\033[1;1H";
		this->save();
		this->team();
	}
}

void Menu::healTeam()
{
	vector<Pokemon> team = this->player->getTeam();
	cout << endl
		 << "=============================" << endl
		 << "|   HÔPITAL BOURG PALETTE   |" << endl
		 << "=============================" << endl
		 << endl
		 << endl
		 << "Tu arrives dans le centre hospitalier de Bourg Palette !" << endl
		 << "L'hôtesse te salue poliment" << endl
		 << endl
		 << " (๑•́ ₃ •̀๑) " << endl
		 << endl;
	sleep(2.5);
	cout << endl
		 << "Ton équipe :" << endl;
	for (int i = 0; i < team.size(); i++)
	{
		string pokeName = team[i].name;
		string pokeHP = " (" + to_string(team[i].getHP()) + "/" + to_string(team[i].getMaxHP()) + ") ";
		team[i].getHP() > 0 ? pokeName += pokeHP : pokeName += " (KO)";
		cout << i + 1 << ". " << pokeName << endl;
	}
	cout << "Ton argent : " << this->player->getMoney() << " ¤" << endl;
	sleep(2.5);
	cout << endl
		 << "'Avez-vous besoin de soigner des pokémons ?'" << endl
		 << endl
		 << "1. Soigner" << endl
		 << endl
		 << "0. Retour" << endl
		 << endl;
	sleep(2.5);
	int userChoice = waitForValidUserInput(1);
	int moneySpend = 0;
	switch (userChoice)
	{
	case 1:
		sleep(1.5);
		cout << "\033[2J\033[1;1H";
		for (int i = 0; i < team.size(); i++)
		{
			int pokeHP = team[i].getHP();
			int pokeMaxHP = team[i].getMaxHP();

			if (pokeHP == 0.0)
			{
				this->player->removeMoney(100);
				moneySpend += 100;
			}
			else if (pokeHP < pokeMaxHP && pokeHP != 0.0)
			{
				this->player->removeMoney(40);
				moneySpend += 40;
			}
		}
		this->player->healPokemons();
		this->save();
		cout << endl
			 << "'Voici la note que vous me devez pour soigner vos pokémons, cher chasseur : " << moneySpend << " ¤ !'" << endl
			 << "'Vos pokémons sont tous revigorés à 100%'" << endl
			 << endl
			 << " ( ˘ ³˘)♥ " << endl
			 << endl;
		team = this->player->getTeam();
		for (int i = 0; i < team.size(); i++)
		{
			string pokeName = team[i].name;
			string pokeHP = " (" + to_string(team[i].getHP()) + "/" + to_string(team[i].getMaxHP()) + ") ";
			cout << i + 1 << ". " << pokeName << pokeHP << endl;
		}
		cout << endl
			 << "Tu repars, toi et tes pokémons, joyeusement !"
			 << endl;
		sleep(5);
		cout << "\033[2J\033[1;1H";
		this->mainMenu();
		break;
	case 0:
		cout << "\033[2J\033[1;1H";
		cout << endl
			 << "Tu repars sans rien dire..." << endl
			 << endl;
		sleep(2.5);
		cout << "\033[2J\033[1;1H";
		this->mainMenu();
		break;
	default:
		cout << endl
			 << "'Excusez-moi ? Vous avez besoin d'aide ?' dit-elle en paniquant devant tes yeux vides..." << endl
			 << endl;
		sleep(2.5);
		this->healTeam();
		break;
	}
}

void Menu::allPCTeam()
{
	vector<Pokemon> team = player->getTeam();
	vector<Pokemon> teamPC = player->getTeamPC();
	cout << endl
		 << "Ton équipe :" << endl;
	for (int i = 0; i < team.size(); i++)
	{
		cout << "(" << i + 1 << ") " << team[i].name << endl;
	}

	for (int i = 0; i < 6 - team.size(); i++)
	{
		cout << "(" << (i + team.size()) + 1 << ") " << endl;
	}

	cout << endl
		 << "Tes pokémons dans le PC :" << endl;
	if (teamPC.size() > 0)
	{
		for (int i = 0; i < teamPC.size(); i++)
		{
			cout << "(" << i + 1 << ") " << teamPC[i].name << endl;
		}
	}
	else
	{
		cout << "(Vide)" << endl;
	}

	cout << endl
		 << "1. Echanger / Ajouter depuis le PC" << endl
		 << "2. Retirer de l'équipe" << endl
		 << "3. Supprimer du PC" << endl
		 << "0. Retour" << endl
		 << endl;
	int userChoice = waitForValidUserInput(3);
	switch (userChoice)
	{
	case 1:
	{
		cout << "Sélectionne un emplacement dans votre équipe (1 à 6)" << endl;
		int pokemonSelected = waitForValidUserInput(6);
		cout << "Sélectionne un pokémon dans votre PC" << endl;
		int pokemonPCSelected = waitForValidUserInput(teamPC.size());
		cout << "Echange en cours..." << endl;
		this->player->swapPokemon(pokemonSelected, pokemonPCSelected);
		sleep(2.5);
		cout << "\033[2J\033[1;1H";
		this->save();
		this->allPCTeam();
		break;
	}
	case 2:
		if (team.size() == 1)
		{
			cout << "Tu ne peux pas avoir une équipe vide. C'est bien trop dangereux !" << endl;
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->save();
			this->allPCTeam();
		}
		else
		{
			cout << "Quel pokémon veux-tu retirer de l'équipe ? Il sera transféré dans le PC." << endl;
			int toMove = waitForValidUserInput(team.size());
			cout << team[toMove - 1].name << " a été transféré dans le PC !" << endl;
			this->player->moveToPC(toMove);
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->save();
			this->allPCTeam();
		}
		break;
	case 3:
	{
		if (teamPC.size() == 0)
		{
			cout << "Ton PC est vide. Capture d'autres pokémons !" << endl;
			sleep(2.5);
		}
		else
		{
			cout << "Quel pokémon veux-tu supprimer du PC ?" << endl;
			int toRemove = waitForValidUserInput(teamPC.size());
			if (toRemove != 0)
			{
				cout << teamPC[toRemove - 1].name << " a été relaché dans la nature..." << endl;
				this->player->removeFromPC(toRemove);
				sleep(2.5);
			}
		}
		cout << "\033[2J\033[1;1H";
		this->save();
		this->allPCTeam();
		break;
	}
	case 0:
		this->mainMenu();
		break;
	}
}

void Menu::shop()
{
	cout << "'Bienvenue dans le magasin, que voulez-vous acheter ?'" << endl
		 << endl
		 << "1. Pokeball" << endl
		 << "2. Superball" << endl
		 << "3. Hyperball" << endl
		 << "4. Masterball" << endl
		 << "5. Potion" << endl
		 << "6. Superpotion" << endl
		 << "7. Hyperpotion" << endl
		 << "8. Potionmax" << endl
		 << endl
		 << "0. Retour" << endl
		 << endl;
	int userChoice = this->waitForValidUserInput(8);
	if (userChoice != 0)
	{
		cout << endl
			 << "'Vous ne pouvez qu'en prendre 20 maximum !'" << endl
			 << endl;
		int howMuch = this->waitForValidUserInput(20);
		if (howMuch == 0)
		{
			cout << endl
				 << "'Vous me faites perdre mon temps.. Au revoir !!'" << endl;
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->mainMenu();
			return;
		}
		switch (userChoice)
		{
		case 1:
			this->player->buyItem("Pokeball", howMuch);
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->save();
			this->mainMenu();
			break;
		case 2:
			this->player->buyItem("Superball", howMuch);
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->save();
			this->mainMenu();
			break;
		case 3:
			this->player->buyItem("Hyperball", howMuch);
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->save();
			this->mainMenu();
			break;
		case 4:
			this->player->buyItem("Masterball", howMuch);
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->save();
			this->mainMenu();
			break;
		case 5:
			this->player->buyItem("Potion", howMuch);
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->save();
			this->mainMenu();
			break;
		case 6:
			this->player->buyItem("Superpotion", howMuch);
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->save();
			this->mainMenu();
			break;
		case 7:
			this->player->buyItem("Hyperpotion", howMuch);
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->save();
			this->mainMenu();
			break;
		case 8:
			this->player->buyItem("Potionmax", howMuch);
			sleep(2.5);
			cout << "\033[2J\033[1;1H";
			this->save();
			this->mainMenu();
			break;
		default:
			this->mainMenu();
			break;
		}
	}
	else
	{
		cout << endl
			 << "Vous me faites perdre mon temps.. Au revoir !" << endl;
		sleep(2.5);
		cout << "\033[2J\033[1;1H";
		this->mainMenu();
	}
}

void Menu::showBackpack()
{
	vector<Item *> backpack = this->player->getBackpack();
	cout << endl
		 << "Ton inventaire :" << endl;
	map<string, int> inventory;
	for (int i = 0; i < backpack.size(); i++)
	{
		try
		{
			inventory[backpack[i]->name] += 1;
		}
		catch (exception e)
		{
			inventory[backpack[i]->name] = 1;
		}
	}

	for (auto item : inventory)
	{
		cout << "- " << item.first << " (" << item.second << ")" << endl;
	}

	cout << endl;
	sleep(3);
	cout << "\033[2J\033[1;1H";
	this->mainMenu();
}

void Menu::save()
{
	this->storage->saveConfig(this->player);
	this->storage->savePlayer(this->player);
}

#endif
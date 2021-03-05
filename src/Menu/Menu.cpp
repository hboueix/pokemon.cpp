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
			 << "| MAISON DU DOCTEUR LAFLEUR |" << endl
			 << "=============================" << endl;
		sleep(1);
		cout << endl
			 << "'Bienvenue, jeune chasseur de pokémon !'" << endl
			 << "..." << endl;
		sleep(2);
		cout << "'Que dis-tu ?'" << endl
			 << "'Tu as besoin d'avoir un pokémon gRaTuIt pour commencer ton aventure !?'" << endl
			 << "'Bon, je vais être serviable..'"
			 << endl;
		sleep(2);
		cout << endl
			 << "'Je te laisse choisir entre ces trois là, au moins !'" << endl
			 << endl
			 << " (っ▀¯▀)つ " << endl
			 << endl
			 << "1 pour Bulbizarre" << endl
			 << "2 pour Salamèche" << endl
			 << "3 pour Carapuce" << endl
			 << endl;
		sleep(1);
		int userChoice = waitForValidUserInput(4, "'Choisis bien, pas d'échanges !'", false);
		switch (userChoice)
		{
		case 1:
			cout << endl
				 << "'La nature est la plus forte !'" << endl
				 << "Tu as choisi Bulbizarre !" << endl
				 << " ᕙ(⇀‸↼‶)ᕗ " << endl
				 << endl;
			this->player->addPokemon(this->storage->getPokemonTemplate("Bulbizarre"));
			sleep(5);
			break;
		case 2:
			cout << endl
				 << "'Tout feu tout flamme !'" << endl
				 << "Tu as choisi Salamèche !" << endl
				 << " ᕙ(⇀‸↼‶)ᕗ " << endl
				 << endl;
			this->player->addPokemon(this->storage->getPokemonTemplate("Salamèche"));
			sleep(5);
			break;
		case 3:
			cout << endl
				 << "'Haha, il est toujours salé !'" << endl
				 << "Tu as choisi Carapuce !" << endl
				 << " ᕙ(⇀‸↼‶)ᕗ " << endl
				 << endl;
			this->player->addPokemon(this->storage->getPokemonTemplate("Carapuce"));
			sleep(5);
			break;
		default:
			cout << endl
				 << "'Non ! Tu ne dois pas !!..'" << endl
				 << "Tu as obtenu Pikachu !!" << endl
				 << " ᕦ(ò_óˇ)ᕤ " << endl
				 << endl;
			this->player->addPokemon(this->storage->getPokemonTemplate("Pikachu"));
			sleep(5);
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
		 << endl
		 << "0. Quitter" << endl
		 << endl;
	this->save();
	int userChoice = waitForValidUserInput(4);
	switch (userChoice)
	{
	case 1:
		this->wildGrass();
		break;
	case 2:
		this->team();
		break;
	case 3:
		this->healTeam();
	case 4:
		this->allPCTeam();
		break;
	case 0:
		this->save();
		cout << "Bye !" << endl;
		break;
	default:
		cout << "Input out of range... This shouldn't be see..." << endl;
		break;
	}
}

int Menu::waitForValidUserInput(int maxValid, string question, bool canExit)
{
	cout << question << endl;
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
	int myPokemonIdx = this->player->getFirstValidPokemonIndex();
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
	}

	if (myPokemon.getHP() > 0 && pokeSauvage->getHP() > 0)
	{
		cout << "Un " << pokeSauvage->name << " apparaît!" << endl
			 << "En Avant " << myPokemon.name << "!" << endl
			 << "============================" << endl;
		cout << "Que voulez vous faire?" << endl
			 << "============================" << endl
			 << endl
			 << "1. Attaquer" << endl
			 << "2. Changer de Pokemon" << endl
			 << "3. Objet" << endl
			 << "4. Fuir" << endl
			 << endl;
	}
	else if (!pokeSauvage->getHP() > 0)
	{
		cout << pokeSauvage->name << " est KO !" << endl
			 << "Vous avez battu le pokémon sauvage !" << endl;
		this->save();
		this->mainMenu();
		return;
	}
	else
	{
		cout << "Votre pokémon est KO..." << endl;
		this->save();
		this->mainMenu();
		return;
	}

	userChoice = waitForValidUserInput(4, "Que doit faire " + myPokemon.name + " ?", false);
	switch (userChoice)
	{
	case 1:
	{
		myPokemon.attacking(*pokeSauvage);
		pokeSauvage->attacking(myPokemon);
		team[myPokemonIdx] = myPokemon;
		this->player->setTeam(team);
		this->save();
		this->wildGrass(pokeSauvage);
		break;
	}
	case 2:
	{
		int newPokeIdx = this->chooseAttackPoke(myPokemonIdx);
		if (myPokemonIdx != newPokeIdx)
		{
			pokeSauvage->attacking(myPokemon);
			team[myPokemonIdx] = myPokemon;
			this->player->setTeam(team);
		}
		this->save();
		this->wildGrass(pokeSauvage, newPokeIdx);
		break;
	}
	case 3:
		this->save();
		this->menuItem();
		this->wildGrass(pokeSauvage);
		break;
	case 4:
		this->save();
		this->mainMenu();
		break;
	default:
		cout << "Input out of range... This shouldn't be see..." << endl;
		break;
	}
}

int Menu::chooseAttackPoke(int actualPokeIdx)
{
	vector<Pokemon> team = this->player->getTeam();
	int userChoice;
	cout << "Choisis ton nouveau pokémon pour attaquer !" << endl
		 << endl;
	for (int i = 0; i < team.size(); i++)
	{
		string pokeName = team[i].name;
		string pokeHP = " (" + to_string(team[i].getHP()) + "/" + to_string(team[i].getMaxHP()) + ") ";
		team[i].getHP() > 0 ? pokeName += pokeHP : pokeName += " (KO)";
		cout << i + 1 << ". " << pokeName << endl;
	}

	cout << endl
		 << "0. Retour" << endl
		 << endl;
	userChoice = this->waitForValidUserInput(team.size());
	if (userChoice == 0)
	{
		return actualPokeIdx;
	}
	else if (team[userChoice - 1].getHP() == 0)
	{
		cout << "Ce pokémon est déjà KO !" << endl
			 << endl;
		userChoice = this->chooseAttackPoke(actualPokeIdx);
	}

	return userChoice - 1;
}

void Menu::menuItem()
{
	vector<Item *> backpack = this->player->getBackPack();
	cout << endl
		 << "Votre inventaire :" << endl;
	// cout << backpack << endl;
	for (int i = 0; i < backpack.size(); i++)
	{
		// string itemName = backpack[i].name;
		cout << i + 1 << ". " << backpack[i]->name << endl;
	}

	cout << endl
		 << "0. Retour" << endl
		 << endl;
	int userChoice = waitForValidUserInput(backpack.size());
	if (userChoice == 0)
	{
		this->wildGrass();
		return;
	}
	else
	{
		//TODO choisir entre ball ou potion
		// cout << backpack[userChoice-1]->name.find("ball") << endl;
		// if (backpack[userChoice-1]->name.find("ball")) {
		// 	cout << "catch! or not" << endl;
		// }
		if (backpack[userChoice - 1]->name.find("otion"))
		{
			vector<Pokemon> team = player->getTeam();
			cout << endl
				 << "Your team :" << endl;
			for (int i = 0; i < team.size(); i++)
			{
				string pokeName = team[i].name;
				string pokeHP = " (" + to_string(team[i].getHP()) + "/" + to_string(team[i].getMaxHP()) + ") ";
				team[i].getHP() > 0 ? pokeName += pokeHP : pokeName += " (KO)";
				cout << i + 1 << ". " << pokeName << endl;
			}
			cout << endl
				 << "0. Retour" << endl
				 << endl;
			//affiche liste pokemon team
			int userChoice2 = waitForValidUserInput(backpack.size(), "Sur quel Pokemon voulez vous utilisez cet objet?");
			if (userChoice2 == 0)
			{
				this->menuItem();
				return;
			}

			backpack[userChoice - 1]->use(&(team[userChoice2 - 1]));
			this->player->setTeam(team);
		}
		sleep(3);
		// this->save();
	}
}

void Menu::team()
{
	vector<Pokemon> team = this->player->getTeam();
	cout << endl
		 << "Votre équipe :" << endl;
	for (int i = 0; i < team.size(); i++)
	{
		string pokeName = team[i].name;
		string pokeHP = " (" + to_string(team[i].getHP()) + "/" + to_string(team[i].getMaxHP()) + ") ";
		team[i].getHP() > 0 ? pokeName += pokeHP : pokeName += " (KO)";
		cout << i + 1 << ". " << pokeName << endl;
	}

	cout << endl
		 << "0. Retour" << endl
		 << endl;
	int userChoice = waitForValidUserInput(team.size(), "Quel pokémon voulez-vous inspecter ?");
	if (userChoice == 0)
	{
		this->mainMenu();
	}
	else
	{
		team[userChoice - 1].showStats();
		sleep(3);
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
		 << "2. Retour" << endl
		 << endl;
	sleep(2.5);
	int userChoice = waitForValidUserInput(2, "Tu réfléchis longuement...", false);
	int moneySpend = 0;
	switch (userChoice)
	{
	case 1:
		sleep(1.5);
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
		this->mainMenu();
		break;
	case 2:
		cout << endl
			 << "Tu repars sans rien dire..." << endl
			 << endl;
		sleep(2.5);
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
		 << "Votre équipe :" << endl;
	for (int i = 0; i < team.size(); i++)
	{
		cout << "(" << i + 1 << ") " << team[i].name << endl;
	}

	for (int i = 0; i < 6 - team.size(); i++)
	{
		cout << "(" << (i + team.size()) + 1 << ") " << endl;
	}

	cout << endl
		 << "Vos pokémons dans le PC :" << endl;
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
		cout << "Sélectionnez un emplacement dans votre équipe (1 à 6)" << endl;
		int pokemonSelected = waitForValidUserInput(6);
		cout << "Sélectionnez un pokémon dans votre PC" << endl;
		int pokemonPCSelected = waitForValidUserInput(teamPC.size());
		cout << "Echange en cours..." << endl;
		this->player->swapPokemon(pokemonSelected, pokemonPCSelected);
		sleep(1);
		this->save();
		this->allPCTeam();
		break;
	}
	case 2:
		if (team.size() == 1)
		{
			cout << "Vous ne pouvez pas avoir une équipe vide. C'est bien trop dangereux !" << endl;
			sleep(2);
			this->save();
			this->allPCTeam();
		}
		else
		{
			cout << "Quel pokémon voulez-vous retirer de l'équipe ? Il sera transféré dans le PC." << endl;
			int toMove = waitForValidUserInput(team.size());
			cout << team[toMove - 1].name << " a été transféré dans le PC !" << endl;
			this->player->moveToPC(toMove);
			sleep(1);
			this->save();
			this->allPCTeam();
		}
		break;
	case 3:
	{
		if (teamPC.size() == 0)
		{
			cout << "Votre PC est vide. Capturez d'autres pokémons !" << endl;
			sleep(1);
		}
		else
		{
			cout << "Quel pokémon voulez-vous supprimer du PC ?" << endl;
			int toRemove = waitForValidUserInput(teamPC.size());
			if (toRemove != 0)
			{
				cout << teamPC[toRemove - 1].name << " a été relaché dans la nature..." << endl;
				this->player->removeFromPC(toRemove);
				sleep(1);
			}
		}
		this->save();
		this->allPCTeam();
		break;
	}
	case 0:
		this->mainMenu();
		break;
	}
}

void Menu::save()
{
	this->storage->saveConfig(this->player);
	this->storage->savePlayer(this->player);
}

#endif
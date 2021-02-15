#ifndef MENU_INCLUDED
#define MENU_INCLUDED

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include "menu.h"
#include "../Storage/Storage.cpp"
#include "../Player/Player.cpp"

using namespace std;

Menu::Menu(Player *player, Storage *storage) { 
	this->storage = storage;
	this->player = player;
}

Menu::~Menu() { }

void Menu::mainMenu() {
	cout << "============================" << endl
		<< "|        POKEMON++         |" << endl
		<< "============================" << endl << endl 
		<< "1. Se balader dans les hautes herbes" << endl
		<< "2. Voir son équipe" << endl
		<< "3. Soigner son équipe" << endl
		<< "4. Voir ses pokémons dans le PC" << endl
		<< endl << "0. Quitter" << endl << endl;
	int userChoice = waitForValidUserInput(4);
	switch (userChoice) {
		case 1:
		{
			this->wildGrass();
			break;
		}
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
			// exit(EXIT_SUCCESS);
			break;
		default:
			cout << "Input out of range... This shouldn't be see..." << endl;
			break;
	}
}

int Menu::waitForValidUserInput(int maxValid) {
	cout << "Que voulez-vous faire ?" << endl;
	int userChoice;
	while (!(cin >> userChoice) || !(userChoice <= maxValid && userChoice >= 0)) {
		cout << "Choix non valide, réessayez." << endl;
		cin.clear();
		cin.ignore(255, '\n');
	}

	return userChoice;
}

void Menu::wildGrass() {
	int userChoice;
	vector<Pokemon> team = player->getTeam();
	Pokemon *pokeSauvage = new Pokemon("Roucool");
	cout << "Un "<< pokeSauvage->name <<" apparaît!" << endl
		<< "En Avant " << team[0].name << "!"<< endl
		<< "============================" << endl;
	while (team[0].getHP() > 0 && pokeSauvage->getHP() > 0) {
		cout << "Que voulez vous faire?" << endl
			<< "============================" << endl << endl 
			<< "1. Attaquer" << endl
			<< "2. Changer de Pokemon" << endl
			<< "3. Objet" << endl
			<< "4. fuir" << endl
			<< endl << "0. Quitter" << endl << endl;
		userChoice = waitForValidUserInput(4);
		switch (userChoice) {
			case 1:
			{
				team[0].attacking(*pokeSauvage);
				this->save();
				break;
			}
			case 2:
				// this->team();
				break;
			case 3:
				// this->healTeam();
			case 4:
				// this->allPCTeam();
				break;
			case 0:
				cout << "Bye !" << endl;
				exit(EXIT_SUCCESS);
				break;
			default:
				cout << "Input out of range... This shouldn't be see..." << endl;
				break;
		}
	}
	cout << "combat terminé!" << endl;
	this->mainMenu();
	
}

void Menu::team() {
	vector<Pokemon> team = player->getTeam();
	cout << endl << "Your team :" << endl;
	for (int i = 0; i < team.size(); i++) {
		string pokeName = team[i].name;
		team[i].getHP() > 0 ? pokeName += "" : pokeName += " (KO)";
		cout << i+1 << ". " << team[i].name << endl;
	}

	cout << endl << "0. Retour" << endl << endl;
	int userChoice = waitForValidUserInput(team.size());
	if (userChoice == 0) {
		this->mainMenu();
	} else {
		team[userChoice-1].showStats();
		sleep(5);
		this->save();
		this->team();
	}
}

void Menu::healTeam() {

}

void Menu::allPCTeam() {
	vector<Pokemon> team = player->getTeam();
	vector<Pokemon> teamPC = player->getTeamPC();
	cout << endl << "Your team :" << endl;
	for (int i = 0; i < team.size(); i++) {
		cout << "(" << i+1 << ") " << team[i].name << endl;
	}

	for (int i = 0; i < 6 - team.size(); i++) {
		cout << "(" << (6 - team.size()) + i+1 << ") " << endl;
	}

	cout << endl << "Your PC :" << endl;
	if (teamPC.size() > 0) {
		for (int i = 0; i < teamPC.size(); i++) {
			cout << "(" << i+1 << ") " << teamPC[i].name << endl;
		}
	} else {
		cout << "(Vide)" << endl;
	}

	cout << endl << "1. Echanger / Ajouter depuis le PC" << endl
		<< "2. Retirer de l'équipe" << endl
		<< "3. Supprimer du PC" << endl
		<< "0. Retour" << endl << endl;
	int userChoice = waitForValidUserInput(3);
	switch (userChoice) {
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
			if (team.size() == 1) {
				cout << "Vous ne pouvez pas avoir une équipe vide. C'est bien trop dangereux !" << endl;
				sleep(2);
				this->save();
				this->allPCTeam();
			} else {
				cout << "Quel pokémon voulez-vous retirer de l'équipe ? Il sera transféré dans le PC." << endl;
				int toMove = waitForValidUserInput(team.size());
				cout << team[toMove-1].name << " a été transféré dans le PC !" << endl;
				this->player->moveToPC(toMove);
				sleep(1);
				this->save();
				this->allPCTeam();
			}
			break;
		case 3:
		{
			if (teamPC.size() == 0) {
				cout << "Votre PC est vide. Capturez d'autres pokémons !" << endl;
				sleep(1); 
			} else {
				cout << "Quel pokémon voulez-vous supprimer du PC ?" << endl;
				int toRemove = waitForValidUserInput(teamPC.size());
				if (toRemove != 0) {
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

void Menu::save() {
	this->storage->savePlayer(this->player);
}

#endif
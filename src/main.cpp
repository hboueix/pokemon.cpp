#include <iostream>

#include "Storage/Storage.cpp"
#include "Menu/Menu.cpp"
#include "Player/Player.cpp"
#include "Pokemon/Pokemon.cpp"

using namespace std;

int main()
{
	Storage *storage = new Storage();
	// TODO move this into a new menu method
	cout << "                                  ,'\\" << endl
		 << "    _.----.        ____         ,'  _\\   ___    ___     ____" << endl
		 << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << endl
		 << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << endl
		 << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << endl
		 << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << endl
		 << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << endl
		 << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << endl
		 << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << endl
		 << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << endl
		 << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << endl
		 << "                                `'                            '-._|" << endl
		 << endl
		 << endl
		 << "1. Nouvelle partie" << endl
		 << "2. Charger une partie" << endl;

	string playerName;
	int choice;
	cin >> choice;
	cin.clear();
	cin.ignore(255, '\n');
	if (choice == 2)
	{
		vector<string> players = storage->loadPlayers();
		if (players.size() > 0)
		{
			// TODO be able to create a new player even if existing players
			cout << "Sauvegarde(s) existante(s) :" << endl;
			for (int i = 0; i < players.size(); i++)
			{
				cout << to_string(i + 1) + ". " << players[i] << endl;
			}
			cout << "Sélectionnez la sauvegarde que vous voulez charger ou chargez la dernière sauvegarde en tapant 'ENTER'." << endl;
			cout << "Chargez une sauvegarde (defaut : " + storage->getLastPlayerName() + "): ";
			string userChoice;
			bool validChoice = false;
			do
			{
				getline(cin, userChoice);
				if (userChoice == "")
				{
					validChoice = true;
					break;
				}
				else
				{
					try
					{
						int choice = stoi(userChoice);
						if (choice <= players.size() && choice >= 1)
						{
							validChoice = true;
						}
						else
						{
							throw exception();
						}
					}
					catch (exception e)
					{
						cout << endl
							 << "Choix non valide, réessayez." << endl
							 << endl;
						cout << "Sauvegarde(s) existante(s) :" << endl;
						for (int i = 0; i < players.size(); i++)
						{
							cout << to_string(i + 1) + ". " << players[i] << endl;
						}
						cout << "Sélectionnez la sauvegarde que vous voulez charger ou chargez la dernière sauvegarde en tapant 'ENTER'." << endl;
						cout << "Chargez une sauvegarde (defaut : " + storage->getLastPlayerName() + "): ";
					}
				}
			} while (!validChoice);

			if (userChoice != "")
			{
				playerName = players[stoi(userChoice) - 1];
			}
			else
			{
				playerName = storage->getLastPlayerName();
			}
		}
		else
		{
			cout << "Aucune sauvegarde existante." << endl;
			cout << "Nouveau joueur : ";
			cin >> playerName;
		}
	}
	else if (choice == 1)
	{
		cout << "Nouveau joueur : ";
		cin >> playerName;
	}

	Player *player = storage->loadPlayer(playerName);
	Menu *myMenu = new Menu(player, storage);
	// storage->load_pokemons();
	myMenu->mainMenu();
	// cout << storage->read("." + playerName + ".pokesave") << endl;

	return 0;
}
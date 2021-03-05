#include <iostream>

#include "Storage/Storage.cpp"
#include "Menu/Menu.cpp"
#include "Player/Player.cpp"
#include "Pokemon/Pokemon.cpp"

using namespace std;

string login(Storage *storage)
{
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
		 << "2. Charger une partie" << endl
		 << endl;

	string playerName;
	int loginChoice;
	while (!(cin >> loginChoice) || (loginChoice != 1 && loginChoice != 2))
	{
		cout << endl
			 << "Choix non valide ! Choix possibles : 1 ou 2" << endl
			 << "1. Nouvelle partie" << endl
			 << "2. Charger une partie" << endl
			 << endl;
		cin.clear();
		cin.ignore(255, '\n');
	}

	cin.clear();
	cin.ignore(255, '\n');
	switch (loginChoice)
	{
	case 2:
	{
		vector<string> players = storage->loadPlayers();
		if (players.size() > 0)
		{
			cout << endl
				 << "Sauvegarde(s) existante(s) :" << endl;
			for (int i = 0; i < players.size(); i++)
			{
				cout << to_string(i + 1) + ". " << players[i] << endl;
			}
			cout << endl
				 << "Sélectionnez la sauvegarde que vous voulez charger ou chargez la dernière sauvegarde en tapant 'ENTER'." << endl
				 << "Chargez une sauvegarde (defaut : " + storage->getLastPlayerName() + "): ";
			string playerChoice;
			bool isValidChoice = false;
			do
			{
				getline(cin, playerChoice);
				if (playerChoice == "")
				{
					isValidChoice = true;
					break;
				}
				else
				{
					try
					{
						int choice = stoi(playerChoice);
						if (choice <= players.size() && choice >= 1)
						{
							isValidChoice = true;
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
							 << endl
							 << "Sauvegarde(s) existante(s) :" << endl;
						for (int i = 0; i < players.size(); i++)
						{
							cout << to_string(i + 1) + ". " << players[i] << endl;
						}
						cout << endl
							 << "Sélectionnez la sauvegarde que vous voulez charger ou chargez la dernière sauvegarde en tapant 'ENTER'." << endl
							 << "Chargez une sauvegarde (defaut : " + storage->getLastPlayerName() + "): ";
					}
				}
			} while (!isValidChoice);

			if (playerChoice != "")
			{
				playerName = players[stoi(playerChoice) - 1];
			}
			else
			{
				playerName = storage->getLastPlayerName();
			}
		}
		else
		{
			cout << "Aucune sauvegarde existante." << endl
				 << "Nouveau joueur : ";
			cin >> playerName;
		}

		break;
	}
	case 1:
	{
		cout << "Nouveau joueur : ";
		cin >> playerName;
		break;
	}
	}

	return playerName;
}

int main()
{
	Storage *storage = new Storage();
	string playerName = login(storage);
	cout << "\033[2J\033[1;1H";
	Player *player = storage->loadPlayer(playerName);
	Menu *myMenu = new Menu(player, storage);
	myMenu->mainMenu();

	return 0;
}
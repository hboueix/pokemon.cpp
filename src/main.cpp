#include <iostream>

#include "Storage/Storage.cpp"
#include "Menu/Menu.cpp"
#include "Player/Player.cpp"
#include "Pokemon/Pokemon.cpp"

using namespace std;

int main() {
	string playerName;
	cout << "Nom du joueur : ";
	cin >> playerName; 
	Storage *storage = new Storage();
	Player *player = storage->loadPlayer(playerName);
	Menu *myMenu = new Menu(player, storage);
	// storage->load_pokemons();
	myMenu->mainMenu();
	// cout << storage->read("." + playerName + ".pokesave") << endl;
	
	return 0;
}
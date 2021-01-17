#ifndef POKEMON_INCLUDED
#define POKEMON_INCLUDED

Pokemon::Pokemon(string pokemonName) {
	name = pokemonName;
	type = "Not implemented";
	attack = 10.0;
	defense = 5.0;
}

Pokemon::~Pokemon() {

}

void Pokemon::showStats() {
	cout << "Nom : " << this->name << endl;
	cout << "Type : " << this->type << endl;
	cout << "ATQ : " << this->attack << endl;
	cout << "DEF : " << this->defense << endl;
}

#endif
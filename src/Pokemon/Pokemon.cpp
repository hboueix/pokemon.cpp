#ifndef POKEMON_INCLUDED
#define POKEMON_INCLUDED

Pokemon::Pokemon(string pokemonName) {
	name = pokemonName;
	type = "Not implemented";
	maxHP = 30.0;
	HP = maxHP;
	attack = 10.0;
	defense = 5.0;
}

Pokemon::Pokemon(string pokemonName, string type, float maxHP, float attack, float defense) {
	name = pokemonName;
	type = type;
	maxHP = maxHP;
	HP = maxHP;
	attack = attack;
	defense = defense;
}

Pokemon::~Pokemon() {

}

void Pokemon::showStats() {
	cout << "Nom : " << this->name << endl
		<< "Type : " << this->type << endl
		<< "HP/maxHP : " << this->HP << " / " << this->maxHP << endl
		<< "ATQ : " << this->attack << endl
		<< "DEF : " << this->defense << endl;
}

void Pokemon::attacking(Pokemon &defender) {
	int damage = this->attack-defender.getDefense();
	if (defender.getHP() - damage > 0) {
		defender.setHP(defender.getHP()-damage);
		cout << this->name << " a infligé " << damage << "HP à " << defender.name << endl
			<< "Il reste " << defender.getHP() << "HP à " << defender.name << endl;
	} else {
		defender.setHP(0);
		cout << this->name << " a infligé " << defender.getHP() << "HP à " << defender.name << endl
			<< defender.name << " est KO." << endl;
	}
}

int Pokemon::getHP(){
	return HP;
}

int Pokemon::getAttack(){
	return attack;
}

int Pokemon::getDefense(){
	return defense;
}

void Pokemon::setHP(int PDV) {
	HP = PDV; 
}


#endif
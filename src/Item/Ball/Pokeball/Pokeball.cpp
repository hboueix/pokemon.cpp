#ifndef POKEBALL_INCLUDED
#define POKEBALL_INCLUDED

#include "pokeball.h"
// #include "../Ball.cpp"

Pokeball::Pokeball():Ball()  {
    name = "Pokeball";
    description = "description for pokeball";
}

Pokeball::~Pokeball() {

}

bool Pokeball::use(Pokemon* pokemon) const {
    int pokeMaxHP = pokemon->getMaxHP();
    int pokeHP = pokemon->getHP();
    return true;
    //TODO: mettre au point un calcul de proba de reussite pour capture
    // int chanceOfCapture = ((1-(pokeHP/pokeMaxHP))/chanceOfSuccess)*100;
    // srand(time(NULL));
    // int random = rand() % 100; 
    // if (random <= chanceOfCapture) {
    // cout << "PokemonCapturé!." << name << chanceOfSuccess << endl;
    // } else {
    //     cout << pokemon->name << " a reussi à s'échapper" << endl;
    // }
    
}

#endif
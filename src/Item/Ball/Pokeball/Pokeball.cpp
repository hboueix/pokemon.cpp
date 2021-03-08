#ifndef POKEBALL_INCLUDED
#define POKEBALL_INCLUDED

#include "pokeball.h"
// #include "../Ball.cpp"

Pokeball::Pokeball():Ball()  {
    name = "Pokeball";
    description = "description for pokeball";
    chanceOfSuccess = 0.20;
}

Pokeball::~Pokeball() {

}

bool Pokeball::use(Pokemon* pokemon) const {
    int pokeMaxHP = pokemon->getMaxHP();
    int pokeHP = pokemon->getHP();
    //TODO: mettre au point un calcul de proba de reussite pour capture
    int percentHp = (pokeHP/pokeMaxHP)*100;
    int chanceOfCapture = ((1-(pokeHP/pokeMaxHP))/chanceOfSuccess);
    srand(time(NULL));
    int random = rand() % 100; 
    cout << chanceOfSuccess << " _ " << percentHp << " _ " <<  random << " _ " << chanceOfCapture << endl;
    if (random <= chanceOfCapture) 
    {
        return true;
    } 
    else 
    {
        return false;
    }
    
}

#endif
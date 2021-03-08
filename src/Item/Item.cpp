#ifndef ITEM_INCLUDED
#define ITEM_INCLUDED

#include "item.h"

Item::Item() {
	name ="item";
	description="no description for item";
	prix = 0;
}

Item::~Item() {
	
}

int Item::getPrix() {
	return prix;
}

string Item::getDescription() {
	return description;
}


#endif
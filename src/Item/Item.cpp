#ifndef ITEM_INCLUDED
#define ITEM_INCLUDED

#include "item.h"

Item::Item() {
	name ="item";
	description="no description for item";
}

Item::~Item() {
	
}

void Item::use() const {
    cout << "Ceci est un item." << name << endl;
}

string Item::getDescription() {
	return description;
}


#endif
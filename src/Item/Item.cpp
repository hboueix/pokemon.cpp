#ifndef ITEM_INCLUDED
#define ITEM_INCLUDED

#include "item.h"

Item::Item() {
	name ="item";
	description="no description for item";
}

Item::~Item() {
	
}

void Item::affiche() const {
    cout << "Ceci est un item." << name << endl;
}

// void Item::use(Item const& i) {
// 	cout << "use" << i.name << endl;
// }

string Item::getDescription() {
	return description;
}


#endif
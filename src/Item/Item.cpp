#ifndef ITEM_INCLUDED
#define ITEM_INCLUDED

#include "item.h"

Item::Item() {
	name ="item";
	description="no description for item";
}

Item::~Item() {
	
}


string Item::getDescription() {
	return description;
}


#endif
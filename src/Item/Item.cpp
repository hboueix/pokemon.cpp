#ifndef ITEM_INCLUDED
#define ITEM_INCLUDED

#include "item.h"

Item::Item() {
	name ="";
	description="";
}

Item::~Item() {

}

string Item::getDescription() {
	return description;
}


#endif
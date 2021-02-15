#ifndef ITEM_HEADERS_INCLUDED
#define ITEM_HEADERS_INCLUDED

#include <iostream>

using namespace std;

class Item {
private:
    string description;

public:
	string name;
    Item();
    ~Item();
    string getDescription();

};

#endif
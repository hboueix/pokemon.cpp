#ifndef ITEM_HEADERS_INCLUDED
#define ITEM_HEADERS_INCLUDED

#include <iostream>
using namespace std;

class Item {
protected:
    string description;

public:
    string type;
	string name;
    Item();
    ~Item();
    virtual bool use(Pokemon* pokemon) const = 0;
    virtual string getDescription();

};

#endif
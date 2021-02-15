#ifndef ITEM_HEADERS_INCLUDED
#define ITEM_HEADERS_INCLUDED

#include <iostream>

using namespace std;

class Item {
protected:
    string description;

public:
	string name;
    Item();
    ~Item();
    virtual void affiche() const;
    // virtual void use(Item const&);
    virtual string getDescription();

};

#endif
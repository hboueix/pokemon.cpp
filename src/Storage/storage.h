#ifndef STORAGE_HEADERS_INCLUDED
#define STORAGE_HEADERS_INCLUDED

#include <iostream>
# include "../Player/player.h"

using namespace std;

class Storage {
private:
	string save;
public:
	Storage();
	~Storage();
	string read(string filePath);
	bool write(string filePath, string toWrite);
	void savePlayer(Player *player);
	Player* loadPlayer(string name);
};

#endif

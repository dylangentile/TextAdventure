#pragma once
#include "settings.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>


class Game{
public:
	Game();
	~Game();
	void init(int gameId, Settings *mysettings);
	std::string gamename;
	char **roommap;
private:
	std::string readIt(std::string dir, int *length);
	bool parser(std::string srcFile, int *filelength);
private:
	std::string error;
};
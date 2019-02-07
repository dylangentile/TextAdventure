#include "game.h"
#include <fstream>
#include <sstream> //for file input;
using namespace std;

Game::Game(){
	error = "";
	gamename = "";
}


Game::~Game(){

}


string
Game::readIt(string dir, int *length){
	ifstream ifs(dir);
	string content((std::istreambuf_iterator<char>(ifs) ),
		(std::istreambuf_iterator<char>()));
	length = (int*)(content.length() - 1);

	return content;


}


bool 
Game::parser(string srcFile, int *filelength){
	int statlen = 0;
	int openquote = -1;
	int closequote = -1;
	int semiloc;
	string statment = "";
	bool z = true;
	while(true){
		if(srcFile[statlen] == '\"' && z == true){
			openquote = statlen;
			z = false;

		}
		if(srcFile[statlen] == '\"' && z == false){
			closequote = statlen;
		}
		if(srcFile[statlen] == '\n'){
			break;
		}
		if(srcFile[statlen] == ':'){
			semiloc = statlen;
		}
		statment += srcFile[statlen];
		statlen++;
	}

	string hh = "";
	for(int i = 0; i < semiloc; i++){
		hh += srcFile[i];
	}
	if(hh == "GAMENAME"){

		for(int i = openquote+1; i < closequote; i++){
			gamename += srcFile[i];
		}
	}
	int statopen;
	int openbr = -1, closebr = -1;
	statlen++;
	statopen = statlen;
	while(true)
	{
		if(srcFile[statlen] == '('){
			openquote = statlen;
		}
		if(srcFile[statlen] == ')'){
			closequote = statlen;
		}
		if(srcFile[statlen] == '{'){
			openbr = statlen;
		}
		if(srcFile[statlen] == '}'){
			closebr = statlen;
			break;
		}
		statlen++;
	}


	hh = "";
	for(int i = statopen; i < openquote; i++){
		hh+= srcFile[i];
	}
	string xaxis = "";
	string yaxis = "";
	if(hh == "ROOMMAP"){
		z = false;
		for(int i = openquote+1; i < closequote; i++){
			if(srcFile[i] == ','){
				z = true;
			}
			else if(!z){
				xaxis += srcFile[i];
			}else if(z == true && srcFile[i] != ','){
				yaxis+=srcFile[i];
			} else {

			}

		}
	}


	int thex, they;

	stringstream ss, zz;
	ss << xaxis;
	ss >> thex;
	zz << yaxis;
	zz >> they;
//Create your 2D array

	roommap = new char*[thex];

	for( int i = 0; i < thex; ++i )
	{
   		roommap[i]  = new char[they];
	}


	for( int i = 0; i < thex; ++i )
	{
    	for( int j = 0; j < they; ++j )
    	{
          roommap[ i ][ j ] = ' ';
    	}
	}

	int st;
	if(srcFile[openbr+1] == '\n'){
		st = openbr+2;
	}else{
		st = openbr+1;
	}
	int ydex = 0;
	int xdex = 0;
	while (true){
		cout << srcFile[st];
		if(srcFile[st] == ','){
			cout << " :comma\n";
		}
		else if(srcFile[st] == '\n'){
			cout << " :newline\n";
			ydex++;
			xdex = 0;
		}
		else if(st == closebr){
			break;
		}else if(srcFile[st] == '*'){
			cout << " :pointer\n";

			st++;
			roommap[ydex][xdex]= toupper(srcFile[st]);
			xdex++;

		}
		else{
			cout << " :room  x:" << xdex << "y: " << ydex << "\n"; 
			roommap[ydex][xdex] = srcFile[st];
			xdex++;

		}
		st++;


	}
	cout << "\n\n\n";
	for( int i = 0; i < thex; ++i )
	{
    	for( int j = 0; j < they; ++j )
    	{
          cout << roommap[ i ][ j ];
    	}
	}

	return true; 

}


void
Game::init(int gameId, Settings *mysettings){
	int *length;
	length = 0;
	if(gameId == 0){
		string p = readIt("../games/tutorial/game.game", length);
		bool g = parser(p, length);
		if(!g){
			cout << "\nThe game you've inputted doesn't work.\n\n" << error;
		}
	}

	cout << "\nWelcome to " << gamename << "!\n";
}
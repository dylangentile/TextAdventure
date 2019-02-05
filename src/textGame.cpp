#include "tutorial.h" //includes game which includes settings, iostream, string cctype etc
using namespace std;


void defaultSettings(Settings *set){
	
	set->color = true;


	cout << "\nDefaults SET...(CONFIRM):";
	string input;
	getline(cin, input);
	cout << "\n\n\u001b[31mCOLORS!\u001b[0m\n";
	cout << "\nIf 'COLORS!' printed in color, you're good, hit ENTER\nIf it printed ?[30;1m or some weird characters like that type an 'n'\n(ENTER/n):";
	getline(cin, input);
	if(tolower(input[0]) == 'n'){
		set->color = false;
	}

}


bool initSettings(Settings *thesettings){
	string input;
	cout << "\nHello and welcome to your adventure! Would you like ASCII colors?\n(Type 'd' for the program to initialize all defaults)\n(Y/n/d):";
	getline(cin, input);
	if(tolower(input[0]) == 'y')
	{
		thesettings->color = true;
	}
	else if(tolower(input[0]) == 'n')
	{
		thesettings->color = false;
	}
	else if(tolower(input[0]) == 'd'){
		return false;
	}
	else
	{
		thesettings->color = true;
	}
	if(thesettings->color){
		cout << "\n\u001b[31mCOLORS!\u001b[0m\n";
	}
	cout << "\nIf 'color!' printed in color, you're good, hit ENTER\nIf it printed ?[30;1m or some weird characters like that type an 'n'\n(ENTER/n):";
	getline(cin, input);
	if(tolower(input[0]) == 'n'){
		thesettings->color = false;
	}

	return true;
}




int main(int argc, char const *argv[])
{
	Settings *userpref = new Settings;
	if(!initSettings(userpref)){
		defaultSettings(userpref);
	}

	cout << "\n\nWould you like a tutorial?\n(y/N)";
	string userin;
	getline(cin, userin);
	if(tolower(userin[0]) == 'y'){
		Tutorial *thetutorial = new Tutorial;
	}
	cout << "Alright. Choose which adventure you'd like:\n\n\t1:Sci-Fi\n\t2:Cowboy\n\t3:Mystery\n(1/2/3.../q):";
	getline(cin, userin);
	if(userin[0] != 'q'){
		Game *thegame = new Game;
		thegame->init(3, userpref);
	}


	return 0;
}
#include <iostream>
#include "RankList.h"

using namespace std;

int main()
{
	RankList ranklist(0);
	
	char quit = 'n';
	
	while (quit != 'y')
	{
		cout << "teamID: " << endl;
		unsigned int teamID;
		cin >> teamID;
		cout << "problemID: " << endl;
		unsigned int problemID;
		cin >> problemID;
		cout << "currentTime: " << endl;
		unsigned int currentTime;
		cin >> currentTime;
		cout << "passed?(y/n): " << endl;
		char flag;
		cin >> flag;
		bool passed = flag == 'y' ? true : false;
		
		ranklist.submit(teamID, problemID, currentTime, passed);
		ranklist.print(cout);
		
		cout << "quit?(y/n)" << endl;
		cin >> quit;
	}
}

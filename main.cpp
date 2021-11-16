//Virginia Vaughan
//Main.cpp




#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;



/*
 *Prompts user for input, stores cylinders into vector, and contains switch case to decide function
  Scan, C-Scan, or Quit
 * */


int main () {

	vector<int> cylinders;

	const int MAX = 299;
	const int MIN = 0;

	int currentLoc, travelDir, flyback;



	cout << "This disk scheduler tries to optimize on seek time for disk accesses." << endl;
	
	cout << "Please enter the current location of the arm: ";
	cin >> currentLoc;
	cout << endl;

	cout << "Please enter the travel direction of the arm." << endl
		<< "(1: Going towards higher numbers, 2: Going towards lower numbers): ";
	cin >> travelDir;
	cout << endl;

	cout << "Please enter the flyback time in number of cylinders: ";
	cin >> flyback;
	cout << endl;

	cout << "Please enter the list of cylinder numbers for the file: ";



return 0;
}

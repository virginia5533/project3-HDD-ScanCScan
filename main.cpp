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

vector<int> readInCylinders(vector<int> vect);

int main () {

	vector<int> cylinders;

	const int MAX = 299;
	const int MIN = 0;

	int currentLoc, travelDir, flyback;
	int choice = -1;


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
	cylinders =  readInCylinders(cylinders);

	//Switch Menu
	do {
	cout << "-------------------------------------------------------------" << endl << endl;
	cout << " +-----------------------+" << endl
	     << " | Please enter a choice |" << endl 
	     << " | 1. SCAN  		 |" << endl
	     << " | 2. C-SCAN             |" << endl
    	     << " | 3. QUIT               |" << endl
     	     << " +-----------------------+" << endl;

	cin >> choice;


	
	}while(choice != 3);







return 0;
}

/*
 *paramater vect<int> vect
  Reads in elements of a vector separated by space until enter is pressed. 
  Assigns element to vect using push_back.
  returns vect
 */
vector<int> readInCylinders(vector<int> vect) {

//	cout << "Reading in Cylinders..." << endl;
	do{
	 int location;
	 cin >> location;

	vect.push_back(location);
	
	}while (cin.peek() != '\n');
//
//	for(int i = 0; i < vect.size(); i++) {
//
//		cout << vect.at(i) << " ";
//		cout << endl;
//	}


	return vect;
}


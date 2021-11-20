//Virginia Vaughan
//Main.cpp




#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;



/*
 *Prompts user for input, stores cylinders into vector, and contains switch case to decide function
  Scan, C-Scan, or Quit
 * */

vector<int> readInCylinders(vector<int> vect);

int findMin(vector<int> vect);
int findMax(vector<int> vect);

vector<int> sort(vector<int> vect);

void scan(vector<int> vect, const int MAX, const int MIN, int min, int max, int travelDir, int  currentLoc);

void cscan(vector<int> vect, const int MAX, const int MIN, int min, int max, int flyback, int currentLoc);



int main () {

	vector<int> cylinders;

	const int MAX = 299;
	const int MIN = 0;

	int currentLoc, travelDir, flyback;
	int choice = -1;
	int cMin = -1;
	int cMax = -1;


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
	
	cMin = findMin(cylinders);
	cMax = findMax(cylinders);
	

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
	cout << endl << endl;

	switch (choice) {

	case 1:
		cout << "SCAN" << endl;
		scan(cylinders, MAX, MIN, cMin, cMax, travelDir, currentLoc);
		break;

	case 2:
                cout << "C-SCAN" << endl;
		cscan(cylinders, MAX, MIN, cMin, cMax, flyback, currentLoc);
		break;

	case 3:
                cout << "Ending the program now..." << endl;
		break;


	default:
		cout << choice << " is not a correct input." << endl;
		break;
	}
	
	}while(choice != 3);




cout << "Completed with exit code: 0" << endl;


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


/*
 *paramater vect<int> vect
  Searches vector for minimum value
  returns minimum
 */

int findMin(vector<int> vect) {

 int min = 99999;

 for(int i = 0; i < vect.size(); i++) {

	 if(vect.at(i) < min) {
              min = vect.at(i);
      }

 }

 return min;

}


/*
 *paramater vect<int> vect
  Searches vector for maximum value
  returns maximum
 */

int findMax(vector<int> vect) {

 int max = -1;

 for(int i = 0; i < vect.size(); i++) {

         if(vect.at(i) > max) {
              max = vect.at(i);
      }

 }

 return max;

}

/*
 *paramater vect<int> vect, MAX, MIN, cMin, cMax, travelDir, currentLoc
  Sorts vector and traverses it in accordance with Scan algorithm
  returns void
 */

void scan(vector<int> vect, const int MAX, const int MIN, int min, int max, int travelDir, int currentLoc) {


	int cylindersTraveled = -1;

	cout << "Running the SCAN algorithm now..." << endl << endl;
	cout << "The sequence of visits to the cylinders: " << endl << endl;

	sort(vect.begin(), vect.end());

	if(travelDir == 1){

	cout << currentLoc << "	";

	for(int i = 0; i < vect.size(); i++) {
		
	if(vect.at(i) >= currentLoc) {
		cout << vect.at(i) << "	";		
	 }
	
	}

	cout << MAX << "	";

	for(int i = vect.size()-1; i >= 0; i--) {

        if(vect.at(i) < currentLoc) {
                cout << vect.at(i) << "	";
         }
        }
	cout << endl << endl;


	cylindersTraveled = (MAX - currentLoc) + (MAX - min);

	cout << "Total cylinder travel for SCAN, arm going upwards before start: ";
	cout << cylindersTraveled << endl << endl;

	}

	else if(travelDir == 2) {

	 cout << currentLoc << "	";


	 for(int i = vect.size()-1; i >= 0; i--) {

        if(vect.at(i) < currentLoc) {
                cout << vect.at(i) << "	";
         }
        }

	cout << MIN << "	";


        for(int i = 0; i < vect.size(); i++) {

        if(vect.at(i) >= currentLoc) {
                cout << vect.at(i) << "	";
         }

        }

        cout << endl << endl;


        cylindersTraveled = (currentLoc - MIN) + (max - MIN);

        cout << "Total cylinder travel for SCAN, arm going downwards before start: ";
        cout << cylindersTraveled << endl << endl;



	}

}

/*
 *paramater vect<int> vect, MAX, MIN, cMin, cMax, flyback, currentLoc
  Sorts vector and traverses it in accordance with C-Scan algorithm
  returns void
 */

void cscan(vector<int> vect, const int MAX, const int MIN, int min, int max, int flyback, int currentLoc){

 int cylindersTraveled = -1;

        cout << "Running the C-SCAN algorithm now..." << endl << endl;
        cout << "The sequence of visits to the cylinders: " << endl << endl;

        sort(vect.begin(), vect.end());

        cout << currentLoc << "	";

        for(int i = 0; i < vect.size(); i++) {

        if(vect.at(i) >= currentLoc) {
                cout << vect.at(i) << "	";
         }

        }

        cout << MAX << "	" << MIN << "        ";
	for(int i = 0; i < vect.size(); i++) {
	if(vect.at(i) < currentLoc) {
                cout << vect.at(i) << "	";
         }
        }
        cout << endl << endl;

	int cBeforeStart = 0;
	for(int i = 0; i < vect.size(); i++) {

		if(vect.at(1) == currentLoc) {
			cBeforeStart = vect.at(0);
			break;
		}

		else if(vect.at(i) < currentLoc) {
			cBeforeStart = vect.at(i);
		}
	}


        cylindersTraveled = (MAX - currentLoc) + flyback +  (cBeforeStart - MIN);

        cout << "Total cylinders travel for C-SCAN: ";
        cout << cylindersTraveled << endl << endl;

        

}



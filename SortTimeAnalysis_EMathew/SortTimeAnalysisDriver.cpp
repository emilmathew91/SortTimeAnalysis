// INCLUDES & NAMESPACES

#include <iostream>
#include <stdlib.h>
#include <time.h> //for clock
#include <conio.h>
#include "SortTimeAnalysisHeader.h"

using namespace std;
// PROTOTYPES

//DEFINES 
//FILES are in put from here
#define INFILE500 "NumFile500.txt"
#define INFILE5K "NumFile5k.txt"
#define INFILE25K "NumFile25k.txt"
#define INFILE100K "NumFile100k.txt"



// MAIN

int main() {
	SortTimeAnalysis Array;
	cout << endl;
	int numberOfElements = 0;

	numberOfElements = Array.getArraySize(INFILE500); //gets array of elements
	cout << "Populating Arrays... < " << numberOfElements << " elements>" << endl;
	cout << "Sorting..." << endl;
	Array.populateArray(INFILE500); //populates array
	cout << "SORTING COMPLETE!" << endl;
	cout << endl;
	numberOfElements = Array.getArraySize(INFILE5K);
	cout << "Populating Arrays... < " << numberOfElements << " elements>" << endl;
	cout << "Sorting..." << endl;
	Array.populateArray(INFILE5K);
	cout << "SORTING COMPLETE!" << endl;
	cout << endl;
	numberOfElements = Array.getArraySize(INFILE25K);
	cout << "Populating Arrays... < " << numberOfElements << " elements>" << endl;
	cout << "Sorting..." << endl;
	Array.populateArray(INFILE25K);
	cout << "SORTING COMPLETE!" << endl;
	cout << endl;
	numberOfElements = Array.getArraySize(INFILE100K);
	cout << "Populating Arrays... < " << numberOfElements << " elements>" << endl;
	cout << "Sorting..." << endl;
	Array.populateArray(INFILE100K);
	cout << "SORTING COMPLETE!" << endl;
	cout << endl;
}
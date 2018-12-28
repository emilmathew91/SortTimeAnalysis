#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <string>
#include "SortTimeAnalysisHeader.h"

using namespace std;

// DEFINES
#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

SortTimeAnalysis::SortTimeAnalysis() { //constructor method
	this->arraySize = 0;
	long double beginTime = 0.0;
	long double endTime = 0.0;
	long double elapsedTime = 0.0;
	long double secondsElapsed = 0.0;
	long int milsElapsed = 0;
}
void SortTimeAnalysis::resetValues() { //resets clock values after each run
	this->beginTime = 0.0;
	this->endTime = 0.0;
	this->elapsedTime = 0.0;
	this->secondsElapsed = 0.0;
	this->milsElapsed = 0;
}

int SortTimeAnalysis::getArraySize(const char* FILENAME) { //gets array size
	int num;
	ifstream inputHandle(FILENAME, ios::in);

	// check to make sure the file opened...
	if (inputHandle.is_open() == true) {
		// if the file opened, read integers until EOF (end of file) is encountered
 		while (inputHandle >> num) {//eof would not work with >> operator. 
				this->arraySize++; 
			}
		}

		// close the file now that we are done reading
		inputHandle.close();
		return this->arraySize;
}

void SortTimeAnalysis::populateArray(const char* FILENAME) {
	this->rootPointer = new int[this->arraySize];//allocates arraySize for rootPointer
	ifstream inputHandle(FILENAME, ios::in);
	// check to make sure the file opened...
	if (inputHandle.is_open() == true) {
		// if the file opened, read integers until EOF (end of file) is encountered
		int i = 0;
		while (!inputHandle.eof()) {
			if (i < arraySize) {
				inputHandle >> this->rootPointer[i];
				i++;
			}
			else {
				cout << "ERROR: There are too many items in the file. (ARRAY_SIZE = " << arraySize << ")" << endl;
				break;
			}
		}
		// close the file now that we are done reading
		inputHandle.close();
	}
	else {
		// if the file didn't open, echo this to the user
		cout << "ERROR: The file \"" << FILENAME << "\" could not be opened for reading..." << endl;
	}
	
	populateTempArray(this->rootPointer); //calls tempPointer
	bubbleSort(this->tempPointer);//bubblesort
	resetValues();//reset clock values
	populateTempArray(this->rootPointer);
	insertionSort(this->tempPointer);//insertion sort
	resetValues();
	populateTempArray(this->rootPointer);
	selectionSort(this->tempPointer);//selection sort
	resetValues();
	delete[] this->rootPointer;//deallocates rootPointer memory
	this->arraySize = 0;//resets array size for next file

}

void SortTimeAnalysis::populateTempArray(int* rootPointer) {//populates tempPointer
	this->tempPointer = new int[this->arraySize];
	for (int i = 0; i <= this->arraySize; i++) {
		this->tempPointer[i] = this->rootPointer[i];
	}
}
void SortTimeAnalysis::bubbleSort(int* rootPointer) {
	Start(); //start clock
	bool swap = TRUE;
	while (swap == TRUE) {
		swap = FALSE;
		for (int i = 0; i <= this->arraySize - 2; i++) {
			int j = i + 1;
			if (this->tempPointer[i] > this->tempPointer[j]) {
				int temp = this->tempPointer[j];
				this->tempPointer[j] = this->tempPointer[i];
				this->tempPointer[i] = temp;
				swap = TRUE;
			}
		}
	}
	Stop(); //stop clock
	delete[] this->tempPointer; //deallocates tempPointer
	DisplayTimerInfo((string)"Bubble Sort");
	
}
void SortTimeAnalysis::insertionSort(int* rootPointer) {
	Start();
	int currentValue;
	for (int i = 1; i < this->arraySize; i++) {
		int j = i - 1;
		currentValue = this->tempPointer[i];
		while (this->tempPointer[j] > currentValue && j >= 0) {
			this->tempPointer[j + 1] = this->tempPointer[j];
			j--;
		}
		this->tempPointer[j + 1] = currentValue;
	}
	Stop();
	delete[] this->tempPointer;
	DisplayTimerInfo((string)"Insertion sort");
}
void SortTimeAnalysis::selectionSort(int* rootPointer) {
	Start();
	for (int i = 0; i < this->arraySize - 1; i++) {
		int currentMin = i;
		for (int j = i + 1; j < this->arraySize; j++) {
			if (this->tempPointer[j] < this->tempPointer[currentMin])
				currentMin = j;
		}

		int tempNum = this->tempPointer[i];
		this->tempPointer[i] = this->tempPointer[currentMin];
		this->tempPointer[currentMin] = tempNum;
	}
	Stop();
	delete[] this->tempPointer;
	DisplayTimerInfo((string)"Selection sort");

}

bool SortTimeAnalysis::Start() {
	if (!Stop()) {
		this->beginTime = clock();
		return true;
	}
	else
		return false;
}
bool SortTimeAnalysis::IsTicking() {
	if (beginTime > 0) {
		return true;
	}
	else
		return false;
}
bool SortTimeAnalysis::Stop() {
	if (IsTicking()) {
		this->endTime = clock();
		return true;
	}
	else
		return false;
}
void SortTimeAnalysis::DisplayTimerInfo(string SORTNAME) {
	elapsedTime = endTime - beginTime;
	double secondsElapsed = elapsedTime / (double)CLOCKS_PER_SEC;
	cout << "Elapsed Time <" << SORTNAME << ">   " << elapsedTime << setprecision(4) << " milliseconds "<< endl;
}




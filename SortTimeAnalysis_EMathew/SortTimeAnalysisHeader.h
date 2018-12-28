#pragma once
#pragma once
#ifndef __SortTimeAnalysis__
#define __SortTimeAnalysis__
#include <iostream>
#include <time.h>
#include <math.h>
#include <string>
using namespace std;

class SortTimeAnalysis {
private:
	int arraySize; //holds arraysize
	int* rootPointer; //input file is piped into this array
	int* tempPointer; //the file is sent here to work on so that original is not altered
	double beginTime; //holds start time
	double endTime; //holds end time
	double elapsedTime; //holds elapsed time, subtract begin and end time
	long int secondsElapsed; //in case i wanted to have time in seconds
	long int milsElapsed; //milliseconds elapsed
	
public:
	//CONSTRUCTORS
	SortTimeAnalysis();
		
	//SETTERS
	void resetValues(); //used to reset clock values after each run
	void populateArray(const char* FILENAME); //populates rootPointer with array from infile
	void populateTempArray(int* rootPointer); //populates tempPointer with rootPointer
	void bubbleSort(int* rootPointer); //bubble sort
	void insertionSort(int* rootPointer); //insertion sort
	void selectionSort(int* rootPointer); //selection sort
	bool Start(); //starts clock
	bool IsTicking(); //checks if clock is ticking
	bool Stop(); //stops clock
	void DisplayTimerInfo(string SORTNAME); //displays info
		
	//GETTERS
	int getArraySize(const char* FILENAME); //gets array size
};











#endif
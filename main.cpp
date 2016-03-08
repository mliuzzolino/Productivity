#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include "dataStructs.h"
#include "tools.h"

using namespace std;


int main(int argc, char* argv[])
{
	string task, lastState, writeState, filePath;
	string beginTime, endTime;
	char isFileEmpty;
	string currentTime = currentDateTime();

	// Instantiate stack for storing items in txt file
	DataStructure<string> stack('s');

	// Declare name of filepath.
	filePath = "studylog.txt";


	// Instantiate input and output file objects
	ifstream inFile;
	ofstream outFile;


	// Obtain the task name from cmd line or user input
	if (argc > 1)
	{
		task = argv[1];
	}
	else 
	{
		cout << "Task: ";
		cin >> task;
	}

	isFileEmpty = checkFileSize(filePath);

	// Check if file is empty
	if (isFileEmpty == 'y')
	{
		cout << "Starting " << task << " task." << endl;

		outFile.open(filePath, ios::app);

		outFile << task << "," << "start" << ",";
		outFile << currentTime << endl;

		outFile.close();
	}

	// File Not Empty
	else
	{

		// Create data stack
		createStack(&stack, filePath);

		// Find last occurance of stack. Returns if it was a start or stop
		lastState = findLastOccurrence(stack, task, &beginTime);


		if (lastState == "start")
		{
			writeState = "stop";
			cout << "Stopping " << task << " task." << endl;
		}
		else if (lastState == "stop")
		{
			writeState = "start";
			cout << "Starting " << task << " task." << endl;
		}

		// Open output file
		outFile.open(filePath, ios::app);
		outFile << task << "," << writeState << ",";
		outFile << currentTime << endl;
		outFile.close();

	}

	return 0;
}



#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <fstream>

char checkFileSize(string filePath);
void createStack(DataStructure<string>* stack, string filePath);
string getFrameTask(string lastOc, int i=0);
string findLastOccurrence(DataStructure<string> stack, string task, string* beginTime);
string getTime(string lastLine);




const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y,%m,%d;%X", &tstruct);

    return buf;
}




char checkFileSize(string filePath)
{
	ifstream inFile;
	inFile.open(filePath);

	string line;
	getline(inFile, line);
	

	if (line.size() != 0)
	{

		return 'n';
	}
	else
	{
		return 'y';
	}

	inFile.close();
	
}


void createStack(DataStructure<string>* stack, string filePath)
{
	string line;
	ifstream inFile;
	inFile.open(filePath);

	getline(inFile, line);
	do
	{
		stack->push(line);	
		getline(inFile, line);
		
	}
	while (! inFile.eof());


	inFile.close();
}



string findLastOccurrence(DataStructure<string> stack, string task, string* beginTime)
{

	string lastOccur, s2, state;
	do
	{
		lastOccur = stack.pop();

		s2 = getFrameTask(lastOccur);		// Checks which program is stored in this stack frame

		if ((stack.size() == 0)	&& (s2 != task))		
		{
			return "stop";
		}
	}
	while (s2 != task);


	state = getFrameTask(lastOccur, s2.length()+1);
	*beginTime = getTime(lastOccur);


	return state;
}



string getFrameTask(string lastOc, int i)
{
	string s1, s2;
	int commaNumber = 0;


	// Obtain first column
	do
	{
		s1 = lastOc[i];
		if (s1 != ",") 
		{
			s2 += s1;
		}
		else
		{
			break;
		}
		i++;
	}
	while (s1 != ",");


	return s2;
}


string getTime(string lastLine)
{	
	int i = 0;
	string charCheck, runTime;


	do
	{
		charCheck = lastLine[i];
		i++;
	}
	while (charCheck != ";");

	for (int j = 0; j < 8; j++)
	{
		runTime += lastLine[i];
		i++;
	}

	cout << runTime << endl;
	return runTime;
}
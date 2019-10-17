/*
Author:         Aaron Meche
Program:        Homework 1 - Logger Class Header file
Description:    This File contains the header for an error message Logger class
Date Due:       10/21/19
Date Created:   10/13/19
Date Last Mod:  10/13/19

Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the logger.cpp file exists in the same folder, subject to change depending on how project is structured
*/


#include <fstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "logger.h"

using namespace std;

Logger::Logger()
{
	
}

void Logger::report(LOGLEVEL log)
{
    time_t now = time(0);
    char* dt = ctime(&now);
	switch(log)
	{
		case PASS_FAIL:
			cout << "Some kind of error" << endl;
			break;
		case PASS_FAIL_RESULT:
			cout << "Some kind of error result" << endl;
			break;
		case DETAIL:
			cout << "Some kind of detail. Testing the time and date stamp:" << endl;
            cout << "The time this test executed is: " << dt << endl;
			break;
		default:
			cout << "There was no error found in this test." << endl;
			break;
	}
		
}
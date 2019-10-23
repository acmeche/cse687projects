//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        Logger.cpp																
// Purpose:     This file contains the implementation for the logger class reponsible for logging
//              outputs of test case execution (including errors)
// Version:     1.0																			
// Language:    C++, Visual Studio 2019														
// Platform:    Windows 10																	
// Application: Single-User Test Harness, CSE687 - Object Oriented Design					
// Author:      Lamont Harrington															
//              Aaron Meche																	
//              Chris Johnson																
//              Jason Mitchell																
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
   Maintenance History
   ===================
   DATE         VERSION     DESCRIPTION
   ----         -------     ----------------------------------------------------------------------
   10/8/2019    1.0         Initial Creation
   10/17/2019   1.0         Cleaned up uncessary includes, renamed report() method to writeLog(),
                            added additional input variable "message" containing text to be logged,
                            added private helper meethod getDateTimeString() to build a formatted
                            string containing date and time.
   10/18/2019   1.0         Added additional input variable "result" containing the result (PASS/FAIL)
                            of the test case execution
*/
#define _CRT_SECURE_NO_WARNINGS // Suppress warning that the use of localtime function may be unsafe
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "logger.h"

using namespace std;

void Logger::writeLog(LOGLEVEL logLevel, E_RESULT result, const char* message)
{
	const char* resultOfTest = NULL;
	switch (result) {
	case PASS:
		resultOfTest = "PASS";
		break;
	case FAIL:
		resultOfTest = "FAIL";
		break;
	}

    char* dt = getDateTimeString();
	switch(logLevel)
	{
	case PASS_FAIL:
		cout << "The test case as executed with the following status message:" << endl;
		cout << "Message: " << message << endl;
		break;
	case PASS_FAIL_RESULT:
		cout << "The test case as executed with the following application-specific message:" << endl;
		cout << "Result: " << resultOfTest << endl;
		cout << "Message: " << message << endl;
		break;
	case DEBUG_FAILURE_DETAIL:
		cout << "The test executed. Detail below:" << endl;
		cout << "Result: " << resultOfTest << endl;
		cout << "Message: " << message << endl;
		cout << "Time:  " << dt << endl;
		break;
	}
}

char* Logger::getDateTimeString()
{
	// Initialize and get current time
	time_t currentTime = time(NULL);

	// Allocate space for date string
	char* dateTimeString = (char*)malloc(100);

	// Format the time correctly
	strftime(dateTimeString, 100, "[%F %T]", localtime(&currentTime));

	return dateTimeString;
}
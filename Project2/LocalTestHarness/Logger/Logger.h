//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        Logger.h																
// Purpose:     This is the header file for the logger class reponsible for logging outputs of 
//              test case execution (including errors)
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
   10/18/2019   1.0			Added additional input variable "result" containing the result (PASS/FAIL)
                            of the test case execution
   10/22/2019   2.0         Coppied from project 1 in order to meet project requirements
*/
#pragma once

#ifdef LOGGER_EXPORTS
#define LOGGER_API __declspec(dllexport)
#else
#define LOGGER_API __declspec(dllimport)
#endif

/**
* Class that allows differing level of logging to the console
* Satisfies the following project criteria:
*	1.	Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
*   2.	Shall use Visual Studio, Community Edition available at no cost.
*   3.	Shall provide packages for an Executive, TestHarness, Logger, and FileManager (if needed).
*/
enum LOGGER_API LOGLEVEL {
    PASS_FAIL,
    PASS_FAIL_RESULT,
    DEBUG_FAILURE_DETAIL
};

enum LOGGER_API E_RESULT {
    PASS,
    FAIL
};

class LOGGER_API Logger {
public:
    static void writeLog(LOGLEVEL logLevel, E_RESULT result, const char* message);
private:
    static char* getDateTimeString();
};

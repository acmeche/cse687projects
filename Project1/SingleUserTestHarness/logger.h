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

#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>

#pragma once

enum LOGLEVEL{
	PASS_FAIL,
	PASS_FAIL_RESULT,
	DETAIL
};

class Logger
{
	public:
		Logger();
		void report(LOGLEVEL log);
	private:
	
		
	
};
	
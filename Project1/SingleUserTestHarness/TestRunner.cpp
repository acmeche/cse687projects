//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        TestRunner.cpp																
// Purpose:     Responsible for initializing the test harness and running the test cases	
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
   DATE         VERSION    DESCRIPTION
   ----         -------    ----------------------------------------------------------------------
   10/8/2019    1.0        Initial Creation
   10/17/2019   1.0        Added system pause command to allow user to see output on screen before
                           closing program window
*/
#include <iostream>
#include "TestHarness.h"
using namespace CSE687_Project1;

int main()
{
	TestHarness harness;
	harness.runTests();

	system("pause");
	return 0;
}
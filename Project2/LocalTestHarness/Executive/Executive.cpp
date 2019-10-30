//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        Executive.cpp																
// Purpose:     Responsible for initializing the executive class and running the test cases	
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
   10/22/2019   2.0        Coppied TestRunner.cpp code into project and replaced it with Executive class
*/

#include <iostream>
#include <fstream>
#include <vector>

#undef UNICODE 
#include <Windows.h>
#include <tchar.h>

#include "TestHarness.h"

using namespace CSE687_Project2;

typedef bool (*executeMethod)();

int main(int argc, char** argv)
{
    TestHarness harness;
    harness.runTests();

    system("pause");
    return 0;
}

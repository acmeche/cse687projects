//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        Executive.cpp															
// Purpose:     This is the source file for the Executive class, which will be responsible for
//              running the test cases loaded from the TestRequest XML file. 
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
   10/22/2019   1.0         Created shell of Executive class. Need to determine how the XML will be
                            parsed and passed to this class.
*/

#include "pch.h"
#include "Executive.h"
#include "TestHarness.h"

using namespace CSE687_Project2;

void Executive::runTests()
{
    TestHarness harness;
    harness.runTests();
}
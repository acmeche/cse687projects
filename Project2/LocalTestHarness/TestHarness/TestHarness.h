//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        TestHarness.h																
// Purpose:     Header file for Test Harness class used for unit testing C++ code for projects
//              created for CSE687
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
   10/22/2019   2.0         Coppied from project 1 in order to meet project requirements
*/
#pragma once
#include "TestHarnessExporter.h"

namespace CSE687_Project2
{
    /**
    * Class that acts as staging point to run all TestCase classes
    * Satisfies the following project criteria:
    *	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
    *	2.) Shall provide a TestHarness class that defines an executor method
    */
    class TESTHARNESS_API TestHarness
    {
    public:
        void runTests();
    };
}

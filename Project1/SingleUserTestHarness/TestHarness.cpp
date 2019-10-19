//////////////////////////////////////////////////////////////////////////////////////////////////
//	File:			TestHarness.cpp																//
//	Purpose:		Test Harness for unit testing C++ code for projects created for CSE687		//
//	Version:		1.0																			//
//	Language:		C++, Visual Studio 2019														//
//	Platform:		Windows 10																	//
//	Application:	Single-User Test Harness, CSE687 - Object Oriented Design					//
//	Author:			Laamont Harrington															//
//					Aaron Meche																	//
//					Chris Johnson																//
//					Jason Mitchell																//
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
	Maintenance History
	===================
	DATE		VERSION		DESCRIPTION
	----		-------		----------------------------------------------------------------------
	10/8/2019	1.0			Initial Creation
	10/15/2019	1.1			Added test harness framework	
*/
#include <iostream>
#include "TestCaseBase.h"
#include "TestHarness.h"
using namespace CSE687_Project1;

void CSE687_Project1::TestHarness::runTests()
{
	/**
	* Try/catch to satisfy the following criteria:
	*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
	*	3.) The executor method Shall invoke a passed callable object in the scope of a try block.
	*		If exceptions are thrown, the catch block you define for this method shall log test failure
	*		and the contents of the exception message.
	*/
	try {
		TestCaseRegistry& testCaseRegistry(TestCaseRegistry::get());
		for (TestCaseRegistry::iterator it = testCaseRegistry.begin(); it != testCaseRegistry.end(); ++it)
		{
			testCaseBase_creator func = *it;
			TestCaseBase* funcPtr = func();
			std::auto_ptr<TestCaseBase> testCase(funcPtr);
			testCase->execute();
		}
	}
	catch (...) {
		// Need to add Logger logic
		std::cout << "An error occured." << std::endl;
	}
}

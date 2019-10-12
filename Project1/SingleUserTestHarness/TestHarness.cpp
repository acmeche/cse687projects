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
*/
#include <iostream>

#include "TestHarness.h"
#include "LambdaTestCase.h"

namespace SingleUserTestHarness
{
	void TestHarness::runTests() 
	{
		LambdaTestCase lamTests(std::cout);
		lamTests.runTests();
	}
}

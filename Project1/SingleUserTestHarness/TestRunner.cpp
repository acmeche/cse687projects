//////////////////////////////////////////////////////////////////////////////////////////////////
//	File:			TestRunner.cpp																//
//	Purpose:		Responsible for initializing the test harness and running the test cases	//
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
#include "TestHarness.h"

int main()
{
	SingleUserTestHarness::TestHarness harness;
	harness.runTests();

	return 0;
}
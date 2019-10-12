//////////////////////////////////////////////////////////////////////////////////////////////////
//	File:			AbsTestHarness.h															//
//	Purpose:		Abstract class with vitrual methods for test harness						//
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
	10/11/2019	1.0			Initial Creation
*/
#pragma once
#include <ostream>
#include "AbsTestHarness.h"

class AbsTestHarness
{
public:
	/**
	* Since the child classes will inherit the parent class, we can declare child classes like:
	* LambdaTestCase test(std::cout)
	*/
	AbsTestHarness(std::ostream& output) : m_output(output) {};

	//Will a virtual function for logging go here?
	// No, most of that should be done in the logging class, we just need a protected member variable to hold that class. Then we can call the logging methods in that class from the child test classes
	virtual ~AbsTestHarness() = default;						// Virtual destructor

	/**
	* We shouldn't need a whole bunch of pure virtual methods here, unless we want all child classes to implement those. Perhaps we do, just a thought...

	virtual bool test1(std::ostream& output) = 0;	// Pure virtual function for interface

	virtual void someTest2(/*some argument?/) = 0;	// Pure virtual function for interface
	*/

	virtual void runTests() = 0;					// Pure virtual function for interface
	
protected:
	// Use this for now until logger class is created, then we'll replace stream with that
	std::ostream& m_output;							// Private member data from accessed Objects
};





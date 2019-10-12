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
#include "LamdaTestCase.h"
#include "AbsTestHarness.h"

class AbsTestHarness
{
public:
	virtual void runAbsTestHarness() = 0;		    // Pure virtual function for interface

	virtual bool test1(std::ostream& output) = 0;	// Pure virtual function for interface
		
	virtual void someTest2(/*some argument?*/) = 0;	// Pure virtual function for interface

	//Will a virtual function for logging go here?
	
	virtual ~AbsTestHarness();						// Virtual destructor
	
protected:
	std::ostream& m_output;							// Private member data from accessed Objects

	std::ostream& n_output;							// Do all of our tests need a place to put the
													// results?
};





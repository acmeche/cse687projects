//////////////////////////////////////////////////////////////////////////////////////////////////
//	File:			LambdaTestCase.h															//
//	Purpose:		--ADD PURPOSE HERE--														//
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
	10/15/2019	1.1			Changed test case base class implementation
*/
#pragma once
//#include <functional>
//#include <initializer_list>
//#include <ostream>
//
//#include "AbsTestHarness.h"
#include "TestCaseBase.h"

namespace CSE687_Project1 {
	class LambdaTestCase : public TestCaseBase {
	public:
		bool execute();
	};
}

///**
//* Class that acts as an child of [abstract testharness class]
//* Satisfies the following project criteria:
//*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
//*	2.) Shall provide a TestHarness class that defines an executor method
//*/
//class LambdaTestCase : public AbsTestHarness
//{
//public:
//	/**
//	* Allows us to output to any stream object (ie cout, file, custom stream object, etc)
//	* Probably beneficial to put this in parent class and child can implement
//	*/
//	LambdaTestCase(std::ostream& output) : AbsTestHarness(output) {}
//	~LambdaTestCase() = default;
//
//	/**
//	* Implemented parent meethod from AbsTestHarness class
//	*/
//	virtual void runTests();
//
//private:
//
//	/**
//	* Method to allow lambda to be executed and returns data from the lambda to the calling class
//	* Satisfies the following project criteria:
//	*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
//	*	2.) Shall provide a TestHarness class that defines an executor method, accepting a callable lambda object
//	*		that accepts no arguments and returns a bool predicate to indicate success or failure.
//	*/
//	template <typename Ret>
//	bool execute(const std::function<Ret(void)> lambda);
//
//	/**
//	* Method to allow lambda to be executed and returns data from the lambda to the calling class
//	* Satisfies the following project criteria:
//	*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
//	*	4.) Shall support linking any number of callable objects for execution, and shall provide a mechanism for executing that sequence.
//	*/
//	template <typename Ret>
//	bool execute(std::initializer_list<const std::function<Ret(void)>> lambdas);
//};


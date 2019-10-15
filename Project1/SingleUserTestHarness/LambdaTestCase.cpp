//////////////////////////////////////////////////////////////////////////////////////////////////
//	File:			LambdaTestCase.cpp															//
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
#include <iostream>
#include "LambdaTestCase.h"

namespace CSE687_Project1 {
	bool LambdaTestCase::execute() {
		std::cout << "LambdaTestCase executing..." << std::endl;
		return true;
	}

	REGISTER_TEST_CASE(LambdaTestCase);
}
///**
//* Test case in order to test the class.
//* This satifies the following project criteria:
//*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
//*	6.) Shall provide a sequence of tests demonstrating all the features of your TestHarness.
//*/
//void LambdaTestCase::runTests()
//{
//	int i = 1;
//	auto lambda = [i]() -> bool {
//		return i < 2;
//	};
//
//	bool result;
//	result = execute<bool>(lambda);
//	i = 5;
//	result = execute<bool>({ lambda, [i]() -> bool {
//		return i < 2;
//	} });
//}
//
//template <typename Ret>
//bool LambdaTestCase::execute(const std::function<Ret(void)> lambda)
//{
//	// Default value for return. Will either return result of lambda, or false if exception is thrown
//	bool result = false;
//	
//	/**
//	* Try/catch to satisfy the following criteria:
//	*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
//	*	3.) The executor method Shall invoke a passed callable object in the scope of a try block. 
//	*		If exceptions are thrown, the catch block you define for this method shall log test failure 
//	*		and the contents of the exception message.
//	*/
//	try 
//	{
//		result = lambda();
//	}
//	catch (std::exception e)
//	{
//		// Logging here
//		result = false;
//		// m_output << "Exception thrown" << std::endl;
//	}
//
//	return result;
//}
//
//template <typename Ret>
//bool LambdaTestCase::execute(std::initializer_list<const std::function<Ret(void)>> lambdas)
//{
//	// Need to determine if this needs to be an AND, OR, or XOR. Will use OR for now
//	bool result = false;
//	for (auto l : lambdas)
//		result = result || execute(l);
//		//result = result && execute(l);
//
//	return result;
//}

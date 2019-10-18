//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        LambdaTestCase.cpp																
// Purpose:     This file contains the implementation for the LambdaTestCase test case
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
   10/15/2019   1.0         Changed test case base class implementation
*/
#include <iostream>
#include "LambdaTestCase.h"

namespace CSE687_Project1 {
	bool LambdaTestCase::execute() 
	{
		std::cout << "LambdaTestCase executing..." << std::endl;

		/**
		* Test case in order to test the class.
		* This satifies the following project criteria:
		*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
		*	6.) Shall provide a sequence of tests demonstrating all the features of your TestHarness.
		*/
		int i = 1;
		auto lambda = [i]() {
			if (i % 2 != 0)
			{
				throw std::bad_exception();
			}

			return i % 2 == 0;
		};
		
		bool result;
		result = internalExecute(lambda);

		i = 5;
		result = result && internalExecute(lambda, [i]() {
			std::cout << "The number stored in captured value is " << std::to_string(i) << std::endl;
		}, []() {
			std::cout << "Another!" <<  std::endl;
		});

		return result;
	}

	template <typename T>
	bool LambdaTestCase::internalExecute(const T& lambda)
	{
			// Default value for return. Will either return result of lambda, or false if exception is thrown
			bool result = false;
			try 
			{
				lambda();
				result = true;
			}
			catch (std::exception e)
			{
				// Throws exception back to calling function after making the result a failure
				result = false;
				throw e;
			}
		
			return result;
	}

	template <typename T, typename ...Funcs>
	bool LambdaTestCase::internalExecute(const T lam, const Funcs... lambdas)
	{
		// Need to determine if this needs to be an AND, OR, or XOR. Will use AND for now
		bool result = internalExecute(lam);
		result = internalExecute(lambdas...) && result;
		return result;
	}

	REGISTER_TEST_CASE(LambdaTestCase);
}

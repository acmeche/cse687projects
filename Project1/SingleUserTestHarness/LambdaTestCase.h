//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        LambdaTestCase.h																
// Purpose:     Header file for LambdaTestCase class
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
   10/15/2019   1.0         Changed test cae base class implementation
   10/17/2019   1.0			Refactored original implementation in order to work with TestCaseBase
                            redesign
*/
#pragma once
#include "TestCaseBase.h"

namespace CSE687_Project1 {
	/**
	* Derivative of the TestCaseBase class to demonstrate running lambda function objects
	*
	*/
	class LambdaTestCase : public TestCaseBase 
	{
		public:
			/**
			* Method to allow lambda to be executed and returns data from the lambda to the calling class
			* Satisfies the following project criteria:
			*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
			*	2.) Shall provide a TestHarness class that defines an executor method, accepting a callable lambda object
			*		that accepts no arguments and returns a bool predicate to indicate success or failure.
			*/
			bool execute();

	private:
		
		/**
		* Internal templated execute function to call a lambda function, catch, and throw exception
		*/
		template <typename T>
		bool internalExecute(const T& lambda);

		/**
		* Internal templated execute function to call a list of lambda functions, catch, and throw exceptions
		*/
		template <typename T, typename ...Funcs>
		bool internalExecute(const T lam, const Funcs... lambdas);
	};
}


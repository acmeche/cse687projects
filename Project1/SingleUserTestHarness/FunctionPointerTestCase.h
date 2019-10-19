//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        FunctionPointerTestCase.h																
// Purpose:     Header file for FunctionPointerTestCase class
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
#include <functional>

#include "TestCaseBase.h"
namespace CSE687_Project1
{
	class FunctionPointerTestCase : public TestCaseBase
	{
		public:
            /**
            * Method to allow function pointer to be executed and returns data from the function pointer to the calling class
            * Satisfies the following project criteria:
            *	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
            *	2.) Shall provide a TestHarness class that defines an executor method, accepting a callable function pointer object
            *		that accepts no arguments and returns a bool predicate to indicate success or failure.
            */
            bool execute();

		private:
            /**
            * Internal templated execute function to call a function pointer function, catch, and throw exception
            */
            template <typename T>
            bool __declspec(nothrow) internalExecute(LOGLEVEL logLevel, const T& functionPointer);

            /**
            * Internal templated execute function to call a list of function pointer functions, catch, and throw exceptions
            */
            template <typename T, typename ...Funcs>
            bool __declspec(nothrow) internalExecute(LOGLEVEL logLevel, const T fp, const Funcs... functionPointer);

	};
}

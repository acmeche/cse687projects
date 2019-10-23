//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        FunctorTestCase.h															
// Purpose:     Header file for FunctorTestCase class																								
// Version:     1.0																			
// Language:    C++, Visual Studio 2019														
// Platform:    Windows 10																	
// Application: Single-User Test Harness, CSE687 - Object Oriented Design					
// Author:      Laamont Harrington															
//              Aaron Meche																	
//              Chris Johnson																
//              Jason Mitchell																
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
   Maintenance History
   ===================
   DATE          VERSION        DESCRIPTION
   ----          -------		------------------------------------------------------------------
   10/15/2019    1.0            Initial Creation
   10/18/2019    1.0            Code cleanup
   10/20/2019    1.0            Code Re work - JDM
*/
#pragma once
#include "TestCaseBase.h"

namespace CSE687_Project1 {
	class FunctorTestCase : public TestCaseBase {
	
	public:
		// Handle for execution.
		bool execute();
		
		// Results for Functor Objects.
		bool eResult = false;
		bool oResult = false;
		bool noResult = false;

		/*Argument for Functor Objects.
		/ I wanted to use "uinshrt_16t" here but
		/ the compiler caught this and trunc'd input to pass.
		*/
		int val;
		bool operator()(int x) {
			val = x;

			// If there is no remainder, you are Even.
			if (x % 2 == 0) { eResult = true; }

			// If there is a remainder, you are Odd.
			if (x % 2 != 0) { oResult = true; }

			// Failure.
			if (x <= 0 || USHRT_MAX < x) {
				noResult = true;
				throw std::invalid_argument("");
			}
			return 1;
		}
		// Member for aesthetics when logging.
		void sLine() {
			std::cout << "====================FunctorTestCaseExecuting====================" << std::endl;
		}
		void eLine() {
			std::cout << "====================FunctorTestCaseComplete====================" << std::endl;
		}
	};
}
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
	 10/25/2019    2.0            Adaptation for DLL use with project 2 - JDM
*/
#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include "TestCaseBase.h"

namespace CSE687_Project2 {
	class FunctorTestCase : public TestCaseBase {

	public:
		// Handle for execution.
		__declspec(dllexport) bool execute();

		// Results for Functor Objects.
		bool eResult = false;
		bool oResult = false;
		bool noResult = false;
		int val = 0;

		__declspec(dllexport) bool operator()(const int x) {
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
		//		// Member for aesthetics when logging.
		//__declspec(dllexport) void sLine(){
		//			std::cout << "====================FunctorTestCaseExecuting====================" << std::endl;
		//			}
		//__declspec(dllexport) void eLine() {
		//			std::cout << "====================FunctorTestCaseComplete=====================" << std::endl;
		//			}
	};

	class FunctorTestCase2 : public TestCaseBase{
		// Record and store even and odd. 
		int _even;
		int _odd;
		// Record and store the pass and fail. 
		int _pass = 0;
		int _fail = 0;
	public:
		// Handle for execution.
__declspec(dllexport) bool execute();
		
   FunctorTestCase2() : _even(0), _odd(0) {}
				
__declspec(dllexport) bool operator()(int j) {
		 if (j < 0) { _fail++; _pass--; }
		 if (j % 2 == 0) { _even += j, _pass++; }
		 else { _odd += j, _pass++; }
		 return 1; 
	}
		// Sum the even and odds to private members. 
    int evenSum() const { return _even; }
    int oddSum()  const { return  _odd; }
		
		// Sum the pass and fail to private members.
    int passes() const { return _pass; };
    int fails() const { return _fail; };

	//	// Member for printing results.
	//__declspec(dllexport) void printFunctorTestCase2Results() {
	//		std::cout << "\t\t" << passes() << ":Passed " << fails() << ":Failed " << std::endl;
	//		}
		};
	}


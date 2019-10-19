//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        FunctorTestCase.cpp																
// Purpose:     FunctorTestCase driver for Test Runner to execute
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
*/
#include <iostream>
#include "FunctorTestCase.h"

namespace CSE687_Project1 {
	bool FunctorTestCase::execute() {
		std::cout << " Functor1 is currently executing " << std::endl;
		Line();
		
		std::cout << " Functor1 testing an odd and even " <<std::endl;
		operator()(3);
		Line();
		
		operator()(8);
		Line();

		/*
		 * I'm still learning the correct way to to perform a try block.
		 * 
		 try {
			operator()(20.00004);
		}
		catch (const std::exception &exc) {
			
			std::cout << exc.what() << std::endl;
			
		} */
		std::cout << " Functor1 passed and is leaving " << std::endl;
		Line();
		return true;
	}

	REGISTER_TEST_CASE(FunctorTestCase);
}
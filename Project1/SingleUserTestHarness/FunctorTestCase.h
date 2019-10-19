//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        FunctorTestCase.h															
// Purpose:     Derived class from TestBaseCase classe for the Single User Test Harness		 
//																								
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
   10/18/2019    1.0			Code cleanup
*/
#pragma once
#include "TestCaseBase.h"

namespace CSE687_Project1 {
	class FunctorTestCase : public TestCaseBase {
		bool result;
	public:
		FunctorTestCase() = default;
		bool execute();
		void operator()(int x) {
			if (x % 2 == 0) {
				std::cout << x << " Is Even " << std::endl;
				
			}else if (x % 2 != 0) {
				std::cout << x << " Is Odd " << std::endl;
			}
			int j = sizeof int16_t;
			if (x < 0 || x <= j){
				//throw (std::make_exception_ptr(x));
				result = false; 
			}
			return;
		}
		/*
		 * Just something here to hold for errors.
		 */
		//FunctorTestCase(std::ostream& output);
	};
	void Line() {
		std::cout << "=====================" << std::endl;
	}
}
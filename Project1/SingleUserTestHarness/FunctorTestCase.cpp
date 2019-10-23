//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        FunctorTestCase.cpp																
// Purpose:     This file contains the implementation for the FunctorTestCase test case
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
   10/18/2019    1.0         Initial Creation
   10/20/2019    1.0         Re worked most of the inital creation - JDM
*/
#include <iostream>
#include "FunctorTestCase.h"

namespace CSE687_Project1 {
	bool FunctorTestCase::execute() {
		// Member for aesthetics.
		FunctorTestCase::sLine();

		// Object to drive the test.
		FunctorTestCase FunctUp;
		
		// Even test.
		FunctUp.operator()(65534);
		  if (FunctUp.eResult) {
				std::string FunctMSG = " Test for Even: " + std::to_string(FunctUp.val);
				logger.writeLog(LOGLEVEL::PASS_FAIL_RESULT, E_RESULT::PASS, FunctMSG.c_str());
			}

		// Odd test.
		FunctUp.operator()(65535);
			if (FunctUp.oResult) {
				std::string FunctMSG = " Test for Odd: " + std::to_string(FunctUp.val);
				logger.writeLog(LOGLEVEL::PASS_FAIL_RESULT, E_RESULT::PASS, FunctMSG.c_str());
			}

		// Exception test.
			try {
				FunctUp.operator()(0);
			}
			catch (std::invalid_argument) {
				std::string FunctMSG = " Test for Invalid Input: " + std::to_string(FunctUp.val);
				logger.writeLog(LOGLEVEL::DEBUG_FAILURE_DETAIL, E_RESULT::FAIL, FunctMSG.c_str());
			}
			try {
				FunctUp.operator()(65536);
			}
			catch (std::invalid_argument) {
				std::string FunctMSG = " Test for valid Input: " + std::to_string(FunctUp.val);
				logger.writeLog(LOGLEVEL::DEBUG_FAILURE_DETAIL, E_RESULT::FAIL, FunctMSG.c_str());
			}
			try {
				FunctUp.operator()(-1);
			}
			catch (std::invalid_argument) {
				std::string FunctMSG = " Test for valid Input: " + std::to_string(FunctUp.val);
				logger.writeLog(LOGLEVEL::DEBUG_FAILURE_DETAIL, E_RESULT::FAIL, FunctMSG.c_str());
			}

    // Member for aesthetics.
		FunctorTestCase::eLine();
		return 1;
	}
	REGISTER_TEST_CASE(FunctorTestCase);
}
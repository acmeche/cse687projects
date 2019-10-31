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
	 10/25/2019    2.0         Adaptation for DLL use with project 2 - JDM
*/
#include "pch.h"
#include "FunctorTestCase.h"
#include "Logger.h"

void printTestArray(int arr[], int n){
	std::cout << " Test Array " << std::endl;
	for (int i = 0; i < n; i++)
	std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

namespace CSE687_Project2 {

	bool FunctorTestCase::execute() {
		// Even test.
		FunctorTestCase::operator()(65534);
		if (FunctorTestCase::eResult) {
			std::string FunctMSG = " Test for Even: " + std::to_string(FunctorTestCase::val);
			Logger::writeLog(LOGLEVEL::PASS_FAIL_RESULT, E_RESULT::PASS, FunctMSG.c_str());
			return 1;
		}
		// Odd test.
		FunctorTestCase::operator()(65535);
		if (FunctorTestCase::oResult) {
			std::string FunctMSG = " Test for Odd: " + std::to_string(FunctorTestCase::val);
			Logger::writeLog(LOGLEVEL::PASS_FAIL_RESULT, E_RESULT::PASS, FunctMSG.c_str());
			return 1;
		}
		// Exception test.
		try {
			FunctorTestCase::operator()(0);
		}
		catch (std::invalid_argument) {
			std::string FunctMSG = " Test for Invalid Input; 0: " + std::to_string(FunctorTestCase::val);
			Logger::writeLog(LOGLEVEL::DEBUG_FAILURE_DETAIL, E_RESULT::PASS, FunctMSG.c_str());
		}
		try {
			FunctorTestCase::operator()(65536);
		}
		catch (std::invalid_argument) {
			std::string FunctMSG = " Test for Invalid Input; Max: " + std::to_string(FunctorTestCase::val);
			Logger::writeLog(LOGLEVEL::DEBUG_FAILURE_DETAIL, E_RESULT::PASS, FunctMSG.c_str());
		}
		try {
			FunctorTestCase::operator()(-1);
		}
		catch (std::invalid_argument) {
			std::string FunctMSG = " Test for valid Input; negative int: " + std::to_string(FunctorTestCase::val);
			Logger::writeLog(LOGLEVEL::DEBUG_FAILURE_DETAIL, E_RESULT::PASS, FunctMSG.c_str());
		}
		return 1;
	}
	REGISTER_TEST_CASE(FunctorTestCase);

//*******************************************//
//---------------AnotherTest---------------//
//*****************************************//
	bool FunctorTestCase2::execute() {
		// Object from Derived Class.
		FunctorTestCase2 functSUM;

		// Test Array to drive the test.
		int functList[] = { 21,10,98,3,88,61,15,36,20,77 };

		// Construct the Derived Class.	
		functSUM = std::for_each(functList, functList + sizeof(functList) / sizeof(functList[0]), functSUM);

		// Print the Test Array to the Console.
		//printTestArray(functList, 10);

		// Log the test results.
		if (functSUM.evenSum() == 252) {
			std::string FunctMSG = "Test even SUM: " + std::to_string(functSUM.evenSum());
			Logger::writeLog(LOGLEVEL::PASS_FAIL_RESULT, E_RESULT::PASS, FunctMSG.c_str());
		}
		else {
			std::string FunctFailEMSG = "Even Test Failed: ";
			Logger::writeLog(LOGLEVEL::PASS_FAIL_RESULT, E_RESULT::FAIL, FunctFailEMSG.c_str());
		}
		if (functSUM.oddSum() == 177) {
			std::string FunctMSG = "Test odd SUM: " + std::to_string(functSUM.oddSum());
			Logger::writeLog(LOGLEVEL::PASS_FAIL_RESULT, E_RESULT::PASS, FunctMSG.c_str());
		}
		else {
			std::string FunctFailOMSG = "Odd Test Failed: ";
			Logger::writeLog(LOGLEVEL::PASS_FAIL_RESULT, E_RESULT::FAIL, FunctFailOMSG.c_str());
		}
		return 1;
	}
	REGISTER_TEST_CASE(FunctorTestCase2);
}

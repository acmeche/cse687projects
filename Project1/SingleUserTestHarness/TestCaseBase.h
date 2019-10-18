//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        TestCaseBase.h																
// Purpose:     Header file for Test Case base class from which new Test Case classes are 
//              derived that encapsulate unit tests executed by the Test Harness for unit testing 
//              C++ code for projects created for CSE687
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
   10/15/2019   1.0         Added test harness frameweork
   10/18/2019   1.0         Added Logger as a protected member. Each test case instance will be 
                            responsible for their own logging
*/
#pragma once
#include <string>
#include <vector>
#include <vector>
#include "Logger.h"

namespace CSE687_Project1 {

	class TestCaseBase {
		public:
			virtual bool execute() = 0;
	protected:
		Logger logger;
	};

	template<class T> TestCaseBase* testCaseBase_factory() {
		return new T;
	}

	typedef TestCaseBase* (*testCaseBase_creator)(void);

	class TestCaseRegistry {
	private:
		std::vector<testCaseBase_creator> m_testCases;
	public:
		typedef std::vector<testCaseBase_creator>::iterator iterator;
		static TestCaseRegistry& get();
		void add(testCaseBase_creator);
		iterator begin();
		iterator end();
	};

	class TestCaseRegistration {
	public:
		TestCaseRegistration(testCaseBase_creator);
	};

/**
* Define command that, when added to the source file of a TestCase, automatically adds it to a list of TestCase objects to run
* Satisfies the following project criteria:
*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
*	4.) Shall support linking any number of callable objects for execution, and shall provide a mechanism for executing that sequence.
*/
#define REGISTER_TEST_CASE(testCase) \
    TestCaseRegistration _testCase_registration_ ## testCase(&testCaseBase_factory<testCase>);

}
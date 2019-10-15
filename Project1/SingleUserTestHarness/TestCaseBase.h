//////////////////////////////////////////////////////////////////////////////////////////////////
//	File:			TestCaseBase.cpp															//
//	Purpose:		Base class from which new Test Case classes are derived that encapsulate	// 
//					unit tests executed by the Test Harness for unit testing C++ code for		// 
//					projects created for CSE687													//
//	Version:		1.0																			//
//	Language:		C++, Visual Studio 2019														//
//	Platform:		Windows 10																	//
//	Application:	Single-User Test Harness, CSE687 - Object Oriented Design					//
//	Author:			Laamont Harrington															//
//					Aaron Meche																	//
//					Chris Johnson																//
//					Jason Mitchell																//
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
	Maintenance History
	===================
	DATE		VERSION		DESCRIPTION
	----		-------		----------------------------------------------------------------------
	10/8/2019	1.0			Initial Creation
	10/15/2019	1.1			Added test harness framework		
*/
#pragma once
#include <string>
#include <vector>

namespace CSE687_Project1 {

	class TestCaseBase {
	public:
		virtual bool execute() = 0;
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

#define REGISTER_TEST_CASE(testCase) \
    TestCaseRegistration _testCase_registration_ ## testCase(&testCaseBase_factory<testCase>);

}
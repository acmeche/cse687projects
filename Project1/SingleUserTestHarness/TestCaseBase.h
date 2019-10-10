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
*/
#pragma once

namespace SingleUserTestHarness 
{
	class TestCaseBase
	{
	public:
		bool execute();
	};
}
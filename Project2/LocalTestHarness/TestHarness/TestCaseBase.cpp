//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        TestCaseBase.cpp																
// Purpose:     Implementation file for Test Case base class from which new Test Case classes are 
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
   10/22/2019   2.0         Coppied from project 1 in order to meet project requirements
   11/1/2019    2.1         Fixed access violation where dll was being released before reference to dll TestCaseBase object was
*/
#include "pch.h"
#pragma once
#include "TestCaseBase.h"

namespace CSE687_Project2 {
    // Returns a singleton instance of the TestCaseRegistry used to manage a vector container 
    // of test case classes
    TestCaseRegistry& TestCaseRegistry::get() {
        static TestCaseRegistry instance;
        return instance;
    }

    // Adds a new element to the vector
    void TestCaseRegistry::add(testCaseBase_creator creator) {
        m_testCases.push_back(creator);
    }

    // Remove an element from the TestCase vector
    void TestCaseRegistry::remove(testCaseBase_creator creator) {
        auto it = std::find(m_testCases.begin(), m_testCases.end(), creator);
        m_testCases.erase(it);
    }

    // Returns an iterator pointing to the first element in the vector
    TestCaseRegistry::iterator TestCaseRegistry::begin() {
        return m_testCases.begin();
    }

    // Returns an iterator referring to the past-the-end element in the vector container
    TestCaseRegistry::iterator TestCaseRegistry::end() {
        return m_testCases.end();
    }

    // Used to register test case class with the Test Harness framework
    // Called by REGISTER_TEST_CASE macro that's implemented in each test case class implementation
    TestCaseRegistration::TestCaseRegistration(testCaseBase_creator creator) {
        TestCaseRegistry::get().add(creator);
    }
}
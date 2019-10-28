//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        LambdaTestCase.h																
// Purpose:     Header file for LambdaTestCase class
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
   10/15/2019   1.0         Changed test cae base class implementation
   10/17/2019   1.0			Refactored original implementation in order to work with TestCaseBase
                            redesign
   10/18/2019   1.0         Updated implementation to account for logger. Also added additional test
   10/22/2019   2.0         Coppied from project 1 to test functionality of calling classes from
                            different packages
*/
#pragma once
#include "TestCaseBase.h"

namespace CSE687_Project2 {
    /**
    * Derivative of the TestCaseBase class to demonstrate running lambda function objects
    *
    */
    class LambdaTestCase : public TestCaseBase
    {
    public:

        __declspec(dllexport) bool execute();

    private:

        /**
        * Internal templated execute function to call a lambda function, catch, and throw exception
        */
        template <typename T>
        bool __declspec(nothrow) internalExecute(LOGLEVEL logLevel, const T& lambda);

        /**
        * Internal templated execute function to call a list of lambda functions, catch, and throw exceptions
        */
        template <typename T, typename ...Funcs>
        bool __declspec(nothrow) internalExecute(LOGLEVEL logLevel, const T lam, const Funcs... lambdas);

        /**
        * Convience method to get lambda that does matrix math
        * \param x - num rows for matrix 1. Must be less than 10
        * \param y - num columns for matrix 1. Must be less than 10
        * \param c - num rows for matrix 2. Must be less than 10
        * \param d - num columns for matrix 2. Must be less than 10
        */
        auto getMatrixLambda(int x, int y, int c, int d);
    };
}


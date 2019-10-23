//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        LambdaTestCase.cpp																
// Purpose:     This file contains the implementation for the LambdaTestCase test case
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
   10/15/2019   1.0         Changed test case base class implementation
   10/17/2019   1.0			Refactored original implementation in order to work with TestCaseBase
                            redesign
   10/18/2019   1.0         Updated implementation to account for logger. Also added additional test
   10/22/2019   2.0         Coppied from project 1 to test functionality of calling classes from
                            different packages
*/
#include <iostream>
#include "LambdaTestCase.h"

namespace CSE687_Project2
{
    auto LambdaTestCase::getMatrixLambda(int x, int y, int c, int d)
    {
        return [x, y, c, d] {
            int a[10][10], b[10][10], mult[10][10], i, j, k;
            // If column of first matrix in not equal to row of second matrix,
            // ask the user to enter the size of matrix again.
            if (y != c)
            {
                throw std::invalid_argument("Error! column of first matrix not equal to row of second.");
            }
            // Storing elements of first matrix.
            for (i = 0; i < x; ++i)
                for (j = 0; j < y; ++j)
                {
                    a[i][j] = j + i;
                }
            // Storing elements of second matrix.
            for (i = 0; i < c; ++i)
                for (j = 0; j < d; ++j)
                {
                    b[i][j] = j + i;
                }
            // Initializing elements of matrix mult to 0.
            for (i = 0; i < x; ++i)
                for (j = 0; j < d; ++j)
                {
                    mult[i][j] = 0;
                }
            // Multiplying matrix a and b and storing in array mult.
            for (i = 0; i < x; ++i)
                for (j = 0; j < d; ++j)
                    for (k = 0; k < y; ++k)
                    {
                        mult[i][j] += a[i][k] * b[k][j];
                    }

            // Displaying the multiplication of two matrix.
            std::cout << std::endl << "Output Matrix: " << std::endl;
            for (i = 0; i < x; ++i)
                for (j = 0; j < d; ++j)
                {
                    std::cout << " " << mult[i][j];
                    if (j == d - 1)
                        std::cout << std::endl;
                }
        };
    }

    bool LambdaTestCase::execute()
    {
        std::cout << "LambdaTestCase executing..." << std::endl;

        /**
        * Test case in order to test the class.
        * This satifies the following project criteria:
        *	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
        *	6.) Shall provide a sequence of tests demonstrating all the features of your TestHarness.
        */
        int i = 1;
        auto lambda = [i]() {
            if (i % 2 != 0)
            {
                throw std::invalid_argument(std::to_string(i) + " is not even!");
            }

            return i % 2 == 0;
        };

        bool result;
        result = internalExecute(LOGLEVEL::PASS_FAIL_RESULT, lambda);

        i = 5;
        result = internalExecute(LOGLEVEL::PASS_FAIL, lambda, [i]() {
            std::cout << "The number stored in captured value is " << std::to_string(i) << std::endl;
            }, []() {
                std::cout << "Another!" << std::endl;
            }) && result;

        result = internalExecute(LOGLEVEL::DEBUG_FAILURE_DETAIL, getMatrixLambda(3, 2, 3, 2), getMatrixLambda(2, 3, 3, 2)) && result;

        std::cout << "=====================" << std::endl;
        return result;
    }

    template <typename T>
    bool __declspec(nothrow) LambdaTestCase::internalExecute(LOGLEVEL logLevel, const T& lambda)
    {
        // Default value for return. Will either return result of lambda, or false if exception is thrown
        bool result = false;
        std::string message;
        try
        {
            lambda();
            result = true;
            message = "Lambda with signature " + std::string(typeid(lambda).name()) + " successfully executed";
            logger.writeLog(logLevel, E_RESULT::PASS, message.c_str());
        }
        catch (const std::exception & e)
        {
            // Prints exption and fails 
            result = false;
            message = "Exception: " + std::string(e.what());
            logger.writeLog(logLevel, E_RESULT::FAIL, message.c_str());
        }

        return result;
    }

    template <typename T, typename ...Funcs>
    bool __declspec(nothrow) LambdaTestCase::internalExecute(LOGLEVEL logLevel, const T lam, const Funcs... lambdas)
    {
        // Need to determine if this needs to be an AND, OR, or XOR. Will use AND for now
        bool result = internalExecute(logLevel, lam);
        result = internalExecute(logLevel, lambdas...) && result;
        return result;
    }

    REGISTER_TEST_CASE(LambdaTestCase);
}

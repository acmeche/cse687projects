//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        FunctionPointerTestCase.cpp																
// Purpose:     This file contains the implementation for the FunctionPointerTestCase test case
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
   10/18/2019   1.0         Added class to solution
*/
#include <stdexcept>
#include <iostream>

#include "FunctionPointerTestCase.h"

namespace CSE687_Project1
{
    /**
    * Function for testing function pointer
    */
    int evenFunctionPointerFail()
    {
        int result = 1 % 2;
        if (result != 0)
            throw std::invalid_argument(std::to_string(result) + " is not even!");

        return result;
    }

    int evenFunctionPointerPass()
    {
        int result = 10 % 2;
        if (result != 0)
            throw std::invalid_argument(std::to_string(result) + " is not even!");

        return result;
    }

    void matrixMathFail()
    {
        int a[10][10], b[10][10], mult[10][10], x = 3, y = 2, c = 3, d = 2, i, j, k;
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
    }

    void matrixMathPass()
    {
        int a[10][10], b[10][10], mult[10][10], x = 2, y = 3, c = 3, d = 2, i, j, k;
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
    }

    bool FunctionPointerTestCase::execute()
    {
        std::cout << "FunctionPointerTestCase executing..." << std::endl;
        auto evenFp = &evenFunctionPointerFail;

        /**
        * Test case in order to test the class.
        * This satifies the following project criteria:
        *	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
        *	6.) Shall provide a sequence of tests demonstrating all the features of your TestHarness.
        */
        bool result;
        result = internalExecute(LOGLEVEL::PASS_FAIL, evenFp);
        result = internalExecute(LOGLEVEL::PASS_FAIL_RESULT, evenFp, &evenFunctionPointerPass) && result;
        result = internalExecute(LOGLEVEL::PASS_FAIL_RESULT, &matrixMathFail, &matrixMathPass) && result;

        return result;
    }

    template <typename T>
    bool __declspec(nothrow) FunctionPointerTestCase::internalExecute(LOGLEVEL logLevel, const T& functionPointer)
    {
        // Default value for return. Will either return result of lambda, or false if exception is thrown
        bool result = false;
        std::string message;

        /**
        * Try/catch to satisfy the following criteria:
        *	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
        *	3.) The executor method Shall invoke a passed callable object in the scope of a try block.
        *		If exceptions are thrown, the catch block you define for this method shall log test failure
        *		and the contents of the exception message.
        */
        try
        {
            functionPointer();
            result = true;
            message = "Function pointer with signature " + std::string(typeid(functionPointer).name()) + " successfully executed";
            logger.writeLog(logLevel, E_RESULT::PASS, message.c_str());
        }
        catch (std::exception e)
        {
            // Prints exption and fails 
            result = false;
            message = "Exception: " + std::string(e.what());
            logger.writeLog(logLevel, E_RESULT::FAIL, message.c_str());
        }

        std::cout << "=====================" << std::endl;
        return result;
    }

    template <typename T, typename ...Funcs>
    bool __declspec(nothrow) FunctionPointerTestCase::internalExecute(LOGLEVEL logLevel, const T fp, const Funcs... functionPointer)
    {
        // Need to determine if this needs to be an AND, OR, or XOR. Will use AND for now
        bool result = internalExecute(logLevel, fp);
        result = internalExecute(logLevel, functionPointer...) && result;
        return result;
    }

    REGISTER_TEST_CASE(FunctionPointerTestCase);
}
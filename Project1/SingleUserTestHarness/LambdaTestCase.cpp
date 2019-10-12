#include <iostream>
#include "LambdaTestCase.h"

/**
* Test case in order to test the class.
* This satifies the following project criteria:
*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
*	6.) Shall provide a sequence of tests demonstrating all the features of your TestHarness.
*/
void LambdaTestCase::runTests()
{
	int i = 1;
	auto lambda = [i]() -> bool {
		return i < 2;
	};

	bool result;
	result = execute<bool>(lambda);
	i = 5;
	result = execute<bool>({ lambda, [i]() -> bool {
		return i < 2;
	} });
}

template <typename Ret>
bool LambdaTestCase::execute(const std::function<Ret(void)> lambda)
{
	// Default value for return. Will either return result of lambda, or false if exception is thrown
	bool result = false;
	
	/**
	* Try/catch to satisfy the following criteria:
	*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
	*	3.) The executor method Shall invoke a passed callable object in the scope of a try block. 
	*		If exceptions are thrown, the catch block you define for this method shall log test failure 
	*		and the contents of the exception message.
	*/
	try 
	{
		result = lambda();
	}
	catch (std::exception e)
	{
		// Logging here
		result = false;
		// m_output << "Exception thrown" << std::endl;
	}

	return result;
}

template <typename Ret>
bool LambdaTestCase::execute(std::initializer_list<const std::function<Ret(void)>> lambdas)
{
	// Need to determine if this needs to be an AND, OR, or XOR. Will use OR for now
	bool result = false;
	for (auto l : lambdas)
		result = result || execute(l);
		//result = result && execute(l);

	return result;
}

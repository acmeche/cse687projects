#include <iostream>
#include "LambdaTestCase.h"

LambdaTestCase::LambdaTestCase(std::ostream& output) : m_output(output)
{
	// empty
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

/**
* Optional Preprocessor test case in order to test the class without needing to use a main.cpp file (at least for this class).
* This satifies the following project criteria:
*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
*	6.) Shall provide a sequence of tests demonstrating all the features of your TestHarness.
*/
#ifdef TEST_LAMBDACASE
int main(int argc, char* argv[])
{
	LambdaTestCase th(std::cout);
	int i = 1;
	auto lambda = [i]() -> bool {
		return i < 2;
	};

	bool result;
	result = th.execute<bool>(lambda);
	i = 5;
	result = th.execute<bool>({ lambda, [i]() -> bool {
		return i < 2;
	} });
	return 0;
}
#endif

#pragma once
#include <functional>
#include <initializer_list>
#include <ostream>

#include "AbsTestHarness.h"

/**
* Class that acts as an child of [abstract testharness class]
* Satisfies the following project criteria:
*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
*	2.) Shall provide a TestHarness class that defines an executor method
*/
class LambdaTestCase : public AbsTestHarness
{
public:
	/**
	* Allows us to output to any stream object (ie cout, file, custom stream object, etc)
	* Probably beneficial to put this in parent class and child can implement
	*/
	LambdaTestCase(std::ostream& output) : AbsTestHarness(output) {}
	~LambdaTestCase() = default;

	/**
	* Implemented parent meethod from AbsTestHarness class
	*/
	virtual void runTests();

private:

	/**
	* Method to allow lambda to be executed and returns data from the lambda to the calling class
	* Satisfies the following project criteria:
	*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
	*	2.) Shall provide a TestHarness class that defines an executor method, accepting a callable lambda object
	*		that accepts no arguments and returns a bool predicate to indicate success or failure.
	*/
	template <typename Ret>
	bool execute(const std::function<Ret(void)> lambda);

	/**
	* Method to allow lambda to be executed and returns data from the lambda to the calling class
	* Satisfies the following project criteria:
	*	1.) Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming language, using the standard C++ libraries.
	*	4.) Shall support linking any number of callable objects for execution, and shall provide a mechanism for executing that sequence.
	*/
	template <typename Ret>
	bool execute(std::initializer_list<const std::function<Ret(void)>> lambdas);
};


#include <iostream>

#include "logger.h"

#include <cstdlib>



using namespace std;


int main()

{
    
    
	Logger i;

	LOGLEVEL o = DETAIL;
	i.report(o);

	return 0;

}
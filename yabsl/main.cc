#include <iostream>
#include "yabsl_driver.hh"

int
main (int argc, char *argv[])
{
	yabsl_driver driver;
	int res=0;

	int i;
	for (i=0; i<argc; ++i)
		if (argv[i] == std::string ("-p"))
			driver.trace_parsing = true;
		else if (argv[i] == std::string ("-s"))
			driver.trace_scanning = true;
		else if (!driver.parse (argv[i]))
			//std::cout << driver.modelName << std::endl;
			std::cout << "Running." << std::endl;
		else
			res = 1;
	return res;
}




#include <iostream>
#include "yabsl-driver.hh"


int
main (int argc, char *argv[])
{
	int res = 0;
	yabsl_driver driver;
	for (int i = 1; i < argc; ++i)
		if (argv[i] == std::string ("-p"))
			driver.trace_parsing = true;
		else if (argv[i] == std::string ("-s"))
			driver.trace_scanning = true;
		else if (!driver.parse (argv[i])) {
			std::cout << "Finished parsing model \"";
			std::cout << driver.modelName << "\"" << std::endl;
		} else
			res = 1;
	return res;
}


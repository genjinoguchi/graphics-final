#include "yabsl_driver.hh"
#include "yabsl_parser.hh"

// Driver Definitions /////////////////////////////////

yabsl_driver::yabsl_driver ()
	: trace_scanning (false), trace_parsing (false)
{
	// init
}

yabsl_driver::~yabsl_driver ()
{

}

int
yabsl_driver::parse (const std::string& f)
{
	file = f;
	scan_begin ();
	yy::yabsl_parser parser (*this);
	parser.set_debug_level (trace_parsing);
	int res = parser.parse();
	scan_end();
	return res;
}

void
yabsl_driver::error (const yy:location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

void
yabsl_driver::error (const std::string& m)
{
  std::cerr << m << std::endl;
}

# ifndef YABSL_DRIVER_HH
# define YABSL_DRIVER_HH

#include <string>
#include <map>
#include "yabsl-parser.hh"


/*
 * Flex expects the signature of yylex
 * to be defined in the macro YY_DECL,
 * and the C++ parser expects it 
 * to be declared.
 */
# define YY_DECL \
	yy::yabsl_parser::symbol_type yylex (yabsl_driver& driver)

/* 
 * Declare it for the parser.
 */
YY_DECL;


/*
 * The class to act as the conductor of
 * scanning and parsing.
 */
class yabsl_driver
{
	public:
		yabsl_driver ();
		virtual ~yabsl_driver ();
		
		std::map<std::string, int> variables;




		// Scanning Phase ////////////////////////
		
		void scan_begin ();
		void scan_end ();
		/*
		 * Indicate whether scan traces
		 * will be generated.
		bool trace_scanning;




		
		// Parsing Phase ////////////////////////

		/*
		 * Runs the parser on file F.
		 * Returns 0 on success.
		 * Hold onto the filename for location
		 * tracking later on.
		 */
		int parse (const std::string& F);
		std::string file;

		/*
		 * Indicate whether parse traces
		 * will be generated.
		 */
		bool trace_parsing;




		// Error Handling ///////////////////////
		
		void error (const yy::location& l, const std::string& m);
		void error (const std::string& m);



	private:

};
#endif // ! YABSL_DRIVER_HH;


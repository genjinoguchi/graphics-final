
# ifndef YABSL_DRIVER_HH
# define YABSL_DRIVER_HH

#include <string>
#include <map>
#include "yabsl-parser.hh"
//#include "../gl_src/model.h"

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

		// Model
		string modelName;


		// Scanning Phase ////////////////////////
		
		void scan_begin ();
		void scan_end ();
		/*
		 * Indicate whether scan traces
		 * will be generated.
		 */
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



		// Error Handling ///////////////////////	
		void print_debug (const yy::location& l, const std::string& m);
		void print_debug (const std::string& m);


	private:

};
#endif // ! YABSL_DRIVER_HH;


/*
#ifndef YABSL_DRIVER_HH
# define YABSL_DRIVER_HH
# include <string>
# include <map>
# include "yabsl-parser.hh"
// Tell Flex the lexer's prototype ...
# define YY_DECL \
  yy::yabsl_parser::symbol_type yylex (yabsl_driver& driver)
// ... and declare it for the parser's sake.
YY_DECL;
// Conducting the whole scanning and parsing of Calc++.
class yabsl_driver
{
public:
  yabsl_driver ();
  virtual ~yabsl_driver ();

  std::map<std::string, int> variables;

  int result;
  // Handling the scanner.
  void scan_begin ();
  void scan_end ();
  bool trace_scanning;
  // Run the parser on file F.
  // Return 0 on success.
  int parse (const std::string& f);
  // The name of the file being parsed.
  // Used later to pass the file name to the location tracker.
  std::string file;
  // Whether parser traces should be generated.
  bool trace_parsing;
  // Error handling.
  void error (const yy::location& l, const std::string& m);
  void error (const std::string& m);
  void print_debug (const yy::location& l, const std::string& m);
  void print_debug (const std::string& m);
};
#endif // ! YABSL_DRIVER_HH
*/

/* YABSL LEXER */ 


/* ======== DEFINITIONS =================== */

%{ /* -*- C++ -*- */

	#include <cerrno>
	#include <climits>
	#include <cstdlib>
	#include <string>

	#include "yabsl_driver.hh"
	#include "yabsl_parser.hh"


	// Work around an incompatibility in flex (at least versions
	// 2.5.31 through 2.5.33): it generates code that does
	// not conform to C89.  See Debian bug 333231
	// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
	#undef yywrap
	#define yywrap() 1

	// Manage the location of the token
	static yy::location loc;

%}

// Tell Flex that this is not a user environment (eg shell/repl)
%option noyywrap nounput noinput

// "Slightly more optimized"
%option batch

// Print debug messages
%option debug

// C++
%option c++

// Enables the use of start condition stacks
%option stack


%{
	// Code run each time a pattern is matched.
	#define YY_USER_ACTION  loc.columns (yyleng);
%}


// Start Conditions. Use %s for inclusive conditions and %x for exclusive ones.
%s COMMENT			/* start condition for comments 	*/
%s QUOTES			/* start condition for strings  	*/
%x PARENS			/* start condition for parentheses	*/
%x BRACKETS			/* start condition for brackets 	*/


%%


/* ============================ RULES ===================================== */

%{
		// Code run each time yylex is called.
		loc.step ();
%}

// WHITESPACE
[ \t]+		loc.step ();
[\n]+		loc.lines (yyleng); loc.step ();

/* //////////////////////////////////////////////////////////////////// */
/* ============================ VARIABLES ============================= */	
[A-Za-z_][A-Za-z0-9_]* {
	yylval.variableVal = atoi(yytext);
	#ifdef DEBUG
	cout << "Found variable : " << yytext << endl;
	#endif

	yy::yabsl_parser::make_
}
/* /////////////////////////////////////////////////////////////////// */
/* ============================ INTEGERS ============================= */	
(-)?[0-9] {
	yylval->integerVal = atoi(yytext);
	#ifdef DEBUG
	cout << "Found integer : " << yytext << endl;
	#endif
	
	return INTEGER
}
/* /////////////////////////////////////////////////////////////////// */
/* ============================ FLOATS =============================== */	
(-)?[0-9]+(\.)[0-9]+ {
	yylval->floatVal = atof(yytext);
	#ifdef DEBUG
	cout << "Found integer : " << to_string(yylval->floatVal) << endl;
	#endif

	return FLOAT;
}
/* //////////////////////////////////////////////////////////////////// */
/* ============================ BRACKETS ============================== */	
\{ {
	#ifdef DEBUG
	cout << "Found open bracket" << endl;
	#endif

	return OPENBRACKET;
}
\} {
	#ifdef DEBUG
	cout << "Found closing bracket" << endl;
	#endif

	return CLOSEBRACKET;
}
/* //////////////////////////////////////////////////////////////////// */
/* ============================ COMMENTS ============================== */	
#(.*) {
	#ifdef DEBUG
	cout << "Found line comment" << endl;
	#endif

	return COMMENT;
}
/* //////////////////////////////////////////////////////////////////// */
/* ============================ WHITESPACE ============================ */	

[ \t]				;	// Ignore white space

/* //////////////////////////////////////////////////////////////////// */



{id}       return yy::yabsl_parser::make_IDENTIFIER(yytext, loc);
.          driver.error (loc, "invalid character");
<<EOF>>    return yy::yabsl_parser::make_END(loc);
%%



/* ============================ END RULES ================================= */


void
yabsl_driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      error ("cannot open " + file + ": " + strerror(errno));
      exit (EXIT_FAILURE);
    }
}

void
yabsl_driver::scan_end ()
{
  fclose (yyin);
}




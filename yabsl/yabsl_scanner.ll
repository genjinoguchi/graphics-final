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

	/** Tell Flex that this is not a user environment (eg shell/repl) */
%option noyywrap nounput noinput

	/** "Slightly more optimized" */
%option batch

	/** Print debug messages */
%option debug

	/** Enables the use of start condition stacks */
%option stack


%{
	/** Code run each time a pattern is matched. */
	#define YY_USER_ACTION  loc.columns (yyleng);
%}


	/* Start Conditions.
	 * Use %s for inclusive conditions and
	 * *x for exclusive conditions.
	 */


	/* Regex Macros */
ID			[A-Za-z_][A-Za-z0-9_]*
SPACE		[ \t]
WHITESPACE	[ \t\n]



%%



	/* ======================= RULES ================================= */
%{
	/** Code run each time yylex is called. */
	loc.step ();
%}
	/* /////////////////////////////////////////////////// */
	/* ================ LOCATION TRACKING ================ */	
[\n]+							{
	loc.lines (yyleng);
	loc.step ();
}
	/* /////////////////////////////////////////////////// */
	/* =================== COMMENTS ====================== */	
<*>#(.*)						{
	// Ignore line comments
	driver.print_debug(loc, "Found line comment");
}
	/* /////////////////////////////////////////////////// */
	/* =============== ERROR CHECKING ==================== */	
	/* /////////////////////////////////////////////////// */
	/* ======================== DEFS ===================== */	
	/* /////////////////////////////////////////////////// */
	/* =================== BRACKETS ====================== */	
\{								{
	driver.print_debug(loc, "Found opening bracket");
	
}
	/* /////////////////////////////////////////////////// */
	/* ====================== FLOATS ===================== */	
	/* /////////////////////////////////////////////////// */
	/* ===================== INTEGERS ==================== */	
	/* /////////////////////////////////////////////////// */
	/* ===================== IDENTIFIERS ================= */	
{ID}							{
	driver.print_debug(loc, "Found identifier");

	return yy::yabsl_parser::make_IDENTIFIER(yytext, loc);
								}
	/* /////////////////////////////////////////////////// */
	/* ====================== END OF FILE ================ */
<<EOF>>							{
	driver.print_debug (loc, "Found end of file.");
	return yy::yabsl_parser::make_END (loc);
}
%%
	/* =================== END RULES ========================== */





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



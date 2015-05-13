
	/* YABSL LEXER */ 


	/* ======== DEFINITIONS =================== */

%{ /* -*- C++ -*- */

	#include <cerrno>
	#include <climits>
	#include <cstdlib>
	#include <string>

	#include "yabsl-driver.hh"
	#include "yabsl-parser.hh"


	// Work around an incompatibility in flex (at least versions
	// 2.5.31 through 2.5.33): it generates code that does
	// not conform to C89.  See Debian bug 333231
	// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
	#undef yywrap
	#define yywrap() 1

	#define yyterminate() return token::END

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
%x BLOCK
%s COMMENT
%x EXPECT_ARGS

	/* Regex Macros */
ID			[A-Za-z0-9_\.]+
WHITESPACE  [ \t\r]+




%%

	/* ======================= RULES ================================= */
%{
	/** Code run each time yylex is called. */
	loc.step ();
%}
	/* /////////////////////////////////////////////////// */
	/* ====================== SPACES ===================== */
<*>[ \t\r]+						{
	/* get rid of whitespace */
	loc.step();
}
	/* /////////////////////////////////////////////////// */
	/* ================ LOCATION TRACKING ================ */	
<*>[\n]							{
	driver.print_debug (loc, "Found new line");
	loc.lines (yyleng);
	loc.step ();
}
	/* /////////////////////////////////////////////////// */
	/* =================== COMMENTS ====================== */	
<*>"/*"							{
	driver.print_debug (loc, "Found comment start tag");
	yy_push_state (COMMENT);
}
<COMMENT>"*/"					{
	driver.print_debug (loc, "Comment block ended.");
	yy_pop_state ();
}
<COMMENT>(("*"[^/])?|[^*])*		;/* Non-greedy regex by Chesley Tan */
	/* /////////////////////////////////////////////////// */
	/* ======================== DEFS ===================== */
"model"							{
	driver.print_debug (loc, "Found new-model identifier");
	return yy::yabsl_parser::make_MODEL_IDENT (loc);
}
<BLOCK>"mesh"							{
	driver.print_debug (loc, "Found new-mesh identifier");
	return yy::yabsl_parser::make_MESH_IDENT (loc);
}
<BLOCK>"transform"						{
	driver.print_debug (loc, "Found new-transform identifier");
	return yy::yabsl_parser::make_TRANS_IDENT (loc);
}
	/* /////////////////////////////////////////////////// */
	/* =================== BRACKETS ====================== */
<INITIAL,BLOCK>\{								{
	driver.print_debug (loc, "Found opening bracket");
	yy_push_state (BLOCK);
	return yy::yabsl_parser::make_LBRACKET (loc);
}
<BLOCK>\}						{
	driver.print_debug (loc, "Found closing bracket");
	yy_pop_state ();
	return yy::yabsl_parser::make_RBRACKET (loc);
}
	/* /////////////////////////////////////////////////// */
	/* ===================== IDENTIFIERS ================= */
<INITIAL,BLOCK>{ID}				{
	driver.print_debug (loc, std::string ("Found identifier: ") + yytext);

	return yy::yabsl_parser::make_IDENTIFIER (yytext, loc);
}
	/* /////////////////////////////////////////////////// */
	/* ===================== SEMICOLONS ================== */
<BLOCK>";"							{
	driver.print_debug (loc, "Found semicolon");
	return yy::yabsl_parser::make_SEMICOLON (loc);
}
	/* /////////////////////////////////////////////////// */
	/* ==================== ERROR CHECKING =============== */
.								{
	driver.print_debug (loc, std::string ("Found catchall") + yytext);
	driver.error (loc, std::string("invalid character: ") + yytext);
}
	/* /////////////////////////////////////////////////// */
	/* ====================== END OF FILE ================ */
<<EOF>>							{
	driver.print_debug ("Reached end of file");	
	return yy::yabsl_parser::make_END (loc);
}
	/* /////////////////////////////////////////////////// */


	/* =================== END RULES ========================== */

%%

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







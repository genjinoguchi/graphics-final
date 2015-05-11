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
// The scanner found the tokens "anim/model/mesh"
%x DEF_ANIM 		/* start condition expecting anim name 	*/
%x DEF_MODEL 		/* start condition expecting model name	*/
%x DEF_TRANS 		/* start condition expecting transformation name	*/
%x DEF_VAR 			/* start condition expecting var name	*/
%x DEF_MESH			/* start condition expecting mesh name	*/
// The type of block that the scanner is currently parsing through
%x MODEL_BLOCK		/* start condition for defining models	*/
%x MESH_BLOCK		/* start condition for defining meshes	*/
%x ANIM_BLOCK		/* start condition for defining anims	*/
%x TRANS_BLOCK		/* start condition for defining transformations	*/
%x VAR_BLOCK		/* start condition for defining variables	*/

// Regex Macros
VARNAME		[A-Za-z_][A-Za-z0-9_]*
SPACE		[ \t]
WHITESPACE	[ \t\n]



%%


/* ============================ RULES ===================================== */
%{
		// Code run each time yylex is called.
		loc.step ();
%}

// WHITESPACE
{SPACE}		loc.step ();
{[\n]+		loc.lines (yyleng); loc.step ();

/* //////////////////////////////////////////////////////////////////// */
/* ========================== ERROR CHECKING ========================== */	
/* //////////////////////////////////////////////////////////////////// */
/* ============================ VARIABLES ============================= */	
<DEF_MODEL>{VARNAME}			{
	yylval.variableVal = atoi(yytext);
	#ifdef DEBUG
	cout << "Creating new model : " << yytext << endl;
	#endif

	/* Create a new model and put it in the driver */


}
<DEF_MESH>{VARNAME}			{
	yylval.variableVal = atoi(yytext);
	#ifdef DEBUG
	cout << "Found mesh name : " << yytext << endl;
	#endif

		
}
<DEF_TRANS>{VARNAME}			{
	yylval.variableVal = atoi(yytext);
	#ifdef DEBUG
	cout << "Found trans name : " << yytext << endl;
	#endif

	/* Search for yytext in model's list of meshes */


}
/* /////////////////////////////////////////////////////////////////// */
/* ============================ FLOATS =============================== */	
(-)?[0-9]+(\.)[0-9]+		{
	yylval->floatVal = atof(yytext);
	#ifdef DEBUG
	cout << "Found float : " << yytext << endl;
	#endif

	return FLOAT;
}
/* //////////////////////////////////////////////////////////////////// */
/* ============================ INTEGERS ============================= */	
(-)?[0-9] 					{
	yylval->integerVal = atoi(yytext);
	#ifdef DEBUG
	cout << "Found integer : " << yytext << endl;
	#endif
	
	return INTEGER
}
/* /////////////////////////////////////////////////////////////////// */
/* ============================= DEFS ================================= */	
(model|anim|var|transform)	{

}
/* //////////////////////////////////////////////////////////////////// */
/* ============================ BRACKETS ============================== */	
\}							{
	#ifdef DEBUG
	cout << "Found closing bracket" << endl;
	#endif

	yy_pop_state();
	return CLOSEBRACKET;
}
/* //////////////////////////////////////////////////////////////////// */
/* ============================ COMMENTS ============================== */	
<*>#(.*)						{
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




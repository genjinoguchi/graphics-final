/* YABSL LEXER */ 


/* ======== DEFINITIONS =================== */

%{ /* -*- C++ -*- */

	#include <cerrno>
	#include <climits>
	#include <cstdlib>
	#include <string>

	#include "yabsl_driver.hh"
	#include "yabsl_parser.tab.hh"


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

/** C++ */
%option c++

/** Enables the use of start condition stacks */
%option stack


%{
	/** Code run each time a pattern is matched. */
	#define YY_USER_ACTION  loc.columns (yyleng);
%}


/** Start Conditions. Use %s for inclusive conditions and %x for exclusive ones. */
%s COMMENT			/* start condition for comments 	*/
// The type of block that the scanner is currently parsing through
%x MODEL_BLOCK		/* start condition for defining models	*/
%x MESH_BLOCK		/* start condition for defining meshes	*/
%x ANIM_BLOCK		/* start condition for defining anims	*/
%x TRANS_BLOCK		/* start condition for defining transformations	*/
%x VAR_BLOCK		/* start condition for defining variables	*/

// Regex Macros
ID			[A-Za-z_][A-Za-z0-9_]*
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
/* ============================= DEFS ================================= */	
(model)					{
	yylval.identVal = yytext;
	#ifdef DEBUG
	cout << "Found model identifier " << endl;
	#endif

	return MODEL_IDENT;
}
(mesh)					{
	yylval.identVal = yytext;
	#ifdef DEBUG
	cout << "Found mesh identifier " << endl;
	#endif

	return MESH_IDENT;
}
(trans)					{
	yylval.identVal = yytext;
	#ifdef DEBUG
	cout << "Found transformation identifier " << endl;
	#endif

	return TRANS_IDENT;
}
/* //////////////////////////////////////////////////////////////////// */
/* ============================ VARIABLES ============================= */	
<DEF_MODEL>{ID}			{
	yylval.variableVal = atoi(yytext);
	#ifdef DEBUG
	cout << " " << yytext << endl;
	#endif

	return VARIABLE;
}
<DEF_MESH>{ID}			{
	yylval.variableVal = atoi(yytext);
	#ifdef DEBUG
	cout << "Found mesh name : " << yytext << endl;
	#endif

	return VARIABLE;		
}
<DEF_TRANS>{ID}			{
	yylval.variableVal = atoi(yytext);
	#ifdef DEBUG
	cout << "Found trans name : " << yytext << endl;
	#endif

	/* Search for yytext in model's list of meshes */

	return VARIABLE;
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




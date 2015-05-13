%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"

/* ==================== DEFINITIONS ======================== */

// Using genuine C++ objects as semantic values.
// class yabsl_parser
%defines
%define parser_class_name
{
	yabsl_parser
}

// Enable assertions
%define api.token.constructor
%define api.value.type variant
%define parse.assert

// Class header;
%code requires
{
	#include <string>
	#include <sstream>
	#include <vector>
	#include <map>

	class yabsl_driver;
	
	using namespace std;
}

// The parsing context (no globals here)
%param 
{	
	yabsl_driver& driver
}

// Request location tracking
%locations
%initial-action
{
	// Initialize the initial location.
	@$.begin.filename = @$.end.filename = &driver.file;
};

// Enable parser tracing and error messages
%define parse.trace
%define parse.error verbose

// Code outputted into yabsl_parser.cc
%code
{
	#include "yabsl-driver.hh"
}

/* ========================= TOKENS ========================= */	
%define api.token.prefix {TOK_}
%token					END	0				"end of file"
%token					LBRACKET			"{"
%token					RBRACKET 			"}"
%token					MODEL_IDENT 		"new-model"
%token					MESH_IDENT 			"new-mesh"
%token					TRANS_IDENT 		"new-transform"
%token 	<std::string>	IDENTIFIER 			"id"
/* ///////////////////////////////////////////////////// */
/* ======================== TYPES======================= */
// Tokens expect genuine C++ types because
// we're using variant-based semantic values.

%type 	<std::string>								MODEL_BLOCK
%type 	<std::string>								TRANSFORM
%type 	<std::vector<std::vector<std::string> > >	TRANS_BLOCK
%type 	<std::vector<std::vector<std::string> > >	transform-directives 
%type 	<std::string> 								MESH
%type 	<std::vector<std::vector<std::string> > > 	MESH_BLOCK
%type 	<std::vector<std::vector<std::string> > >	mesh-directives
%type 	<std::vector<std::string> >					directive
%type 	<std::vector<std::string> >					args

%type 	<std::string> 								unit
/* ///////////////////////////////////////////////////// */

%printer { yyoutput << $$; } <*>;



%%



/* ============================ RULES ===================================== */

%start unit;

unit : "new-mesh"
		  {
		      $$ = "Model successfully parsed.";
		  }
		| %empty {}
		;


MODEL : "new-model" "id"
		{
			driver.print_debug ("Creating new model");
			driver.modelName = $2;
	  	}
	  ;

MODEL_BLOCK : "{" "id" "}"
			  {
			      driver.print_debug (std::string("Test identifier") + $2);
			  }
			;

/*

MESH : "new-mesh" "id" MESH_BLOCK
	   {
	       /* 
		    * Add the value of MESH_BLOCK
		    * to a new mesh object.
			* Then, add it to the "global" model.
			*
			//driver.model.addMesh($2);
			//driver.model.getTransform($3)->command($3);
	   }
	 ;

TRANSFORM : "new-transform" "id" TRANS_BLOCK
		    {
		 		/* 
				 * Add the value of TRANS_BLOCK
				 * to a new transform object.
				 * Create the new transform, and then push commands to it.
				 *
				//driver.model.addTransform($2);
				//driver.model.getTransform($2)->command($3);
			}
		  ;

MODEL_BLOCK : "{" model-directives "}"
			  {
				
			  }
			;

TRANS_BLOCK : "{" transform-directives "}"
			  {
			      $$ = $2;
				  /*
				  #ifdef DEBUG
				  int i,j;
				  for (i=0; i<$2.size(); i++) {
					  for (j=0; j<$2[i].size(); j++) {
					      std::cout << $2[i][j] << " ";
					  }
                      std::cout << std::endl;
				  }
				  #endif
				  *
			  }
			;

MESH_BLOCK : "{" mesh-directives "}"
			  {
			      $$ = $2;
				  /*
				  #ifdef DEBUG
				  int i,j;
				  for (i=0; i<$2.size(); i++) {
					  for (j=0; j<$2[i].size(); j++) {
					      std::cout << $2[i][j] << " ";
					  }
                      std::cout << std::endl;
				  }
				  #endif
				  *
			  }
			;

model-directives : MESH model-directives
				   {
				   
				   }
				 | TRANSFORM model-directives
				   {
				   
				   }
				 | %empty {}
				 ;

mesh-directives : mesh-directives directive
				  {
				      $1.push_back ($2);
					  $$ = $1;
				  }
				| %empty {}
				;

transform-directives : transform-directives directive
					   {
					       $1.push_back ($2);
						   $$ = $1;
					   }
					 | %empty {}
					 ;

directive : args "\n"
		    {
		    	 $$ = $1;
			}
          ;

args : args "id"
	   {
	       $1.push_back ($2);
		   $$ = $1;
	   }
	 | %empty {}
	 ;
*/

/* ========================= END SUBROUTINES ============================= */


%%


void
yy::yabsl_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}

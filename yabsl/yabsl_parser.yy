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
	#include "yabsl_driver.hh"
	/*
	#include "../gl_src/model.h"
	#include "../gl_src/mesh.h"
	*/
}


/* ========================= TOKENS ========================= */	
// User friendly names for tokens
%define api.token.prefix {TOK_}
%token
	END  0		"end of file"
	LBRACKET	"{"
	RBRACKET	"}"
	MODEL_IDENT	"new-model"
	MESH_IDENT	"new-mesh"
	TRANS_IDENT	"new-transform"
;
%token <string> IDENTIFIER "id"
%token <string> COMMAND "cmd"
%token <string> ARGS "args"
/* ///////////////////////////////////////////////////// */
/* ======================== TYPES======================= */
// Tokens expect genuine C++ types because
// we're using variant-based semantic values.

/* ///////////////////////////////////////////////////// */




// For printing values
//%printer { yyoutput << $$; } <*>;


/* ========================= END DEFINITIONS ============================== */


%%


/* ============================ RULES ===================================== */

program : 
		| MODEL BLOCK

MODEL : "new-model" "id"
		{
			driver.print_debug("Creating new model");
			driver.modelName = $2;
	  	}
	  ;

MESH : "new-mesh" "id" MESH_BLOCK
	   {
	       /* 
		    * Add the value of MESH_BLOCK
		    * to a new mesh object.
			* Then, add it to the "global" model.
			*/
	   }
	 ;

TRANSFORM : "new-transform" "id" TRANS_BLOCK
		    {
		 		/* 
				 * Add the value of TRANS_BLOCK
				 * to a new transform object.
				 * Then, add it to the "global" model.
				 */
			}

MODEL-BLOCK : "{" model-directives "}"
			  {
	 		    /* Add meshes and transforms to the model */
			  }
			;

TRANS-BLOCK : "{" transform-directives "}"
			  {
			
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

mesh-directives : directive mesh-directives
				  {
				      
				  }
				| %empty {}
				;

transform-directives : directive transform-directives
					   {
					       
					   }
					 | %empty {}
					 ;

directive : "cmd" string-list
		    {
		  
			}
          ;

string-list : "str" "args"
			  {
			      
			  }
			| %empty {}
			;



/* ========================= END SUBROUTINES ============================= */


%%



void
yy::yabsl_parser::error (const location_type& l,
  const std::string& m)
{
  driver.error (l, m);
}

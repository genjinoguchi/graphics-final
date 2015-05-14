%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.2"

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
	#include "../model.h"
}

/* ========================= TOKENS ========================= */	
%define api.token.prefix {TOK_}
%token					END	0				"end of file"
%token					LBRACKET			"{"
%token					RBRACKET 			"}"
%token					MODEL_IDENT 		"new-model"
%token					MESH_IDENT 			"new-mesh"
%token					TRANS_IDENT 		"new-transform"
%token 					NEW_LINE			"\n"
%token 	<std::string>	IDENTIFIER 			"id"
%token 					SEMICOLON			";"
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
%type 	<std::string>								unit
// No %destructor is needed to enable memory deallocation
// during error recovery; the memory, for strings for instance,
// will be reclaimed by the regular destructors.
/* ///////////////////////////////////////////////////// */
/* ======================= PRINTERS ==================== */
%printer 	{ yyoutput << $$; } 	MODEL_BLOCK TRANSFORM MESH unit
%printer 	{ yyoutput << $$; } 	IDENTIFIER
%printer 	{ 	
				/*
				std::string output;
				output = "COMMAND LIST: \n";
			    for (int i=0; i<$$.size(); i++) {
					std::cout << "aijwefoijawef" << $$.size() << std::endl;
					for (int j=0; j<$$[i].size(); j++) {
						output += $$[i][j] + std::string(" ");
					}
					output += std::string("\n");
				}
				yyoutput << output;
				*/
				yyoutput << "Good afternoon.";
			} TRANS_BLOCK MESH_BLOCK transform-directives mesh-directives directive args
/* ///////////////////////////////////////////////////// */





%%



/* ============================ RULES ===================================== */

%start unit;

unit : MODEL MODEL_BLOCK
		  {
		      $$ = "Model successfully parsed.";
		  }
		| %empty {}
		;

MODEL : "new-model" "id"
		{
			driver.modelName = $2;
			driver.print_debug (std::string("Creating new model: ") + driver.modelName);
			Model::models[$2];
	  	}
	  ;

MESH : "new-mesh" "id" MESH_BLOCK
	   {
	       /* 
		    * Add the value of MESH_BLOCK
		    * to a new mesh object.
			* Then, add it to the "global" model.
			*/
			Mesh *m = new Mesh();
			for (int i=0; i<$3.size(); i++) {
				m->doCommand($3[i]);
			}

			Model::models[driver.modelName].addChild($2, m);
	   }
	 ;

TRANSFORM : "new-transform" "id" TRANS_BLOCK
		    {
		 		/* 
				 * Add the value of TRANS_BLOCK
				 * to a new transform object.
				 * Create the new transform, and then push commands to it.
				 */
				Model.models[driver.modelName].addTransform ($2);

				// It would be better to use iterators, but
				// there would be way too many "std::"'s.
				for (int i=0; i<$3.size(); i++) {
					Model.models[driver.modelName].getTransform ($2)->
						addTransformElement ($3[i][0],$3[i][1],$3[i][2],$3[i][3]);
				}

				//driver.model.addTransform($2);
				//driver.model.getTransform($2)->command($3);
			}
		  ;

MODEL_BLOCK : "{" model-directives "}"
			  {
			      $$ = $2;
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
				  */
			  }
			;

MESH_BLOCK : "{" mesh-directives "}"
			  {
			      $$ = $2;
			  }
			;

model-directives : MESH model-directives
				   {
				       /* placeholder for recursion */
				   }
				 | TRANSFORM model-directives
				   {
				       /* placeholder for recursion */
				   }
				 | %empty
				   {

				   }
				 ;

mesh-directives : mesh-directives directive
				  {
				      $1.push_back ($2);
					  $$ = $1;
				  }
				| %empty
					 {
		   			     std::vector<std::vector<string> > tmp;
		   			     $$ = tmp;
		   			     std::vector<std::vector<string> > ().swap(tmp);
					 }
				;

transform-directives : transform-directives directive
					   {
					       $1.push_back ($2);
						   $$ = $1;
					   }
					 | %empty
					   {
		   			       std::vector<std::vector<string> > tmp;
		   				   $$ = tmp;
		   				   std::vector<std::vector<string> > ().swap(tmp);

					   }
					 ;



directive : args ";"
		    {
		    	 $$ = $1;
			}
          ;

args : args "id"
	   {
		   $1.push_back ($2);
		   $$ = $1;
	   }
	 | %empty 
	   {
	       std::vector<std::string> tmp;
		   $$ = tmp;
		   std::vector<std::string> ().swap(tmp);
	   }
	 ;


/* ========================= END SUBROUTINES ============================= */


%%


void
yy::yabsl_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}

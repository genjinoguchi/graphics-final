// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "yabsl-parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "yabsl-parser.hh"

// User implementation prologue.

#line 51 "yabsl-parser.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 53 "yabsl-parser.yy" // lalr1.cc:413

	#include "yabsl-driver.hh"
	//#include "model.h"

#line 58 "yabsl-parser.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 144 "yabsl-parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  
	yabsl_parser
::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  
	yabsl_parser
::
	yabsl_parser
 (yabsl_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  
	yabsl_parser
::~
	yabsl_parser
 ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  
	yabsl_parser
::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  
	yabsl_parser
::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  
	yabsl_parser
::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  
	yabsl_parser
::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  
	yabsl_parser
::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  
	yabsl_parser
::symbol_number_type
  
	yabsl_parser
::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  
	yabsl_parser
::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  
	yabsl_parser
::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 27: // ANIM_BLOCK
      case 31: // anim-directives
        value.move< Anim* > (that.value);
        break;

      case 35: // ANIM_DURATION
        value.move< double > (that.value);
        break;

      case 32: // ANIM_VARY
        value.move< std::pair<string, std::vector<std::pair<int, int> > >  > (that.value);
        break;

      case 15: // "id"
      case 18: // unit
      case 20: // VAR
      case 21: // MESH
      case 22: // TRANSFORM
      case 23: // ANIM
      case 24: // MODEL_BLOCK
      case 36: // ANIM_NEXT
      case 37: // ANIM_ANIMATE
        value.move< std::string > (that.value);
        break;

      case 33: // DOUBLE_BLOCK
      case 34: // DOUBLES
        value.move< std::vector<std::pair<int, int> >  > (that.value);
        break;

      case 38: // directive
      case 39: // args
        value.move< std::vector<std::string>  > (that.value);
        break;

      case 25: // TRANS_BLOCK
      case 26: // MESH_BLOCK
      case 29: // mesh-directives
      case 30: // transform-directives
        value.move< std::vector<std::vector<std::string> >  > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  
	yabsl_parser
::stack_symbol_type&
  
	yabsl_parser
::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 27: // ANIM_BLOCK
      case 31: // anim-directives
        value.copy< Anim* > (that.value);
        break;

      case 35: // ANIM_DURATION
        value.copy< double > (that.value);
        break;

      case 32: // ANIM_VARY
        value.copy< std::pair<string, std::vector<std::pair<int, int> > >  > (that.value);
        break;

      case 15: // "id"
      case 18: // unit
      case 20: // VAR
      case 21: // MESH
      case 22: // TRANSFORM
      case 23: // ANIM
      case 24: // MODEL_BLOCK
      case 36: // ANIM_NEXT
      case 37: // ANIM_ANIMATE
        value.copy< std::string > (that.value);
        break;

      case 33: // DOUBLE_BLOCK
      case 34: // DOUBLES
        value.copy< std::vector<std::pair<int, int> >  > (that.value);
        break;

      case 38: // directive
      case 39: // args
        value.copy< std::vector<std::string>  > (that.value);
        break;

      case 25: // TRANS_BLOCK
      case 26: // MESH_BLOCK
      case 29: // mesh-directives
      case 30: // transform-directives
        value.copy< std::vector<std::vector<std::string> >  > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  
	yabsl_parser
::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  
	yabsl_parser
::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 15: // "id"

#line 105 "yabsl-parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 431 "yabsl-parser.cc" // lalr1.cc:636
        break;

      case 18: // unit

#line 104 "yabsl-parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 438 "yabsl-parser.cc" // lalr1.cc:636
        break;

      case 21: // MESH

#line 104 "yabsl-parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 445 "yabsl-parser.cc" // lalr1.cc:636
        break;

      case 22: // TRANSFORM

#line 104 "yabsl-parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 452 "yabsl-parser.cc" // lalr1.cc:636
        break;

      case 24: // MODEL_BLOCK

#line 104 "yabsl-parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 459 "yabsl-parser.cc" // lalr1.cc:636
        break;

      case 25: // TRANS_BLOCK

#line 106 "yabsl-parser.yy" // lalr1.cc:636
        { 	
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
			}
#line 480 "yabsl-parser.cc" // lalr1.cc:636
        break;

      case 26: // MESH_BLOCK

#line 106 "yabsl-parser.yy" // lalr1.cc:636
        { 	
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
			}
#line 501 "yabsl-parser.cc" // lalr1.cc:636
        break;

      case 29: // mesh-directives

#line 106 "yabsl-parser.yy" // lalr1.cc:636
        { 	
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
			}
#line 522 "yabsl-parser.cc" // lalr1.cc:636
        break;

      case 30: // transform-directives

#line 106 "yabsl-parser.yy" // lalr1.cc:636
        { 	
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
			}
#line 543 "yabsl-parser.cc" // lalr1.cc:636
        break;

      case 38: // directive

#line 106 "yabsl-parser.yy" // lalr1.cc:636
        { 	
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
			}
#line 564 "yabsl-parser.cc" // lalr1.cc:636
        break;

      case 39: // args

#line 106 "yabsl-parser.yy" // lalr1.cc:636
        { 	
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
			}
#line 585 "yabsl-parser.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  
	yabsl_parser
::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  
	yabsl_parser
::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  
	yabsl_parser
::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  
	yabsl_parser
::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  
	yabsl_parser
::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  
	yabsl_parser
::debug_level_type
  
	yabsl_parser
::debug_level () const
  {
    return yydebug_;
  }

  void
  
	yabsl_parser
::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline 
	yabsl_parser
::state_type
  
	yabsl_parser
::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  
	yabsl_parser
::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  
	yabsl_parser
::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  
	yabsl_parser
::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 42 "yabsl-parser.yy" // lalr1.cc:745
{
	// Initialize the initial location.
	yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 730 "yabsl-parser.cc" // lalr1.cc:745

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 27: // ANIM_BLOCK
      case 31: // anim-directives
        yylhs.value.build< Anim* > ();
        break;

      case 35: // ANIM_DURATION
        yylhs.value.build< double > ();
        break;

      case 32: // ANIM_VARY
        yylhs.value.build< std::pair<string, std::vector<std::pair<int, int> > >  > ();
        break;

      case 15: // "id"
      case 18: // unit
      case 20: // VAR
      case 21: // MESH
      case 22: // TRANSFORM
      case 23: // ANIM
      case 24: // MODEL_BLOCK
      case 36: // ANIM_NEXT
      case 37: // ANIM_ANIMATE
        yylhs.value.build< std::string > ();
        break;

      case 33: // DOUBLE_BLOCK
      case 34: // DOUBLES
        yylhs.value.build< std::vector<std::pair<int, int> >  > ();
        break;

      case 38: // directive
      case 39: // args
        yylhs.value.build< std::vector<std::string>  > ();
        break;

      case 25: // TRANS_BLOCK
      case 26: // MESH_BLOCK
      case 29: // mesh-directives
      case 30: // transform-directives
        yylhs.value.build< std::vector<std::vector<std::string> >  > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 136 "yabsl-parser.yy" // lalr1.cc:859
    {
		      yylhs.value.as< std::string > () = "Model successfully parsed.";
		  }
#line 884 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 139 "yabsl-parser.yy" // lalr1.cc:859
    {}
#line 890 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 143 "yabsl-parser.yy" // lalr1.cc:859
    {
			driver.modelName = yystack_[0].value.as< std::string > ();
			driver.print_debug (std::string ("Creating new model: ") + driver.modelName);

//			Model::models[$2];
	  	}
#line 901 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 152 "yabsl-parser.yy" // lalr1.cc:859
    {
	      driver.print_debug (std::string ("Found new var: ") + yystack_[1].value.as< std::string > ());
//	      Model::models[driver.modelName].addVar($2);

		  yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > ();
	  }
#line 912 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 161 "yabsl-parser.yy" // lalr1.cc:859
    {
	       /* 
		    * Add the value of MESH_BLOCK
		    * to a new mesh object.
			* Then, add it to the "global" model.
			*/
			driver.print_debug (std::string ("Creating new mesh: ") + yystack_[1].value.as< std::string > ());
			
//			Mesh *m = new Mesh();
			for (int i=0; i<yystack_[0].value.as< std::vector<std::vector<std::string> >  > ().size(); i++) {
//				m->doCommand($3[i]);
			}

//			Model::models[driver.modelName].addChild($2, m);
	   }
#line 932 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 179 "yabsl-parser.yy" // lalr1.cc:859
    {
			    driver.print_debug (std::string ("Creating new transform: ") + yystack_[1].value.as< std::string > ());
//				Model::models[driver.modelName].addTransform ($2);
		 		/* 
				 * Add the value of TRANS_BLOCK
				 * to a new transform object.
				 * Create the new transform, and then push commands to it.
				 */

				// It would be better to use iterators, but
				// there would be way too many "std::"'s.
				for (int i=0; i<yystack_[0].value.as< std::vector<std::vector<std::string> >  > ().size (); i++) {
//					Model::models[driver.modelName].getTransform ($2)->
//						addTransformElement ($3[i][0],$3[i][1],$3[i][2],$3[i][3]);
				}

				//driver.model.addTransform($2);
				//driver.model.getTransform($2)->command($3);
			}
#line 956 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 201 "yabsl-parser.yy" // lalr1.cc:859
    {
	       driver.print_debug (std::string("Creating new anim: ") + yystack_[1].value.as< std::string > ());
		   Model::models[driver.modelName].anims[yystack_[1].value.as< std::string > ()];
	       Model::models[driver.modelName].anims[yystack_[1].value.as< std::string > ()] = yystack_[0].value.as< Anim* > ();
	   }
#line 966 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 209 "yabsl-parser.yy" // lalr1.cc:859
    {
			      
			  }
#line 974 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 215 "yabsl-parser.yy" // lalr1.cc:859
    {
			      yylhs.value.as< std::vector<std::vector<std::string> >  > () = yystack_[1].value.as< std::vector<std::vector<std::string> >  > ();
			  }
#line 982 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 221 "yabsl-parser.yy" // lalr1.cc:859
    {
			      yylhs.value.as< std::vector<std::vector<std::string> >  > () = yystack_[1].value.as< std::vector<std::vector<std::string> >  > ();
			  }
#line 990 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 227 "yabsl-parser.yy" // lalr1.cc:859
    {
		         yylhs.value.as< Anim* > () = yystack_[1].value.as< Anim* > ();
			 }
#line 998 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 232 "yabsl-parser.yy" // lalr1.cc:859
    {}
#line 1004 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 233 "yabsl-parser.yy" // lalr1.cc:859
    {}
#line 1010 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 234 "yabsl-parser.yy" // lalr1.cc:859
    {}
#line 1016 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 235 "yabsl-parser.yy" // lalr1.cc:859
    {}
#line 1022 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 236 "yabsl-parser.yy" // lalr1.cc:859
    {}
#line 1028 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 240 "yabsl-parser.yy" // lalr1.cc:859
    {
				      yystack_[1].value.as< std::vector<std::vector<std::string> >  > ().push_back (yystack_[0].value.as< std::vector<std::string>  > ());
					  yylhs.value.as< std::vector<std::vector<std::string> >  > () = yystack_[1].value.as< std::vector<std::vector<std::string> >  > ();
				  }
#line 1037 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 245 "yabsl-parser.yy" // lalr1.cc:859
    {
		   			     std::vector<std::vector<string> > tmp;
		   			     yylhs.value.as< std::vector<std::vector<std::string> >  > () = tmp;
		   			     std::vector<std::vector<string> > ().swap(tmp);
					 }
#line 1047 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 253 "yabsl-parser.yy" // lalr1.cc:859
    {
					       yystack_[1].value.as< std::vector<std::vector<std::string> >  > ().push_back (yystack_[0].value.as< std::vector<std::string>  > ());
						   yylhs.value.as< std::vector<std::vector<std::string> >  > () = yystack_[1].value.as< std::vector<std::vector<std::string> >  > ();
					   }
#line 1056 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 258 "yabsl-parser.yy" // lalr1.cc:859
    {
		   			       std::vector<std::vector<string> > tmp;
		   				   yylhs.value.as< std::vector<std::vector<std::string> >  > () = tmp;
		   				   std::vector<std::vector<string> > ().swap(tmp);

					   }
#line 1067 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 270 "yabsl-parser.yy" // lalr1.cc:859
    {
				      AnimFunc* tempFunc = new AnimFunc();
					  for (int i=0; i<yystack_[1].value.as< std::pair<string, std::vector<std::pair<int, int> > >  > ().second.size (); i++) {
					      tempFunc->addOrderedPair((yystack_[1].value.as< std::pair<string, std::vector<std::pair<int, int> > >  > ().second)[i].first, (yystack_[1].value.as< std::pair<string, std::vector<std::pair<int, int> > >  > ().second)[i].second);
					  }
					  yystack_[0].value.as< Anim* > ().addFunc(yystack_[1].value.as< std::pair<string, std::vector<std::pair<int, int> > >  > ().first, tempFunc);
				  }
#line 1079 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 278 "yabsl-parser.yy" // lalr1.cc:859
    {
				      yystack_[0].value.as< Anim* > ().duration = yystack_[1].value.as< double > ();
				  }
#line 1087 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 282 "yabsl-parser.yy" // lalr1.cc:859
    {
				      yystack_[0].value.as< Anim* > ().animate = yystack_[1].value.as< std::string > ();
				  }
#line 1095 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 286 "yabsl-parser.yy" // lalr1.cc:859
    {
				      yystack_[0].value.as< Anim* > ().next = yystack_[1].value.as< std::string > ();
				  }
#line 1103 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 290 "yabsl-parser.yy" // lalr1.cc:859
    {
				      yylhs.value.as< Anim* > () = new Anim();
				  }
#line 1111 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 295 "yabsl-parser.yy" // lalr1.cc:859
    {
				std::pair<string, std::vector<std::pair<int, int> > > tmp;
				
			}
#line 1120 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 301 "yabsl-parser.yy" // lalr1.cc:859
    {
			       yylhs.value.as< std::vector<std::pair<int, int> >  > () = yystack_[1].value.as< std::vector<std::pair<int, int> >  > ();
			   }
#line 1128 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 305 "yabsl-parser.yy" // lalr1.cc:859
    {
		      yylhs.value.as< std::vector<std::pair<int, int> >  > ().push_back(std::make_pair(std::stod(yystack_[3].value.as< std::vector<std::pair<int, int> >  > ()), std::stod(yystack_[2].value.as< std::string > ())));
		  }
#line 1136 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 309 "yabsl-parser.yy" // lalr1.cc:859
    {
			  std::vector<std::pair<int, int> > tmp;
		      yylhs.value.as< std::vector<std::pair<int, int> >  > () = tmp;
			  std::vector<std::pair<int, int> > ().swap(tmp);
		  }
#line 1146 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 316 "yabsl-parser.yy" // lalr1.cc:859
    {
					yylhs.value.as< double > () = std::stod(yystack_[1].value.as< std::string > ());
				}
#line 1154 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 321 "yabsl-parser.yy" // lalr1.cc:859
    {
				yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > ();
			}
#line 1162 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 326 "yabsl-parser.yy" // lalr1.cc:859
    {
			       yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > (); 
			   }
#line 1170 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 336 "yabsl-parser.yy" // lalr1.cc:859
    {
		    	 yylhs.value.as< std::vector<std::string>  > () = yystack_[1].value.as< std::vector<std::string>  > ();
			}
#line 1178 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 342 "yabsl-parser.yy" // lalr1.cc:859
    {
		   yystack_[1].value.as< std::vector<std::string>  > ().push_back (yystack_[0].value.as< std::string > ());
		   yylhs.value.as< std::vector<std::string>  > () = yystack_[1].value.as< std::vector<std::string>  > ();
	   }
#line 1187 "yabsl-parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 347 "yabsl-parser.yy" // lalr1.cc:859
    {
	       std::vector<std::string> tmp;
		   yylhs.value.as< std::vector<std::string>  > () = tmp;
		   std::vector<std::string> ().swap(tmp);
	   }
#line 1197 "yabsl-parser.cc" // lalr1.cc:859
    break;


#line 1201 "yabsl-parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  
	yabsl_parser
::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  
	yabsl_parser
::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char 
	yabsl_parser
::yypact_ninf_ = -25;

  const signed char 
	yabsl_parser
::yytable_ninf_ = -1;

  const signed char
  
	yabsl_parser
::yypact_[] =
  {
      15,     6,    22,    20,   -25,   -25,    -5,   -25,     9,    10,
      11,    12,    -5,    -5,    -5,    -5,    24,    26,    27,    16,
      28,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,    -3,   -25,    29,    30,    21,    23,    25,    31,    33,
      -3,    -3,    -3,    -3,   -25,   -25,   -10,   -25,   -25,    32,
      34,    35,    36,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,    -4,   -25,    38,    39,   -25
  };

  const unsigned char
  
	yabsl_parser
::yydefact_[] =
  {
       3,     0,     0,     0,     4,     1,    17,     2,     0,     0,
       0,     0,    17,    17,    17,    17,     0,     0,     0,     0,
       0,    15,    13,    14,    16,     9,    19,     6,    21,     7,
       5,    26,     8,    36,    36,     0,     0,     0,     0,     0,
      26,    26,    26,    26,    11,    18,     0,    10,    20,     0,
       0,     0,     0,    12,    22,    23,    25,    24,    35,    34,
      30,    27,    31,    32,    33,     0,    28,     0,     0,    29
  };

  const signed char
  
	yabsl_parser
::yypgoto_[] =
  {
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,     0,   -25,   -25,   -24,   -25,   -25,   -25,   -25,   -25,
     -25,     5,   -25
  };

  const signed char
  
	yabsl_parser
::yydefgoto_[] =
  {
      -1,     2,     3,    12,    13,    14,    15,     7,    29,    27,
      32,    16,    33,    34,    39,    40,    61,    65,    41,    42,
      43,    45,    46
  };

  const unsigned char
  
	yabsl_parser
::yytable_[] =
  {
      66,     8,     9,    10,    11,    58,    59,    35,    36,    37,
      38,    67,    21,    22,    23,    24,    54,    55,    56,    57,
       1,     4,     5,     6,    17,    18,    19,    20,    25,    26,
      28,    31,    30,    44,    47,    60,    49,    53,    50,    48,
      51,     0,     0,     0,     0,     0,    52,     0,     0,     0,
      62,    63,    64,    68,     0,    69
  };

  const signed char
  
	yabsl_parser
::yycheck_[] =
  {
       4,     6,     7,     8,     9,    15,    16,    10,    11,    12,
      13,    15,    12,    13,    14,    15,    40,    41,    42,    43,
       5,    15,     0,     3,    15,    15,    15,    15,     4,     3,
       3,     3,    16,     4,     4,     3,    15,     4,    15,    34,
      15,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      16,    16,    16,    15,    -1,    16
  };

  const unsigned char
  
	yabsl_parser
::yystos_[] =
  {
       0,     5,    18,    19,    15,     0,     3,    24,     6,     7,
       8,     9,    20,    21,    22,    23,    28,    15,    15,    15,
      15,    28,    28,    28,    28,     4,     3,    26,     3,    25,
      16,     3,    27,    29,    30,    10,    11,    12,    13,    31,
      32,    35,    36,    37,     4,    38,    39,     4,    38,    15,
      15,    15,    15,     4,    31,    31,    31,    31,    15,    16,
       3,    33,    16,    16,    16,    34,     4,    15,    15,    16
  };

  const unsigned char
  
	yabsl_parser
::yyr1_[] =
  {
       0,    17,    18,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    28,    28,    28,    28,    29,    29,
      30,    30,    31,    31,    31,    31,    31,    32,    33,    34,
      34,    35,    36,    37,    38,    39,    39
  };

  const unsigned char
  
	yabsl_parser
::yyr2_[] =
  {
       0,     2,     2,     0,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     0,     2,     0,
       2,     0,     2,     2,     2,     2,     0,     3,     3,     4,
       0,     3,     3,     3,     2,     2,     0
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const 
	yabsl_parser
::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"{\"", "\"}\"",
  "\"new-model\"", "\"new-mesh\"", "\"new-transform\"", "\"new-var\"",
  "\"new-anim\"", "\"anim-vary\"", "\"anim-duration\"", "\"anim-next\"",
  "\"anim-animate\"", "\"\\n\"", "\"id\"", "\";\"", "$accept", "unit",
  "MODEL", "VAR", "MESH", "TRANSFORM", "ANIM", "MODEL_BLOCK",
  "TRANS_BLOCK", "MESH_BLOCK", "ANIM_BLOCK", "model-directives",
  "mesh-directives", "transform-directives", "anim-directives",
  "ANIM_VARY", "DOUBLE_BLOCK", "DOUBLES", "ANIM_DURATION", "ANIM_NEXT",
  "ANIM_ANIMATE", "directive", "args", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  
	yabsl_parser
::yyrline_[] =
  {
       0,   135,   135,   139,   142,   151,   160,   178,   200,   208,
     214,   220,   226,   232,   233,   234,   235,   236,   239,   244,
     252,   257,   269,   277,   281,   285,   289,   294,   300,   304,
     308,   315,   320,   325,   335,   341,   346
  };

  // Print the state stack on the debug stream.
  void
  
	yabsl_parser
::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  
	yabsl_parser
::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1646 "yabsl-parser.cc" // lalr1.cc:1167
#line 358 "yabsl-parser.yy" // lalr1.cc:1168



void
yy::yabsl_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}

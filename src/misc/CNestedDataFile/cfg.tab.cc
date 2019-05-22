/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse cfg_parse
#define yylex   cfg_lex
#define yyerror cfg_error
#define yylval  cfg_lval
#define yychar  cfg_char
#define yydebug cfg_debug
#define yynerrs cfg_nerrs
#define yylloc cfg_lloc

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     LIT_NUMBER = 259,
     LIT_STRING = 260,
     TRUE = 261,
     FALSE = 262,
     INCLUDE = 263,
     NE = 264,
     EQ = 265,
     GE = 266,
     LE = 267,
     OR = 268,
     AND = 269
   };
#endif
#define IDENT 258
#define LIT_NUMBER 259
#define LIT_STRING 260
#define TRUE 261
#define FALSE 262
#define INCLUDE 263
#define NE 264
#define EQ 265
#define GE 266
#define LE 267
#define OR 268
#define AND 269




/* Copy the first part of user declarations.  */
#line 1 "../../../src/misc/CNestedDataFile/cfg.y"


/* 
 * Copyright (C) 2002 - David W. Durham
 * 
 * This file is not part of any particular application.
 * 
 * CNestedDataFile is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 * 
 * CNestedDataFile is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
 */

#include <math.h>

#include <stack>
#include <stdexcept>

#include "CNestedDataFile.h"

#include <istring>

struct RTokenPosition
{
	int first_line,last_line;
	int first_column,last_column;
	const char *text;
};
#define YYLTYPE RTokenPosition
#define YYLSP_NEEDED 1

stack<string> scopeStack;

void cfg_error(int line,const char *msg);
void cfg_error(const YYLTYPE &pos,const char *msg);
void cfg_error(const char *msg);

int cfg_lex();

void cfg_init();
void cfg_deinit();

void cfg_includeFile(const char *filename);

void checkForDupMember(int line,const char *key);

static const string getCurrentScope();

int myyynerrs=0;

#define VERIFY_TYPE(ap,a) 				\
	if(a->type!=CNestedDataFile::ktFloat)			\
		cfg_error(ap,"invalid operand; numeric type expected"); 	

#define BINARY_EXPR(r,ap,a,bp,b,o)	\
	VERIFY_TYPE(ap,a)		\
	VERIFY_TYPE(bp,b)		\
	r=a;				\
	r->floatValue = r->floatValue o b->floatValue;	 \
	delete b;


union cfg_parse_union
{
	char *				stringValue;
	double				floatValue;
	int 				intValue;
	CNestedDataFile::CVariant *	variant;
	vector<CNestedDataFile::CVariant> *variantList;
};
#define YYSTYPE union cfg_parse_union



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 218 "cfg.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   104

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  21
/* YYNRULES -- Number of rules. */
#define YYNRULES  55
/* YYNRULES -- Number of states. */
#define YYNSTATES  88

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   269

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    28,     2,     2,
      22,    23,    26,    24,    21,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    17,
      29,    18,    30,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,     2,    20,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    15,    33,    16,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    14,    15,    18,    21,
      23,    25,    30,    38,    41,    43,    44,    46,    48,    52,
      54,    58,    60,    62,    64,    66,    68,    72,    76,    78,
      81,    83,    85,    87,    91,    95,    99,   101,   105,   109,
     111,   115,   119,   123,   127,   129,   133,   137,   139,   143,
     145,   149,   151,   157,   159,   161
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      35,     0,    -1,    -1,    36,    39,    -1,    -1,     3,    15,
      38,    39,    16,    -1,    -1,    39,    40,    -1,     1,    17,
      -1,     1,    -1,    37,    -1,     3,    18,    53,    17,    -1,
       3,    19,    20,    18,    15,    41,    16,    -1,     8,     5,
      -1,    17,    -1,    -1,    42,    -1,    53,    -1,    41,    21,
      53,    -1,     1,    -1,    41,    21,     1,    -1,     4,    -1,
       5,    -1,     6,    -1,     7,    -1,    54,    -1,    22,    53,
      23,    -1,    22,     1,    23,    -1,    43,    -1,    45,    44,
      -1,    24,    -1,    25,    -1,    44,    -1,    46,    26,    44,
      -1,    46,    27,    44,    -1,    46,    28,    44,    -1,    46,
      -1,    47,    24,    46,    -1,    47,    25,    46,    -1,    47,
      -1,    48,    12,    47,    -1,    48,    11,    47,    -1,    48,
      29,    47,    -1,    48,    30,    47,    -1,    48,    -1,    49,
      10,    48,    -1,    49,     9,    48,    -1,    49,    -1,    50,
      14,    49,    -1,    50,    -1,    51,    13,    50,    -1,    51,
      -1,    51,    31,    53,    32,    52,    -1,    52,    -1,     3,
      -1,    54,    33,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   128,   128,   128,   139,   138,   153,   155,   158,   162,
     169,   171,   184,   192,   197,   202,   205,   212,   226,   241,
     245,   256,   260,   265,   269,   275,   305,   312,   321,   323,
     338,   339,   343,   344,   345,   346,   351,   352,   373,   378,
     379,   380,   381,   382,   386,   387,   388,   392,   393,   397,
     398,   403,   404,   409,   415,   419
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "LIT_NUMBER", "LIT_STRING", 
  "TRUE", "FALSE", "INCLUDE", "NE", "EQ", "GE", "LE", "OR", "AND", "'{'", 
  "'}'", "';'", "'='", "'['", "']'", "','", "'('", "')'", "'+'", "'-'", 
  "'*'", "'/'", "'%'", "'<'", "'>'", "'?'", "':'", "'|'", "$accept", 
  "start", "@1", "scope", "@2", "scope_body", "scope_body_item", 
  "array_body", "array_body2", "primary_expr", "unary_expr", "unary_op", 
  "multiplicative_expr", "additive_expr", "relational_expr", 
  "equality_expr", "logical_and_expr", "logical_or_expr", 
  "conditional_expr", "expr", "qualified_ident", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   123,   125,    59,    61,    91,
      93,    44,    40,    41,    43,    45,    42,    47,    37,    60,
      62,    63,    58,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    34,    36,    35,    38,    37,    39,    39,    39,    39,
      40,    40,    40,    40,    40,    41,    41,    42,    42,    42,
      42,    43,    43,    43,    43,    43,    43,    43,    44,    44,
      45,    45,    46,    46,    46,    46,    47,    47,    47,    48,
      48,    48,    48,    48,    49,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    54,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     0,     5,     0,     2,     2,     1,
       1,     4,     7,     2,     1,     0,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     1,     2,
       1,     1,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     5,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     0,     1,     9,     3,     8,     0,     0,    14,
      10,     7,     4,     0,     0,    13,     0,    54,    21,    22,
      23,    24,     0,    30,    31,    28,    32,     0,    36,    39,
      44,    47,    49,    51,    53,     0,    25,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     5,
      27,    26,    33,    34,    35,    37,    38,    41,    40,    42,
      43,    46,    45,    48,    50,     0,    55,     0,     0,    19,
       0,    16,    17,    52,    12,     0,    20,    18
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     1,     2,    10,    16,     5,    11,    80,    81,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -23
static const yysigned_char yypact[] =
{
     -23,    15,    68,   -23,    -8,    74,   -23,    42,    12,   -23,
     -23,   -23,   -23,    40,    -1,   -23,    71,   -23,   -23,   -23,
     -23,   -23,     7,   -23,   -23,   -23,   -23,    40,    70,     3,
      37,    80,    16,   -11,   -23,    17,    -7,    24,    67,    27,
      31,   -23,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,   -23,    75,    58,   -23,
     -23,   -23,   -23,   -23,   -23,    70,    70,     3,     3,     3,
       3,    37,    37,    80,    16,    54,   -23,     0,    40,   -23,
       2,   -23,   -23,   -23,   -23,    34,   -23,   -23
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -23,   -23,   -23,   -23,   -23,    85,   -23,   -23,   -23,   -23,
       9,   -23,    35,    45,    48,    49,    50,   -23,    25,   -22,
     -23
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -16
static const yysigned_char yytable[] =
{
      40,    79,    54,    17,    18,    19,    20,    21,    39,     6,
      17,    18,    19,    20,    21,     3,   -15,    15,    84,    37,
      55,   -15,    22,    85,    23,    24,    57,    45,    46,    22,
      53,    23,    24,    75,    56,    86,    41,    17,    18,    19,
      20,    21,    58,    17,    18,    19,    20,    21,    47,    48,
      60,    62,    63,    64,    61,    82,    22,    12,    23,    24,
      13,    14,    22,    87,    23,    24,    49,    50,    -6,     4,
       7,    -6,     4,    77,    -6,     8,    -6,     7,    76,    -6,
      65,    66,     8,    59,     9,    -6,    78,    -6,    -6,    51,
      52,     9,    67,    68,    69,    70,    42,    43,    44,    71,
      72,    38,    73,    83,    74
};

static const unsigned char yycheck[] =
{
      22,     1,    13,     3,     4,     5,     6,     7,     1,    17,
       3,     4,     5,     6,     7,     0,    16,     5,    16,    20,
      31,    21,    22,    21,    24,    25,    33,    24,    25,    22,
      14,    24,    25,    55,    17,     1,    27,     3,     4,     5,
       6,     7,    18,     3,     4,     5,     6,     7,    11,    12,
      23,    42,    43,    44,    23,    77,    22,    15,    24,    25,
      18,    19,    22,    85,    24,    25,    29,    30,     0,     1,
       3,     3,     1,    15,     3,     8,     8,     3,     3,     8,
      45,    46,     8,    16,    17,    17,    32,    16,    17,     9,
      10,    17,    47,    48,    49,    50,    26,    27,    28,    51,
      52,    16,    53,    78,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    35,    36,     0,     1,    39,    17,     3,     8,    17,
      37,    40,    15,    18,    19,     5,    38,     3,     4,     5,
       6,     7,    22,    24,    25,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    20,    39,     1,
      53,    44,    26,    27,    28,    24,    25,    11,    12,    29,
      30,     9,    10,    14,    13,    31,    17,    33,    18,    16,
      23,    23,    44,    44,    44,    46,    46,    47,    47,    47,
      47,    48,    48,    49,    50,    53,     3,    15,    32,     1,
      41,    42,    53,    52,    16,    21,     1,    53
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		do				\
			  {				\
			    yylerrsp = yylsp;		\
			    *++yylerrsp = yyloc;	\
			    goto yyerrlab1;		\
			  }				\
			while (0)


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value, Location);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yytype, yyvaluep, yylocationp)
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  YYLTYPE *yylerrsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
  *++yylsp = yylloc;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 128 "../../../src/misc/CNestedDataFile/cfg.y"
    { cfg_init(); }
    break;

  case 3:
#line 129 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		cfg_deinit();

		return(myyynerrs!=0);
	}
    break;

  case 4:
#line 139 "../../../src/misc/CNestedDataFile/cfg.y"
    { /* mid-rule action */

		checkForDupMember(yylsp[-1].first_line,yyvsp[-1].stringValue);

		scopeStack.push(yyvsp[-1].stringValue);

		free(yyvsp[-1].stringValue);

		/* now continue parsing for new scope's body */
	}
    break;

  case 5:
#line 148 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		scopeStack.pop();
	}
    break;

  case 8:
#line 159 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		cfg_error(yylsp[-1],"syntax error");
	}
    break;

  case 9:
#line 163 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		cfg_error(yylsp[0],"syntax error");
	}
    break;

  case 11:
#line 172 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		checkForDupMember(yylsp[-3].first_line,yyvsp[-3].stringValue);
		if(yyvsp[-1].variant->type==CNestedDataFile::ktFloat)
			CNestedDataFile::parseTree->createKey((getCurrentScope()+yyvsp[-3].stringValue).c_str(),yyvsp[-1].variant->floatValue);
		else if(yyvsp[-1].variant->type==CNestedDataFile::ktString)
			CNestedDataFile::parseTree->createKey((getCurrentScope()+yyvsp[-3].stringValue).c_str(),yyvsp[-1].variant->stringValue);
		else
			yyerror(yylsp[-2],"assigning an invalid typed value to an identifier");

		delete yyvsp[-1].variant;
		free(yyvsp[-3].stringValue);
	}
    break;

  case 12:
#line 185 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		checkForDupMember(yylsp[-6].first_line,yyvsp[-6].stringValue);
		CNestedDataFile::parseTree->createKey((getCurrentScope()+yyvsp[-6].stringValue).c_str(),*yyvsp[-1].variantList);

		delete yyvsp[-1].variantList;
		free(yyvsp[-6].stringValue);
	}
    break;

  case 13:
#line 193 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		cfg_includeFile(yyvsp[0].stringValue);
		free(yyvsp[0].stringValue);
	}
    break;

  case 15:
#line 202 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variantList=new vector<CNestedDataFile::CVariant>;
	}
    break;

  case 16:
#line 206 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variantList=yyvsp[0].variantList;
	}
    break;

  case 17:
#line 213 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variantList=new vector<CNestedDataFile::CVariant>;

		if(yyvsp[0].variant->type==CNestedDataFile::ktFloat)
			yyval.variantList->push_back(CNestedDataFile::CVariant("",yyvsp[0].variant->floatValue));
		else if(yyvsp[0].variant->type==CNestedDataFile::ktString)
			yyval.variantList->push_back(CNestedDataFile::CVariant("",yyvsp[0].variant->stringValue));
		else
			yyerror(yylsp[0],"invalid typed value in array initializer");

		delete yyvsp[0].variant;
	}
    break;

  case 18:
#line 227 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variantList=yyvsp[-2].variantList;

		if(yyvsp[0].variant->type==CNestedDataFile::ktFloat)
			yyval.variantList->push_back(CNestedDataFile::CVariant("",yyvsp[0].variant->floatValue));
		else if(yyvsp[0].variant->type==CNestedDataFile::ktString)
			yyval.variantList->push_back(CNestedDataFile::CVariant("",yyvsp[0].variant->stringValue));
		else
			yyerror(yylsp[0],"invalid typed value in array initializer");

		delete yyvsp[0].variant;
	}
    break;

  case 19:
#line 242 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variantList=new vector<CNestedDataFile::CVariant>;
	}
    break;

  case 20:
#line 246 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variantList=yyvsp[-2].variantList;
	}
    break;

  case 21:
#line 257 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=new CNestedDataFile::CVariant("",yyvsp[0].floatValue);
	}
    break;

  case 22:
#line 261 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=new CNestedDataFile::CVariant("",yyvsp[0].stringValue);
		free(yyvsp[0].stringValue);
	}
    break;

  case 23:
#line 266 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=new CNestedDataFile::CVariant("","true");
	}
    break;

  case 24:
#line 270 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=new CNestedDataFile::CVariant("","false");
	}
    break;

  case 25:
#line 276 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		CNestedDataFile::CVariant *value;
		if(!CNestedDataFile::parseTree->findVariantNode(value,yyvsp[0].stringValue,0,false,CNestedDataFile::parseTree->root))
		{
			cfg_error(yylsp[0],("symbol not found: '"+string(yyvsp[0].stringValue)+"'").c_str());
			value=new CNestedDataFile::CVariant("",0.0);
		}
			
		switch(value->type)
		{
		case CNestedDataFile::ktString:
			yyval.variant=new CNestedDataFile::CVariant("",value->stringValue);
			break;
		case CNestedDataFile::ktFloat:
			yyval.variant=new CNestedDataFile::CVariant("",value->floatValue);
			break;
		case CNestedDataFile::ktScope:
			cfg_error(yylsp[0],("symbol resolves to a scope: '"+string(yyvsp[0].stringValue)+"'").c_str());
			value=new CNestedDataFile::CVariant("",0.0);
			break;
		default:
			throw(runtime_error("cfg_parse -- unhandled variant type"));

		}

		free(yyvsp[0].stringValue);
	}
    break;

  case 26:
#line 306 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=yyvsp[-1].variant;
	}
    break;

  case 27:
#line 313 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyclearin;
		yyval.variant=new CNestedDataFile::CVariant("",0.0);
	}
    break;

  case 28:
#line 321 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 29:
#line 324 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		if(yyvsp[0].variant->type!=CNestedDataFile::ktFloat)
			cfg_error(yylsp[0],"invalid operand");
		yyval.variant=yyvsp[0].variant;
		if(yyvsp[-1].intValue=='+')
			yyval.variant->floatValue=+yyval.variant->floatValue;
		else if(yyvsp[-1].intValue=='-')
			yyval.variant->floatValue=-yyval.variant->floatValue;
		else
			throw(runtime_error("cfg_parse -- internal error parsing unary_expr"));
	}
    break;

  case 30:
#line 338 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.intValue='+'; }
    break;

  case 31:
#line 339 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.intValue='-'; }
    break;

  case 32:
#line 343 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 33:
#line 344 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,*) }
    break;

  case 34:
#line 345 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,/) }
    break;

  case 35:
#line 346 "../../../src/misc/CNestedDataFile/cfg.y"
    { VERIFY_TYPE(yylsp[-2],yyvsp[-2].variant) VERIFY_TYPE(yylsp[0],yyvsp[0].variant) yyval.variant=yyvsp[-2].variant; yyval.variant->floatValue=fmod(yyval.variant->floatValue,yyvsp[0].variant->floatValue); delete yyvsp[0].variant; }
    break;

  case 36:
#line 351 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 37:
#line 353 "../../../src/misc/CNestedDataFile/cfg.y"
    { 
		if(yyvsp[-2].variant->type==CNestedDataFile::ktFloat)
		{
			BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,+) 
		}
		else if(yyvsp[-2].variant->type==CNestedDataFile::ktString)
		{
			if(yyvsp[0].variant->type!=CNestedDataFile::ktString)
				yyerror(yylsp[0],"string type expected");
			yyval.variant=yyvsp[-2].variant;
			yyval.variant->stringValue+=yyvsp[0].variant->stringValue;
			delete yyvsp[0].variant;
		}
		else
		{
			yyerror(yylsp[-2],"invalid type");
			yyval.variant=yyvsp[-2].variant;
			delete yyvsp[0].variant;
		}
	}
    break;

  case 38:
#line 373 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,-) }
    break;

  case 39:
#line 378 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 40:
#line 379 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,<=) }
    break;

  case 41:
#line 380 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,>=) }
    break;

  case 42:
#line 381 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,<) }
    break;

  case 43:
#line 382 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,>) }
    break;

  case 44:
#line 386 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 45:
#line 387 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,==) }
    break;

  case 46:
#line 388 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,!=) }
    break;

  case 47:
#line 392 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 48:
#line 393 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,&&) }
    break;

  case 49:
#line 397 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 50:
#line 398 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,||) }
    break;

  case 51:
#line 403 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 52:
#line 404 "../../../src/misc/CNestedDataFile/cfg.y"
    { VERIFY_TYPE(yylsp[-4],yyvsp[-4].variant) yyval.variant=(yyvsp[-4].variant->floatValue ? ((delete yyvsp[0].variant),yyvsp[-2].variant) : ((delete yyvsp[-2].variant),yyvsp[0].variant)); delete yyvsp[-4].variant; }
    break;

  case 53:
#line 409 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 54:
#line 416 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.stringValue=yyvsp[0].stringValue;
	}
    break;

  case 55:
#line 420 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.stringValue=(char *)realloc(yyval.stringValue,strlen(yyval.stringValue)+1+strlen(yyvsp[0].stringValue)+1);
		strcat(yyval.stringValue,CNestedDataFile::delimChar);
		strcat(yyval.stringValue,yyvsp[0].stringValue);

		free(yyvsp[0].stringValue);
	}
    break;


    }

/* Line 999 of yacc.c.  */
#line 1588 "cfg.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;
  yylsp -= yylen;

  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }

  yylerrsp = yylsp;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp, yylsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval, &yylloc);
      yychar = YYEMPTY;
      *++yylerrsp = yylloc;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp, yylsp);
      yyvsp--;
      yystate = *--yyssp;
      yylsp--;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
  YYLLOC_DEFAULT (yyloc, yylsp, (yylerrsp - yylsp));
  *++yylsp = yyloc;

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 431 "../../../src/misc/CNestedDataFile/cfg.y"


#include "cfg.lex.c"

void cfg_error(int line,const char *msg)
{
	fprintf(stderr,"%s:%d: %s\n",currentFilename.c_str(),line,msg);
	
	myyynerrs++;
	if(myyynerrs>25)
		throw(runtime_error("cfg_error -- more than 25 errors; bailing"));
}

void cfg_error(const RTokenPosition &pos,const char *msg)
{
	int line=pos.first_line;
	
	cfg_error(line,msg);
}

void cfg_error(const char *msg)
{
	cfg_error(yylloc.first_line,msg);
}

void checkForDupMember(int line,const char *key)
{
	if(CNestedDataFile::parseTree->keyExists((getCurrentScope()+key).c_str()))
		cfg_error(line,("duplicate scope name: "+(getCurrentScope()+string(key))).c_str());
}

static const string getCurrentScope()
{
	stack<string> copy=scopeStack;
	string s;
	while(!copy.empty())
	{
		s=copy.top()+s;
		s=CNestedDataFile::delimChar+s;

		copy.pop();
	}

	s+=CNestedDataFile::delimChar;

	s.erase(0,1);

	return(s);
}




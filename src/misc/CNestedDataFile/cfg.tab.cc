/* A Bison parser, made from ../../../src/misc/CNestedDataFile/cfg.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

#define yyparse cfg_parse
#define yylex cfg_lex
#define yyerror cfg_error
#define yylval cfg_lval
#define yychar cfg_char
#define yydebug cfg_debug
#define yynerrs cfg_nerrs
#define YYLSP_NEEDED 1

# define	IDENT	257
# define	LIT_NUMBER	258
# define	LIT_STRING	259
# define	TRUE	260
# define	FALSE	261
# define	INCLUDE	262
# define	GETTEXT	263
# define	NE	264
# define	EQ	265
# define	GE	266
# define	LE	267
# define	OR	268
# define	AND	269

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

/*
 * As well as parsing CNestedDataFile data files, this is also used on the
 * side by string_to_anytype<vector> to parse a string and create a vector
 * of values from it.
 *
 * s2at means string_to_anytype used below.  Anything with this in front can be
 * ignored when maintaining this code for its primary use (parsing data files)
 *
 * Just adding this to be able to reuse this yacc file for string_to_anytype<vector>()
 * Since the generated yacc parser uses global variables, it's would cause a problem
 * if the string_to_anytype<vector>() function were called while it was parsing an actual
 * datafile... But, currently I see no reason for that to happen (unless I one day
 * implement array subscripting in the arithmetic expression stuff.)
 */
#include "../../../config/common.h"

#include <math.h>
#include <string.h>

#include <stack>
#include <stdexcept>

#include "CNestedDataFile.h"
#include "anytype.h"

struct RTokenPosition
{
	int first_line,last_line;
	int first_column,last_column;
	const char *text;
};
#define YYLTYPE RTokenPosition
#define YYLSP_NEEDED 1
#define YYERROR_VERBOSE

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

#define VERIFY_TYPE(ap,a)				\
	if(a->type!=CNestedDataFile::ktValue)		\
		cfg_error(ap,"invalid operand; value type expected");

#define BINARY_EXPR(r,ap,a,bp,b,o)	\
	VERIFY_TYPE(ap,a)		\
	VERIFY_TYPE(bp,b)		\
	r=a;				\
	double x1,x2;			\
	r->stringValue = strdup( anytype_to_string<double>(string_to_anytype<double>(r->stringValue,x1) o string_to_anytype<double>(b->stringValue,x2)).c_str() );	\
	delete b;


union cfg_parse_union
{
	char *				stringValue;
	CNestedDataFile::CVariant *	variant;
};
#define YYSTYPE union cfg_parse_union


#ifndef YYLTYPE
typedef struct yyltype
{
  int first_line;
  int first_column;

  int last_line;
  int last_column;
} yyltype;

# define YYLTYPE yyltype
# define YYLTYPE_IS_TRIVIAL 1
#endif

#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		105
#define	YYFLAG		-32768
#define	YYNTBASE	36

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 269 ? yytranslate[x] : 59)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    30,     2,     2,
      24,    25,    28,    26,    23,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    19,
      31,    22,    32,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,    35,    18,    16,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     1,     4,     8,     9,    15,    16,    19,    22,
      24,    25,    28,    30,    36,    39,    41,    44,    48,    50,
      54,    56,    60,    62,    64,    69,    71,    73,    75,    77,
      81,    85,    87,    90,    93,    95,    99,   103,   107,   109,
     113,   117,   119,   123,   127,   131,   135,   137,   141,   145,
     147,   151,   153,   157,   159,   165,   167,   169,   173,   176,
     180,   182,   184,   188,   190
};
static const short yyrhs[] =
{
      -1,    36,    40,     0,    36,    16,    56,     0,     0,     3,
      17,    39,    40,    18,     0,     0,    40,    42,     0,     1,
      19,     0,     1,     0,     0,    20,    21,     0,    38,     0,
       3,    41,    22,    54,    19,     0,     8,     5,     0,    19,
       0,    17,    18,     0,    17,    44,    18,     0,    54,     0,
      44,    23,    54,     0,     1,     0,    44,    23,     1,     0,
       4,     0,     5,     0,     9,    24,     5,    25,     0,     6,
       0,     7,     0,    43,     0,    55,     0,    24,    54,    25,
       0,    24,     1,    25,     0,    45,     0,    26,    46,     0,
      27,    46,     0,    46,     0,    47,    28,    46,     0,    47,
      29,    46,     0,    47,    30,    46,     0,    47,     0,    48,
      26,    47,     0,    48,    27,    47,     0,    48,     0,    49,
      13,    48,     0,    49,    12,    48,     0,    49,    31,    48,
       0,    49,    32,    48,     0,    49,     0,    50,    11,    49,
       0,    50,    10,    49,     0,    50,     0,    51,    15,    50,
       0,    51,     0,    52,    14,    51,     0,    52,     0,    52,
      33,    54,    34,    53,     0,    53,     0,     3,     0,    55,
      35,     3,     0,    17,    18,     0,    17,    57,    18,     0,
       1,     0,    58,     0,    57,    23,    58,     0,    54,     0,
       1,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   151,   155,   162,   171,   171,   187,   188,   191,   192,
     202,   203,   207,   209,   220,   225,   229,   233,   244,   250,
     262,   266,   277,   282,   287,   293,   297,   303,   310,   343,
     350,   359,   361,   372,   387,   388,   389,   390,   395,   396,
     397,   402,   403,   404,   405,   406,   410,   411,   412,   416,
     417,   421,   422,   427,   428,   433,   439,   443,   458,   459,
     460,   464,   469,   478,   479
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "IDENT", "LIT_NUMBER", "LIT_STRING", "TRUE", 
  "FALSE", "INCLUDE", "GETTEXT", "NE", "EQ", "GE", "LE", "OR", "AND", 
  "'~'", "'{'", "'}'", "';'", "'['", "']'", "'='", "','", "'('", "')'", 
  "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'?'", "':'", "'|'", 
  "init", "start", "scope", "@1", "scope_body", "opt_old_array", 
  "scope_body_item", "array_body", "array_body2", "primary_expr", 
  "unary_expr", "multiplicative_expr", "additive_expr", "relational_expr", 
  "equality_expr", "logical_and_expr", "logical_or_expr", 
  "conditional_expr", "expr", "qualified_ident", "s2at_array_body", 
  "s2at_array_body2", "s2at_array_item", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    36,    37,    37,    39,    38,    40,    40,    40,    40,
      41,    41,    42,    42,    42,    42,    43,    43,    44,    44,
      44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    46,    46,    46,    47,    47,    47,    47,    48,    48,
      48,    49,    49,    49,    49,    49,    50,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    55,    55,    56,    56,
      56,    57,    57,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     0,     2,     3,     0,     5,     0,     2,     2,     1,
       0,     2,     1,     5,     2,     1,     2,     3,     1,     3,
       1,     3,     1,     1,     4,     1,     1,     1,     1,     3,
       3,     1,     2,     2,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     5,     1,     1,     3,     2,     3,
       1,     1,     3,     1,     1
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       1,     0,     9,     0,     2,     8,    60,     0,     3,    10,
       0,    15,    12,     7,    64,    56,    22,    23,    25,    26,
       0,     0,    58,     0,     0,     0,    27,    31,    34,    38,
      41,    46,    49,    51,    53,    55,    63,    28,     0,    61,
       4,     0,     0,    14,     0,    20,    16,     0,    18,     0,
       0,    32,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
       0,    11,     0,     0,    17,     0,    30,    29,    35,    36,
      37,    39,    40,    43,    42,    44,    45,    48,    47,    50,
      52,     0,    57,    62,     0,     0,    24,    21,    19,     0,
       5,    13,    54,     0,     0,     0
};

static const short yydefgoto[] =
{
       1,   103,    12,    70,     4,    42,    13,    26,    47,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       8,    38,    39
};

static const short yypact[] =
{
  -32768,   144,   -12,     2,    18,-32768,-32768,     5,-32768,    53,
      12,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
       0,    35,-32768,    62,   132,   132,-32768,-32768,-32768,    20,
     -11,    15,    64,    28,   -13,-32768,-32768,    25,    -5,-32768,
  -32768,    43,    50,-32768,    71,-32768,-32768,     7,-32768,    55,
      58,-32768,-32768,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,    81,-32768,    89,
     147,-32768,   132,    60,-32768,   116,-32768,-32768,-32768,-32768,
  -32768,    20,    20,   -11,   -11,   -11,   -11,    15,    15,    64,
      28,    57,-32768,-32768,   143,    68,-32768,-32768,-32768,   132,
  -32768,-32768,-32768,    97,    99,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768,-32768,    30,-32768,-32768,-32768,-32768,-32768,
     -20,    21,    -3,    19,    37,    38,-32768,     3,   -21,-32768,
  -32768,-32768,    36
};


#define	YYLAST		166


static const short yytable[] =
{
      48,    65,    50,     6,    51,    52,    14,     5,    15,    16,
      17,    18,    19,    68,    20,    56,    57,    43,    69,     7,
      66,     9,    21,    22,    44,    74,    10,    58,    59,    23,
      75,    24,    25,    78,    79,    80,    45,    11,    15,    16,
      17,    18,    19,    64,    20,    91,    60,    61,    53,    54,
      55,    95,    21,    46,    98,    83,    84,    85,    86,    23,
      67,    24,    25,    49,    71,    15,    16,    17,    18,    19,
      40,    20,    72,    41,    62,    63,    73,    81,    82,    21,
      76,    87,    88,    77,    92,    96,    23,   101,    24,    25,
      14,    99,    15,    16,    17,    18,    19,   104,    20,   105,
      94,    89,   102,    90,     0,    93,    21,     0,     0,     0,
       0,     0,     0,    23,     0,    24,    25,    97,     0,    15,
      16,    17,    18,    19,     0,    20,     0,     0,     0,     0,
       0,     0,     0,    21,     0,    15,    16,    17,    18,    19,
      23,    20,    24,    25,    -6,     2,     9,    -6,     2,    21,
      -6,    10,    -6,     0,     0,    -6,    23,     0,    24,    25,
       3,   100,    11,    -6,     0,    -6,    -6
};

static const short yycheck[] =
{
      21,    14,    23,     1,    24,    25,     1,    19,     3,     4,
       5,     6,     7,    18,     9,    26,    27,     5,    23,    17,
      33,     3,    17,    18,    24,    18,     8,    12,    13,    24,
      23,    26,    27,    53,    54,    55,     1,    19,     3,     4,
       5,     6,     7,    15,     9,    66,    31,    32,    28,    29,
      30,    72,    17,    18,    75,    58,    59,    60,    61,    24,
      35,    26,    27,     1,    21,     3,     4,     5,     6,     7,
      17,     9,    22,    20,    10,    11,     5,    56,    57,    17,
      25,    62,    63,    25,     3,    25,    24,    19,    26,    27,
       1,    34,     3,     4,     5,     6,     7,     0,     9,     0,
      70,    64,    99,    65,    -1,    69,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    26,    27,     1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,     3,     4,     5,     6,     7,
      24,     9,    26,    27,     0,     1,     3,     3,     1,    17,
       3,     8,     8,    -1,    -1,     8,    24,    -1,    26,    27,
      16,    18,    19,    19,    -1,    18,    19
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

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

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

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
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


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
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
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
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


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
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
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

#ifdef YYERROR_VERBOSE

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
#endif

#line 315 "/usr/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
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
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
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

  if (yyssp >= yyss + yystacksize - 1)
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
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
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 1:
#line 151 "../../../src/misc/CNestedDataFile/cfg.y"
{ cfg_init(); }
    break;
case 2:
#line 156 "../../../src/misc/CNestedDataFile/cfg.y"
{
		cfg_deinit();

		return myyynerrs!=0;
	}
    break;
case 3:
#line 163 "../../../src/misc/CNestedDataFile/cfg.y"
{
		cfg_deinit();
		return myyynerrs!=0;
	}
    break;
case 4:
#line 172 "../../../src/misc/CNestedDataFile/cfg.y"
{ /* mid-rule action */

		checkForDupMember(yylsp[-1].first_line,yyvsp[-1].stringValue);

		scopeStack.push(yyvsp[-1].stringValue);

		free(yyvsp[-1].stringValue);

		/* now continue parsing for new scope's body */
	}
    break;
case 5:
#line 181 "../../../src/misc/CNestedDataFile/cfg.y"
{
		scopeStack.pop();
	}
    break;
case 13:
#line 210 "../../../src/misc/CNestedDataFile/cfg.y"
{
		checkForDupMember(yylsp[-4].first_line,yyvsp[-4].stringValue);
		if(yyvsp[-1].variant->type==CNestedDataFile::ktValue)
			CNestedDataFile::parseTree->prvCreateKey(getCurrentScope()+yyvsp[-4].stringValue,0,*yyvsp[-1].variant,CNestedDataFile::parseTree->root);
		else
			yyerror(yylsp[-2],"assigning an invalid typed value to an identifier");

		delete yyvsp[-1].variant;
		free(yyvsp[-4].stringValue);
	}
    break;
case 14:
#line 221 "../../../src/misc/CNestedDataFile/cfg.y"
{
		cfg_includeFile(yyvsp[0].stringValue);
		free(yyvsp[0].stringValue);
	}
    break;
case 16:
#line 230 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.stringValue=strdup("{}");
	}
    break;
case 17:
#line 234 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.stringValue=(char *)malloc((1+strlen(yyvsp[-1].stringValue)+1)+1);
		strcpy(yyval.stringValue,"{");
		strcat(yyval.stringValue,yyvsp[-1].stringValue);
		strcat(yyval.stringValue,"}");
		free(yyvsp[-1].stringValue);
	}
    break;
case 18:
#line 245 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.stringValue=strdup(yyvsp[0].variant->stringValue.c_str());
		delete yyvsp[0].variant;
	}
    break;
case 19:
#line 251 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.stringValue=(char *)malloc((strlen(yyvsp[-2].stringValue)+1+yyvsp[0].variant->stringValue.size())+1);
		strcpy(yyval.stringValue,yyvsp[-2].stringValue);
		strcat(yyval.stringValue,",");
		strcat(yyval.stringValue,yyvsp[0].variant->stringValue.c_str());

		free(yyvsp[-2].stringValue);
		delete yyvsp[0].variant;
	}
    break;
case 20:
#line 263 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.stringValue=strdup("");
	}
    break;
case 21:
#line 267 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.stringValue=yyvsp[-2].stringValue;
	}
    break;
case 22:
#line 278 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=new CNestedDataFile::CVariant(yyvsp[0].stringValue);
		free(yyvsp[0].stringValue);
	}
    break;
case 23:
#line 283 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=new CNestedDataFile::CVariant(anytype_to_string<string>(yyvsp[0].stringValue));
		free(yyvsp[0].stringValue);
	}
    break;
case 24:
#line 288 "../../../src/misc/CNestedDataFile/cfg.y"
{
		/* having gettext(...) around a string simply causes an entry to be created in the rezound.pot file */
		yyval.variant=new CNestedDataFile::CVariant(anytype_to_string<string>(yyvsp[-1].stringValue));
		free(yyvsp[-1].stringValue);
	}
    break;
case 25:
#line 294 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=new CNestedDataFile::CVariant("true");
	}
    break;
case 26:
#line 298 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=new CNestedDataFile::CVariant("false");
	}
    break;
case 27:
#line 304 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=new CNestedDataFile::CVariant(yyvsp[0].stringValue);
		free(yyvsp[0].stringValue);
	}
    break;
case 28:
#line 311 "../../../src/misc/CNestedDataFile/cfg.y"
{
		if(CNestedDataFile::parseTree==NULL)
		{
			yyval.variant=new CNestedDataFile::CVariant("");
		}
		else
		{
			CNestedDataFile::CVariant *value;
			if(!CNestedDataFile::parseTree->findVariantNode(value,yyvsp[0].stringValue,0,false,CNestedDataFile::parseTree->root))
			{
				cfg_error(yylsp[0],("symbol not found: '"+string(yyvsp[0].stringValue)+"'").c_str());
				value=new CNestedDataFile::CVariant("");
			}

			switch(value->type)
			{
			case CNestedDataFile::ktValue:
				yyval.variant=new CNestedDataFile::CVariant(value->stringValue);
				break;
			case CNestedDataFile::ktScope:
				cfg_error(yylsp[0],("symbol resolves to a scope: '"+string(yyvsp[0].stringValue)+"'").c_str());
				value=new CNestedDataFile::CVariant("");
				break;
			default:
				throw runtime_error("cfg_parse -- unhandled variant type");
			}
		}

		free(yyvsp[0].stringValue);
	}
    break;
case 29:
#line 344 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=yyvsp[-1].variant;
	}
    break;
case 30:
#line 351 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyclearin;
		yyval.variant=new CNestedDataFile::CVariant("");
	}
    break;
case 31:
#line 359 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 32:
#line 362 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=yyvsp[0].variant;
		if(yyvsp[0].variant->type!=CNestedDataFile::ktValue)
			cfg_error(yylsp[0],"invalid operand");
		else
		{
			double x;
			yyval.variant->stringValue=strdup(anytype_to_string<double>(+string_to_anytype<double>(yyval.variant->stringValue,x)).c_str());
		}
	}
    break;
case 33:
#line 373 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=yyvsp[0].variant;
		if(yyvsp[0].variant->type!=CNestedDataFile::ktValue)
			cfg_error(yylsp[0],"invalid operand");
		else
		{
			double x;
			yyval.variant->stringValue=strdup(anytype_to_string<double>(-string_to_anytype<double>(yyval.variant->stringValue,x)).c_str());
		}
	}
    break;
case 34:
#line 387 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 35:
#line 388 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,*) }
    break;
case 36:
#line 389 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,/) }
    break;
case 37:
#line 390 "../../../src/misc/CNestedDataFile/cfg.y"
{ double x1,x2; VERIFY_TYPE(yylsp[-2],yyvsp[-2].variant) VERIFY_TYPE(yylsp[0],yyvsp[0].variant) yyval.variant=yyvsp[-2].variant; yyval.variant->stringValue= strdup( anytype_to_string<double>(fmod(string_to_anytype<double>(yyval.variant->stringValue,x1),string_to_anytype<double>(yyvsp[0].variant->stringValue,x2))).c_str() ); delete yyvsp[0].variant; }
    break;
case 38:
#line 395 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 39:
#line 396 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,+) }
    break;
case 40:
#line 397 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,-) }
    break;
case 41:
#line 402 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 42:
#line 403 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,<=) }
    break;
case 43:
#line 404 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,>=) }
    break;
case 44:
#line 405 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,<) }
    break;
case 45:
#line 406 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,>) }
    break;
case 46:
#line 410 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 47:
#line 411 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,==) }
    break;
case 48:
#line 412 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,!=) }
    break;
case 49:
#line 416 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 50:
#line 417 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,&&) }
    break;
case 51:
#line 421 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 52:
#line 422 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,||) }
    break;
case 53:
#line 427 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 54:
#line 428 "../../../src/misc/CNestedDataFile/cfg.y"
{ double x; VERIFY_TYPE(yylsp[-4],yyvsp[-4].variant) yyval.variant=(string_to_anytype<double>(yyvsp[-4].variant->stringValue,x) ? ((delete yyvsp[0].variant),yyvsp[-2].variant) : ((delete yyvsp[-2].variant),yyvsp[0].variant)); delete yyvsp[-4].variant; }
    break;
case 55:
#line 433 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 56:
#line 440 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.stringValue=yyvsp[0].stringValue;
	}
    break;
case 57:
#line 444 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.stringValue=(char *)realloc(yyval.stringValue,strlen(yyval.stringValue)+1+strlen(yyvsp[0].stringValue)+1);
		strcat(yyval.stringValue,CNestedDataFile::delim.c_str());
		strcat(yyval.stringValue,yyvsp[0].stringValue);

		free(yyvsp[0].stringValue);
	}
    break;
case 58:
#line 458 "../../../src/misc/CNestedDataFile/cfg.y"
{}
    break;
case 59:
#line 459 "../../../src/misc/CNestedDataFile/cfg.y"
{}
    break;
case 60:
#line 460 "../../../src/misc/CNestedDataFile/cfg.y"
{ YYABORT; }
    break;
case 61:
#line 465 "../../../src/misc/CNestedDataFile/cfg.y"
{
		CNestedDataFile::s2at_return_value.push_back(yyvsp[0].variant->stringValue);
		delete yyvsp[0].variant;
	}
    break;
case 62:
#line 470 "../../../src/misc/CNestedDataFile/cfg.y"
{
		CNestedDataFile::s2at_return_value.push_back(yyvsp[0].variant->stringValue);
		delete yyvsp[0].variant;
	}
    break;
case 63:
#line 478 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 64:
#line 479 "../../../src/misc/CNestedDataFile/cfg.y"
{ YYABORT; }
    break;
}

#line 705 "/usr/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
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
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 483 "../../../src/misc/CNestedDataFile/cfg.y"


#include "cfg.lex.c"

void cfg_error(int line,const char *msg)
{
	myyynerrs++;

	if(CNestedDataFile::s2at_string.size()>0)
		// suppress error messages when in s2at mode
		return;

	fprintf(stderr,"%s:%d: %s\n",currentFilename.c_str(),line,msg);

	if(myyynerrs>25)
		throw runtime_error("cfg_error -- more than 25 errors; bailing");
}

void cfg_error(const RTokenPosition &pos,const char *msg)
{
	cfg_error(pos.first_line,msg);
}

void cfg_error(const char *msg)
{
	cfg_error(yylloc.first_line,msg);
}

void checkForDupMember(int line,const char *key)
{
	if(CNestedDataFile::parseTree->keyExists(getCurrentScope()+key))
		cfg_error(line,("duplicate scope name: "+(getCurrentScope()+string(key))).c_str());
}

static const string getCurrentScope()
{
	stack<string> copy=scopeStack;
	string s;
	while(!copy.empty())
	{
		s=copy.top()+s;
		s=CNestedDataFile::delim+s;
		copy.pop();
	}

	s+=CNestedDataFile::delim;

	s.erase(0,1);

	return s;
}





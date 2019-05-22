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
# define	NE	263
# define	EQ	264
# define	GE	265
# define	LE	266
# define	OR	267
# define	AND	268

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



#line 76 "../../../src/misc/CNestedDataFile/cfg.y"
#ifndef YYSTYPE
typedef union cfg_parse_union
{
	char *				stringValue;
	double				floatValue;
	int 				intValue;
	CNestedDataFile::CVariant *	variant;
	vector<CNestedDataFile::CVariant> *variantList;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif

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



#define	YYFINAL		88
#define	YYFLAG		-32768
#define	YYNTBASE	34

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 268 ? yytranslate[x] : 54)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
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
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     1,     4,     5,    11,    12,    15,    18,    20,
      22,    27,    35,    38,    40,    41,    43,    45,    49,    51,
      55,    57,    59,    61,    63,    65,    69,    73,    75,    78,
      80,    82,    84,    88,    92,    96,    98,   102,   106,   108,
     112,   116,   120,   124,   126,   130,   134,   136,   140,   142,
     146,   148,   154,   156,   158
};
static const short yyrhs[] =
{
      -1,    35,    38,     0,     0,     3,    15,    37,    38,    16,
       0,     0,    38,    39,     0,     1,    17,     0,     1,     0,
      36,     0,     3,    18,    52,    17,     0,     3,    19,    20,
      18,    15,    40,    16,     0,     8,     5,     0,    17,     0,
       0,    41,     0,    52,     0,    40,    21,    52,     0,     1,
       0,    40,    21,     1,     0,     4,     0,     5,     0,     6,
       0,     7,     0,    53,     0,    22,    52,    23,     0,    22,
       1,    23,     0,    42,     0,    44,    43,     0,    24,     0,
      25,     0,    43,     0,    45,    26,    43,     0,    45,    27,
      43,     0,    45,    28,    43,     0,    45,     0,    46,    24,
      45,     0,    46,    25,    45,     0,    46,     0,    47,    12,
      46,     0,    47,    11,    46,     0,    47,    29,    46,     0,
      47,    30,    46,     0,    47,     0,    48,    10,    47,     0,
      48,     9,    47,     0,    48,     0,    49,    14,    48,     0,
      49,     0,    50,    13,    49,     0,    50,     0,    50,    31,
      52,    32,    51,     0,    51,     0,     3,     0,    53,    33,
       3,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   127,   127,   137,   137,   153,   154,   157,   161,   168,
     170,   183,   191,   196,   200,   204,   211,   225,   240,   244,
     255,   259,   264,   268,   274,   304,   311,   320,   322,   337,
     338,   342,   343,   344,   345,   350,   351,   372,   377,   378,
     379,   380,   381,   385,   386,   387,   391,   392,   396,   397,
     402,   403,   408,   414,   418
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "IDENT", "LIT_NUMBER", "LIT_STRING", "TRUE", 
  "FALSE", "INCLUDE", "NE", "EQ", "GE", "LE", "OR", "AND", "'{'", "'}'", 
  "';'", "'='", "'['", "']'", "','", "'('", "')'", "'+'", "'-'", "'*'", 
  "'/'", "'%'", "'<'", "'>'", "'?'", "':'", "'|'", "start", "@1", "scope", 
  "@2", "scope_body", "scope_body_item", "array_body", "array_body2", 
  "primary_expr", "unary_expr", "unary_op", "multiplicative_expr", 
  "additive_expr", "relational_expr", "equality_expr", "logical_and_expr", 
  "logical_or_expr", "conditional_expr", "expr", "qualified_ident", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    35,    34,    37,    36,    38,    38,    38,    38,    39,
      39,    39,    39,    39,    40,    40,    41,    41,    41,    41,
      42,    42,    42,    42,    42,    42,    42,    43,    43,    44,
      44,    45,    45,    45,    45,    46,    46,    46,    47,    47,
      47,    47,    47,    48,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    53,    53
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     0,     2,     0,     5,     0,     2,     2,     1,     1,
       4,     7,     2,     1,     0,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     3,     3,     1,     2,     1,
       1,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     5,     1,     1,     3
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       1,     0,     8,     2,     7,     0,     0,    13,     9,     6,
       3,     0,     0,    12,     0,    53,    20,    21,    22,    23,
       0,    29,    30,    27,    31,     0,    35,    38,    43,    46,
      48,    50,    52,     0,    24,     0,     0,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     4,    26,    25,
      32,    33,    34,    36,    37,    40,    39,    41,    42,    45,
      44,    47,    49,     0,    54,     0,     0,    18,     0,    15,
      16,    51,    11,     0,    19,    17,     0,     0,     0
};

static const short yydefgoto[] =
{
      86,     1,     8,    14,     3,     9,    78,    79,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

static const short yypact[] =
{
  -32768,    68,    -8,    74,-32768,    42,    10,-32768,-32768,-32768,
  -32768,    40,    -3,-32768,    71,-32768,-32768,-32768,-32768,-32768,
       7,-32768,-32768,-32768,-32768,    40,    70,     3,    37,    80,
       5,   -11,-32768,     9,     1,    12,    67,    19,    27,-32768,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,-32768,    51,    58,-32768,-32768,-32768,
  -32768,-32768,-32768,    70,    70,     3,     3,     3,     3,    37,
      37,    80,     5,    46,-32768,     0,    40,-32768,     2,-32768,
  -32768,-32768,-32768,    34,-32768,-32768,    86,   101,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768,-32768,    88,-32768,-32768,-32768,-32768,    11,
  -32768,    56,    47,    31,    52,    53,-32768,    28,   -20,-32768
};


#define	YYLAST		105


static const short yytable[] =
{
      38,    77,    52,    15,    16,    17,    18,    19,    37,     4,
      15,    16,    17,    18,    19,    13,   -14,    35,    82,    51,
      53,   -14,    20,    83,    21,    22,    54,    43,    44,    20,
      56,    21,    22,    73,    55,    84,    39,    15,    16,    17,
      18,    19,    58,    15,    16,    17,    18,    19,    45,    46,
      59,    60,    61,    62,    74,    80,    20,    10,    21,    22,
      11,    12,    20,    85,    21,    22,    47,    48,    -5,     2,
       5,    -5,     2,    75,    -5,     6,    -5,     5,    76,    -5,
      69,    70,     6,    57,     7,    -5,    87,    -5,    -5,    49,
      50,     7,    65,    66,    67,    68,    40,    41,    42,    63,
      64,    88,    36,    71,    81,    72
};

static const short yycheck[] =
{
      20,     1,    13,     3,     4,     5,     6,     7,     1,    17,
       3,     4,     5,     6,     7,     5,    16,    20,    16,    14,
      31,    21,    22,    21,    24,    25,    17,    24,    25,    22,
      18,    24,    25,    53,    33,     1,    25,     3,     4,     5,
       6,     7,    23,     3,     4,     5,     6,     7,    11,    12,
      23,    40,    41,    42,     3,    75,    22,    15,    24,    25,
      18,    19,    22,    83,    24,    25,    29,    30,     0,     1,
       3,     3,     1,    15,     3,     8,     8,     3,    32,     8,
      49,    50,     8,    16,    17,    17,     0,    16,    17,     9,
      10,    17,    45,    46,    47,    48,    26,    27,    28,    43,
      44,     0,    14,    51,    76,    52
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
#line 127 "../../../src/misc/CNestedDataFile/cfg.y"
{ cfg_init(); }
    break;
case 2:
#line 128 "../../../src/misc/CNestedDataFile/cfg.y"
{
		cfg_deinit();

		return(myyynerrs!=0);
	}
    break;
case 3:
#line 138 "../../../src/misc/CNestedDataFile/cfg.y"
{ /* mid-rule action */

		checkForDupMember(yylsp[-1].first_line,yyvsp[-1].stringValue);

		scopeStack.push(yyvsp[-1].stringValue);

		free(yyvsp[-1].stringValue);

		// now continue parsing for new scope's body
	}
    break;
case 4:
#line 147 "../../../src/misc/CNestedDataFile/cfg.y"
{
		scopeStack.pop();
	}
    break;
case 7:
#line 158 "../../../src/misc/CNestedDataFile/cfg.y"
{
		cfg_error(yylsp[-1],"syntax error");
	}
    break;
case 8:
#line 162 "../../../src/misc/CNestedDataFile/cfg.y"
{
		cfg_error(yylsp[0],"syntax error");
	}
    break;
case 10:
#line 171 "../../../src/misc/CNestedDataFile/cfg.y"
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
case 11:
#line 184 "../../../src/misc/CNestedDataFile/cfg.y"
{
		checkForDupMember(yylsp[-6].first_line,yyvsp[-6].stringValue);
		CNestedDataFile::parseTree->createKey((getCurrentScope()+yyvsp[-6].stringValue).c_str(),*yyvsp[-1].variantList);

		delete yyvsp[-1].variantList;
		free(yyvsp[-6].stringValue);
	}
    break;
case 12:
#line 192 "../../../src/misc/CNestedDataFile/cfg.y"
{
		cfg_includeFile(yyvsp[0].stringValue);
		free(yyvsp[0].stringValue);
	}
    break;
case 14:
#line 201 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variantList=new vector<CNestedDataFile::CVariant>;
	}
    break;
case 15:
#line 205 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variantList=yyvsp[0].variantList;
	}
    break;
case 16:
#line 212 "../../../src/misc/CNestedDataFile/cfg.y"
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
case 17:
#line 226 "../../../src/misc/CNestedDataFile/cfg.y"
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
case 18:
#line 241 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variantList=new vector<CNestedDataFile::CVariant>;
	}
    break;
case 19:
#line 245 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variantList=yyvsp[-2].variantList;
	}
    break;
case 20:
#line 256 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=new CNestedDataFile::CVariant("",yyvsp[0].floatValue);
	}
    break;
case 21:
#line 260 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=new CNestedDataFile::CVariant("",yyvsp[0].stringValue);
		free(yyvsp[0].stringValue);
	}
    break;
case 22:
#line 265 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=new CNestedDataFile::CVariant("","true");
	}
    break;
case 23:
#line 269 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=new CNestedDataFile::CVariant("","false");
	}
    break;
case 24:
#line 275 "../../../src/misc/CNestedDataFile/cfg.y"
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
case 25:
#line 305 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.variant=yyvsp[-1].variant;
	}
    break;
case 26:
#line 312 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyclearin;
		yyval.variant=new CNestedDataFile::CVariant("",0.0);
	}
    break;
case 27:
#line 320 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 28:
#line 323 "../../../src/misc/CNestedDataFile/cfg.y"
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
case 29:
#line 337 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.intValue='+'; }
    break;
case 30:
#line 338 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.intValue='-'; }
    break;
case 31:
#line 342 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 32:
#line 343 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,*) }
    break;
case 33:
#line 344 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,/) }
    break;
case 34:
#line 345 "../../../src/misc/CNestedDataFile/cfg.y"
{ VERIFY_TYPE(yylsp[-2],yyvsp[-2].variant) VERIFY_TYPE(yylsp[0],yyvsp[0].variant) yyval.variant=yyvsp[-2].variant; yyval.variant->floatValue=fmod(yyval.variant->floatValue,yyvsp[0].variant->floatValue); delete yyvsp[0].variant; }
    break;
case 35:
#line 350 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 36:
#line 352 "../../../src/misc/CNestedDataFile/cfg.y"
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
case 37:
#line 372 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,-) }
    break;
case 38:
#line 377 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 39:
#line 378 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,<=) }
    break;
case 40:
#line 379 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,>=) }
    break;
case 41:
#line 380 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,<) }
    break;
case 42:
#line 381 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,>) }
    break;
case 43:
#line 385 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 44:
#line 386 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,==) }
    break;
case 45:
#line 387 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,!=) }
    break;
case 46:
#line 391 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 47:
#line 392 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,&&) }
    break;
case 48:
#line 396 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 49:
#line 397 "../../../src/misc/CNestedDataFile/cfg.y"
{ BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,||) }
    break;
case 50:
#line 402 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 51:
#line 403 "../../../src/misc/CNestedDataFile/cfg.y"
{ VERIFY_TYPE(yylsp[-4],yyvsp[-4].variant) yyval.variant=(yyvsp[-4].variant->floatValue ? ((delete yyvsp[0].variant),yyvsp[-2].variant) : ((delete yyvsp[-2].variant),yyvsp[0].variant)); delete yyvsp[-4].variant; }
    break;
case 52:
#line 408 "../../../src/misc/CNestedDataFile/cfg.y"
{ yyval.variant=yyvsp[0].variant; }
    break;
case 53:
#line 415 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.stringValue=yyvsp[0].stringValue;
	}
    break;
case 54:
#line 419 "../../../src/misc/CNestedDataFile/cfg.y"
{
		yyval.stringValue=(char *)realloc(yyval.stringValue,strlen(yyval.stringValue)+1+strlen(yyvsp[0].stringValue)+1);
		strcat(yyval.stringValue,CNestedDataFile::delimChar);
		strcat(yyval.stringValue,yyvsp[0].stringValue);

		free(yyvsp[0].stringValue);
	}
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
#line 430 "../../../src/misc/CNestedDataFile/cfg.y"


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


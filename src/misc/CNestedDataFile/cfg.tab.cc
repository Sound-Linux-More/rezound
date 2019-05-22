/* A Bison parser, made by GNU Bison 1.875d.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
     GETTEXT = 264,
     NE = 265,
     EQ = 266,
     GE = 267,
     LE = 268,
     OR = 269,
     AND = 270
   };
#endif
#define IDENT 258
#define LIT_NUMBER 259
#define LIT_STRING 260
#define TRUE 261
#define FALSE 262
#define INCLUDE 263
#define GETTEXT 264
#define NE 265
#define EQ 266
#define GE 267
#define LE 268
#define OR 269
#define AND 270




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
#line 236 "cfg.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
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
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
             && defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   166

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  24
/* YYNRULES -- Number of rules. */
#define YYNRULES  65
/* YYNRULES -- Number of states. */
#define YYNSTATES  105

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    12,    18,    19,    22,
      25,    27,    28,    31,    33,    39,    42,    44,    47,    51,
      53,    57,    59,    63,    65,    67,    72,    74,    76,    78,
      80,    84,    88,    90,    93,    96,    98,   102,   106,   110,
     112,   116,   120,   122,   126,   130,   134,   138,   140,   144,
     148,   150,   154,   156,   160,   162,   168,   170,   172,   176,
     179,   183,   185,   187,   191,   193
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      38,     0,    -1,    -1,    37,    41,    -1,    37,    16,    57,
      -1,    -1,     3,    17,    40,    41,    18,    -1,    -1,    41,
      43,    -1,     1,    19,    -1,     1,    -1,    -1,    20,    21,
      -1,    39,    -1,     3,    42,    22,    55,    19,    -1,     8,
       5,    -1,    19,    -1,    17,    18,    -1,    17,    45,    18,
      -1,    55,    -1,    45,    23,    55,    -1,     1,    -1,    45,
      23,     1,    -1,     4,    -1,     5,    -1,     9,    24,     5,
      25,    -1,     6,    -1,     7,    -1,    44,    -1,    56,    -1,
      24,    55,    25,    -1,    24,     1,    25,    -1,    46,    -1,
      26,    47,    -1,    27,    47,    -1,    47,    -1,    48,    28,
      47,    -1,    48,    29,    47,    -1,    48,    30,    47,    -1,
      48,    -1,    49,    26,    48,    -1,    49,    27,    48,    -1,
      49,    -1,    50,    13,    49,    -1,    50,    12,    49,    -1,
      50,    31,    49,    -1,    50,    32,    49,    -1,    50,    -1,
      51,    11,    50,    -1,    51,    10,    50,    -1,    51,    -1,
      52,    15,    51,    -1,    52,    -1,    53,    14,    52,    -1,
      53,    -1,    53,    33,    55,    34,    54,    -1,    54,    -1,
       3,    -1,    56,    35,     3,    -1,    17,    18,    -1,    17,
      58,    18,    -1,     1,    -1,    59,    -1,    58,    23,    59,
      -1,    55,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   151,   151,   155,   162,   172,   171,   186,   188,   191,
     192,   201,   203,   207,   209,   220,   225,   229,   233,   244,
     250,   262,   266,   277,   282,   287,   293,   297,   303,   310,
     343,   350,   359,   361,   372,   387,   388,   389,   390,   395,
     396,   397,   402,   403,   404,   405,   406,   410,   411,   412,
     416,   417,   421,   422,   427,   428,   433,   439,   443,   458,
     459,   460,   464,   469,   478,   479
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "LIT_NUMBER", "LIT_STRING",
  "TRUE", "FALSE", "INCLUDE", "GETTEXT", "NE", "EQ", "GE", "LE", "OR",
  "AND", "'~'", "'{'", "'}'", "';'", "'['", "']'", "'='", "','", "'('",
  "')'", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'?'", "':'",
  "'|'", "$accept", "init", "start", "scope", "@1", "scope_body",
  "opt_old_array", "scope_body_item", "array_body", "array_body2",
  "primary_expr", "unary_expr", "multiplicative_expr", "additive_expr",
  "relational_expr", "equality_expr", "logical_and_expr",
  "logical_or_expr", "conditional_expr", "expr", "qualified_ident",
  "s2at_array_body", "s2at_array_body2", "s2at_array_item", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   126,   123,   125,    59,
      91,    93,    61,    44,    40,    41,    43,    45,    42,    47,
      37,    60,    62,    63,    58,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    36,    37,    38,    38,    40,    39,    41,    41,    41,
      41,    42,    42,    43,    43,    43,    43,    44,    44,    45,
      45,    45,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    47,    47,    47,    48,    48,    48,    48,    49,
      49,    49,    50,    50,    50,    50,    50,    51,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    56,    56,    57,
      57,    57,    58,    58,    59,    59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     3,     0,     5,     0,     2,     2,
       1,     0,     2,     1,     5,     2,     1,     2,     3,     1,
       3,     1,     3,     1,     1,     4,     1,     1,     1,     1,
       3,     3,     1,     2,     2,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     5,     1,     1,     3,     2,
       3,     1,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     0,    10,     0,     3,     1,     9,    61,     0,
       4,    11,     0,    16,    13,     8,    65,    57,    23,    24,
      26,    27,     0,     0,    59,     0,     0,     0,    28,    32,
      35,    39,    42,    47,    50,    52,    54,    56,    64,    29,
       0,    62,     5,     0,     0,    15,     0,    21,    17,     0,
      19,     0,     0,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,     0,     0,    12,     0,     0,    18,     0,    31,    30,
      36,    37,    38,    40,    41,    44,    43,    45,    46,    49,
      48,    51,    53,     0,    58,    63,     0,     0,    25,    22,
      20,     0,     6,    14,    55
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     1,     2,    14,    72,     5,    44,    15,    28,    49,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    10,    40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -24
static const short int yypact[] =
{
     -24,   144,    17,   -12,     2,    18,   -24,   -24,   -24,     5,
     -24,    38,    55,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,     0,    35,   -24,    62,   132,   132,   -24,   -24,
     -24,    20,   -11,    15,    46,    28,   -13,   -24,   -24,    29,
      -5,   -24,   -24,    49,    54,   -24,    77,   -24,   -24,     7,
     -24,    58,    59,   -24,   -24,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,    82,
     -24,    89,   147,   -24,   132,    66,   -24,   116,   -24,   -24,
     -24,   -24,   -24,    20,    20,   -11,   -11,   -11,   -11,    15,
      15,    46,    28,    53,   -24,   -24,   143,    78,   -24,   -24,
     -24,   132,   -24,   -24,   -24
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -24,   -24,   -24,   -24,   -24,    27,   -24,   -24,   -24,   -24,
     -24,   -22,    19,    12,    16,    34,    36,   -24,     1,   -23,
     -24,   -24,   -24,    30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -8
static const yysigned_char yytable[] =
{
      50,    67,    52,     8,    53,    54,    16,     7,    17,    18,
      19,    20,    21,    70,    22,    58,    59,     6,    71,     9,
      68,    11,    23,    24,    46,    76,    12,    60,    61,    25,
      77,    26,    27,    80,    81,    82,    47,    13,    17,    18,
      19,    20,    21,    66,    22,    93,    62,    63,    55,    56,
      57,    97,    23,    48,   100,    42,    64,    65,    43,    25,
      45,    26,    27,    51,    69,    17,    18,    19,    20,    21,
      73,    22,    85,    86,    87,    88,    74,    83,    84,    23,
      89,    90,    75,    78,    79,    94,    25,   101,    26,    27,
      16,    98,    17,    18,    19,    20,    21,   103,    22,    96,
      91,    95,   104,    92,     0,     0,    23,     0,     0,     0,
       0,     0,     0,    25,     0,    26,    27,    99,     0,    17,
      18,    19,    20,    21,     0,    22,     0,     0,     0,     0,
       0,     0,     0,    23,     0,    17,    18,    19,    20,    21,
      25,    22,    26,    27,    -7,     3,    11,    -7,     3,    23,
      -7,    12,    -7,     0,     0,    -7,    25,     0,    26,    27,
       4,   102,    13,    -7,     0,    -7,    -7
};

static const yysigned_char yycheck[] =
{
      23,    14,    25,     1,    26,    27,     1,    19,     3,     4,
       5,     6,     7,    18,     9,    26,    27,     0,    23,    17,
      33,     3,    17,    18,    24,    18,     8,    12,    13,    24,
      23,    26,    27,    55,    56,    57,     1,    19,     3,     4,
       5,     6,     7,    15,     9,    68,    31,    32,    28,    29,
      30,    74,    17,    18,    77,    17,    10,    11,    20,    24,
       5,    26,    27,     1,    35,     3,     4,     5,     6,     7,
      21,     9,    60,    61,    62,    63,    22,    58,    59,    17,
      64,    65,     5,    25,    25,     3,    24,    34,    26,    27,
       1,    25,     3,     4,     5,     6,     7,    19,     9,    72,
      66,    71,   101,    67,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    26,    27,     1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,     3,     4,     5,     6,     7,
      24,     9,    26,    27,     0,     1,     3,     3,     1,    17,
       3,     8,     8,    -1,    -1,     8,    24,    -1,    26,    27,
      16,    18,    19,    19,    -1,    18,    19
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    37,    38,     1,    16,    41,     0,    19,     1,    17,
      57,     3,     8,    19,    39,    43,     1,     3,     4,     5,
       6,     7,     9,    17,    18,    24,    26,    27,    44,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      58,    59,    17,    20,    42,     5,    24,     1,    18,    45,
      55,     1,    55,    47,    47,    28,    29,    30,    26,    27,
      12,    13,    31,    32,    10,    11,    15,    14,    33,    35,
      18,    23,    40,    21,    22,     5,    18,    23,    25,    25,
      47,    47,    47,    48,    48,    49,    49,    49,    49,    50,
      50,    51,    52,    55,     3,    59,    41,    55,    25,     1,
      55,    34,    18,    19,    54
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
#define YYERROR		goto yyerrorlab


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
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
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
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
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
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
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

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
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
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

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
	short int *yyss1 = yyss;
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
	short int *yyss1 = yyss;
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
  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 151 "../../../src/misc/CNestedDataFile/cfg.y"
    { cfg_init(); }
    break;

  case 3:
#line 156 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		cfg_deinit();

		return myyynerrs!=0;
	}
    break;

  case 4:
#line 163 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		cfg_deinit();
		return myyynerrs!=0;
	}
    break;

  case 5:
#line 172 "../../../src/misc/CNestedDataFile/cfg.y"
    { /* mid-rule action */

		checkForDupMember(yylsp[-1].first_line,yyvsp[-1].stringValue);

		scopeStack.push(yyvsp[-1].stringValue);

		free(yyvsp[-1].stringValue);

		/* now continue parsing for new scope's body */
	}
    break;

  case 6:
#line 181 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		scopeStack.pop();
	}
    break;

  case 14:
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

  case 15:
#line 221 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		cfg_includeFile(yyvsp[0].stringValue);
		free(yyvsp[0].stringValue);
	}
    break;

  case 17:
#line 230 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.stringValue=strdup("{}");
	}
    break;

  case 18:
#line 234 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.stringValue=(char *)malloc((1+strlen(yyvsp[-1].stringValue)+1)+1);
		strcpy(yyval.stringValue,"{");
		strcat(yyval.stringValue,yyvsp[-1].stringValue);
		strcat(yyval.stringValue,"}");
		free(yyvsp[-1].stringValue);
	}
    break;

  case 19:
#line 245 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.stringValue=strdup(yyvsp[0].variant->stringValue.c_str());
		delete yyvsp[0].variant;
	}
    break;

  case 20:
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

  case 21:
#line 263 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.stringValue=strdup("");
	}
    break;

  case 22:
#line 267 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.stringValue=yyvsp[-2].stringValue;
	}
    break;

  case 23:
#line 278 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=new CNestedDataFile::CVariant(yyvsp[0].stringValue);
		free(yyvsp[0].stringValue);
	}
    break;

  case 24:
#line 283 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=new CNestedDataFile::CVariant(anytype_to_string<string>(yyvsp[0].stringValue));
		free(yyvsp[0].stringValue);
	}
    break;

  case 25:
#line 288 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		/* having gettext(...) around a string simply causes an entry to be created in the rezound.pot file */
		yyval.variant=new CNestedDataFile::CVariant(anytype_to_string<string>(yyvsp[-1].stringValue));
		free(yyvsp[-1].stringValue);
	}
    break;

  case 26:
#line 294 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=new CNestedDataFile::CVariant("true");
	}
    break;

  case 27:
#line 298 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=new CNestedDataFile::CVariant("false");
	}
    break;

  case 28:
#line 304 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=new CNestedDataFile::CVariant(yyvsp[0].stringValue);
		free(yyvsp[0].stringValue);
	}
    break;

  case 29:
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

  case 30:
#line 344 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.variant=yyvsp[-1].variant;
	}
    break;

  case 31:
#line 351 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyclearin;
		yyval.variant=new CNestedDataFile::CVariant("");
	}
    break;

  case 32:
#line 359 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 33:
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

  case 34:
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

  case 35:
#line 387 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 36:
#line 388 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,*) }
    break;

  case 37:
#line 389 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,/) }
    break;

  case 38:
#line 390 "../../../src/misc/CNestedDataFile/cfg.y"
    { double x1,x2; VERIFY_TYPE(yylsp[-2],yyvsp[-2].variant) VERIFY_TYPE(yylsp[0],yyvsp[0].variant) yyval.variant=yyvsp[-2].variant; yyval.variant->stringValue= strdup( anytype_to_string<double>(fmod(string_to_anytype<double>(yyval.variant->stringValue,x1),string_to_anytype<double>(yyvsp[0].variant->stringValue,x2))).c_str() ); delete yyvsp[0].variant; }
    break;

  case 39:
#line 395 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 40:
#line 396 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,+) }
    break;

  case 41:
#line 397 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,-) }
    break;

  case 42:
#line 402 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 43:
#line 403 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,<=) }
    break;

  case 44:
#line 404 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,>=) }
    break;

  case 45:
#line 405 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,<) }
    break;

  case 46:
#line 406 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,>) }
    break;

  case 47:
#line 410 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 48:
#line 411 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,==) }
    break;

  case 49:
#line 412 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,!=) }
    break;

  case 50:
#line 416 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 51:
#line 417 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,&&) }
    break;

  case 52:
#line 421 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 53:
#line 422 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR(yyval.variant,yylsp[-2],yyvsp[-2].variant,yylsp[0],yyvsp[0].variant,||) }
    break;

  case 54:
#line 427 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 55:
#line 428 "../../../src/misc/CNestedDataFile/cfg.y"
    { double x; VERIFY_TYPE(yylsp[-4],yyvsp[-4].variant) yyval.variant=(string_to_anytype<double>(yyvsp[-4].variant->stringValue,x) ? ((delete yyvsp[0].variant),yyvsp[-2].variant) : ((delete yyvsp[-2].variant),yyvsp[0].variant)); delete yyvsp[-4].variant; }
    break;

  case 56:
#line 433 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 57:
#line 440 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.stringValue=yyvsp[0].stringValue;
	}
    break;

  case 58:
#line 444 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyval.stringValue=(char *)realloc(yyval.stringValue,strlen(yyval.stringValue)+1+strlen(yyvsp[0].stringValue)+1);
		strcat(yyval.stringValue,CNestedDataFile::delim.c_str());
		strcat(yyval.stringValue,yyvsp[0].stringValue);

		free(yyvsp[0].stringValue);
	}
    break;

  case 59:
#line 458 "../../../src/misc/CNestedDataFile/cfg.y"
    {}
    break;

  case 60:
#line 459 "../../../src/misc/CNestedDataFile/cfg.y"
    {}
    break;

  case 61:
#line 460 "../../../src/misc/CNestedDataFile/cfg.y"
    { YYABORT; }
    break;

  case 62:
#line 465 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		CNestedDataFile::s2at_return_value.push_back(yyvsp[0].variant->stringValue);
		delete yyvsp[0].variant;
	}
    break;

  case 63:
#line 470 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		CNestedDataFile::s2at_return_value.push_back(yyvsp[0].variant->stringValue);
		delete yyvsp[0].variant;
	}
    break;

  case 64:
#line 478 "../../../src/misc/CNestedDataFile/cfg.y"
    { yyval.variant=yyvsp[0].variant; }
    break;

  case 65:
#line 479 "../../../src/misc/CNestedDataFile/cfg.y"
    { YYABORT; }
    break;


    }

/* Line 1010 of yacc.c.  */
#line 1656 "cfg.tab.c"

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
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
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

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp, yylsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	  *++yylerrsp = yylloc;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  yylerrsp = yylsp;
  *++yylerrsp = yyloc;
  yylsp -= yylen;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
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
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
  YYLLOC_DEFAULT (yyloc, yylsp, yylerrsp - yylsp);
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







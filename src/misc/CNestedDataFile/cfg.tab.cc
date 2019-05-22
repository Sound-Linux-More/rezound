/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         cfg_parse
#define yylex           cfg_lex
#define yyerror         cfg_error
#define yylval          cfg_lval
#define yychar          cfg_char
#define yydebug         cfg_debug
#define yynerrs         cfg_nerrs
#define yylloc          cfg_lloc

/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
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



/* Line 268 of yacc.c  */
#line 178 "cfg.tab.c"

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

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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
/* Tokens.  */
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
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


/* Line 343 of yacc.c  */
#line 262 "cfg.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  105

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    12,    18,    19,    22,
      25,    27,    28,    31,    33,    39,    42,    44,    47,    51,
      53,    57,    59,    63,    65,    67,    72,    74,    76,    78,
      80,    84,    88,    90,    93,    96,    98,   102,   106,   110,
     112,   116,   120,   122,   126,   130,   134,   138,   140,   144,
     148,   150,   154,   156,   160,   162,   168,   170,   172,   176,
     179,   183,   185,   187,   191,   193
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
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
static const yytype_uint16 yyrline[] =
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

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "LIT_NUMBER", "LIT_STRING",
  "TRUE", "FALSE", "INCLUDE", "GETTEXT", "NE", "EQ", "GE", "LE", "OR",
  "AND", "'~'", "'{'", "'}'", "';'", "'['", "']'", "'='", "','", "'('",
  "')'", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'?'", "':'",
  "'|'", "$accept", "init", "start", "scope", "$@1", "scope_body",
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
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   126,   123,   125,    59,
      91,    93,    61,    44,    40,    41,    43,    45,    42,    47,
      37,    60,    62,    63,    58,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
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
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     0,     5,     0,     2,     2,
       1,     0,     2,     1,     5,     2,     1,     2,     3,     1,
       3,     1,     3,     1,     1,     4,     1,     1,     1,     1,
       3,     3,     1,     2,     2,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     5,     1,     1,     3,     2,
       3,     1,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
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

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    14,    72,     5,    44,    15,    28,    49,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    10,    40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -24
static const yytype_int16 yypact[] =
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
static const yytype_int8 yypgoto[] =
{
     -24,   -24,   -24,   -24,   -24,    27,   -24,   -24,   -24,   -24,
     -24,   -22,    19,    12,    16,    34,    36,   -24,     1,   -23,
     -24,   -24,   -24,    30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -8
static const yytype_int8 yytable[] =
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

#define yypact_value_is_default(yystate) \
  ((yystate) == (-24))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
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
static const yytype_uint8 yystos[] =
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
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
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
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
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 151 "../../../src/misc/CNestedDataFile/cfg.y"
    { cfg_init(); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 156 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		cfg_deinit();

		return myyynerrs!=0;
	}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 163 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		cfg_deinit();
		return myyynerrs!=0;
	}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 172 "../../../src/misc/CNestedDataFile/cfg.y"
    { /* mid-rule action */

		checkForDupMember((yylsp[(1) - (2)]).first_line,(yyvsp[(1) - (2)].stringValue));

		scopeStack.push((yyvsp[(1) - (2)].stringValue));

		free((yyvsp[(1) - (2)].stringValue));

		/* now continue parsing for new scope's body */
	}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 181 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		scopeStack.pop();
	}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 210 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		checkForDupMember((yylsp[(1) - (5)]).first_line,(yyvsp[(1) - (5)].stringValue));
		if((yyvsp[(4) - (5)].variant)->type==CNestedDataFile::ktValue)
			CNestedDataFile::parseTree->prvCreateKey(getCurrentScope()+(yyvsp[(1) - (5)].stringValue),0,*(yyvsp[(4) - (5)].variant),CNestedDataFile::parseTree->root);
		else
			yyerror((yylsp[(3) - (5)]),"assigning an invalid typed value to an identifier");

		delete (yyvsp[(4) - (5)].variant);
		free((yyvsp[(1) - (5)].stringValue));
	}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 221 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		cfg_includeFile((yyvsp[(2) - (2)].stringValue));
		free((yyvsp[(2) - (2)].stringValue));
	}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 230 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.stringValue)=strdup("{}");
	}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 234 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.stringValue)=(char *)malloc((1+strlen((yyvsp[(2) - (3)].stringValue))+1)+1);
		strcpy((yyval.stringValue),"{");
		strcat((yyval.stringValue),(yyvsp[(2) - (3)].stringValue));
		strcat((yyval.stringValue),"}");
		free((yyvsp[(2) - (3)].stringValue));
	}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 245 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.stringValue)=strdup((yyvsp[(1) - (1)].variant)->stringValue.c_str());
		delete (yyvsp[(1) - (1)].variant);
	}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 251 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.stringValue)=(char *)malloc((strlen((yyvsp[(1) - (3)].stringValue))+1+(yyvsp[(3) - (3)].variant)->stringValue.size())+1);
		strcpy((yyval.stringValue),(yyvsp[(1) - (3)].stringValue));
		strcat((yyval.stringValue),",");
		strcat((yyval.stringValue),(yyvsp[(3) - (3)].variant)->stringValue.c_str());

		free((yyvsp[(1) - (3)].stringValue));
		delete (yyvsp[(3) - (3)].variant);
	}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 263 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.stringValue)=strdup("");
	}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 267 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.stringValue)=(yyvsp[(1) - (3)].stringValue);
	}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 278 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.variant)=new CNestedDataFile::CVariant((yyvsp[(1) - (1)].stringValue));
		free((yyvsp[(1) - (1)].stringValue));
	}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 283 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.variant)=new CNestedDataFile::CVariant(anytype_to_string<string>((yyvsp[(1) - (1)].stringValue)));
		free((yyvsp[(1) - (1)].stringValue));
	}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 288 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		/* having gettext(...) around a string simply causes an entry to be created in the rezound.pot file */
		(yyval.variant)=new CNestedDataFile::CVariant(anytype_to_string<string>((yyvsp[(3) - (4)].stringValue)));
		free((yyvsp[(3) - (4)].stringValue));
	}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 294 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.variant)=new CNestedDataFile::CVariant("true");
	}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 298 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.variant)=new CNestedDataFile::CVariant("false");
	}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 304 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.variant)=new CNestedDataFile::CVariant((yyvsp[(1) - (1)].stringValue));
		free((yyvsp[(1) - (1)].stringValue));
	}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 311 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		if(CNestedDataFile::parseTree==NULL)
		{
			(yyval.variant)=new CNestedDataFile::CVariant("");
		}
		else
		{
			CNestedDataFile::CVariant *value;
			if(!CNestedDataFile::parseTree->findVariantNode(value,(yyvsp[(1) - (1)].stringValue),0,false,CNestedDataFile::parseTree->root))
			{
				cfg_error((yylsp[(1) - (1)]),("symbol not found: '"+string((yyvsp[(1) - (1)].stringValue))+"'").c_str());
				value=new CNestedDataFile::CVariant("");
			}

			switch(value->type)
			{
			case CNestedDataFile::ktValue:
				(yyval.variant)=new CNestedDataFile::CVariant(value->stringValue);
				break;
			case CNestedDataFile::ktScope:
				cfg_error((yylsp[(1) - (1)]),("symbol resolves to a scope: '"+string((yyvsp[(1) - (1)].stringValue))+"'").c_str());
				value=new CNestedDataFile::CVariant("");
				break;
			default:
				throw runtime_error("cfg_parse -- unhandled variant type");
			}
		}

		free((yyvsp[(1) - (1)].stringValue));
	}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 344 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.variant)=(yyvsp[(2) - (3)].variant);
	}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 351 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		yyclearin;
		(yyval.variant)=new CNestedDataFile::CVariant("");
	}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 359 "../../../src/misc/CNestedDataFile/cfg.y"
    { (yyval.variant)=(yyvsp[(1) - (1)].variant); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 362 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.variant)=(yyvsp[(2) - (2)].variant);
		if((yyvsp[(2) - (2)].variant)->type!=CNestedDataFile::ktValue)
			cfg_error((yylsp[(2) - (2)]),"invalid operand");
		else
		{
			double x;
			(yyval.variant)->stringValue=strdup(anytype_to_string<double>(+string_to_anytype<double>((yyval.variant)->stringValue,x)).c_str());
		}
	}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 373 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.variant)=(yyvsp[(2) - (2)].variant);
		if((yyvsp[(2) - (2)].variant)->type!=CNestedDataFile::ktValue)
			cfg_error((yylsp[(2) - (2)]),"invalid operand");
		else
		{
			double x;
			(yyval.variant)->stringValue=strdup(anytype_to_string<double>(-string_to_anytype<double>((yyval.variant)->stringValue,x)).c_str());
		}
	}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 387 "../../../src/misc/CNestedDataFile/cfg.y"
    { (yyval.variant)=(yyvsp[(1) - (1)].variant); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 388 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),*) }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 389 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),/) }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 390 "../../../src/misc/CNestedDataFile/cfg.y"
    { double x1,x2; VERIFY_TYPE((yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant)) VERIFY_TYPE((yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant)) (yyval.variant)=(yyvsp[(1) - (3)].variant); (yyval.variant)->stringValue= strdup( anytype_to_string<double>(fmod(string_to_anytype<double>((yyval.variant)->stringValue,x1),string_to_anytype<double>((yyvsp[(3) - (3)].variant)->stringValue,x2))).c_str() ); delete (yyvsp[(3) - (3)].variant); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 395 "../../../src/misc/CNestedDataFile/cfg.y"
    { (yyval.variant)=(yyvsp[(1) - (1)].variant); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 396 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),+) }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 397 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),-) }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 402 "../../../src/misc/CNestedDataFile/cfg.y"
    { (yyval.variant)=(yyvsp[(1) - (1)].variant); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 403 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),<=) }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 404 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),>=) }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 405 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),<) }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 406 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),>) }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 410 "../../../src/misc/CNestedDataFile/cfg.y"
    { (yyval.variant)=(yyvsp[(1) - (1)].variant); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 411 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),==) }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 412 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),!=) }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 416 "../../../src/misc/CNestedDataFile/cfg.y"
    { (yyval.variant)=(yyvsp[(1) - (1)].variant); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 417 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),&&) }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 421 "../../../src/misc/CNestedDataFile/cfg.y"
    { (yyval.variant)=(yyvsp[(1) - (1)].variant); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 422 "../../../src/misc/CNestedDataFile/cfg.y"
    { BINARY_EXPR((yyval.variant),(yylsp[(1) - (3)]),(yyvsp[(1) - (3)].variant),(yylsp[(3) - (3)]),(yyvsp[(3) - (3)].variant),||) }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 427 "../../../src/misc/CNestedDataFile/cfg.y"
    { (yyval.variant)=(yyvsp[(1) - (1)].variant); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 428 "../../../src/misc/CNestedDataFile/cfg.y"
    { double x; VERIFY_TYPE((yylsp[(1) - (5)]),(yyvsp[(1) - (5)].variant)) (yyval.variant)=(string_to_anytype<double>((yyvsp[(1) - (5)].variant)->stringValue,x) ? ((delete (yyvsp[(5) - (5)].variant)),(yyvsp[(3) - (5)].variant)) : ((delete (yyvsp[(3) - (5)].variant)),(yyvsp[(5) - (5)].variant))); delete (yyvsp[(1) - (5)].variant); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 433 "../../../src/misc/CNestedDataFile/cfg.y"
    { (yyval.variant)=(yyvsp[(1) - (1)].variant); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 440 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.stringValue)=(yyvsp[(1) - (1)].stringValue);
	}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 444 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		(yyval.stringValue)=(char *)realloc((yyval.stringValue),strlen((yyval.stringValue))+1+strlen((yyvsp[(3) - (3)].stringValue))+1);
		strcat((yyval.stringValue),CNestedDataFile::delim.c_str());
		strcat((yyval.stringValue),(yyvsp[(3) - (3)].stringValue));

		free((yyvsp[(3) - (3)].stringValue));
	}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 458 "../../../src/misc/CNestedDataFile/cfg.y"
    {}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 459 "../../../src/misc/CNestedDataFile/cfg.y"
    {}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 460 "../../../src/misc/CNestedDataFile/cfg.y"
    { YYABORT; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 465 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		CNestedDataFile::s2at_return_value.push_back((yyvsp[(1) - (1)].variant)->stringValue);
		delete (yyvsp[(1) - (1)].variant);
	}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 470 "../../../src/misc/CNestedDataFile/cfg.y"
    {
		CNestedDataFile::s2at_return_value.push_back((yyvsp[(3) - (3)].variant)->stringValue);
		delete (yyvsp[(3) - (3)].variant);
	}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 478 "../../../src/misc/CNestedDataFile/cfg.y"
    { (yyval.variant)=(yyvsp[(1) - (1)].variant); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 479 "../../../src/misc/CNestedDataFile/cfg.y"
    { YYABORT; }
    break;



/* Line 1806 of yacc.c  */
#line 2167 "cfg.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
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






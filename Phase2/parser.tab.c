
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

    //INCLUDES
    #include <stdio.h>
    #include "compiler.h"
    #include <stdbool.h>
    //----------------------------------------------
    //Function Prototypes
    extern void export_symbol_table();
    extern void log_errors(int, int);
    extern void check_unused();
    //----------------------------------------------
    node *construct_operation_node(int oper, int nops, ...);
    node *construct_identifier_node(char*, int = -1, int = -1);
    node *construct_constant_node(int, int, ...);
    //----------------------------------------------

    void free_node(node *p);
    int execute(node *p, int = -1, int = -1, int = 0, ...);

    //----------------------------------------------
    int yylex(void);
    void yyerror(const char *emsg);
    extern int line;


/* Line 189 of yacc.c  */
#line 99 "parser.tab.c"

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
     INTEGER = 258,
     FLOAT = 259,
     BOOL = 260,
     STRING = 261,
     VARIABLE = 262,
     IF = 263,
     SWITCH = 264,
     CASE = 265,
     DEFAULT = 266,
     FOR = 267,
     WHILE = 268,
     DO = 269,
     BREAK = 270,
     CONTINUE = 271,
     CONST = 272,
     INT_TYPE = 273,
     FLOAT_TYPE = 274,
     BOOL_TYPE = 275,
     STRING_TYPE = 276,
     VOID_TYPE = 277,
     FUNCTION = 278,
     PRINT = 279,
     RETURN = 280,
     IFX = 281,
     ELSE = 282,
     ENDLINE = 283,
     OR = 284,
     AND = 285,
     NOTEQUAL = 286,
     EQUAL = 287,
     LESS_EQUAL = 288,
     GREATER_EQUAL = 289,
     NOT = 290,
     NEGATIVE = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 32 "parser.y"

    int iVal;              /*   integer       */
    float fVal;            /*   float         */
    bool bVal;             /*   boolean       */
    char *strVal;          /*   string        */

    char *varName;         /*   variable      */

    char *sIdx;            /*   symbol table  */

    node *n;               /*   node          */



/* Line 214 of yacc.c  */
#line 186 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 198 "parser.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   473

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    45,    40,    38,     2,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    46,
      32,    29,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    30,    31,    34,    35,    36,    37,
      42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      20,    22,    24,    26,    28,    30,    32,    35,    39,    41,
      43,    45,    48,    52,    57,    63,    65,    69,    71,    73,
      75,    77,    82,    94,   102,   111,   119,   131,   139,   148,
     155,   162,   168,   172,   174,   176,   178,   180,   182,   185,
     189,   193,   197,   201,   205,   209,   213,   217,   221,   225,
     229,   233
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    -1,    52,    53,    -1,    -1,    28,
      -1,    67,    -1,    55,    -1,    56,    -1,    24,    67,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      59,    -1,    25,    28,    -1,    25,    67,    28,    -1,    15,
      -1,    16,    -1,    53,    -1,    54,    53,    -1,     7,    29,
      57,    -1,    58,     7,    29,    57,    -1,    17,    58,     7,
      29,    57,    -1,    67,    -1,     7,    29,    57,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    23,    44,    67,
      45,    -1,    12,    44,    56,    46,    67,    46,    55,    45,
      47,    54,    48,    -1,    13,    44,    67,    45,    47,    54,
      48,    -1,    14,    47,    54,    48,    13,    44,    67,    45,
      -1,     8,    44,    67,    45,    47,    54,    48,    -1,     8,
      44,    67,    45,    47,    54,    48,    27,    47,    54,    48,
      -1,     9,    44,     7,    45,    47,    65,    48,    -1,     9,
      44,     7,    45,    47,    65,    66,    48,    -1,    10,     3,
      49,    53,    15,    65,    -1,    10,     5,    49,    53,    15,
      65,    -1,    10,     3,    49,    53,    15,    -1,    11,    49,
      53,    -1,     3,    -1,     4,    -1,     6,    -1,     5,    -1,
       7,    -1,    42,    67,    -1,    67,    38,    67,    -1,    67,
      39,    67,    -1,    67,    40,    67,    -1,    67,    41,    67,
      -1,    67,    32,    67,    -1,    67,    33,    67,    -1,    67,
      31,    67,    -1,    67,    30,    67,    -1,    67,    37,    67,
      -1,    67,    36,    67,    -1,    67,    35,    67,    -1,    67,
      34,    67,    -1,    44,    67,    45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   113,   113,   116,   117,   120,   121,   123,   124,   126,
     129,   130,   131,   133,   134,   135,   138,   139,   141,   142,
     146,   147,   150,   153,   154,   157,   158,   162,   163,   164,
     165,   169,   174,   177,   181,   185,   186,   189,   190,   193,
     194,   195,   198,   204,   205,   206,   207,   208,   211,   213,
     214,   215,   216,   217,   218,   221,   222,   223,   224,   225,
     226,   227
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT", "BOOL", "STRING",
  "VARIABLE", "IF", "SWITCH", "CASE", "DEFAULT", "FOR", "WHILE", "DO",
  "BREAK", "CONTINUE", "CONST", "INT_TYPE", "FLOAT_TYPE", "BOOL_TYPE",
  "STRING_TYPE", "VOID_TYPE", "FUNCTION", "PRINT", "RETURN", "IFX", "ELSE",
  "ENDLINE", "'='", "OR", "AND", "'<'", "'>'", "NOTEQUAL", "EQUAL",
  "LESS_EQUAL", "GREATER_EQUAL", "'+'", "'-'", "'*'", "'/'", "NOT",
  "NEGATIVE", "'('", "')'", "';'", "'{'", "'}'", "':'", "$accept",
  "program", "functions", "statement", "statement_list",
  "assignment_statement", "declaration_statement",
  "nested_rhs_assignment_statement", "data_type", "function_call",
  "for_statement", "while_statement", "do_while_statement", "if_statement",
  "switch_statement", "cases", "default_statement", "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    61,
     284,   285,    60,    62,   286,   287,   288,   289,    43,    45,
      42,    47,   290,   291,    40,    41,    59,   123,   125,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    55,    56,    56,    57,    57,    58,    58,    58,
      58,    59,    60,    61,    62,    63,    63,    64,    64,    65,
      65,    65,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     1,
       1,     2,     3,     4,     5,     1,     3,     1,     1,     1,
       1,     4,    11,     7,     8,     7,    11,     7,     8,     6,
       6,     5,     3,     1,     1,     1,     1,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    43,    44,    46,    45,    47,     0,
       0,     0,     0,     0,    18,    19,     0,    27,    28,    29,
      30,     0,     0,     0,     5,     0,     0,     3,     7,     8,
       0,    15,    10,    11,    12,    13,    14,     6,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     9,    16,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    22,    25,     0,     0,
       0,     0,    20,     0,     0,     0,    17,    61,     0,    56,
      55,    53,    54,    60,    59,    58,    57,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,    21,     0,    31,
      23,    26,     0,     0,     0,     0,     0,    24,     0,     0,
       0,     0,     0,     0,    35,     0,     0,     0,    37,     0,
       0,     0,    33,     0,     0,     0,     0,     0,    38,     0,
      34,     0,     0,     0,    42,     0,     0,    41,     0,     0,
      36,    39,    40,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    72,    73,    28,    29,    66,    30,    31,
      32,    33,    34,    35,    36,   110,   119,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
     -80,    19,   365,   -80,   -80,   -80,   -80,   -80,   -26,   -14,
       0,     7,    12,   -24,   -80,   -80,    84,   -80,   -80,   -80,
     -80,    16,     8,     3,   -80,     8,     8,   -80,   -80,   -80,
      55,   -80,   -80,   -80,   -80,   -80,   -80,   180,    22,     8,
      56,    80,     8,   365,    58,     8,   -80,   180,   -80,   134,
     -80,    81,    38,     8,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,    40,   -80,   180,   380,    27,
      28,   396,   -80,   135,    47,   412,   -80,   -80,    22,   225,
     270,    89,    89,    89,    89,    89,    89,    14,    14,   -80,
     -80,    22,    31,    46,     8,    48,    94,   -80,    22,   -80,
     -80,   -80,   365,    98,    50,   365,    65,   -80,   181,    17,
       5,    87,   227,     8,   104,    83,    86,    96,   -80,    85,
     -26,    91,   -80,   428,    99,   365,   365,   365,   -80,   110,
     -80,   365,   146,   161,   -80,   365,   273,    98,    98,   319,
     -80,   -80,   -80,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,    -2,   -56,    67,   139,   -30,   165,   -80,
     -80,   -80,   -80,   -80,   -80,   -79,   -80,   -21
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      27,    47,    49,    38,    50,    51,     4,     5,     6,     7,
      46,     4,     5,     6,     7,    46,   117,    67,    68,     3,
     115,    71,   116,    43,    75,     4,     5,     6,     7,    65,
      39,    48,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    40,    25,   108,    26,   100,   112,
      25,    41,    26,   118,    63,    64,    42,    67,   141,   142,
      45,   101,    52,    69,    25,    74,    26,    78,   107,    91,
      67,    97,    93,   104,    94,   136,    98,    67,   102,   139,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   123,   103,   120,   105,   111,    16,    17,    18,
      19,    20,    17,    18,    19,    20,    97,   106,   109,   113,
      97,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   132,   133,   134,    77,    61,    62,    63,
      64,   124,   125,   128,    97,   126,   129,    97,     4,     5,
       6,     7,     8,     9,    10,   127,   131,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   135,    21,    22,
      23,   137,    76,    24,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   138,    25,   121,    26,
      70,    44,     0,    96,     4,     5,     6,     7,     8,     9,
      10,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    21,    22,    23,     0,     0,    24,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    25,     0,    26,     0,     0,     0,   114,
       4,     5,     6,     7,     8,     9,    10,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
      21,    22,    23,     0,     0,    24,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,    25,
       0,    26,     0,     0,     0,   122,     4,     5,     6,     7,
       8,     9,    10,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,     0,
       0,    24,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,    25,     0,    26,     0,     0,
       0,   140,     4,     5,     6,     7,     8,     9,    10,     0,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,    21,    22,    23,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    26,     0,     0,     0,   143,     4,     5,
       6,     7,     8,     9,    10,     0,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
      23,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,    26,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,    92,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,    95,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,    99,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,   130
};

static const yytype_int16 yycheck[] =
{
       2,    22,    23,    29,    25,    26,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    11,    38,    39,     0,
       3,    42,     5,    47,    45,     3,     4,     5,     6,     7,
      44,    28,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    44,    42,   102,    44,    78,   105,
      42,    44,    44,    48,    40,    41,    44,    78,   137,   138,
      44,    91,     7,     7,    42,     7,    44,    29,    98,    29,
      91,    73,    45,    94,    46,   131,    29,    98,    47,   135,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,   113,    47,     7,    47,    46,    17,    18,    19,
      20,    21,    18,    19,    20,    21,   108,    13,    10,    44,
     112,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   125,   126,   127,    45,    38,    39,    40,
      41,    27,    49,    48,   136,    49,    45,   139,     3,     4,
       5,     6,     7,     8,     9,    49,    47,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    47,    23,    24,
      25,    15,    28,    28,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    15,    42,   111,    44,
      41,    16,    -1,    48,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    -1,    -1,    28,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    -1,    -1,    28,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    42,
      -1,    44,    -1,    -1,    -1,    48,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      -1,    28,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    42,    -1,    44,    -1,    -1,
      -1,    48,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    44,    -1,    -1,    -1,    48,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    45,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    45,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    45,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    52,     0,     3,     4,     5,     6,     7,     8,
       9,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    23,    24,    25,    28,    42,    44,    53,    55,    56,
      58,    59,    60,    61,    62,    63,    64,    67,    29,    44,
      44,    44,    44,    47,    58,    44,     7,    67,    28,    67,
      67,    67,     7,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     7,    57,    67,    67,     7,
      56,    67,    53,    54,     7,    67,    28,    45,    29,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    29,    45,    45,    46,    45,    48,    53,    29,    45,
      57,    57,    47,    47,    67,    47,    13,    57,    54,    10,
      65,    46,    54,    44,    48,     3,     5,    11,    48,    66,
       7,    55,    48,    67,    27,    49,    49,    49,    48,    45,
      45,    47,    53,    53,    53,    47,    54,    15,    15,    54,
      48,    65,    65,    48
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
# if YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    { /*last thing to finish*/check_unused();;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {execute((yyvsp[(2) - (2)].n)); free_node((yyvsp[(2) - (2)].n)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {(yyval.n)=NULL;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {std::cout<<"Endline "<<std::endl;(yyval.n) = construct_operation_node(ENDLINE,1, NULL,NULL);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {std::cout<<"expression "<<std::endl; (yyval.n)=(yyvsp[(1) - (1)].n);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {std::cout<<"assignment_statement "<<std::endl;   (yyval.n)=(yyvsp[(1) - (1)].n);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {std::cout<<"declaration_statement "<<std::endl;  (yyval.n)=(yyvsp[(1) - (1)].n);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {std::cout<<"PRINT EXP "<<std::endl;  (yyval.n)=construct_operation_node(PRINT,1,(yyvsp[(2) - (2)].n));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {std::cout<<"for_statement "<<std::endl;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {std::cout<<"while_statement "<<std::endl;    (yyval.n)=(yyvsp[(1) - (1)].n);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {std::cout<<"do_while_statement "<<std::endl; (yyval.n)=(yyvsp[(1) - (1)].n);}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {std::cout<<"if_statement "<<std::endl;(yyval.n)=(yyvsp[(1) - (1)].n);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {std::cout<<"switch_statement "<<std::endl;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {std::cout<<"function_call "<<std::endl;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {std::cout<<"RETURN "<<std::endl;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {std::cout<<"RETURN EXP "<<std::endl;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {std::cout<<"BREAK "<<std::endl;  construct_operation_node(BREAK,1,NULL);}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {std::cout<<"CONTINUE "<<std::endl; construct_operation_node(CONTINUE,1,NULL);}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    {(yyval.n)=(yyvsp[(1) - (1)].n);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {(yyval.n)=construct_operation_node(ENDLINE,2,(yyvsp[(1) - (2)].n),(yyvsp[(2) - (2)].n));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {(yyval.n) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(1) - (3)].sIdx)),(yyvsp[(3) - (3)].n));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { (yyval.n) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(2) - (4)].sIdx), (yyvsp[(1) - (4)].iVal)), (yyvsp[(4) - (4)].n));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { (yyval.n) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(3) - (5)].sIdx), (yyvsp[(2) - (5)].iVal), CONST), (yyvsp[(5) - (5)].n));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {(yyval.n)=(yyvsp[(1) - (1)].n);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {(yyval.n)=construct_operation_node('=',2,construct_identifier_node((yyvsp[(1) - (3)].sIdx)),(yyvsp[(3) - (3)].n));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {(yyval.iVal)=INT_TYPE;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {(yyval.iVal)=FLOAT_TYPE;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {(yyval.iVal)=BOOL_TYPE;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {(yyval.iVal)=STRING_TYPE;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    {std::cout<<"for_statement "<<std::endl; (yyval.n) = construct_operation_node(FOR, 4, (yyvsp[(3) - (11)].n), (yyvsp[(5) - (11)].n), (yyvsp[(7) - (11)].n), (yyvsp[(10) - (11)].n));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {std::cout<<"while_statement "<<std::endl; (yyval.n)=construct_operation_node(WHILE,2,(yyvsp[(3) - (7)].n),(yyvsp[(6) - (7)].n));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {std::cout<<"do_while_statement" <<std::endl; (yyval.n)=construct_operation_node(DO,2,(yyvsp[(3) - (8)].n),(yyvsp[(7) - (8)].n));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {(yyval.n)=construct_operation_node(IF,2,(yyvsp[(3) - (7)].n),(yyvsp[(6) - (7)].n));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    {(yyval.n)=construct_operation_node(IF,3,(yyvsp[(3) - (11)].n),(yyvsp[(6) - (11)].n),(yyvsp[(10) - (11)].n));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {(yyval.n)=construct_operation_node(SWITCH,2,construct_identifier_node((yyvsp[(3) - (7)].sIdx)),(yyvsp[(6) - (7)].n));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {(yyval.n)=construct_operation_node(SWITCH,3,construct_identifier_node((yyvsp[(3) - (8)].sIdx)),(yyvsp[(6) - (8)].n),(yyvsp[(7) - (8)].n));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {(yyval.n)=construct_operation_node(CASE,4,construct_constant_node(INTEGER,INT_TYPE,(yyvsp[(2) - (6)].iVal)),(yyvsp[(4) - (6)].n),construct_operation_node(BREAK,0),(yyvsp[(6) - (6)].n));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {(yyval.n)=construct_operation_node(CASE,3,construct_constant_node(INTEGER,INT_TYPE,(yyvsp[(2) - (5)].iVal)),(yyvsp[(4) - (5)].n),construct_operation_node(BREAK,0));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {(yyval.n)=construct_operation_node(DEFAULT,1,(yyvsp[(3) - (3)].n));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {(yyval.n) = construct_constant_node( INTEGER, INT_TYPE,(yyvsp[(1) - (1)].iVal));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {(yyval.n) = construct_constant_node( FLOAT, FLOAT_TYPE,(yyvsp[(1) - (1)].fVal));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {(yyval.n) =  construct_constant_node( STRING, STRING_TYPE,(yyvsp[(1) - (1)].strVal));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {(yyval.n) =  construct_constant_node( BOOL, BOOL_TYPE,(yyvsp[(1) - (1)].bVal));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {(yyval.n) = construct_identifier_node((yyvsp[(1) - (1)].sIdx));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {(yyval.n)=construct_operation_node(NOT,2,(yyvsp[(2) - (2)].n));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {(yyval.n)=construct_operation_node('+',2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {(yyval.n)=construct_operation_node('-',2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {(yyval.n)=construct_operation_node('*',2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {(yyval.n)=construct_operation_node('/',2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {(yyval.n)=construct_operation_node('<',2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {(yyval.n)=construct_operation_node('>',2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {(yyval.n)=construct_operation_node(AND,2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {(yyval.n)=construct_operation_node(OR,2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {(yyval.n)=construct_operation_node(GREATER_EQUAL,2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {(yyval.n)=construct_operation_node(LESS_EQUAL,2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    {(yyval.n)=construct_operation_node(EQUAL,2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    {(yyval.n)=construct_operation_node(NOTEQUAL,2,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    {(yyval.n)=(yyvsp[(2) - (3)].n);}
    break;



/* Line 1455 of yacc.c  */
#line 1998 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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



/* Line 1675 of yacc.c  */
#line 230 "parser.y"

/* End of Production Rules */


/* Part 5 : Functions and Main */
node *construct_constant_node(int type, int dataType, ...) {
     va_list ap; /* variable argument list */
     node *p;
     size_t nodeSize;

     /* allocate Node */
     nodeSize = NODESIZE + sizeof(constantNode);
     if ((p = (node*)malloc(nodeSize)) == NULL)
     {
         yyerror("out of memory");
     }

     /* copy information */
     p->type = CONSTANT;
     p->con.dataType = dataType;
     va_start(ap, dataType); /* initialize va */
     p->con.value = va_arg(ap, valueType); /* get value */
     va_end(ap); /* clean up va */

     return p;
}

/* node *construct_value_node(int dataType, int intValue, float floatValue, bool boolValue,char *stringValue, bool isConstant, char *name = NULL) { */

  
    /* node *p; */

    /* allocate node */
    /* if ((p = (node *)malloc(sizeof(node))) == NULL)
        yyerror("out of memory"); */

   
    /* if(isConstant)
    { */
        /* copy information if VALUE */
          /* p->type = CONST;
          p->con.dataType=dataType;
          p->con.name=name;

          switch (dataType)
          {
            
            case INTEGER:
              p->con.value.intValue = intValue;
              break;

            case FLOAT:
              p->con.value.floatValue = floatValue;
              break;
            
            case BOOL:
              p->con.value.boolValue = boolValue;
              break;

            case STRING:
              p->con.value.stringValue = stringValue;
              break;

          } */
    /* }
    else
    { */
         /* copy information if VALUE */
          /* p->type = VALUE;
          p->value.type=dataType;
          switch (dataType)
          {
            
            case INTEGER:
              p->value.intValue = intValue;
              break;

            case FLOAT:
              p->value.floatValue = floatValue;
              break;
            
            case BOOL:
              p->value.boolValue = boolValue;
              break;

            case STRING:
              p->value.stringValue = stringValue;
              break;

          }
    } */

    

    /* return p;
} */

node *construct_operation_node(int oper, int nOpers, ...) {
  va_list ap; /* variable argument list */
  node *p;
  size_t nodeSize;
  int i = 0;
  
  nodeSize = NODESIZE + sizeof(opNode) +
    (nOpers - 1) * sizeof(node*);
  if ((p = (node*)malloc(nodeSize)) == NULL)
  {
    yyerror("out of memory");
  }

  /* copy information */
  p->type = OP;
  p->opr.oper = oper;
  p->opr.nops = nOpers;

  va_start(ap, nOpers);
  for (i = 0; i < nOpers; i++)
  {
    p->opr.op[i] = va_arg(ap, node*);
  }
  va_end(ap);
  return p;
}

node *construct_identifier_node(char* i, int dataType, int qualifier) {
  node *p;
  size_t nodeSize;
  nodeSize = NODESIZE + sizeof(idNode);
  if ((p = (node*)malloc(nodeSize)) == NULL)
    yyerror("out of memory");

  /* copy information */
  p->type = ID;
  p->id.name = strdup(i);
  p->id.dataType = dataType;
  p->id.qualifier = qualifier;
  return p;
}

void free_node(node *p) {
  int i;

  if (!p) /* nothing to free */
  {
    return; 
  }
  if (p->type == OP) /* free sub-nodes */
  {
    for (i = 0; i < p->opr.nops; i++)
      free_node(p->opr.op[i]);
  }
  free (p);
}

int main(void)
{
    
    yyparse();
    export_symbol_table();
    return 0;
}

void yyerror(const char *emsg) {

  log_errors(6,line);
  fprintf(stderr, "Syntax Error in Line %d: %s\n", line, emsg);
  export_symbol_table();
  exit(0);
}

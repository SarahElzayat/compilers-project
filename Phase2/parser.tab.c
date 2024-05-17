
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
    extern void log_symbol_table();
    extern void log_errors(int,const char *);
    extern void check_unused();
    //----------------------------------------------
    Node *construct_operation_node(int oper, int nops, ...);
    Node *construct_identifier_node(char*, int = -1, int = -1);
    Node *construct_constant_node(int, int, ...);
    //----------------------------------------------

    void free_node(Node *p);
    int execute_all(Node *p, int = -1, int = -1, int = 0, ...);

    //----------------------------------------------
    int yylex(void);
    void yyerror(const char *emsg);
    extern int line;
    //----------------------------------------------


/* Line 189 of yacc.c  */
#line 101 "parser.tab.c"

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
     STRING = 260,
     BOOL = 261,
     VARIABLE = 262,
     IF = 263,
     SWITCH = 264,
     CASE = 265,
     DEFAULT = 266,
     SWITCH_BODY = 267,
     FOR = 268,
     WHILE = 269,
     DO = 270,
     REPEAT = 271,
     BREAK = 272,
     CONTINUE = 273,
     CONST = 274,
     INT_TYPE = 275,
     FLOAT_TYPE = 276,
     BOOL_TYPE = 277,
     STRING_TYPE = 278,
     VOID_TYPE = 279,
     DECLARE_ONLY = 280,
     FUNCTION = 281,
     PRINT = 282,
     RETURN = 283,
     BLOCK = 284,
     IFX = 285,
     ELSE = 286,
     FUNC = 287,
     OR = 288,
     AND = 289,
     NOT_EQUAL = 290,
     EQUAL = 291,
     LESS_EQUAL = 292,
     GREATER_EQUAL = 293,
     NOT = 294,
     NEGATIVE = 295
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 30 "parser.y"

  int intValue;                          /* integer  */
  float floatValue;                      /* double   */
  char* stringValue;                     /* string   */
  bool boolValue;                        /* boolean  */

  char *sIndex;                       /* symbol table index */
  char *varType;                      /* variable type      */
  Node *nodePtr;                      /*   node             */



/* Line 214 of yacc.c  */
#line 190 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 202 "parser.tab.c"

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
#define YYLAST   600

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    46,     2,     2,
      52,    53,    44,    42,    54,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    49,
      37,    33,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    34,    35,
      38,    39,    40,    41,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    14,    18,    21,
      24,    26,    28,    30,    32,    34,    36,    38,    40,    44,
      47,    50,    60,    64,    66,    67,    73,    76,    80,    82,
      83,    89,    95,   107,   115,   127,   135,   137,   140,   146,
     152,   153,   157,   159,   160,   161,   164,   166,   168,   172,
     176,   177,   179,   182,   187,   193,   195,   197,   199,   201,
     203,   204,   206,   208,   212,   218,   220,   223,   225,   227,
     229,   231,   233,   236,   239,   243,   247,   251,   255,   259,
     263,   267,   271,   275,   279,   283,   287,   291
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    -1,    58,    59,    -1,    -1,    49,
      -1,    82,    49,    -1,    27,    82,    49,    -1,    75,    49,
      -1,    77,    49,    -1,    65,    -1,    66,    -1,    67,    -1,
      62,    -1,    60,    -1,    63,    -1,    68,    -1,    69,    -1,
      50,    81,    51,    -1,    17,    49,    -1,    18,    49,    -1,
      26,    77,    52,    61,    53,    50,    59,    63,    51,    -1,
      77,    54,    61,    -1,    77,    -1,    -1,     7,    52,    64,
      53,    49,    -1,    28,    59,    -1,    82,    54,    64,    -1,
      82,    -1,    -1,    14,    52,    82,    53,    59,    -1,    15,
      81,    16,    82,    49,    -1,    13,    52,    79,    49,    74,
      49,    76,    53,    50,    81,    51,    -1,     8,    52,    82,
      53,    50,    81,    51,    -1,     8,    52,    82,    53,    50,
      81,    51,    31,    50,    81,    51,    -1,     9,    52,    82,
      53,    50,    70,    51,    -1,    71,    -1,    71,    72,    -1,
      10,     3,    55,    73,    71,    -1,    10,     6,    55,    73,
      71,    -1,    -1,    11,    55,    73,    -1,    81,    -1,    -1,
      -1,    27,    82,    -1,    77,    -1,    82,    -1,     7,    33,
      62,    -1,     7,    33,    80,    -1,    -1,    75,    -1,    78,
       7,    -1,    78,     7,    33,    80,    -1,    19,    78,     7,
      33,    80,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,    -1,    77,    -1,    82,    -1,     7,    33,
      80,    -1,    52,     7,    33,    80,    53,    -1,    59,    -1,
      81,    59,    -1,     3,    -1,     4,    -1,     5,    -1,     7,
      -1,     6,    -1,    43,    82,    -1,    47,    82,    -1,    82,
      42,    82,    -1,    82,    43,    82,    -1,    82,    44,    82,
      -1,    82,    45,    82,    -1,    82,    46,    82,    -1,    82,
      37,    82,    -1,    82,    36,    82,    -1,    82,    41,    82,
      -1,    82,    40,    82,    -1,    82,    38,    82,    -1,    82,
      39,    82,    -1,    82,    35,    82,    -1,    82,    34,    82,
      -1,    52,    82,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   105,   105,   108,   109,   113,   114,   115,   117,   118,
     120,   121,   122,   124,   125,   126,   128,   129,   130,   131,
     132,   136,   138,   139,   140,   143,   146,   149,   150,   151,
     155,   158,   161,   165,   166,   169,   173,   174,   178,   179,
     180,   184,   188,   189,   193,   194,   195,   196,   199,   200,
     204,   205,   208,   209,   210,   213,   214,   215,   216,   217,
     221,   222,   225,   226,   227,   230,   231,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT", "STRING", "BOOL",
  "VARIABLE", "IF", "SWITCH", "CASE", "DEFAULT", "SWITCH_BODY", "FOR",
  "WHILE", "DO", "REPEAT", "BREAK", "CONTINUE", "CONST", "INT_TYPE",
  "FLOAT_TYPE", "BOOL_TYPE", "STRING_TYPE", "VOID_TYPE", "DECLARE_ONLY",
  "FUNCTION", "PRINT", "RETURN", "BLOCK", "IFX", "ELSE", "FUNC", "'='",
  "OR", "AND", "'>'", "'<'", "NOT_EQUAL", "EQUAL", "LESS_EQUAL",
  "GREATER_EQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "NOT", "NEGATIVE",
  "';'", "'{'", "'}'", "'('", "')'", "','", "':'", "$accept", "program",
  "functions", "statement", "function_declaration", "parameter_list",
  "function_call", "return_statement", "comma_expressions",
  "while_statement", "do_while_statement", "for_statement", "if_statement",
  "switch_statement", "switch_body", "cases", "default_statement",
  "case_statement", "for_mid_stmt", "assignment_statement",
  "for_assignment", "declaration_statement", "data_type",
  "for_declaration", "rhs_nested_expression", "statement_list",
  "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    61,   288,   289,    62,    60,   290,   291,
     292,   293,    43,    45,    42,    47,    37,   294,   295,    59,
     123,   125,    40,    41,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    61,    61,    61,    62,    63,    64,    64,    64,
      65,    66,    67,    68,    68,    69,    70,    70,    71,    71,
      71,    72,    73,    73,    74,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    78,    78,    78,    78,    78,
      79,    79,    80,    80,    80,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       2,     9,     3,     1,     0,     5,     2,     3,     1,     0,
       5,     5,    11,     7,    11,     7,     1,     2,     5,     5,
       0,     3,     1,     0,     0,     2,     1,     1,     3,     3,
       0,     1,     2,     4,     5,     1,     1,     1,     1,     1,
       0,     1,     1,     3,     5,     1,     2,     1,     1,     1,
       1,     1,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    67,    68,    69,    71,    70,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     5,     0,     0,
       3,    14,    13,    15,    10,    11,    12,    16,    17,     0,
       0,     0,     0,     0,    29,     0,     0,    60,     0,    65,
       0,    19,    20,     0,     0,    70,     0,    26,    72,    73,
       0,     0,     8,     9,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,    70,
       0,    48,    49,    62,     0,    28,     0,     0,    61,     0,
       0,     0,    66,     0,    24,     7,    18,    87,     0,    86,
      85,    80,    79,    83,    84,    82,    81,    74,    75,    76,
      77,    78,     0,    70,     0,    29,     0,     0,    44,     0,
       0,     0,     0,    23,    70,    53,    63,     0,    25,    27,
       0,    40,     0,     0,    46,    47,    30,    31,    54,     0,
      24,     0,     0,     0,     0,    36,    45,    50,     0,    22,
      64,    33,     0,     0,    35,     0,    37,     0,    51,     0,
       0,     0,    43,    43,    43,     0,     0,     0,    40,    42,
      40,    41,     0,    21,     0,    38,    39,     0,    34,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    49,    31,   122,    32,    33,    84,    34,
      35,    36,    37,    38,   144,   145,   156,   168,   133,    39,
     159,    40,    41,    89,    82,   169,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -164
static const yytype_int16 yypact[] =
{
    -164,    19,   423,  -164,  -164,  -164,  -164,  -164,   -29,   -23,
     -22,   -10,     3,   423,     7,    10,   129,  -164,  -164,  -164,
    -164,  -164,   -11,    85,   423,    85,    85,  -164,   423,    85,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,    27,
      29,    40,   483,    96,    85,    85,    85,   -11,    85,  -164,
     173,  -164,  -164,    72,    28,  -164,   499,  -164,  -164,  -164,
     223,   318,  -164,  -164,    48,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,  -164,   -27,
     159,  -164,  -164,   531,    31,   442,   368,   418,  -164,    34,
     463,    85,  -164,    52,   -11,  -164,  -164,  -164,   255,   543,
     554,   210,   210,   210,   210,   210,   210,     0,     0,  -164,
    -164,  -164,   255,    54,    45,    85,    46,    47,    30,   423,
     515,   255,    42,    50,    73,  -164,  -164,   255,  -164,  -164,
     423,    95,    85,    59,  -164,   531,  -164,  -164,  -164,    61,
     -11,    56,   273,    25,    63,   101,   531,   108,   423,  -164,
    -164,    88,    66,    68,  -164,    69,  -164,    92,  -164,    76,
      98,    80,   423,   423,   423,    81,    82,   423,    95,   423,
      95,  -164,   423,  -164,   323,  -164,  -164,   373,  -164,  -164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,    -2,  -164,    -6,    93,   -25,    23,  -164,
    -164,  -164,  -164,  -164,  -164,  -163,  -164,  -149,  -164,    -3,
    -164,   -20,   125,  -164,   -95,   -12,    -5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      30,    50,    54,   125,    43,   175,   112,   176,    16,    17,
      18,    19,    20,    21,   170,   171,    60,   126,    56,     3,
      58,    59,    57,    44,    61,    44,   138,    88,   152,    45,
      46,   153,   141,     4,     5,     6,     7,    55,    83,    85,
      86,    87,    47,    90,    75,    76,    77,    64,    92,    16,
      17,    18,    19,    20,    21,    48,    51,   132,    92,    52,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    25,   123,    61,    62,    26,    63,    93,
      94,    98,    29,   118,   114,   121,   120,   127,     4,     5,
       6,     7,    55,    83,   128,   139,   130,   131,   134,     4,
       5,     6,     7,    79,   140,   143,   112,    83,   147,   150,
      85,   148,   155,   135,   154,   157,    83,   136,   142,   161,
     123,   162,    83,   163,   164,    43,    24,   146,    25,   165,
     167,   172,    26,   173,   149,   166,    81,    29,   129,    25,
      92,    53,     0,    26,   158,     0,   160,     0,    80,    17,
      18,    19,    20,    21,     0,   174,     0,     0,     0,     0,
     177,     0,     4,     5,     6,     7,   113,    92,     0,     0,
       0,     0,    92,     0,     0,    92,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,    91,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
      23,    24,    25,     0,     0,     0,    26,     0,     0,     0,
       0,    29,     0,     0,     0,     0,    25,     0,     0,     0,
      26,     0,    27,    28,     0,    29,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
      23,    24,    73,    74,    75,    76,    77,     0,     4,     5,
       6,     7,   124,     0,     0,     0,    25,     0,     0,     0,
      26,     0,    27,    28,    96,    29,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    25,    22,
      23,    24,    26,     0,     0,     0,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     0,     0,
      26,     0,    27,    28,   151,    29,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
      23,    24,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    25,     0,     0,     0,
      26,    97,    27,    28,   178,    29,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
      23,    24,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    25,     0,     0,     0,
      26,   116,    27,    28,   179,    29,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
      23,    24,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    25,     0,     0,     0,
      26,   117,    27,    28,     0,    29,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,     0,     0,     0,     0,     0,   115,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,     0,     0,     0,     0,     0,   119,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,     0,    78,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,     0,    95,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,   137,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77
};

static const yytype_int16 yycheck[] =
{
       2,    13,    22,    98,    33,   168,    33,   170,    19,    20,
      21,    22,    23,    24,   163,   164,    28,   112,    23,     0,
      25,    26,    24,    52,    29,    52,   121,    47,     3,    52,
      52,     6,   127,     3,     4,     5,     6,     7,    43,    44,
      45,    46,    52,    48,    44,    45,    46,     7,    50,    19,
      20,    21,    22,    23,    24,    52,    49,    27,    60,    49,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    43,    94,    80,    49,    47,    49,     7,
      52,    33,    52,    49,    53,    33,    91,    33,     3,     4,
       5,     6,     7,    98,    49,    53,    50,    50,   118,     3,
       4,     5,     6,     7,    54,    10,    33,   112,    49,    53,
     115,    50,    11,   118,    51,     7,   121,   119,   130,    31,
     140,    55,   127,    55,    55,    33,    28,   132,    43,    53,
      50,    50,    47,    51,   140,   160,    43,    52,   115,    43,
     142,    16,    -1,    47,   147,    -1,   148,    -1,    52,    20,
      21,    22,    23,    24,    -1,   167,    -1,    -1,    -1,    -1,
     172,    -1,     3,     4,     5,     6,     7,   169,    -1,    -1,
      -1,    -1,   174,    -1,    -1,   177,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    43,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      47,    -1,    49,    50,    -1,    52,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    42,    43,    44,    45,    46,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      47,    -1,    49,    50,    51,    52,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    43,    26,
      27,    28,    47,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      47,    -1,    49,    50,    51,    52,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    43,    -1,    -1,    -1,
      47,    53,    49,    50,    51,    52,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    43,    -1,    -1,    -1,
      47,    53,    49,    50,    51,    52,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    43,    -1,    -1,    -1,
      47,    53,    49,    50,    -1,    52,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    49,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    49,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    49,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,     0,     3,     4,     5,     6,     7,     8,
       9,    13,    14,    15,    17,    18,    19,    20,    21,    22,
      23,    24,    26,    27,    28,    43,    47,    49,    50,    52,
      59,    60,    62,    63,    65,    66,    67,    68,    69,    75,
      77,    78,    82,    33,    52,    52,    52,    52,    52,    59,
      81,    49,    49,    78,    77,     7,    82,    59,    82,    82,
      81,    82,    49,    49,     7,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    49,     7,
      52,    62,    80,    82,    64,    82,    82,    82,    77,    79,
      82,    16,    59,     7,    52,    49,    51,    53,    33,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    33,     7,    53,    54,    53,    53,    49,    53,
      82,    33,    61,    77,     7,    80,    80,    33,    49,    64,
      50,    50,    27,    74,    77,    82,    59,    49,    80,    53,
      54,    80,    81,    10,    70,    71,    82,    49,    50,    61,
      53,    51,     3,     6,    51,    11,    72,     7,    75,    76,
      59,    31,    55,    55,    55,    53,    63,    50,    73,    81,
      73,    73,    50,    51,    81,    71,    71,    81,    51,    51
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
#line 105 "parser.y"
    { /*last thing to finish*/ check_unused_variables();;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { execute_all((yyvsp[(2) - (2)].nodePtr)); /*free_node($2);*/ ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {(yyval.nodePtr) = NULL;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    { /*std::cout<<"expression "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (2)].nodePtr); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    { /*std::cout<<"PRINT "<<std::endl;*/(yyval.nodePtr) = construct_operation_node(PRINT, 1, (yyvsp[(2) - (3)].nodePtr)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { /*std::cout<<"assignment_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (2)].nodePtr); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    { /*std::cout<<"declaration_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (2)].nodePtr); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { /*std::cout<<"while_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { /*std::cout<<"do_while_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    { /*std::cout<<"for_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {std::cout<<"function_call "<<std::endl;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {std::cout<<"function_declaration "<<std::endl;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    { /*std::cout<<"return_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    { /*std::cout<<"if_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    { /*std::cout<<"switch_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    { /*std::cout<<"statement_list_block "<<std::endl;*/ (yyval.nodePtr) = construct_operation_node(BLOCK, 1, (yyvsp[(2) - (3)].nodePtr));; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    { /*std::cout<<"BREAK "<<std::endl;*/ (yyval.nodePtr) = construct_operation_node(BREAK, 1, NULL); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    { /*std::cout<<"CONTINUE "<<std::endl;*/(yyval.nodePtr) = construct_operation_node(CONTINUE, 1, NULL); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {(yyval.nodePtr)=construct_operation_node(FUNCTION,4,(yyvsp[(2) - (9)].nodePtr),(yyvsp[(4) - (9)].nodePtr),(yyvsp[(7) - (9)].nodePtr),(yyvsp[(8) - (9)].nodePtr));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {(yyval.nodePtr)=construct_operation_node(COMMA,2,(yyvsp[(1) - (3)].nodePtr),(yyvsp[(3) - (3)].nodePtr));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {(yyval.nodePtr)=(yyvsp[(1) - (1)].nodePtr);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {(yyval.nodePtr)=NULL;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {(yyval.nodePtr)=construct_operation_node(CALL,2,construct_identifier_node((yyvsp[(1) - (5)].sIndex)),(yyvsp[(3) - (5)].nodePtr));}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(RETURN, 1, (yyvsp[(2) - (2)].nodePtr)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(COMMA, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { (yyval.nodePtr) = NULL; ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(WHILE, 2, (yyvsp[(3) - (5)].nodePtr), (yyvsp[(5) - (5)].nodePtr)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(DO, 2, (yyvsp[(2) - (5)].nodePtr), (yyvsp[(4) - (5)].nodePtr)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(FOR, 4, (yyvsp[(3) - (11)].nodePtr), (yyvsp[(5) - (11)].nodePtr), (yyvsp[(7) - (11)].nodePtr), (yyvsp[(10) - (11)].nodePtr)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(IF, 2, (yyvsp[(3) - (7)].nodePtr), (yyvsp[(6) - (7)].nodePtr)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(IF, 3, (yyvsp[(3) - (11)].nodePtr), (yyvsp[(6) - (11)].nodePtr), (yyvsp[(10) - (11)].nodePtr)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(SWITCH, 2, (yyvsp[(3) - (7)].nodePtr), (yyvsp[(6) - (7)].nodePtr)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    { /*$$ = construct_operation_node(SWITCH_BODY, 1, $1);*/ ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    { /*$$ = construct_operation_node(SWITCH_BODY, 2, $1, $2);*/ ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(CASE, 3, construct_constant_node(INTEGER, INT_TYPE, (yyvsp[(2) - (5)].intValue)), (yyvsp[(4) - (5)].nodePtr), (yyvsp[(5) - (5)].nodePtr)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(CASE, 3, construct_constant_node(BOOL, BOOL_TYPE, (yyvsp[(2) - (5)].boolValue)), (yyvsp[(4) - (5)].nodePtr), (yyvsp[(5) - (5)].nodePtr)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(DEFAULT, 1, (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(PRINT, 1, (yyvsp[(2) - (2)].nodePtr)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(1) - (3)].sIndex)), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(1) - (3)].sIndex)), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(DECLARE_ONLY, 1, construct_identifier_node((yyvsp[(2) - (2)].sIndex), (yyvsp[(1) - (2)].intValue))); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(2) - (4)].sIndex), (yyvsp[(1) - (4)].intValue)), (yyvsp[(4) - (4)].nodePtr)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(3) - (5)].sIndex), (yyvsp[(2) - (5)].intValue), CONST), (yyvsp[(5) - (5)].nodePtr)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    { (yyval.intValue) = INT_TYPE ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    { (yyval.intValue) = FLOAT_TYPE ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    { (yyval.intValue) = BOOL_TYPE ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    { (yyval.intValue) = STRING_TYPE ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    { (yyval.intValue) = VOID_TYPE ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(1) - (3)].sIndex)), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(2) - (5)].sIndex)), (yyvsp[(4) - (5)].nodePtr)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, (yyvsp[(1) - (2)].nodePtr), (yyvsp[(2) - (2)].nodePtr)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 235 "parser.y"
    { (yyval.nodePtr) = construct_constant_node(INTEGER, INT_TYPE, (yyvsp[(1) - (1)].intValue)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    { (yyval.nodePtr) = construct_constant_node(FLOAT, FLOAT_TYPE, (yyvsp[(1) - (1)].floatValue)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    { (yyval.nodePtr) = construct_constant_node(STRING, STRING_TYPE, (yyvsp[(1) - (1)].stringValue)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    { (yyval.nodePtr) = construct_identifier_node((yyvsp[(1) - (1)].sIndex)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    { (yyval.nodePtr) = construct_constant_node (BOOL, BOOL_TYPE, (yyvsp[(1) - (1)].boolValue)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(NEGATIVE, 1, (yyvsp[(2) - (2)].nodePtr)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(NOT, 1, (yyvsp[(2) - (2)].nodePtr)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('+', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('-', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('*', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('/', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('%', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('<', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('>', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(GREATER_EQUAL, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(LESS_EQUAL, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(NOT_EQUAL, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(EQUAL, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(AND, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(OR, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(2) - (3)].nodePtr); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2240 "parser.tab.c"
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
#line 258 "parser.y"


Node *construct_constant_node(int type, int dataType, ...) {
  va_list ap;
  Node *p;
  size_t nodeSize;

  /* allocate Node */
  nodeSize = SIZEOFNODE + sizeof(ConstantNode);
  if ((p = (Node*)malloc(nodeSize)) == NULL)
    yyerror("out of memory");

  /* copy information */
  p->type = CONSTANT;
  p->con.dataType = dataType;
  va_start(ap, dataType);
  p->con.value = va_arg(ap, ValueType);
  va_end(ap);

  return p;
}

Node *construct_identifier_node(char* i, int dataType, int qualifier) {
  Node *p;
  size_t nodeSize;
  /* allocate Node */
  nodeSize = SIZEOFNODE + sizeof(IdentifierNode);
  if ((p = (Node*)malloc(nodeSize)) == NULL)
    yyerror("out of memory");

  /* copy information */
  p->type = IDENTIFIER;
  p->id.name = strdup(i);
  p->id.dataType = dataType;
  p->id.qualifier = qualifier;
  return p;
}

Node *construct_operation_node(int oper, int nops, ...) {
  va_list ap;
  Node *p;
  size_t nodeSize;
  int i;
  
  /* allocate Node */
  nodeSize = SIZEOFNODE + sizeof(OperationNode) +
    (nops - 1) * sizeof(Node*);
  if ((p = (Node*)malloc(nodeSize)) == NULL)
    yyerror("out of memory");

  /* copy information */
  p->type = OPERATION;
  p->opr.symbol = oper;
  p->opr.nops = nops;
  va_start(ap, nops);
  for (i = 0; i < nops; i++)
    p->opr.op[i] = va_arg(ap, Node*);
  va_end(ap);
  return p;
}

void free_node(Node *p) {
  int i;

  if (!p) return;
  if (p->type == OPERATION) {
    for (i = 0; i < p->opr.nops; i++)
      free_node(p->opr.op[i]);
  }
  free (p);
}

int main(void) {
  yyparse();
  log_symbol_table();
  return 0;
}


void yyerror(const char *emsg) {

  log_errors(line,emsg);
  fprintf(stderr, "Line %d: %s\n", line, emsg);
  log_symbol_table();
  exit(0);

}

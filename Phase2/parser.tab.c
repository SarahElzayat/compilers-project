
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
     OR = 287,
     AND = 288,
     NOT_EQUAL = 289,
     EQUAL = 290,
     LESS_EQUAL = 291,
     GREATER_EQUAL = 292,
     NOT = 293,
     NEGATIVE = 294
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
#line 189 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 201 "parser.tab.c"

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
#define YYLAST   571

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
      51,    52,    43,    41,     2,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    48,
      36,    32,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    33,    34,    37,
      38,    39,    40,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    14,    18,    21,
      24,    26,    28,    30,    32,    34,    38,    41,    44,    50,
      56,    68,    76,    88,    96,    98,   101,   107,   113,   114,
     118,   120,   121,   122,   125,   127,   129,   133,   134,   136,
     139,   144,   150,   152,   154,   156,   158,   160,   161,   163,
     165,   169,   175,   177,   180,   182,   184,   186,   188,   190,
     193,   196,   200,   204,   208,   212,   216,   220,   224,   228,
     232,   236,   240,   244,   248
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    56,    -1,    56,    57,    -1,    -1,    48,
      -1,    75,    48,    -1,    27,    75,    48,    -1,    68,    48,
      -1,    70,    48,    -1,    58,    -1,    59,    -1,    60,    -1,
      61,    -1,    62,    -1,    49,    74,    50,    -1,    17,    48,
      -1,    18,    48,    -1,    14,    51,    75,    52,    57,    -1,
      15,    74,    16,    75,    48,    -1,    13,    51,    72,    48,
      67,    48,    69,    52,    49,    74,    50,    -1,     8,    51,
      75,    52,    49,    74,    50,    -1,     8,    51,    75,    52,
      49,    74,    50,    31,    49,    74,    50,    -1,     9,    51,
      75,    52,    49,    63,    50,    -1,    64,    -1,    64,    65,
      -1,    10,     3,    53,    66,    64,    -1,    10,     6,    53,
      66,    64,    -1,    -1,    11,    53,    66,    -1,    74,    -1,
      -1,    -1,    27,    75,    -1,    70,    -1,    75,    -1,     7,
      32,    73,    -1,    -1,    68,    -1,    71,     7,    -1,    71,
       7,    32,    73,    -1,    19,    71,     7,    32,    73,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      -1,    70,    -1,    75,    -1,     7,    32,    73,    -1,    51,
       7,    32,    73,    52,    -1,    57,    -1,    74,    57,    -1,
       3,    -1,     4,    -1,     5,    -1,     7,    -1,     6,    -1,
      42,    75,    -1,    46,    75,    -1,    75,    41,    75,    -1,
      75,    42,    75,    -1,    75,    43,    75,    -1,    75,    44,
      75,    -1,    75,    45,    75,    -1,    75,    36,    75,    -1,
      75,    35,    75,    -1,    75,    40,    75,    -1,    75,    39,
      75,    -1,    75,    37,    75,    -1,    75,    38,    75,    -1,
      75,    34,    75,    -1,    75,    33,    75,    -1,    51,    75,
      52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   104,   104,   107,   108,   112,   113,   114,   116,   117,
     119,   120,   121,   123,   124,   125,   126,   127,   141,   144,
     147,   151,   152,   155,   159,   160,   164,   165,   166,   170,
     174,   175,   179,   180,   181,   182,   186,   190,   191,   195,
     196,   197,   200,   201,   202,   203,   204,   208,   209,   213,
     214,   215,   219,   220,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243
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
  "FUNCTION", "PRINT", "RETURN", "BLOCK", "IFX", "ELSE", "'='", "OR",
  "AND", "'>'", "'<'", "NOT_EQUAL", "EQUAL", "LESS_EQUAL", "GREATER_EQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "NOT", "NEGATIVE", "';'", "'{'",
  "'}'", "'('", "')'", "':'", "$accept", "program", "functions",
  "statement", "while_statement", "do_while_statement", "for_statement",
  "if_statement", "switch_statement", "switch_body", "cases",
  "default_statement", "case_statement", "for_mid_stmt",
  "assignment_statement", "for_assignment", "declaration_statement",
  "data_type", "for_declaration", "rhs_nexted_expression",
  "statement_list", "expression", 0
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
     285,   286,    61,   287,   288,    62,    60,   289,   290,   291,
     292,    43,    45,    42,    47,    37,   293,   294,    59,   123,
     125,    40,    41,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    59,
      60,    61,    61,    62,    63,    63,    64,    64,    64,    65,
      66,    66,    67,    67,    67,    67,    68,    69,    69,    70,
      70,    70,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     3,     2,     2,
       1,     1,     1,     1,     1,     3,     2,     2,     5,     5,
      11,     7,    11,     7,     1,     2,     5,     5,     0,     3,
       1,     0,     0,     2,     1,     1,     3,     0,     1,     2,
       4,     5,     1,     1,     1,     1,     1,     0,     1,     1,
       3,     5,     1,     2,     1,     1,     1,     1,     1,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    54,    55,    56,    58,    57,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    43,    44,
      45,    46,     0,     0,     0,     5,     0,     0,     3,    10,
      11,    12,    13,    14,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    52,     0,    16,    17,     0,    57,     0,
      59,    60,     0,     0,     8,     9,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,    57,     0,    36,    49,     0,     0,    48,     0,     0,
       0,    53,     0,     7,    15,    74,     0,    73,    72,    67,
      66,    70,    71,    69,    68,    61,    62,    63,    64,    65,
       0,    57,     0,     0,    32,     0,     0,     0,    40,    50,
       0,     0,    28,     0,     0,    34,    35,    18,    19,    41,
       0,     0,     0,     0,    24,    33,    37,    51,    21,     0,
       0,    23,     0,    25,     0,    38,     0,     0,    31,    31,
      31,     0,     0,    28,    30,    28,    29,     0,     0,    26,
      27,     0,    22,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    43,    29,    30,    31,    32,    33,   123,
     124,   133,   143,   114,    34,   136,    35,    36,    78,    73,
     144,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -137
static const yytype_int16 yypact[] =
{
    -137,    13,   343,  -137,  -137,  -137,  -137,  -137,    -4,   -31,
     -20,   -16,    -3,   343,   -18,     1,    17,  -137,  -137,  -137,
    -137,  -137,   133,   133,   133,  -137,   343,   133,  -137,  -137,
    -137,  -137,  -137,  -137,    16,    27,    69,   455,   228,   133,
     133,   -13,   133,  -137,   147,  -137,  -137,    82,  -137,   471,
    -137,  -137,    64,   371,  -137,  -137,    58,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
    -137,    60,   277,  -137,   503,   395,   415,  -137,    45,   435,
     133,  -137,    63,  -137,  -137,  -137,   228,   515,   526,     2,
       2,     2,     2,     2,     2,   -21,   -21,  -137,  -137,  -137,
     228,    65,    47,    51,   376,   343,   487,   228,  -137,  -137,
     228,   343,    92,   133,    57,  -137,   503,  -137,  -137,  -137,
      56,   196,     9,    59,   100,   503,   109,  -137,    86,    67,
      68,  -137,    70,  -137,    -4,  -137,    66,    73,   343,   343,
     343,    75,   343,    92,   343,    92,  -137,   343,   245,  -137,
    -137,   294,  -137,  -137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,    -2,  -137,  -137,  -137,  -137,  -137,  -137,
    -118,  -137,  -136,  -137,    -1,  -137,   -39,   110,  -137,   -81,
     -12,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      28,    44,    77,   145,   146,   108,    16,    17,    18,    19,
      20,    21,   129,     3,    52,   130,    49,    50,    51,   109,
      39,    53,    67,    68,    69,   149,   119,   150,    38,   120,
      45,    40,    74,    75,    76,    41,    79,    17,    18,    19,
      20,    21,    81,    65,    66,    67,    68,    69,    42,    46,
      81,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    54,   115,    53,     4,     5,     6,
       7,     8,     9,    10,   106,    55,    56,    11,    12,    13,
      74,    14,    15,    16,    17,    18,    19,    20,    21,    82,
      86,    22,   100,   104,    74,   107,   111,   110,   116,   121,
     112,    74,   122,   117,    74,   126,    23,   125,   127,   131,
      24,   132,    25,    26,    84,    27,   134,   137,   141,    81,
     138,   139,   142,   140,   147,   135,    47,     0,     0,     0,
     148,     0,     0,     0,     0,   151,     4,     5,     6,     7,
      48,     0,    81,     0,     0,     0,    81,     0,     0,    81,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      11,    12,    13,    80,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,    22,    23,     0,     0,     0,    24,
       0,     0,     0,     0,    27,     0,     0,     0,     0,    23,
       0,     0,     0,    24,     0,    25,    26,     0,    27,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    11,
      12,    13,     0,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     6,     7,    71,     0,     0,    23,     0,
       0,     0,    24,     0,    25,    26,   128,    27,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    11,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      23,     0,    22,     0,    24,     0,     0,     0,     0,    72,
       4,     5,     6,     7,   101,     0,     0,    23,     0,     0,
       0,    24,     0,    25,    26,   152,    27,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,    12,    13,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    23,
       0,    22,     0,    24,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
      24,     0,    25,    26,   153,    27,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     7,    48,     0,    23,     0,     0,     0,    24,
       0,    25,    26,     0,    27,    16,    17,    18,    19,    20,
      21,     0,     0,   113,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    23,     0,
       0,     0,    24,    85,     0,     0,     0,    27,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,   102,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,   103,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,   105,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,    70,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    83,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,   118,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69
};

static const yytype_int16 yycheck[] =
{
       2,    13,    41,   139,   140,    86,    19,    20,    21,    22,
      23,    24,     3,     0,    26,     6,    22,    23,    24,   100,
      51,    27,    43,    44,    45,   143,   107,   145,    32,   110,
      48,    51,    38,    39,    40,    51,    42,    20,    21,    22,
      23,    24,    44,    41,    42,    43,    44,    45,    51,    48,
      52,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    48,   104,    72,     3,     4,     5,
       6,     7,     8,     9,    80,    48,     7,    13,    14,    15,
      86,    17,    18,    19,    20,    21,    22,    23,    24,     7,
      32,    27,    32,    48,   100,    32,    49,    32,   104,   111,
      49,   107,    10,   105,   110,    48,    42,   113,    52,    50,
      46,    11,    48,    49,    50,    51,     7,    31,    52,   121,
      53,    53,    49,    53,    49,   126,    16,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,   147,     3,     4,     5,     6,
       7,    -1,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    42,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    -1,    48,    49,    -1,    51,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
      14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    42,    -1,
      -1,    -1,    46,    -1,    48,    49,    50,    51,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    13,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      42,    -1,    27,    -1,    46,    -1,    -1,    -1,    -1,    51,
       3,     4,     5,     6,     7,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    42,
      -1,    27,    -1,    46,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      46,    -1,    48,    49,    50,    51,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    49,    -1,    51,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    42,    -1,
      -1,    -1,    46,    52,    -1,    -1,    -1,    51,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    48,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    48,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    48,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    56,     0,     3,     4,     5,     6,     7,     8,
       9,    13,    14,    15,    17,    18,    19,    20,    21,    22,
      23,    24,    27,    42,    46,    48,    49,    51,    57,    58,
      59,    60,    61,    62,    68,    70,    71,    75,    32,    51,
      51,    51,    51,    57,    74,    48,    48,    71,     7,    75,
      75,    75,    74,    75,    48,    48,     7,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      48,     7,    51,    73,    75,    75,    75,    70,    72,    75,
      16,    57,     7,    48,    50,    52,    32,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      32,     7,    52,    52,    48,    52,    75,    32,    73,    73,
      32,    49,    49,    27,    67,    70,    75,    57,    48,    73,
      73,    74,    10,    63,    64,    75,    48,    52,    50,     3,
       6,    50,    11,    65,     7,    68,    69,    31,    53,    53,
      53,    52,    49,    66,    74,    66,    66,    49,    74,    64,
      64,    74,    50,    50
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
#line 104 "parser.y"
    { /*last thing to finish*/ check_unused_variables();;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { execute_all((yyvsp[(2) - (2)].nodePtr)); free_node((yyvsp[(2) - (2)].nodePtr)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {(yyval.nodePtr) = NULL;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    { /*std::cout<<"expression "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (2)].nodePtr); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    { /*std::cout<<"PRINT "<<std::endl;*/(yyval.nodePtr) = construct_operation_node(PRINT, 1, (yyvsp[(2) - (3)].nodePtr)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    { /*std::cout<<"assignment_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (2)].nodePtr); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { /*std::cout<<"declaration_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (2)].nodePtr); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    { /*std::cout<<"while_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { /*std::cout<<"do_while_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { /*std::cout<<"for_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    { /*std::cout<<"if_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    { /*std::cout<<"switch_statement "<<std::endl;*/ (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    { /*std::cout<<"statement_list_block "<<std::endl;*/ (yyval.nodePtr) = construct_operation_node(BLOCK, 1, (yyvsp[(2) - (3)].nodePtr));; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    { /*std::cout<<"BREAK "<<std::endl;*/ (yyval.nodePtr) = construct_operation_node(BREAK, 1, NULL); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    { /*std::cout<<"CONTINUE "<<std::endl;*/(yyval.nodePtr) = construct_operation_node(CONTINUE, 1, NULL); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(WHILE, 2, (yyvsp[(3) - (5)].nodePtr), (yyvsp[(5) - (5)].nodePtr)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(DO, 2, (yyvsp[(2) - (5)].nodePtr), (yyvsp[(4) - (5)].nodePtr)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(FOR, 4, (yyvsp[(3) - (11)].nodePtr), (yyvsp[(5) - (11)].nodePtr), (yyvsp[(7) - (11)].nodePtr), (yyvsp[(10) - (11)].nodePtr)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(IF, 2, (yyvsp[(3) - (7)].nodePtr), (yyvsp[(6) - (7)].nodePtr)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(IF, 3, (yyvsp[(3) - (11)].nodePtr), (yyvsp[(6) - (11)].nodePtr), (yyvsp[(10) - (11)].nodePtr)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(SWITCH, 2, (yyvsp[(3) - (7)].nodePtr), (yyvsp[(6) - (7)].nodePtr)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { /*$$ = construct_operation_node(SWITCH_BODY, 1, $1);*/ ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    { /*$$ = construct_operation_node(SWITCH_BODY, 2, $1, $2);*/ ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(CASE, 3, construct_constant_node(INTEGER, INT_TYPE, (yyvsp[(2) - (5)].intValue)), (yyvsp[(4) - (5)].nodePtr), (yyvsp[(5) - (5)].nodePtr)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(CASE, 3, construct_constant_node(BOOL, BOOL_TYPE, (yyvsp[(2) - (5)].boolValue)), (yyvsp[(4) - (5)].nodePtr), (yyvsp[(5) - (5)].nodePtr)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(DEFAULT, 1, (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(PRINT, 1, (yyvsp[(2) - (2)].nodePtr)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(1) - (3)].sIndex)), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(DECLARE_ONLY, 1, construct_identifier_node((yyvsp[(2) - (2)].sIndex), (yyvsp[(1) - (2)].intValue))); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(2) - (4)].sIndex), (yyvsp[(1) - (4)].intValue)), (yyvsp[(4) - (4)].nodePtr)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(3) - (5)].sIndex), (yyvsp[(2) - (5)].intValue), CONST), (yyvsp[(5) - (5)].nodePtr)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    { (yyval.intValue) = INT_TYPE ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    { (yyval.intValue) = FLOAT_TYPE ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    { (yyval.intValue) = BOOL_TYPE ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    { (yyval.intValue) = STRING_TYPE ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    { (yyval.intValue) = VOID_TYPE ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, NULL, NULL); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(1) - (3)].sIndex)), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('=', 2, construct_identifier_node((yyvsp[(2) - (5)].sIndex)), (yyvsp[(4) - (5)].nodePtr)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(1) - (1)].nodePtr); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(';', 2, (yyvsp[(1) - (2)].nodePtr), (yyvsp[(2) - (2)].nodePtr)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    { (yyval.nodePtr) = construct_constant_node(INTEGER, INT_TYPE, (yyvsp[(1) - (1)].intValue)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    { (yyval.nodePtr) = construct_constant_node(FLOAT, FLOAT_TYPE, (yyvsp[(1) - (1)].floatValue)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    { (yyval.nodePtr) = construct_constant_node(STRING, STRING_TYPE, (yyvsp[(1) - (1)].stringValue)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    { (yyval.nodePtr) = construct_identifier_node((yyvsp[(1) - (1)].sIndex)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    { (yyval.nodePtr) = construct_constant_node(BOOL, BOOL_TYPE, (yyvsp[(1) - (1)].boolValue)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(NEGATIVE, 1, (yyvsp[(2) - (2)].nodePtr)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(NOT, 1, (yyvsp[(2) - (2)].nodePtr)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('+', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('-', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('*', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('/', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('%', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 235 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('<', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    { (yyval.nodePtr) = construct_operation_node('>', 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(GREATER_EQUAL, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(LESS_EQUAL, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(NOT_EQUAL, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(EQUAL, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(AND, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { (yyval.nodePtr) = construct_operation_node(OR, 2, (yyvsp[(1) - (3)].nodePtr), (yyvsp[(3) - (3)].nodePtr)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    { (yyval.nodePtr) = (yyvsp[(2) - (3)].nodePtr); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2126 "parser.tab.c"
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
#line 247 "parser.y"


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

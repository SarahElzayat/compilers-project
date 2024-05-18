
/*  A Bison parser, made from parser.y
 by  GNU Bison version 1.27
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INTEGER	257
#define	FLOAT	258
#define	STRING	259
#define	BOOL	260
#define	VARIABLE	261
#define	IF	262
#define	SWITCH	263
#define	CASE	264
#define	DEFAULT	265
#define	SWITCH_BODY	266
#define	FOR	267
#define	WHILE	268
#define	DO	269
#define	REPEAT	270
#define	BREAK	271
#define	CONTINUE	272
#define	CONST	273
#define	INT_TYPE	274
#define	FLOAT_TYPE	275
#define	BOOL_TYPE	276
#define	STRING_TYPE	277
#define	VOID_TYPE	278
#define	DECLARE_ONLY	279
#define	FUNCTION	280
#define	PRINT	281
#define	RETURN	282
#define	BLOCK	283
#define	IFX	284
#define	ELSE	285
#define	FUNC	286
#define	OR	287
#define	AND	288
#define	GREATER_EQUAL	289
#define	LESS_EQUAL	290
#define	EQUAL	291
#define	NOT_EQUAL	292
#define	NOT	293
#define	NEGATIVE	294

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

#line 30 "parser.y"
typedef union {
  int intValue;                          /* integer  */
  float floatValue;                      /* double   */
  char* stringValue;                     /* string   */
  bool boolValue;                        /* boolean  */

  char *sIndex;                       /* symbol table index */
  char *varType;                      /* variable type      */
  Node *nodePtr;                      /*   node             */
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		177
#define	YYFLAG		-32768
#define	YYNTBASE	56

#define YYTRANSLATE(x) ((unsigned)(x) <= 294 ? yytranslate[x] : 80)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,    46,     2,     2,    52,
    53,    44,    42,    54,    43,     2,    45,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    55,    49,    41,
    33,    40,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    50,     2,    51,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    34,    35,    36,    37,
    38,    39,    47,    48
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     6,     8,    11,    15,    18,    21,    23,
    25,    27,    29,    31,    33,    35,    37,    41,    44,    47,
    57,    61,    63,    64,    70,    73,    77,    79,    80,    86,
    92,   104,   112,   124,   128,   136,   145,   153,   160,   161,
   164,   166,   168,   172,   176,   177,   179,   182,   187,   193,
   195,   197,   199,   201,   203,   204,   206,   208,   212,   218,
   220,   223,   225,   227,   229,   231,   233,   236,   239,   243,
   247,   251,   255,   259,   263,   267,   271,   275,   279,   283,
   287,   291
};

static const short yyrhs[] = {    57,
     0,    57,    58,     0,     0,    49,     0,    79,    49,     0,
    27,    79,    49,     0,    72,    49,     0,    74,    49,     0,
    64,     0,    65,     0,    66,     0,    61,     0,    59,     0,
    62,     0,    67,     0,    69,     0,    50,    78,    51,     0,
    17,    49,     0,    18,    49,     0,    26,    74,    52,    60,
    53,    50,    58,    62,    51,     0,    74,    54,    60,     0,
    74,     0,     0,     7,    52,    63,    53,    49,     0,    28,
    58,     0,    63,    54,    79,     0,    79,     0,     0,    14,
    52,    79,    53,    58,     0,    15,    78,    16,    79,    49,
     0,    13,    52,    76,    49,    71,    49,    73,    53,    50,
    78,    51,     0,     8,    52,    79,    53,    50,    78,    51,
     0,     8,    52,    79,    53,    50,    78,    51,    31,    50,
    78,    51,     0,    11,    55,    58,     0,     9,    52,     7,
    53,    50,    70,    51,     0,     9,    52,     7,    53,    50,
    70,    68,    51,     0,    10,     3,    55,    58,    17,    49,
    70,     0,    10,     3,    55,    58,    17,    49,     0,     0,
    27,    79,     0,    74,     0,    79,     0,     7,    33,    61,
     0,     7,    33,    77,     0,     0,    72,     0,    75,     7,
     0,    75,     7,    33,    77,     0,    19,    75,     7,    33,
    77,     0,    20,     0,    21,     0,    22,     0,    23,     0,
    24,     0,     0,    74,     0,    79,     0,     7,    33,    77,
     0,    52,     7,    33,    77,    53,     0,    58,     0,    78,
    58,     0,     3,     0,     4,     0,     5,     0,     7,     0,
     6,     0,    43,    79,     0,    47,    79,     0,    79,    42,
    79,     0,    79,    43,    79,     0,    79,    44,    79,     0,
    79,    45,    79,     0,    79,    46,    79,     0,    79,    41,
    79,     0,    79,    40,    79,     0,    79,    36,    79,     0,
    79,    37,    79,     0,    79,    39,    79,     0,    79,    38,
    79,     0,    79,    35,    79,     0,    79,    34,    79,     0,
    52,    79,    53,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   105,   108,   109,   113,   114,   115,   117,   118,   120,   121,
   122,   124,   125,   126,   128,   129,   130,   131,   132,   136,
   138,   139,   140,   143,   146,   149,   150,   151,   154,   158,
   161,   165,   166,   170,   174,   175,   178,   179,   184,   186,
   187,   188,   191,   192,   195,   197,   200,   201,   202,   205,
   206,   207,   208,   209,   212,   214,   217,   218,   219,   222,
   223,   227,   228,   229,   230,   231,   232,   233,   234,   235,
   236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
   246,   247
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","INTEGER",
"FLOAT","STRING","BOOL","VARIABLE","IF","SWITCH","CASE","DEFAULT","SWITCH_BODY",
"FOR","WHILE","DO","REPEAT","BREAK","CONTINUE","CONST","INT_TYPE","FLOAT_TYPE",
"BOOL_TYPE","STRING_TYPE","VOID_TYPE","DECLARE_ONLY","FUNCTION","PRINT","RETURN",
"BLOCK","IFX","ELSE","FUNC","'='","OR","AND","GREATER_EQUAL","LESS_EQUAL","EQUAL",
"NOT_EQUAL","'>'","'<'","'+'","'-'","'*'","'/'","'%'","NOT","NEGATIVE","';'",
"'{'","'}'","'('","')'","','","':'","program","functions","statement","function_declaration",
"parameter_list","function_call","return_statement","comma_expressions","while_statement",
"do_while_statement","for_statement","if_statement","default_statement","switch_statement",
"cases","for_mid_stmt","assignment_statement","for_assignment","declaration_statement",
"data_type","for_declaration","rhs_nested_expression","statement_list","expression", NULL
};
#endif

static const short yyr1[] = {     0,
    56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
    58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
    60,    60,    60,    61,    62,    63,    63,    63,    64,    65,
    66,    67,    67,    68,    69,    69,    70,    70,    71,    71,
    71,    71,    72,    72,    73,    73,    74,    74,    74,    75,
    75,    75,    75,    75,    76,    76,    77,    77,    77,    78,
    78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
    79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
    79,    79
};

static const short yyr2[] = {     0,
     1,     2,     0,     1,     2,     3,     2,     2,     1,     1,
     1,     1,     1,     1,     1,     1,     3,     2,     2,     9,
     3,     1,     0,     5,     2,     3,     1,     0,     5,     5,
    11,     7,    11,     3,     7,     8,     7,     6,     0,     2,
     1,     1,     3,     3,     0,     1,     2,     4,     5,     1,
     1,     1,     1,     1,     0,     1,     1,     3,     5,     1,
     2,     1,     1,     1,     1,     1,     2,     2,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3
};

static const short yydefact[] = {     3,
     1,    62,    63,    64,    66,    65,     0,     0,     0,     0,
     0,     0,     0,     0,    50,    51,    52,    53,    54,     0,
     0,     0,     0,     0,     4,     0,     0,     2,    13,    12,
    14,     9,    10,    11,    15,    16,     0,     0,     0,     0,
     0,    28,     0,     0,    55,     0,    60,     0,    18,    19,
     0,     0,    65,     0,    25,    67,    68,     0,     0,     7,
     8,    47,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     5,    65,     0,    43,    44,
    57,     0,    27,     0,     0,    56,     0,     0,     0,    61,
     0,    23,     6,    17,    82,     0,    81,    80,    76,    77,
    79,    78,    75,    74,    69,    70,    71,    72,    73,     0,
    65,     0,     0,     0,     0,    39,     0,     0,     0,     0,
    22,    65,    48,    58,     0,    24,    26,     0,     0,     0,
     0,    41,    42,    29,    30,    49,     0,    23,     0,     0,
     0,     0,    40,    45,     0,    21,    59,    32,     0,     0,
    35,     0,     0,    46,     0,     0,     0,     0,     0,    36,
     0,     0,     0,     0,    34,     0,    20,     0,     0,     0,
    33,    38,    31,    37,     0,     0,     0
};

static const short yydefgoto[] = {   175,
     1,    47,    29,   120,    30,    31,    82,    32,    33,    34,
    35,   152,    36,   142,   131,    37,   155,    38,    39,    87,
    80,    48,    40
};

static const short yypact[] = {-32768,
   407,-32768,-32768,-32768,-32768,   -29,   -32,   -26,   -20,   -12,
   407,    -7,    -5,    39,-32768,-32768,-32768,-32768,-32768,   167,
   107,   407,   107,   107,-32768,   407,   107,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    -4,    -3,    17,   426,
   189,   107,   107,    49,   167,   107,-32768,   157,-32768,-32768,
    63,    19,-32768,   442,-32768,-32768,-32768,   207,   -28,-32768,
-32768,    40,   107,   107,   107,   107,   107,   107,   107,   107,
   107,   107,   107,   107,   107,-32768,   -11,   239,-32768,-32768,
   474,   -16,   474,   352,    36,-32768,    42,   402,   107,-32768,
    60,   167,-32768,-32768,-32768,   289,   486,   497,    90,    90,
    90,    90,    90,    90,   -15,   -15,-32768,-32768,-32768,   289,
    61,    46,   107,    50,    52,    45,   407,   458,   289,    43,
    51,    66,-32768,-32768,   289,-32768,   474,   407,    94,   107,
    57,-32768,   474,-32768,-32768,-32768,    59,   167,    54,   257,
   112,    -8,   474,   110,   407,-32768,-32768,    87,    64,    68,
-32768,    70,    91,-32768,    73,    99,    79,   407,   407,-32768,
    80,    89,   407,   126,-32768,   407,-32768,   307,    96,   357,
-32768,    94,-32768,-32768,   146,   147,-32768
};

static const short yypgoto[] = {-32768,
-32768,    -1,-32768,    10,   108,     0,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   -21,-32768,     8,-32768,   -18,   139,-32768,
   -91,   -25,    12
};


#define	YYLAST		543


static const short yytable[] = {    28,
    58,    52,   150,    41,   123,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,   124,    43,
    55,   110,    42,    62,    95,    44,    86,   136,    73,    74,
    75,    45,    54,   139,    56,    57,   112,   113,    59,    46,
    42,    49,   151,    50,    60,    61,    90,     2,     3,     4,
     5,    53,    81,    83,    84,    85,    90,    88,    15,    16,
    17,    18,    19,    14,    15,    16,    17,    18,    19,    91,
    92,   130,    96,   121,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,    23,   115,    59,
   116,    24,   119,   125,   126,   137,    27,   132,   110,   128,
   118,   129,   140,   141,   138,   144,   147,    81,   145,     2,
     3,     4,     5,    53,   149,   134,   153,   157,   158,   121,
   160,    81,   159,    41,   127,   161,    22,   133,   163,   166,
    81,    71,    72,    73,    74,    75,    81,   168,    90,   167,
   170,   143,   169,   156,   172,   176,   177,   146,    79,    23,
   174,   154,    51,    24,     0,   162,   164,   165,    27,     2,
     3,     4,     5,     6,     7,     8,    90,     0,    90,     9,
    10,    11,    89,    12,    13,    14,    15,    16,    17,    18,
    19,     0,    20,    21,    22,    14,    15,    16,    17,    18,
    19,     2,     3,     4,     5,    77,     0,     0,     0,    23,
     0,     0,     0,    24,     0,    25,    26,     0,    27,     2,
     3,     4,     5,     6,     7,     8,     0,     0,     0,     9,
    10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
    19,    23,    20,    21,    22,    24,     0,     0,     0,     0,
    78,     2,     3,     4,     5,   111,     0,     0,     0,    23,
     0,     0,     0,    24,     0,    25,    26,    94,    27,     2,
     3,     4,     5,     6,     7,     8,     0,     0,     0,     9,
    10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
    19,    23,    20,    21,    22,    24,     0,     0,     0,     0,
    27,     2,     3,     4,     5,   122,     0,     0,     0,    23,
     0,     0,     0,    24,     0,    25,    26,   148,    27,     2,
     3,     4,     5,     6,     7,     8,     0,     0,     0,     9,
    10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
    19,    23,    20,    21,    22,    24,     0,     0,     0,     0,
    78,     0,     0,     0,     0,     0,     0,     0,     0,    23,
     0,     0,     0,    24,     0,    25,    26,   171,    27,     2,
     3,     4,     5,     6,     7,     8,     0,     0,     0,     9,
    10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
    19,     0,    20,    21,    22,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,     0,    23,
     0,     0,     0,    24,   114,    25,    26,   173,    27,     2,
     3,     4,     5,     6,     7,     8,     0,     0,     0,     9,
    10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
    19,     0,    20,    21,    22,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,     0,    23,
     0,     0,     0,    24,   117,    25,    26,     0,    27,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,     0,     0,    76,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
    93,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,     0,     0,   135,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75
};

static const short yycheck[] = {     1,
    26,    20,    11,    33,    96,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,   110,    52,
    22,    33,    52,     7,    53,    52,    45,   119,    44,    45,
    46,    52,    21,   125,    23,    24,    53,    54,    27,    52,
    52,    49,    51,    49,    49,    49,    48,     3,     4,     5,
     6,     7,    41,    42,    43,     7,    58,    46,    20,    21,
    22,    23,    24,    19,    20,    21,    22,    23,    24,     7,
    52,    27,    33,    92,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    43,    53,    78,
    49,    47,    33,    33,    49,    53,    52,   116,    33,    50,
    89,    50,   128,    10,    54,    49,    53,    96,    50,     3,
     4,     5,     6,     7,     3,   117,     7,    31,    55,   138,
    51,   110,    55,    33,   113,    53,    28,   116,    50,    50,
   119,    42,    43,    44,    45,    46,   125,   163,   140,    51,
   166,   130,    17,   145,    49,     0,     0,   138,    41,    43,
   172,   144,    14,    47,    -1,   156,   158,   159,    52,     3,
     4,     5,     6,     7,     8,     9,   168,    -1,   170,    13,
    14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
    24,    -1,    26,    27,    28,    19,    20,    21,    22,    23,
    24,     3,     4,     5,     6,     7,    -1,    -1,    -1,    43,
    -1,    -1,    -1,    47,    -1,    49,    50,    -1,    52,     3,
     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
    14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
    24,    43,    26,    27,    28,    47,    -1,    -1,    -1,    -1,
    52,     3,     4,     5,     6,     7,    -1,    -1,    -1,    43,
    -1,    -1,    -1,    47,    -1,    49,    50,    51,    52,     3,
     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
    14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
    24,    43,    26,    27,    28,    47,    -1,    -1,    -1,    -1,
    52,     3,     4,     5,     6,     7,    -1,    -1,    -1,    43,
    -1,    -1,    -1,    47,    -1,    49,    50,    51,    52,     3,
     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
    14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
    24,    43,    26,    27,    28,    47,    -1,    -1,    -1,    -1,
    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
    -1,    -1,    -1,    47,    -1,    49,    50,    51,    52,     3,
     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
    14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
    24,    -1,    26,    27,    28,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    -1,    43,
    -1,    -1,    -1,    47,    53,    49,    50,    51,    52,     3,
     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    13,
    14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
    24,    -1,    26,    27,    28,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    -1,    43,
    -1,    -1,    -1,    47,    53,    49,    50,    -1,    52,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    -1,    -1,    49,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
    49,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    -1,    -1,    49,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"
/* This file comes from bison-1.27.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 216 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
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
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
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

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 105 "parser.y"
{ /*last thing to finish*/ check_unused_variables();;
    break;}
case 2:
#line 108 "parser.y"
{ execute_all(yyvsp[0].nodePtr); /*free_node($2);*/ ;
    break;}
case 3:
#line 109 "parser.y"
{yyval.nodePtr = NULL;;
    break;}
case 4:
#line 113 "parser.y"
{ yyval.nodePtr = construct_operation_node(';', 2, NULL, NULL); ;
    break;}
case 5:
#line 114 "parser.y"
{ /*std::cout<<"expression "<<std::endl;*/ yyval.nodePtr = yyvsp[-1].nodePtr; ;
    break;}
case 6:
#line 115 "parser.y"
{ /*std::cout<<"PRINT "<<std::endl;*/yyval.nodePtr = construct_operation_node(PRINT, 1, yyvsp[-1].nodePtr); ;
    break;}
case 7:
#line 117 "parser.y"
{ /*std::cout<<"assignment_statement "<<std::endl;*/ yyval.nodePtr = yyvsp[-1].nodePtr; ;
    break;}
case 8:
#line 118 "parser.y"
{ /*std::cout<<"declaration_statement "<<std::endl;*/ yyval.nodePtr = yyvsp[-1].nodePtr; ;
    break;}
case 9:
#line 120 "parser.y"
{ /*std::cout<<"while_statement "<<std::endl;*/ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 10:
#line 121 "parser.y"
{ /*std::cout<<"do_while_statement "<<std::endl;*/ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 11:
#line 122 "parser.y"
{ /*std::cout<<"for_statement "<<std::endl;*/ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 12:
#line 124 "parser.y"
{/*std::cout<<"function_call "<<std::endl;*/ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 13:
#line 125 "parser.y"
{/*std::cout<<"function_declaration "<<std::endl;*/ yyval.nodePtr = yyvsp[0].nodePtr;;
    break;}
case 14:
#line 126 "parser.y"
{ /*std::cout<<"return_statement "<<std::endl;*/ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 15:
#line 128 "parser.y"
{ /*std::cout<<"if_statement "<<std::endl;*/ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 16:
#line 129 "parser.y"
{ /*std::cout<<"switch_statement "<<std::endl;*/ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 17:
#line 130 "parser.y"
{ /*std::cout<<"statement_list_block "<<std::endl;*/ yyval.nodePtr = construct_operation_node(BLOCK, 1, yyvsp[-1].nodePtr);; ;
    break;}
case 18:
#line 131 "parser.y"
{ /*std::cout<<"BREAK "<<std::endl;*/ yyval.nodePtr = construct_operation_node(BREAK, 1, NULL); ;
    break;}
case 19:
#line 132 "parser.y"
{ /*std::cout<<"CONTINUE "<<std::endl;*/yyval.nodePtr = construct_operation_node(CONTINUE, 1, NULL); ;
    break;}
case 20:
#line 136 "parser.y"
{yyval.nodePtr=construct_operation_node(FUNCTION,4,yyvsp[-7].nodePtr,yyvsp[-5].nodePtr,yyvsp[-2].nodePtr,yyvsp[-1].nodePtr);;
    break;}
case 21:
#line 138 "parser.y"
{yyval.nodePtr=construct_operation_node(COMMA,2,yyvsp[-2].nodePtr,yyvsp[0].nodePtr);;
    break;}
case 22:
#line 139 "parser.y"
{yyval.nodePtr=yyvsp[0].nodePtr;;
    break;}
case 23:
#line 140 "parser.y"
{yyval.nodePtr=NULL;
    break;}
case 24:
#line 143 "parser.y"
{yyval.nodePtr=construct_operation_node(CALL,2,construct_identifier_node(yyvsp[-4].sIndex),yyvsp[-2].nodePtr);
    break;}
case 25:
#line 146 "parser.y"
{ yyval.nodePtr = construct_operation_node(RETURN, 1, yyvsp[0].nodePtr); ;
    break;}
case 26:
#line 149 "parser.y"
{ yyval.nodePtr = construct_operation_node(COMMA, 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 27:
#line 150 "parser.y"
{ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 28:
#line 151 "parser.y"
{ yyval.nodePtr = NULL; ;
    break;}
case 29:
#line 155 "parser.y"
{ yyval.nodePtr = construct_operation_node(WHILE, 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 30:
#line 158 "parser.y"
{ yyval.nodePtr = construct_operation_node(DO, 2, yyvsp[-3].nodePtr, yyvsp[-1].nodePtr); ;
    break;}
case 31:
#line 161 "parser.y"
{ yyval.nodePtr = construct_operation_node(FOR, 4, yyvsp[-8].nodePtr, yyvsp[-6].nodePtr, yyvsp[-4].nodePtr, yyvsp[-1].nodePtr); ;
    break;}
case 32:
#line 165 "parser.y"
{ yyval.nodePtr = construct_operation_node(IF, 2, yyvsp[-4].nodePtr, yyvsp[-1].nodePtr); ;
    break;}
case 33:
#line 166 "parser.y"
{ yyval.nodePtr = construct_operation_node(IF, 3, yyvsp[-8].nodePtr, yyvsp[-5].nodePtr, yyvsp[-1].nodePtr); ;
    break;}
case 34:
#line 171 "parser.y"
{ yyval.nodePtr = construct_operation_node(DEFAULT, 1, yyvsp[0].nodePtr); ;
    break;}
case 35:
#line 174 "parser.y"
{yyval.nodePtr=construct_operation_node(SWITCH,2,construct_identifier_node(yyvsp[-4].sIndex),yyvsp[-1].nodePtr);;
    break;}
case 36:
#line 175 "parser.y"
{yyval.nodePtr=construct_operation_node(SWITCH,3,construct_identifier_node(yyvsp[-5].sIndex),yyvsp[-2].nodePtr,yyvsp[-1].nodePtr);;
    break;}
case 37:
#line 178 "parser.y"
{yyval.nodePtr=construct_operation_node(CASE,4,construct_constant_node(INTEGER,INT_TYPE,yyvsp[-5].intValue),yyvsp[-3].nodePtr,construct_operation_node(BREAK,0),yyvsp[0].nodePtr);;
    break;}
case 38:
#line 179 "parser.y"
{yyval.nodePtr=construct_operation_node(CASE,3,construct_constant_node(INTEGER,INT_TYPE,yyvsp[-4].intValue),yyvsp[-2].nodePtr,construct_operation_node(BREAK,0));;
    break;}
case 39:
#line 185 "parser.y"
{ yyval.nodePtr = construct_operation_node(';', 2, NULL, NULL); ;
    break;}
case 40:
#line 186 "parser.y"
{ yyval.nodePtr = construct_operation_node(PRINT, 1, yyvsp[0].nodePtr); ;
    break;}
case 41:
#line 187 "parser.y"
{ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 42:
#line 188 "parser.y"
{ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 43:
#line 191 "parser.y"
{std::cout<<"function_call assignement matched\n"; yyval.nodePtr = construct_operation_node('=', 2, construct_identifier_node(yyvsp[-2].sIndex), yyvsp[0].nodePtr); ;
    break;}
case 44:
#line 192 "parser.y"
{ yyval.nodePtr = construct_operation_node('=', 2, construct_identifier_node(yyvsp[-2].sIndex), yyvsp[0].nodePtr); ;
    break;}
case 45:
#line 196 "parser.y"
{ yyval.nodePtr = construct_operation_node(';', 2, NULL, NULL); ;
    break;}
case 46:
#line 197 "parser.y"
{ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 47:
#line 200 "parser.y"
{ yyval.nodePtr = construct_operation_node(DECLARE_ONLY, 1, construct_identifier_node(yyvsp[0].sIndex, yyvsp[-1].intValue)); ;
    break;}
case 48:
#line 201 "parser.y"
{ yyval.nodePtr = construct_operation_node('=', 2, construct_identifier_node(yyvsp[-2].sIndex, yyvsp[-3].intValue), yyvsp[0].nodePtr); ;
    break;}
case 49:
#line 202 "parser.y"
{ yyval.nodePtr = construct_operation_node('=', 2, construct_identifier_node(yyvsp[-2].sIndex, yyvsp[-3].intValue, CONST), yyvsp[0].nodePtr); ;
    break;}
case 50:
#line 205 "parser.y"
{ yyval.intValue = INT_TYPE ;
    break;}
case 51:
#line 206 "parser.y"
{ yyval.intValue = FLOAT_TYPE ;
    break;}
case 52:
#line 207 "parser.y"
{ yyval.intValue = BOOL_TYPE ;
    break;}
case 53:
#line 208 "parser.y"
{ yyval.intValue = STRING_TYPE ;
    break;}
case 54:
#line 209 "parser.y"
{ yyval.intValue = VOID_TYPE ;
    break;}
case 55:
#line 213 "parser.y"
{ yyval.nodePtr = construct_operation_node(';', 2, NULL, NULL); ;
    break;}
case 56:
#line 214 "parser.y"
{ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 57:
#line 217 "parser.y"
{ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 58:
#line 218 "parser.y"
{ yyval.nodePtr = construct_operation_node('=', 2, construct_identifier_node(yyvsp[-2].sIndex), yyvsp[0].nodePtr); ;
    break;}
case 59:
#line 219 "parser.y"
{ yyval.nodePtr = construct_operation_node('=', 2, construct_identifier_node(yyvsp[-3].sIndex), yyvsp[-1].nodePtr); ;
    break;}
case 60:
#line 222 "parser.y"
{ yyval.nodePtr = yyvsp[0].nodePtr; ;
    break;}
case 61:
#line 223 "parser.y"
{ yyval.nodePtr = construct_operation_node(';', 2, yyvsp[-1].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 62:
#line 227 "parser.y"
{ yyval.nodePtr = construct_constant_node(INTEGER, INT_TYPE, yyvsp[0].intValue); ;
    break;}
case 63:
#line 228 "parser.y"
{ yyval.nodePtr = construct_constant_node(FLOAT, FLOAT_TYPE, yyvsp[0].floatValue); ;
    break;}
case 64:
#line 229 "parser.y"
{ yyval.nodePtr = construct_constant_node(STRING, STRING_TYPE, yyvsp[0].stringValue); ;
    break;}
case 65:
#line 230 "parser.y"
{ yyval.nodePtr = construct_identifier_node(yyvsp[0].sIndex); ;
    break;}
case 66:
#line 231 "parser.y"
{ yyval.nodePtr = construct_constant_node (BOOL, BOOL_TYPE, yyvsp[0].boolValue); ;
    break;}
case 67:
#line 232 "parser.y"
{ yyval.nodePtr = construct_operation_node(NEGATIVE, 1, yyvsp[0].nodePtr); ;
    break;}
case 68:
#line 233 "parser.y"
{ yyval.nodePtr = construct_operation_node(NOT, 1, yyvsp[0].nodePtr); ;
    break;}
case 69:
#line 234 "parser.y"
{ yyval.nodePtr = construct_operation_node('+', 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 70:
#line 235 "parser.y"
{ yyval.nodePtr = construct_operation_node('-', 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 71:
#line 236 "parser.y"
{ yyval.nodePtr = construct_operation_node('*', 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 72:
#line 237 "parser.y"
{ yyval.nodePtr = construct_operation_node('/', 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 73:
#line 238 "parser.y"
{ yyval.nodePtr = construct_operation_node('%', 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 74:
#line 239 "parser.y"
{ yyval.nodePtr = construct_operation_node('<', 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 75:
#line 240 "parser.y"
{ yyval.nodePtr = construct_operation_node('>', 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 76:
#line 241 "parser.y"
{ yyval.nodePtr = construct_operation_node(GREATER_EQUAL, 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 77:
#line 242 "parser.y"
{ yyval.nodePtr = construct_operation_node(LESS_EQUAL, 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 78:
#line 243 "parser.y"
{ yyval.nodePtr = construct_operation_node(NOT_EQUAL, 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 79:
#line 244 "parser.y"
{ yyval.nodePtr = construct_operation_node(EQUAL, 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 80:
#line 245 "parser.y"
{ yyval.nodePtr = construct_operation_node(AND, 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 81:
#line 246 "parser.y"
{ yyval.nodePtr = construct_operation_node(OR, 2, yyvsp[-2].nodePtr, yyvsp[0].nodePtr); ;
    break;}
case 82:
#line 247 "parser.y"
{ yyval.nodePtr = yyvsp[-1].nodePtr; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 542 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

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

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 250 "parser.y"


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
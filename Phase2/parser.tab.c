
/*  A Bison parser, made from parser.y
 by  GNU Bison version 1.27
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INTEGER	257
#define	FLOAT	258
#define	BOOL	259
#define	STRING	260
#define	VARIABLE	261
#define	IF	262
#define	SWITCH	263
#define	CASE	264
#define	DEFAULT	265
#define	FOR	266
#define	WHILE	267
#define	DO	268
#define	BREAK	269
#define	CONTINUE	270
#define	CONST	271
#define	INT_TYPE	272
#define	FLOAT_TYPE	273
#define	BOOL_TYPE	274
#define	STRING_TYPE	275
#define	FUNCTION	276
#define	PRINT	277
#define	RETURN	278
#define	IFX	279
#define	ELSE	280
#define	ENDLINE	281
#define	OR	282
#define	AND	283
#define	GREATER_EQUAL	284
#define	LESS_EQUAL	285
#define	EQUAL	286
#define	NOTEQUAL	287
#define	NOT	288
#define	NEGATIVE	289

#line 1 "parser.y"
  

    //INCLUDES
    #include <stdio.h>
    #include "compiler.h"
    #include <stdbool.h>
    //----------------------------------------------
    //Function Prototypes
    extern void export_symbol_table();
    node *construct_operation_node(int oper, int nops, ...);
    node *construct_identifier_node(char*, int = -1, int = -1);
    node *construct_constant_node(int, int, ...);
    node *construct_value_node(int, int, float, bool, char*, bool, char* = NULL);
    //----------------------------------------------

    void free_node(node *p);
    int execute(node *p, int = -1, int = -1, int = 0, ...);

    //----------------------------------------------
    int yylex(void);
    void yyerror(const char *msg);

#line 29 "parser.y"
typedef union
{
    int iVal;              /*   integer       */
    float fVal;            /*   float         */
    bool bVal;             /*   boolean       */
    char *strVal;          /*   string        */

    char *conName;         /*   constant      */
    char *varName;         /*   variable      */

    char *sIdx;            /*   symbol table  */

    node *n;               /*   node          */
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		142
#define	YYFLAG		-32768
#define	YYNTBASE	49

#define YYTRANSLATE(x) ((unsigned)(x) <= 289 ? yytranslate[x] : 64)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
    44,    39,    37,     2,    38,     2,    40,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    48,    45,    35,
    28,    36,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    46,     2,    47,     2,     2,     2,     2,     2,
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
    27,    29,    30,    31,    32,    33,    34,    41,    42
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    13,    18,    20,    22,
    24,    26,    28,    30,    33,    37,    39,    41,    45,    50,
    55,    61,    63,    65,    67,    69,    81,    89,    98,   106,
   118,   126,   135,   142,   149,   155,   159,   161,   163,   165,
   167,   169,   172,   176,   180,   184,   188,   192,   196,   199,
   203,   207,   211,   215,   219,   223
};

static const short yyrhs[] = {    50,
     0,    51,     0,    50,    51,     0,    52,     0,    54,     0,
    63,     0,    23,    43,    63,    44,     0,    56,     0,    57,
     0,    58,     0,    59,     0,    60,     0,    53,     0,    24,
    27,     0,    24,    63,    27,     0,    15,     0,    16,     0,
     7,    28,    63,     0,    22,    43,    63,    44,     0,    55,
     7,    28,    63,     0,    17,    55,     7,    28,    63,     0,
    18,     0,    19,     0,    20,     0,    21,     0,    12,    43,
    54,    45,    63,    45,    52,    44,    46,    50,    47,     0,
    13,    43,    63,    44,    46,    50,    47,     0,    14,    46,
    50,    47,    13,    43,    63,    44,     0,     8,    43,    63,
    44,    46,    50,    47,     0,     8,    43,    63,    44,    46,
    50,    47,    26,    46,    50,    47,     0,     9,    43,     7,
    44,    46,    61,    47,     0,     9,    43,     7,    44,    46,
    61,    62,    47,     0,    10,     3,    48,    51,    15,    61,
     0,    10,     5,    48,    51,    15,    61,     0,    10,     3,
    48,    51,    15,     0,    11,    48,    51,     0,     3,     0,
     4,     0,     6,     0,     5,     0,     7,     0,    38,    63,
     0,    63,    37,    63,     0,    63,    38,    63,     0,    63,
    39,    63,     0,    63,    40,    63,     0,    63,    35,    63,
     0,    63,    36,    63,     0,    41,    63,     0,    63,    30,
    63,     0,    63,    29,    63,     0,    63,    31,    63,     0,
    63,    32,    63,     0,    63,    33,    63,     0,    63,    34,
    63,     0,    43,    63,    44,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   109,   112,   113,   116,   117,   118,   120,   123,   124,   125,
   127,   128,   129,   132,   133,   135,   136,   140,   145,   150,
   151,   155,   156,   157,   158,   163,   166,   170,   174,   175,
   178,   179,   182,   183,   184,   187,   191,   194,   195,   196,
   197,   199,   201,   202,   203,   204,   205,   206,   208,   209,
   210,   211,   212,   213,   214,   215
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","INTEGER",
"FLOAT","BOOL","STRING","VARIABLE","IF","SWITCH","CASE","DEFAULT","FOR","WHILE",
"DO","BREAK","CONTINUE","CONST","INT_TYPE","FLOAT_TYPE","BOOL_TYPE","STRING_TYPE",
"FUNCTION","PRINT","RETURN","IFX","ELSE","ENDLINE","'='","OR","AND","GREATER_EQUAL",
"LESS_EQUAL","EQUAL","NOTEQUAL","'<'","'>'","'+'","'-'","'*'","'/'","NOT","NEGATIVE",
"'('","')'","';'","'{'","'}'","':'","program","statement_list","statement","assignment_statement",
"function_call","declaration_statement","data_type","for_statement","while_statement",
"do_while_statement","if_statement","switch_statement","cases","default_statement",
"expression", NULL
};
#endif

static const short yyr1[] = {     0,
    49,    50,    50,    51,    51,    51,    51,    51,    51,    51,
    51,    51,    51,    51,    51,    51,    51,    52,    53,    54,
    54,    55,    55,    55,    55,    56,    57,    58,    59,    59,
    60,    60,    61,    61,    61,    62,    63,    63,    63,    63,
    63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
    63,    63,    63,    63,    63,    63
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     1,     4,     1,     1,     1,
     1,     1,     1,     2,     3,     1,     1,     3,     4,     4,
     5,     1,     1,     1,     1,    11,     7,     8,     7,    11,
     7,     8,     6,     6,     5,     3,     1,     1,     1,     1,
     1,     2,     3,     3,     3,     3,     3,     3,     2,     3,
     3,     3,     3,     3,     3,     3
};

static const short yydefact[] = {     0,
    37,    38,    40,    39,    41,     0,     0,     0,     0,     0,
    16,    17,     0,    22,    23,    24,    25,     0,     0,     0,
     0,     0,     0,     1,     2,     4,    13,     5,     0,     8,
     9,    10,    11,    12,     6,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    41,    14,     0,    42,    49,     0,
     3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
     0,     0,     0,    15,    56,     0,    51,    50,    52,    53,
    54,    55,    47,    48,    43,    44,    45,    46,     0,     0,
     0,     0,     0,     0,    19,     7,    20,     0,     0,     0,
     0,     0,    21,     0,     0,     0,     0,     0,     0,    29,
     0,     0,     0,    31,     0,     0,     0,    27,     0,     0,
     0,     0,     0,    32,     0,    28,     0,     0,     0,    36,
     0,     0,    35,     0,     0,    30,    33,    34,    26,     0,
     0,     0
};

static const short yydefgoto[] = {   140,
    24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
    34,   106,   115,    35
};

static const short yypact[] = {   290,
-32768,-32768,-32768,-32768,   -26,   -18,    -7,    -3,    -1,     4,
-32768,-32768,    74,-32768,-32768,-32768,-32768,     8,    11,   312,
   318,   318,   318,   290,-32768,-32768,-32768,-32768,    46,-32768,
-32768,-32768,-32768,-32768,   393,   318,   318,    50,    10,   318,
   290,    52,   318,   318,-32768,-32768,   381,-32768,-32768,   151,
-32768,    32,   318,   318,   318,   318,   318,   318,   318,   318,
   318,   318,   318,   318,   393,   196,    19,    33,   241,     0,
    36,   333,   349,-32768,-32768,   318,   404,   309,   297,   297,
   297,   297,   297,   297,   -29,   -29,-32768,-32768,    31,    35,
   318,    37,    66,   318,-32768,-32768,   393,   290,    72,   107,
   290,    42,   393,   110,    34,    15,    79,   155,   318,    63,
    48,    53,    54,-32768,    43,   -26,    56,-32768,   365,    58,
   290,   290,   290,-32768,    59,-32768,   290,    92,    94,-32768,
   290,   200,    72,    72,   245,-32768,-32768,-32768,-32768,   112,
   120,-32768
};

static const short yypgoto[] = {-32768,
   -40,   -24,     3,-32768,    96,   136,-32768,-32768,-32768,-32768,
-32768,   -89,-32768,    12
};


#define	YYLAST		444


static const short yytable[] = {    51,
    70,    36,     1,     2,     3,     4,     5,     6,     7,    63,
    64,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    37,   113,    13,    14,    15,    16,
    17,    47,    48,    49,    50,    38,   111,    21,   112,    39,
    22,    40,    23,   137,   138,    51,    93,    65,    66,    41,
    43,    69,    52,    44,    72,    73,    67,   104,    71,    76,
   108,   114,    90,    94,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    98,    91,   102,    51,
    99,   105,   101,    51,   109,   116,   132,    97,   120,   124,
   135,    14,    15,    16,    17,   121,   128,   129,   130,   125,
   122,   123,   100,   127,   131,   103,   133,    51,   134,   117,
    51,   141,     1,     2,     3,     4,     5,     6,     7,   142,
   119,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    68,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    21,    42,     0,
    22,   107,    23,     0,     0,     0,   110,     1,     2,     3,
     4,     5,     6,     7,     0,     0,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,     0,    21,     0,    75,    22,     0,    23,     0,     0,
     0,   118,     1,     2,     3,     4,     5,     6,     7,     0,
     0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,     0,    21,     0,    89,
    22,     0,    23,     0,     0,     0,   136,     1,     2,     3,
     4,     5,     6,     7,     0,     0,     8,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,     0,    21,     0,    92,    22,     0,    23,     0,     0,
     0,   139,     1,     2,     3,     4,     5,     6,     7,     0,
     0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,     1,     2,     3,     4,    45,     0,
     1,     2,     3,     4,    45,     0,     0,    21,     0,     0,
    22,     0,    23,    61,    62,    63,    64,     0,    46,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    21,
     0,     0,    22,     0,    23,    21,     0,     0,    22,     0,
    23,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,     0,     0,     0,    95,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
     0,     0,    96,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,     0,     0,    74,   126,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64
};

static const short yycheck[] = {    24,
    41,    28,     3,     4,     5,     6,     7,     8,     9,    39,
    40,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,    43,    11,    17,    18,    19,    20,
    21,    20,    21,    22,    23,    43,     3,    38,     5,    43,
    41,    43,    43,   133,   134,    70,    47,    36,    37,    46,
    43,    40,     7,    43,    43,    44,     7,    98,     7,    28,
   101,    47,    44,    28,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    46,    45,    13,   104,
    46,    10,    46,   108,    43,     7,   127,    76,    26,    47,
   131,    18,    19,    20,    21,    48,   121,   122,   123,    44,
    48,    48,    91,    46,    46,    94,    15,   132,    15,   107,
   135,     0,     3,     4,     5,     6,     7,     8,     9,     0,
   109,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,    39,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    38,    13,    -1,
    41,    45,    43,    -1,    -1,    -1,    47,     3,     4,     5,
     6,     7,     8,     9,    -1,    -1,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    -1,    38,    -1,    44,    41,    -1,    43,    -1,    -1,
    -1,    47,     3,     4,     5,     6,     7,     8,     9,    -1,
    -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    -1,    38,    -1,    44,
    41,    -1,    43,    -1,    -1,    -1,    47,     3,     4,     5,
     6,     7,     8,     9,    -1,    -1,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    -1,    38,    -1,    44,    41,    -1,    43,    -1,    -1,
    -1,    47,     3,     4,     5,     6,     7,     8,     9,    -1,
    -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,     3,     4,     5,     6,     7,    -1,
     3,     4,     5,     6,     7,    -1,    -1,    38,    -1,    -1,
    41,    -1,    43,    37,    38,    39,    40,    -1,    27,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    38,
    -1,    -1,    41,    -1,    43,    38,    -1,    -1,    41,    -1,
    43,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    -1,    -1,    -1,    44,    29,    30,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
    -1,    -1,    44,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    -1,    -1,    27,    44,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40
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
#line 109 "parser.y"
{execute(yyvsp[0].n);free_node(yyvsp[0].n); std::cout<<"program "<<std::endl;exit(0);;
    break;}
case 2:
#line 112 "parser.y"
{yyval.n=yyvsp[0].n;;
    break;}
case 3:
#line 113 "parser.y"
{yyval.n=construct_operation_node(STATEMENT_LIST,2,yyvsp[-1].n,yyvsp[0].n);;
    break;}
case 4:
#line 116 "parser.y"
{std::cout<<"assignment_statement "<<std::endl;   yyval.n=yyvsp[0].n;;
    break;}
case 5:
#line 117 "parser.y"
{std::cout<<"declaration_statement "<<std::endl;  yyval.n=yyvsp[0].n;;
    break;}
case 6:
#line 118 "parser.y"
{std::cout<<"expression "<<std::endl; yyval.n=yyvsp[0].n;;
    break;}
case 7:
#line 120 "parser.y"
{std::cout<<"PRINT EXP "<<std::endl;  yyval.n=construct_operation_node(PRINT,1,yyvsp[-1].n);;
    break;}
case 8:
#line 123 "parser.y"
{std::cout<<"for_statement "<<std::endl;;
    break;}
case 9:
#line 124 "parser.y"
{std::cout<<"while_statement "<<std::endl;yyval.n=yyvsp[0].n;
    break;}
case 10:
#line 125 "parser.y"
{std::cout<<"do_while_statement "<<std::endl;;
    break;}
case 11:
#line 127 "parser.y"
{std::cout<<"if_statement "<<std::endl;yyval.n=yyvsp[0].n;;
    break;}
case 12:
#line 128 "parser.y"
{std::cout<<"switch_statement "<<std::endl;;
    break;}
case 13:
#line 129 "parser.y"
{std::cout<<"function_call "<<std::endl;;
    break;}
case 14:
#line 132 "parser.y"
{std::cout<<"RETURN "<<std::endl;;
    break;}
case 15:
#line 133 "parser.y"
{std::cout<<"RETURN EXP "<<std::endl;;
    break;}
case 16:
#line 135 "parser.y"
{std::cout<<"BREAK "<<std::endl;construct_operation_node(BREAK,0);
    break;}
case 17:
#line 136 "parser.y"
{std::cout<<"CONTINUE "<<std::endl;;
    break;}
case 18:
#line 140 "parser.y"
{yyval.n = construct_operation_node(ASSIGNMENT, 2, construct_identifier_node(yyvsp[-2].sIdx),yyvsp[0].n);;
    break;}
case 19:
#line 145 "parser.y"
{;
    break;}
case 20:
#line 150 "parser.y"
{ yyval.n = construct_operation_node('=', 2, construct_identifier_node(yyvsp[-2].sIdx, yyvsp[-3].iVal), yyvsp[0].n);;
    break;}
case 21:
#line 151 "parser.y"
{ yyval.n = construct_operation_node('=', 2, construct_identifier_node(yyvsp[-2].sIdx, yyvsp[-3].iVal, CONST), yyvsp[0].n);;
    break;}
case 22:
#line 155 "parser.y"
{yyval.iVal=INT_TYPE;
    break;}
case 23:
#line 156 "parser.y"
{yyval.iVal=FLOAT_TYPE;
    break;}
case 24:
#line 157 "parser.y"
{yyval.iVal=BOOL_TYPE;
    break;}
case 25:
#line 158 "parser.y"
{yyval.iVal=STRING_TYPE;
    break;}
case 26:
#line 163 "parser.y"
{std::cout<<"for_statement "<<std::endl; yyval.n = construct_operation_node(FOR, 4, yyvsp[-8].n, yyvsp[-6].n, yyvsp[-4].n, yyvsp[-1].n);;
    break;}
case 27:
#line 166 "parser.y"
{std::cout<<"while_statement "<<std::endl; yyval.n=construct_operation_node(WHILE,2,yyvsp[-4].n,yyvsp[-1].n);;
    break;}
case 28:
#line 170 "parser.y"
{std::cout<<"do_while_statement" <<std::endl; yyval.n=construct_operation_node(DO,2,yyvsp[-5].n,yyvsp[-1].n);;
    break;}
case 29:
#line 174 "parser.y"
{yyval.n=construct_operation_node(IF,2,yyvsp[-4].n,yyvsp[-1].n);;
    break;}
case 30:
#line 175 "parser.y"
{yyval.n=construct_operation_node(IF,3,yyvsp[-8].n,yyvsp[-5].n,yyvsp[-1].n);;
    break;}
case 31:
#line 178 "parser.y"
{yyval.n=construct_operation_node(SWITCH,2,construct_identifier_node(yyvsp[-4].sIdx),yyvsp[-1].n);;
    break;}
case 32:
#line 179 "parser.y"
{yyval.n=construct_operation_node(SWITCH,3,construct_identifier_node(yyvsp[-5].sIdx),yyvsp[-2].n,yyvsp[-1].n);;
    break;}
case 33:
#line 182 "parser.y"
{yyval.n=construct_operation_node(CASE,4,construct_constant_node(INTEGER,INT_TYPE,yyvsp[-4].iVal),yyvsp[-2].n,construct_operation_node(BREAK,0),yyvsp[0].n);;
    break;}
case 34:
#line 183 "parser.y"
{;
    break;}
case 35:
#line 184 "parser.y"
{yyval.n=construct_operation_node(CASE,3,construct_constant_node(INTEGER,INT_TYPE,yyvsp[-3].iVal),yyvsp[-1].n,construct_operation_node(BREAK,0));;
    break;}
case 36:
#line 187 "parser.y"
{yyval.n=construct_operation_node(DEFAULT,1,yyvsp[0].n);;
    break;}
case 37:
#line 193 "parser.y"
{yyval.n = construct_constant_node( INTEGER, INT_TYPE,yyvsp[0].iVal);;
    break;}
case 38:
#line 194 "parser.y"
{yyval.n = construct_constant_node( FLOAT, FLOAT_TYPE,yyvsp[0].fVal);;
    break;}
case 39:
#line 195 "parser.y"
{yyval.n =  construct_constant_node( STRING, STRING_TYPE,yyvsp[0].strVal);;
    break;}
case 40:
#line 196 "parser.y"
{yyval.n =  construct_constant_node( BOOL, BOOL_TYPE,yyvsp[0].bVal);;
    break;}
case 41:
#line 197 "parser.y"
{yyval.n = construct_identifier_node(yyvsp[0].sIdx);;
    break;}
case 42:
#line 199 "parser.y"
{yyval.n=construct_operation_node(NEGATIVE,1,yyvsp[0].n);;
    break;}
case 43:
#line 201 "parser.y"
{yyval.n=construct_operation_node('+',2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 44:
#line 202 "parser.y"
{yyval.n=construct_operation_node('-',2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 45:
#line 203 "parser.y"
{yyval.n=construct_operation_node('*',2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 46:
#line 204 "parser.y"
{yyval.n=construct_operation_node('/',2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 47:
#line 205 "parser.y"
{yyval.n=construct_operation_node('<',2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 48:
#line 206 "parser.y"
{yyval.n=construct_operation_node('>',2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 49:
#line 208 "parser.y"
{yyval.n=construct_operation_node(NOT,2,yyvsp[0].n);;
    break;}
case 50:
#line 209 "parser.y"
{yyval.n=construct_operation_node(AND,2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 51:
#line 210 "parser.y"
{yyval.n=construct_operation_node(OR,2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 52:
#line 211 "parser.y"
{yyval.n=construct_operation_node(GREATER_EQUAL,2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 53:
#line 212 "parser.y"
{yyval.n=construct_operation_node(LESS_EQUAL,2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 54:
#line 213 "parser.y"
{yyval.n=construct_operation_node(EQUAL,2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 55:
#line 214 "parser.y"
{yyval.n=construct_operation_node(NOTEQUAL,2,yyvsp[-2].n,yyvsp[0].n);;
    break;}
case 56:
#line 215 "parser.y"
{yyval.n=yyvsp[-1].n;
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
#line 218 "parser.y"

/* End of Production Rules */


/* Part 5 : Functions and Main */
node *construct_constant_node(int type, int dataType, ...) {
     va_list ap; /* variable argument list */
     node *p;
     size_t nodeSize;

     /* allocate Node */
     nodeSize = SIZEOF_NODETYPE + sizeof(constantNode);
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
  
  nodeSize = SIZEOF_NODETYPE + sizeof(opNode) +
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
  nodeSize = SIZEOF_NODETYPE + sizeof(idNode);
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
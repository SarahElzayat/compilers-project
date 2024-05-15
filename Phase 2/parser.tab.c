
/*  A Bison parser, made from parser.y
 by  GNU Bison version 1.27
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INTEGER	257
#define	FLOAT	258
#define	CHAR	259
#define	BOOL	260
#define	STRING	261
#define	VARIABLE	262
#define	CONSTANT	263
#define	IF	264
#define	SWITCH	265
#define	CASE	266
#define	DEFAULT	267
#define	FOR	268
#define	WHILE	269
#define	DO	270
#define	BREAK	271
#define	CONTINUE	272
#define	CONST	273
#define	INT_TYPE	274
#define	FLOAT_TYPE	275
#define	BOOL_TYPE	276
#define	CHAR_TYPE	277
#define	STRING_TYPE	278
#define	FUNCTION	279
#define	PRINT	280
#define	RETURN	281
#define	IFX	282
#define	ELSE	283
#define	ENDLINE	284
#define	OR	285
#define	AND	286
#define	GREATER_EQUAL	287
#define	LESS_EQUAL	288
#define	EQUAL	289
#define	NOTEQUAL	290
#define	NOT	291

#line 2 "parser.y"

    #include <stdio.h>
    #include "compiler.h"
    #include <stdbool.h>

    extern void export_symbol_table();
    node *construct_operation_node(int oper, int nops, ...);
    node *construct_identifier_node(char*, int = -1, int = -1);
    node *construct_constant_node(int, int, ...);
    void free_node(node *p);
    int execute(node *p, int = -1, int = -1, int = 0, ...);

    int yylex(void);
    void yyerror(const char *msg);

#line 22 "parser.y"
typedef union
{
    int i;              /*   integer  */
    float f;            /*   integer  */
    char c;             /*   char     */
    bool b;              /*   boolean  */
    char *s;            /*   string   */
    char *v;            /*   variable type */
    char *sIdx;           /*   symbol table */
    node *n;            /*   node     */
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		141
#define	YYFLAG		-32768
#define	YYNTBASE	51

#define YYTRANSLATE(x) ((unsigned)(x) <= 291 ? yytranslate[x] : 70)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
    48,    42,    40,     2,    41,     2,    43,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    50,    49,    38,
    31,    39,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    45,     2,    46,     2,     2,     2,     2,     2,
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
    27,    28,    29,    30,    32,    33,    34,    35,    36,    37,
    44
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    15,    17,    19,    21,
    23,    25,    27,    29,    31,    33,    35,    37,    39,    41,
    45,    49,    54,    58,    61,    66,    68,    70,    72,    74,
    76,    82,    87,    97,   103,   110,   116,   124,   132,   141,
   147,   153,   154,   158,   162,   166,   170,   174,   178,   181,
   185,   189,   193,   197,   201,   205,   209,   213,   215,   217,
   219,   221,   223
};

static const short yyrhs[] = {    52,
     0,    53,     0,    52,    53,     0,    54,     0,    55,     0,
    45,    52,    46,     0,    56,     0,    61,     0,    69,     0,
    59,     0,    57,     0,    58,     0,    17,     0,    18,     0,
    62,     0,    63,     0,    65,     0,    64,     0,    66,     0,
     8,    31,    69,     0,     9,    31,    69,     0,    26,    47,
    69,    48,     0,    27,    69,    30,     0,    27,    30,     0,
    25,    47,    69,    48,     0,    20,     0,    21,     0,    22,
     0,    23,     0,    24,     0,    19,    60,     9,    31,    69,
     0,    60,     8,    31,    69,     0,    14,    47,    61,    49,
    69,    49,    56,    48,    53,     0,    15,    47,    69,    48,
    53,     0,    16,    53,    15,    47,    69,    48,     0,    10,
    47,    69,    48,    53,     0,    10,    47,    69,    48,    53,
    29,    53,     0,    11,    47,     8,    48,    45,    67,    46,
     0,    11,    47,     8,    48,    45,    67,    68,    46,     0,
    12,     3,    50,    53,    67,     0,    12,     6,    50,    53,
    67,     0,     0,    13,    50,    53,     0,    69,    40,    69,
     0,    69,    41,    69,     0,    69,    42,    69,     0,    69,
    43,    69,     0,    47,    69,    48,     0,    44,    69,     0,
    69,    33,    69,     0,    69,    32,    69,     0,    69,    34,
    69,     0,    69,    35,    69,     0,    69,    36,    69,     0,
    69,    37,    69,     0,    69,    38,    69,     0,    69,    39,
    69,     0,     3,     0,     4,     0,     5,     0,     7,     0,
     8,     0,     9,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    95,    98,    99,   102,   103,   104,   107,   108,   109,   110,
   111,   112,   113,   114,   117,   118,   119,   120,   121,   125,
   126,   129,   132,   133,   136,   139,   140,   141,   142,   143,
   146,   147,   151,   154,   157,   160,   161,   164,   165,   168,
   169,   170,   173,   176,   177,   178,   179,   180,   181,   182,
   183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
   193,   194,   195
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","INTEGER",
"FLOAT","CHAR","BOOL","STRING","VARIABLE","CONSTANT","IF","SWITCH","CASE","DEFAULT",
"FOR","WHILE","DO","BREAK","CONTINUE","CONST","INT_TYPE","FLOAT_TYPE","BOOL_TYPE",
"CHAR_TYPE","STRING_TYPE","FUNCTION","PRINT","RETURN","IFX","ELSE","ENDLINE",
"'='","OR","AND","GREATER_EQUAL","LESS_EQUAL","EQUAL","NOTEQUAL","'<'","'>'",
"'+'","'-'","'*'","'/'","NOT","'{'","'}'","'('","')'","';'","':'","program",
"statement_list","statement","simple_statement","compound_statement","assignment_statement",
"print_statement","return_expression","function_call","data_type","declaration_statement",
"for_statement","while_statement","do_while_statement","if_statement","switch_statement",
"cases","default_statement","expression", NULL
};
#endif

static const short yyr1[] = {     0,
    51,    52,    52,    53,    53,    53,    54,    54,    54,    54,
    54,    54,    54,    54,    55,    55,    55,    55,    55,    56,
    56,    57,    58,    58,    59,    60,    60,    60,    60,    60,
    61,    61,    62,    63,    64,    65,    65,    66,    66,    67,
    67,    67,    68,    69,    69,    69,    69,    69,    69,    69,
    69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
    69,    69,    69
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     3,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
     3,     4,     3,     2,     4,     1,     1,     1,     1,     1,
     5,     4,     9,     5,     6,     5,     7,     7,     8,     5,
     5,     0,     3,     3,     3,     3,     3,     3,     2,     3,
     3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
     1,     1,     1
};

static const short yydefact[] = {     0,
    58,    59,    60,    61,    62,    63,     0,     0,     0,     0,
     0,    13,    14,     0,    26,    27,    28,    29,    30,     0,
     0,     0,     0,     0,     0,     1,     2,     4,     5,     7,
    11,    12,    10,     0,     8,    15,    16,    18,    17,    19,
     9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    62,    63,    24,     0,    49,     0,     0,     3,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
     0,     0,    23,     6,    48,     0,    51,    50,    52,    53,
    54,    55,    56,    57,    44,    45,    46,    47,     0,     0,
     0,     0,     0,     0,    25,    22,    32,    36,    42,     0,
    34,     0,    31,     0,     0,     0,     0,    35,    37,     0,
     0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
    39,     0,    42,    42,    43,    33,    40,    41,     0,     0,
     0
};

static const short yydefgoto[] = {   139,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,   116,   124,    41
};

static const short yypact[] = {   164,
-32768,-32768,-32768,-32768,   -19,   -10,   -33,   -20,    -6,    13,
   164,-32768,-32768,    43,-32768,-32768,-32768,-32768,-32768,    14,
    26,    15,    35,   164,    35,   164,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    27,-32768,-32768,-32768,-32768,-32768,-32768,
   265,    35,    35,    35,    66,   -17,    35,    60,    67,    35,
    35,-32768,-32768,-32768,   117,-32768,   119,    72,-32768,    46,
    35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
    35,    35,   265,   265,   180,    30,    31,   197,    34,    52,
   214,   231,-32768,-32768,-32768,    35,    59,   275,    28,    28,
    28,    28,    28,    28,   -26,   -26,-32768,-32768,   164,    39,
    35,   164,    35,    35,-32768,-32768,   265,    56,    74,   161,
-32768,   248,   265,   164,     7,   -12,    17,-32768,-32768,    75,
    81,    82,-32768,    70,   -19,   -10,   100,   164,   164,   164,
-32768,   164,    74,    74,-32768,-32768,-32768,-32768,   162,   170,
-32768
};

static const short yypgoto[] = {-32768,
   137,   -11,-32768,-32768,    88,-32768,-32768,-32768,   163,   130,
-32768,-32768,-32768,-32768,-32768,  -102,-32768,   -14
};


#define	YYLAST		318


static const short yytable[] = {    48,
   122,    14,    15,    16,    17,    18,    19,    55,    56,   120,
    58,    42,   121,    44,    59,    71,    72,     1,     2,     3,
    43,     4,    52,    53,   125,   126,    45,    73,    74,    75,
   137,   138,    78,   123,    60,    81,    82,     1,     2,     3,
    46,     4,    52,    53,    54,    59,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    23,    47,
    50,    25,    15,    16,    17,    18,    19,    69,    70,    71,
    72,   107,    51,    76,    79,    80,    86,   100,    23,   101,
   103,    25,   104,   109,   114,   115,   110,   108,   112,   113,
   111,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,   119,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,   131,   133,   134,   135,    85,
   136,     1,     2,     3,   128,     4,     5,     6,     7,     8,
   129,   130,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    83,   132,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    57,   140,    23,    24,    84,    25,     1,     2,     3,   141,
     4,     5,     6,     7,     8,    77,    49,     9,    10,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    22,     0,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,   127,     0,     0,    23,    24,   117,
    25,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,     0,     0,     0,     0,    99,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
     0,     0,     0,     0,   102,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,     0,     0,     0,
     0,   105,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,     0,     0,     0,     0,   106,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,     0,     0,     0,     0,   118,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72
};

static const short yycheck[] = {    11,
    13,    19,    20,    21,    22,    23,    24,    22,    23,     3,
    25,    31,     6,    47,    26,    42,    43,     3,     4,     5,
    31,     7,     8,     9,     8,     9,    47,    42,    43,    44,
   133,   134,    47,    46,     8,    50,    51,     3,     4,     5,
    47,     7,     8,     9,    30,    57,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    44,    47,
    47,    47,    20,    21,    22,    23,    24,    40,    41,    42,
    43,    86,    47,     8,    15,     9,    31,    48,    44,    49,
    47,    47,    31,    45,    29,    12,   101,    99,   103,   104,
   102,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,   114,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    46,   128,   129,   130,    48,
   132,     3,     4,     5,    50,     7,     8,     9,    10,    11,
    50,    50,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    23,    24,    25,    26,    27,    30,    48,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    24,     0,    44,    45,    46,    47,     3,     4,     5,     0,
     7,     8,     9,    10,    11,    46,    14,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,   117,    -1,    -1,    44,    45,    49,
    47,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    -1,    -1,    -1,    -1,    48,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    -1,    -1,    -1,    -1,    48,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
    -1,    48,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    -1,    -1,    -1,    -1,    48,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    -1,    -1,    -1,    -1,    48,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43
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
#line 95 "parser.y"
{;
    break;}
case 3:
#line 99 "parser.y"
{;
    break;}
case 4:
#line 102 "parser.y"
{;
    break;}
case 5:
#line 103 "parser.y"
{;
    break;}
case 6:
#line 104 "parser.y"
{;
    break;}
case 7:
#line 107 "parser.y"
{;
    break;}
case 8:
#line 108 "parser.y"
{;
    break;}
case 9:
#line 109 "parser.y"
{;
    break;}
case 10:
#line 110 "parser.y"
{;
    break;}
case 11:
#line 111 "parser.y"
{;
    break;}
case 12:
#line 112 "parser.y"
{;
    break;}
case 13:
#line 113 "parser.y"
{;
    break;}
case 14:
#line 114 "parser.y"
{;
    break;}
case 20:
#line 125 "parser.y"
{;
    break;}
case 21:
#line 126 "parser.y"
{;
    break;}
case 48:
#line 180 "parser.y"
{yyval.n=yyvsp[-1].n;
    break;}
case 49:
#line 181 "parser.y"
{yyval.n=yyvsp[0].n;
    break;}
case 50:
#line 182 "parser.y"
{yyval.n=yyvsp[-2].n&&yyvsp[0].n;
    break;}
case 58:
#line 190 "parser.y"
{yyval.n=yyvsp[0].i;
    break;}
case 59:
#line 191 "parser.y"
{yyval.n=yyvsp[0].f;
    break;}
case 60:
#line 192 "parser.y"
{yyval.n=yyvsp[0].c;
    break;}
case 61:
#line 193 "parser.y"
{yyval.n=yyvsp[0].s;
    break;}
case 62:
#line 194 "parser.y"
{yyval.n=yyvsp[0].sIdx;
    break;}
case 63:
#line 195 "parser.y"
{yyval.n=yyvsp[0].s;
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
#line 197 "parser.y"

/* End of Production Rules */


/* Part 5 : Functions and Main */
node *construct_constant_node(int type, int dataType, ...) {
    va_list ap; /* variable argument list */
    node *p;
    size_t nodeSize;

    /* allocate Node */
    nodeSize = SIZEOF_NODETYPE + sizeof(constantNode);
    if ((p = (Node*)malloc(nodeSize)) == NULL)
    {
        yyerror("out of memory");
    }

    /* copy information */
    p->type = CONSTANT;
    p->con.dataType = dataType;
    va_start(ap, dataType); /* initialize va */
    p->con.value = va_arg(ap, valType); /* get value */
    va_end(ap); /* clean up va */

    return p;
}

node *construct_op_node(int oper, int nOpers, ...) {
  va_list ap; /* variable argument list */
  node *p;
  size_t nodeSize;
  int i = 0;
  
  /* allocate Node */
  nodeSize = SIZEOF_NODETYPE + sizeof(opNode) +
    (nOpers - 1) * sizeof(node*);
  if ((p = (Node*)malloc(nodeSize)) == NULL)
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

node *construct_id_node(char* i, int dataType, int qualifier) {
  node *p;
  size_t nodeSize;
  /* allocate Node */
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
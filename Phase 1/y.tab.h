
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     FLOAT = 259,
     CHAR = 260,
     BOOL = 261,
     STRING = 262,
     VARIABLE = 263,
     CONSTANT = 264,
     IF = 265,
     SWITCH = 266,
     CASE = 267,
     DEFAULT = 268,
     FOR = 269,
     WHILE = 270,
     DO = 271,
     BREAK = 272,
     CONTINUE = 273,
     CONST = 274,
     INT_TYPE = 275,
     FLOAT_TYPE = 276,
     BOOL_TYPE = 277,
     CHAR_TYPE = 278,
     STRING_TYPE = 279,
     FUNCTION = 280,
     PRINT = 281,
     RETURN = 282,
     IFX = 283,
     ELSE = 284,
     ENDLINE = 285,
     OR = 286,
     AND = 287,
     NOTEQUAL = 288,
     EQUAL = 289,
     LESS_EQUAL = 290,
     GREATER_EQUAL = 291,
     NOT = 292
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOAT 259
#define CHAR 260
#define BOOL 261
#define STRING 262
#define VARIABLE 263
#define CONSTANT 264
#define IF 265
#define SWITCH 266
#define CASE 267
#define DEFAULT 268
#define FOR 269
#define WHILE 270
#define DO 271
#define BREAK 272
#define CONTINUE 273
#define CONST 274
#define INT_TYPE 275
#define FLOAT_TYPE 276
#define BOOL_TYPE 277
#define CHAR_TYPE 278
#define STRING_TYPE 279
#define FUNCTION 280
#define PRINT 281
#define RETURN 282
#define IFX 283
#define ELSE 284
#define ENDLINE 285
#define OR 286
#define AND 287
#define NOTEQUAL 288
#define EQUAL 289
#define LESS_EQUAL 290
#define GREATER_EQUAL 291
#define NOT 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 16 "parser.y"

    int i;              /* integer */
    float f;            /* integer */
    char c;             /* char */
    int b;           /*  boolean */
    char *s;            /* string */



/* Line 1676 of yacc.c  */
#line 136 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;




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

/* Line 1676 of yacc.c  */
#line 30 "parser.y"

  int intValue;                          /* integer  */
  float floatValue;                      /* double   */
  char* stringValue;                     /* string   */
  bool boolValue;                        /* boolean  */

  char *sIndex;                       /* symbol table index */
  char *varType;                      /* variable type      */
  Node *nodePtr;                      /*   node             */



/* Line 1676 of yacc.c  */
#line 104 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



/* Part 1 : Definitions */
%{
    #include "y.tab.h"
    #include "compiler.h"
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(char *);
%}
/* End of Definitions */


/* Part 2 : Regular Expressions */
%%

/* 1. Data Types. */
"const"             {return CONSTANT;}
"int"               {return TYPE_INT;}
"float"             {return TYPE_FLOAT;} 
"bool"              {return TYPE_BOOL;}

/* 2. Variables and Constants declaration. */
[a-zA-Z_][a-zA-Z0-9_]*      {return VARIABLE;}
[A-Z_][A-Z0-9_]*            {return CONSTANT;}

/* 3. Mathematical and logical expressions. */

/* Numerical Values */
/* INTEGERS */
[0-9]+                      { yylval.i = atoi(yytext); return INTEGER;}

/* FLOATS */
(0|[1-9][0-9]*)\.[0-9]*     {yylval.f = atof(yytext); return FLOAT;}

/* BOOLS */
"true"     {return BOOL;}
"false"     {return BOOL;}

/* Operations / Special Characters */
[()+-*/{}<>=.^]              { return yytext[0];}

/* Logical Operators */
"&&"                        { return AND; }
"||"                        { return OR; }
"!"                         { return NOT; }
"=="                        {return EQUAL;}
"!="                        {return NOT_EQUAL;}
"<"                         {return LESS;}
">"                         {return GREATER;}
"<="                        {return LESS_EQUAL;}
">="                        {return GREATER_EQUAL;}


/* 4. Assignment statements. */

/* 5. If-then-else statement, while loops, repeat-until loops, for loops, switch statement. */
/* KEYWORDS */
"if" { return IF; }
"else" { return ELSE; }
"elif"  { return ELIF; }
"while" { return WHILE; }
"for" { return FOR; }
"switch" { return SWITCH; }
"case" { return CASE; }
"default" { return DEFAULT; }
"break" { return BREAK; }
"continue" { return CONTINUE; }
"return" { return RETURN; }
"print" { return PRINT; }
"true" { return TRUE; }
"false" { return FALSE; }

/* 6. Block structure (nested scopes where variables may be declared at the  beginning of blocks).*/
/*
not sure yet bas i think it will go something like this
{and any characters inside} { return BLOCK; } bas we have to check that the braces are balanced
*/

/* 7. Function */
"def" { return FUNCTION; }


/* Skip whitspaces and comments */
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \n\t]*                      { ; }


/* Unkown Characters */
.      { char msg[1024];
        sprintf(msg, "Unknown character: %s", yytext);
        yyerror(msg);}


%%
/* End of Production Rules */

int yywrap(void) {
    return 1;
}

void yyerror(const char *s) {
  fprintf(stderr, "Line %d: %s\n", yylineno, s);
  exit(0);
}

/* Part 3 : Functions and Main*/

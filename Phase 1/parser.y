/* Part 1 : Definitions */
%{
    #include <stdio.h>
    #include "compiler.h"
    #include <stdbool.h>
    
    int yylex(void);
    void yyerror(const char *);
%}
/* End of Definitions */



/* Part 2 : Unions */
%union
{
    int i;              /* integer */
    float f;            /* integer */
    char c;             /* char */
    int b;           /*  boolean */
    char *s;            /* string */
}

/* End of Unions */

/* Part 3 : Tokens */
/* 
Keyword     Description
%left	    Identifies tokens that are left-associative with other tokens.
%nonassoc	Identifies tokens that are not associative with other tokens.
%right	    Identifies tokens that are right-associative with other tokens.
%start	    Identifies a nonterminal name for the start symbol.
%token	    Identifies the token names that the yacc command accepts. Declares all token names in the declarations section.
%type	    Identifies the type of nonterminals. Type-checking is performed when this construct is present.
%union	    Identifies the yacc value stack as the union of the various type of values desired. By default, the values returned are integers. The effect of this construct is to provide the declaration of YYSTYPE directly from the input.
*/


/* Terminal names */
                                              

/* Data types */
%token <i> INTEGER
%token <f> FLOAT
%token <c> CHAR
%token <b> BOOL
%token <s> STRING

%token <s> VARIABLE
%token <s> CONSTANT
/* Keywords */
%token IF                                                 /* Keywords for if statement */
%token SWITCH CASE DEFAULT                                          /* Keywords for switch statement */
%token FOR WHILE DO BREAK CONTINUE                                  /* Keywords for loops */
%token CONST INT_TYPE FLOAT_TYPE BOOL_TYPE CHAR_TYPE STRING_TYPE    /* Keywords for data types */
%token FUNCTION                                                     /* Keyword for function declaration */
%token PRINT                                                        /* Keyword for print */
%nonassoc RETURN
%nonassoc IFX                                                      /* Keyword for If statement precedance handling*/
%nonassoc ELSE                                                      /* Keyword for else statement */
%nonassoc ENDLINE 
/* Operators */
/* The order matters as we go down the precedence of the operator increases */
/* left and right keywords gove  */

%right '='
%left OR
%left AND
%left GREATER_EQUAL LESS_EQUAL EQUAL NOTEQUAL '<' '>'
%left '+' '-'
%left '*' '/'
%right NOT


/* Non Terminal Types */

/* End of Tokens */


/* Part 4 : Production Rules */
%%

program : statement_list
        ;

statement_list : statement
               | statement_list statement
               ;

statement : simple_statement
          | compound_statement
          | '{' statement_list '}'
          ;

simple_statement : assignment_statement
                 | declaration_statement
                 | expression
                 | function_call
                 | print_statement
                 | return_expression
                 | BREAK
                 | CONTINUE
                 ;

compound_statement : for_statement
                   | while_statement
                   | if_statement
                   | do_while_statement
                   | switch_statement
                   ;


assignment_statement : VARIABLE '=' expression
                     | CONSTANT '=' expression
                     ;

print_statement : PRINT '(' expression ')' 
                ;   
 
return_expression : RETURN expression ENDLINE
                  | RETURN ENDLINE
                  ;

function_call : FUNCTION '(' expression ')'
            ;

data_type : INT_TYPE
          | FLOAT_TYPE
          | BOOL_TYPE
          | CHAR_TYPE
          | STRING_TYPE
          ;

declaration_statement : CONST data_type CONSTANT '=' expression
                      | data_type VARIABLE '=' expression
                      ;


for_statement : FOR '(' declaration_statement ';' expression ';' assignment_statement ')' statement
              ;

while_statement : WHILE '(' expression ')' statement
                ;

do_while_statement : DO statement WHILE '(' expression ')'
                   ;

if_statement : IF '(' expression ')' statement %prec IFX
             | IF '(' expression ')' statement ELSE statement
             ;

switch_statement :  SWITCH '(' VARIABLE ')' '{' cases '}'
                 |  SWITCH '(' VARIABLE ')' '{' cases  default_statement'}'
                 ;

cases : CASE INTEGER ':' statement cases
      | CASE BOOL ':' statement cases
      |
      ;

default_statement : DEFAULT ':' statement

 
expression : expression '+' expression 
           | expression '-' expression 
           | expression '*' expression 
           | expression '/' expression 
           | '(' expression ')' 
           | NOT expression
           | expression AND expression
           | expression OR expression
           | expression GREATER_EQUAL expression
           | expression LESS_EQUAL expression
           | expression EQUAL expression
           | expression NOTEQUAL expression
           | expression '<' expression
           | expression '>' expression     
           | INTEGER
           | FLOAT
           | CHAR
           | STRING                   
           | VARIABLE                  
           | CONSTANT
           ;
%%
/* End of Production Rules */


/* Part 5 : Functions and Main */
int main(void)
{
    yyparse();
    return 0;
}
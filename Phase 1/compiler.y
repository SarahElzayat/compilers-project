/* Part 1 : Definitions */
%{
    #include <stdio.h>
    #include "compiler.h"
    #include <stdbool.h>

    Node *get_Constant_Node(int, int, ...);                 /*creating a Node for a constant*/
    Node *get_Operation_Node(int op, int nops, ...);        /*creating a Node for an operation*/
    Node *get_Identifier_Node(char*, int = -1, int = -1);   /*creating a Node for an identifier Variable*/
    
    void freeNode(Node *p);                                 /*freeing the memory allocated to a Node*/

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
    /* bool b; */       /* boolean */
    char *s;            /* string */
    Node *nPtr;         /* Node pointer */
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
%token <s> VARIABLE
%token <s> CONSTANT

/* Data types */
%token <i> INTEGER
/* %token <f> FLOAT
%token <c> CHAR
%token <b> BOOL
%token <s> STRING */

/* Keywords */
/* %token IF ELSE ELIF Keywords for if statement */
/* %token SWITCH CASE DEFAULT Keywords for switch case statement */
/* %token FOR WHILE DO BREAK CONTINUE Keywords for loops */
/* %token CONST INT_TYPE FLOAT_TYPE BOOL_TYPE CHAR_TYPE Keywords for data types */
%token RETURN /* Keyword for return statement */
%token FUNCTION /* Keyword for function declaration */
%token PRINT /* Keyword for print */
/* %token TRUE FALSE Keywords for boolean values */

/* Operators */
/* The order matters as we go down the precedence of the operator increases */
/* left and right keywords gove  */

%right '='
/* %left OR
%left AND
%left GREATER_EQUAL LESS_EQUAL EQUAL NOTEQUAL */
%left '+' '-'
%left '*' '/'
/* %right NOT */


/* Non Terminal Types */
%type <i> expression
 

/* End of Tokens */


/* Part 4 : Production Rules */
%%

program : statement_list
        ;

statement_list : statement
               ;

statement : simple_statement
          | compound_statement
          ;

simple_statement : assignment_statement
                 | return_statement 
                 | print_statement
                 | function_call
                 ;

compound_statement : 
                  ;


assignment_statement : VARIABLE '=' expression
                     | CONSTANT '=' expression
                     ;

return_statement : RETURN expression
                 | RETURN
                 ;

print_statement : PRINT expression
                ;          

function_call : FUNCTION '(' expression ')'
            ;

expression : expression '+' expression 
           | expression '-' expression 
           | expression '*' expression 
           | expression '/' expression 
           | '(' expression ')'        
           | INTEGER                   
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
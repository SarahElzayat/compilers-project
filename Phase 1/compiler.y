/* Part 1 : Definitions */
%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}
/* End of Definitions */



/* Part 2 : Unions */
%union
{
    int i;
    float f;
    char c;
    bool b;
    char *s;
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
%token VARIABLE
%token CONSTANT

/* Data types */
%token <i> INTEGER
%token <f> FLOAT
%token <c> CHAR
%token <b> BOOL
%token <s> STRING

/* Keywords */
%token IF ELSE ELIF /* Keywords for if statement */
%token SWITCH CASE DEFAULT /* Keywords for switch case statement */
%token FOR WHILE DO BREAK CONTINUE /* Keywords for loops */
%token CONST INT_TYPE FLOAT_TYPE BOOL_TYPE CHAR_TYPE /* Keywords for data types */
%token RETURN /* Keyword for return statement */
%token FUNCTION /* Keyword for function declaration */
%token PRINT /* Keyword for print */
%token TRUE FALSE /* Keywords for boolean values */

/* Operators */
/* The order matters as we go down the precedence of the operator increases */
/* left and right keywords gove  */

%right '='
%left OR
%left AND
%left GREATER_EQUAL LESS_EQUAL EQUAL NOTEQUAL GREATER LESS
%left '+' '-'
%left '*' '/'
%right NOT


/* Non Terminal Types */
%type <i> expression

 

/* End of Tokens */


/* Part 4 : Production Rules */
%%
/* Example */
declaration: VARIABLE '=' expression
            | VARIABLE '=' CONSTANT
            ;

expression: expression '+' expression
            | expression '-' expression
            | expression '*' expression
            | expression '/' expression
            | '(' expression ')'
            | CONSTANT
            | INTEGER
            | FLOAT
            | CHAR
            | BOOL
            | VARIABLE
            | STRING
            ;


%%
/* End of Production Rules */


/* Part 5 : Functions and Main */
void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
    exit(1);
}

int main(void)
{
    yyparse();
    return 0;
}
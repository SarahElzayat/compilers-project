%{  
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
%}


/* End of Definitions */



/* Part 2 : Unions */
%union
{
    int i;              /*   integer  */
    float f;            /*   integer  */
    char c;             /*   char     */
    bool b;              /*   boolean  */
    char *s;            /*   string   */
    char *v;            /*   variable type */
    char *sIdx;           /*   symbol table */
    node *n;            /*   node     */
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
%token <sIdx> VARIABLE

/* %token <s> VARIABLE */
%token <s> CONSTANT
/* Keywords */
%token IF                                                 /* Keywords for if statement */
%token SWITCH CASE DEFAULT                                          /* Keywords for switch statement */
%token FOR WHILE DO BREAK CONTINUE                                  /* Keywords for loops */
%token CONST_TYPE INT_TYPE FLOAT_TYPE BOOL_TYPE CHAR_TYPE STRING_TYPE    /* Keywords for data types */
%token FUNCTION                                                     /* Keyword for function declaration */
%token PRINT                                                        /* Keyword for print */
%nonassoc RETURN
%nonassoc IFX                                                      /* Keyword for If statement precedance handling*/
%nonassoc ELSE                                                      /* Keyword for else statement */
%nonassoc ENDLINE 
///print 

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
%type <n> program statement_list statement simple_statement compound_statement assignment_statement 
%type <n> print_statement return_expression function_call declaration_statement 
%type <n> for_statement while_statement do_while_statement if_statement switch_statement cases default_statement expression
%type <n> data_type

/* End of Tokens */


/* Part 4 : Production Rules */
%%

program : statement_list
        ;

statement_list : statement                  {execute($1);}
               | statement_list statement     {}
               ;

statement : simple_statement                  {}
          | compound_statement                 {}
          | '{' statement_list '}'              {}
          ;

simple_statement : assignment_statement         {}
                 | declaration_statement        {}
                 | expression                   {}
                 | function_call                {}
                 | print_statement               {}
                 | return_expression              {}    
                 | BREAK                          {}
                 | CONTINUE                 {}
                 ;

compound_statement : for_statement      {}
                   | while_statement      {}
                   | if_statement         {}
                   | do_while_statement     {}
                   | switch_statement     {}
                   ;



assignment_statement : VARIABLE '=' expression     {$$ = construct_operation_node(ASSIGNMENT, 2, construct_identifier_node($1),$3);}
                     | CONSTANT '=' expression    {}
                     ;

print_statement : PRINT '(' expression ')'    {$$ = construct_operation_node(PRINT, 1,$3);}
                ;   
return_expression : RETURN expression ENDLINE   {}
                  | RETURN ENDLINE                {}
                  ;

function_call : FUNCTION '(' expression ')'   {}
            ;

data_type : INT_TYPE      {}
          | FLOAT_TYPE    {}
          | BOOL_TYPE   {}
          | CHAR_TYPE     {}
          | STRING_TYPE     {}
          ;

declaration_statement : CONST_TYPE data_type CONSTANT '=' expression    {}
                      | data_type VARIABLE '=' expression             {}
                      ;


for_statement : FOR '(' declaration_statement ';' expression ';' assignment_statement ')' statement   {}
              ;

while_statement : WHILE '(' expression ')' statement    {}
                ;

do_while_statement : DO statement WHILE '(' expression ')'        {}
                    ;

if_statement : IF '(' expression ')' statement %prec IFX              {}
             | IF '(' expression ')' statement ELSE statement         {}
             ;

switch_statement :  SWITCH '(' VARIABLE ')' '{' cases '}'                           {}
                 |  SWITCH '(' VARIABLE ')' '{' cases  default_statement'}'           {}
                 ;

cases : CASE INTEGER ':' statement cases                  {}
      | CASE BOOL ':' statement cases           {}
      |                                           {}
      ;

default_statement : DEFAULT ':' statement     {}

 
expression : expression '+' expression            {$$=construct_operation_node('+',2,$1,$3);}
           | expression '-' expression            {$$=construct_operation_node('-',2,$1,$3);}
           | expression '*' expression            {$$=construct_operation_node('*',2,$1,$3);}
           | expression '/' expression            {$$=construct_operation_node('/',2,$1,$3);}
           | '(' expression ')'                   {$$=$2}
           | NOT expression                       {$$=construct_operation_node(NOT,2,$2);}
           | expression AND expression        {$$=construct_operation_node(AND,2,$1,$3);}
           | expression OR expression         {$$=construct_operation_node(OR,2,$1,$3);}
           | expression GREATER_EQUAL expression    {$$=construct_operation_node(GREATER_EQUAL,2,$1,$3);}
           | expression LESS_EQUAL expression     {$$=construct_operation_node(LESS_EQUAL,2,$1,$3);}
           | expression EQUAL expression      {$$=construct_operation_node(EQUAL,2,$1,$3);}
           | expression NOTEQUAL expression   {$$=construct_operation_node(NOTEQUAL,2,$1,$3);}
           | expression '<' expression          {$$=construct_operation_node('<',2,$1,$3);}
           | expression '>' expression         {$$=construct_operation_node('>',2,$1,$3);}
           | INTEGER                    {$$ = construct_value_node( INTEGER, $1,0.0,0,NULL);}
           | FLOAT                     {$$ = construct_value_node(FLOAT,0,$1,0,NULL);}
           | CHAR                      {$$ = construct_value_node(CHAR,0,0.0,$1,NULL);}
           | STRING                     {$$ = construct_value_node(STRING,0,0.0,0,$1);}             
           | VARIABLE                               {$$= construct_identifier_node($1)}
           | CONSTANT                               {}
           ;
%%
/* End of Production Rules */


/* Part 5 : Functions and Main */
node *construct_constant_node(int type, int dataType, ...) {
    // va_list ap; /* variable argument list */
    // node *p;
    // size_t nodeSize;

    // /* allocate Node */
    // nodeSize = SIZEOF_NODETYPE + sizeof(constantNode);
    // if ((p = (node*)malloc(nodeSize)) == NULL)
    // {
    //     yyerror("out of memory");
    // }

    // /* copy information */
    // p->type = CONST;
    // p->con.dataType = dataType;
    // va_start(ap, dataType); /* initialize va */
    // p->con.value = va_arg(ap, valType); /* get value */
    // va_end(ap); /* clean up va */

    // return p;
}

node *construct_value_node(int dataType,int intValue, float floatValue, char charValue, char *stringValue) {

  
    node *p;

    /* allocate node */
    if ((p = (node *)malloc(sizeof(node))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = VALUE;
    p->value.type=dataType;

    switch (dataType)
    {
      
      case INTEGER:
  
        p->value.intValue = intValue;
        
        break;
      case FLOAT:
        p->value.floatValue = floatValue;
        
        break;
      case CHAR:
        p->value.charValue = charValue;
        

        break;
      case STRING:
        p->value.stringValue = stringValue;
        break;
        /* case BOOL:
        p->value.boolValue = 0.0;
        break; */
    }

    return p;
}

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
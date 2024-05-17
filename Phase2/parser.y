%{  

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
%}

/* End of Definitions */



/* Part 2 : Unions of yylval */
%union
{
    int iVal;              /*   integer       */
    float fVal;            /*   float         */
    bool bVal;             /*   boolean       */
    char *strVal;          /*   string        */

    char *conName;         /*   constant      */
    char *varName;         /*   variable      */

    char *sIdx;            /*   symbol table  */

    node *n;               /*   node          */
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
%token <iVal> INTEGER
%token <fVal> FLOAT
%token <bVal> BOOL
%token <strVal> STRING

%token <sIdx> VARIABLE

/* Keywords */
%token IF                                                                /* Keywords for if statement */
%token SWITCH CASE DEFAULT                                               /* Keywords for switch statement */
%token FOR WHILE DO BREAK CONTINUE                                       /* Keywords for loops */
%token CONST INT_TYPE FLOAT_TYPE BOOL_TYPE STRING_TYPE              /* Keywords for data types */
%token FUNCTION                                                          /* Keyword for function declaration */
%token PRINT                                                             /* Keyword for print */


%nonassoc RETURN
%nonassoc IFX                                                       /* Keyword for If statement precedance handling*/
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
%nonassoc NEGATIVE

/* Non Terminal Types */
%type <n> program statement_list statement assignment_statement 
%type <n> function_call declaration_statement 
%type <n> for_statement while_statement do_while_statement if_statement switch_statement cases expression default_statement
%type <iVal> data_type

/* End of Tokens */


/* Part 4 : Production Rules */
%%

program : statement_list   {execute($1);free_node($1); std::cout<<"program "<<std::endl;exit(0);}
        ;

statement_list : statement                    {$$=$1;}
               | statement_list statement     {$$=construct_operation_node(STATEMENT_LIST,2,$1,$2);}
               ;

statement : assignment_statement              {std::cout<<"assignment_statement "<<std::endl;   $$=$1;}
          | declaration_statement             {std::cout<<"declaration_statement "<<std::endl;  $$=$1;}
          | expression                        {std::cout<<"expression "<<std::endl; $$=$1;}

          | PRINT '(' expression ')'          {std::cout<<"PRINT EXP "<<std::endl;  $$=construct_operation_node(PRINT,1,$3);}


          | for_statement                     {std::cout<<"for_statement "<<std::endl;}
          | while_statement                   {std::cout<<"while_statement "<<std::endl;$$=$1}
          | do_while_statement                {std::cout<<"do_while_statement "<<std::endl;}

          | if_statement                      {std::cout<<"if_statement "<<std::endl;$$=$1;}
          | switch_statement                  {std::cout<<"switch_statement "<<std::endl;}
          | function_call                     {std::cout<<"function_call "<<std::endl;}


          | RETURN ENDLINE                    {std::cout<<"RETURN "<<std::endl;}
          | RETURN expression ENDLINE         {std::cout<<"RETURN EXP "<<std::endl;}

          | BREAK                             {std::cout<<"BREAK "<<std::endl;construct_operation_node(BREAK,0)}
          | CONTINUE                          {std::cout<<"CONTINUE "<<std::endl;}
          ;


assignment_statement : VARIABLE '=' expression  {$$ = construct_operation_node(ASSIGNMENT, 2, construct_identifier_node($1),$3);}
                     ;

              

function_call : FUNCTION '(' expression ')'   {}
            ;



declaration_statement : data_type VARIABLE '=' expression    { $$ = construct_operation_node('=', 2, construct_identifier_node($2, $1), $4);}
                      | CONST data_type VARIABLE '=' expression    { $$ = construct_operation_node('=', 2, construct_identifier_node($3, $2, CONST), $5);}
                      ;


data_type : INT_TYPE          {$$=INT_TYPE}
          | FLOAT_TYPE        {$$=FLOAT_TYPE}
          | BOOL_TYPE         {$$=BOOL_TYPE}
          | STRING_TYPE       {$$=STRING_TYPE}
          ;


/* Loops */
for_statement : FOR '(' declaration_statement ';' expression ';' assignment_statement ')' '{'statement_list'}'   {std::cout<<"for_statement "<<std::endl; $$ = construct_operation_node(FOR, 4, $3, $5, $7, $10);}
              ;

while_statement : WHILE '(' expression ')'  '{' statement_list '}'    {std::cout<<"while_statement "<<std::endl; $$=construct_operation_node(WHILE,2,$3,$6);}
                ;


do_while_statement : DO '{' statement_list '}' WHILE '(' expression ')'        {std::cout<<"do_while_statement" <<std::endl; $$=construct_operation_node(DO,2,$3,$7);}
                    ;

/* Conditional Statement */
if_statement : IF '(' expression ')' '{' statement_list '}' %prec IFX                         {$$=construct_operation_node(IF,2,$3,$6);}
             | IF '(' expression ')' '{' statement_list '}'ELSE '{' statement_list  '}'       {$$=construct_operation_node(IF,3,$3,$6,$10);}
              ;

switch_statement :  SWITCH '(' VARIABLE ')' '{' cases '}'                           {$$=construct_operation_node(SWITCH,2,construct_identifier_node($3),$6);}
                 |  SWITCH '(' VARIABLE ')' '{' cases  default_statement'}'          {$$=construct_operation_node(SWITCH,3,construct_identifier_node($3),$6,$7);}
                 ;

cases : CASE INTEGER ':' statement BREAK cases                  {$$=construct_operation_node(CASE,4,construct_constant_node(INTEGER,INT_TYPE,$2),$4,construct_operation_node(BREAK,0),$6);}
      | CASE BOOL ':' statement BREAK cases                     {}
      | CASE INTEGER ':' statement  BREAK                 {$$=construct_operation_node(CASE,3,construct_constant_node(INTEGER,INT_TYPE,$2),$4,construct_operation_node(BREAK,0));}
      ;

default_statement : DEFAULT ':' statement     {$$=construct_operation_node(DEFAULT,1,$3);}
                  ;
 
 
expression : 
            /*Terminal*/
            INTEGER                    {$$ = construct_constant_node( INTEGER, INT_TYPE,$1);}
           | FLOAT                     {$$ = construct_constant_node( FLOAT, FLOAT_TYPE,$1);}
           | STRING                    {$$ =  construct_constant_node( STRING, STRING_TYPE,$1);}  
           | BOOL                      {$$ =  construct_constant_node( BOOL, BOOL_TYPE,$1);}
           | VARIABLE                  {$$ = construct_identifier_node($1);}
           /*Negative*/
            | '-' expression %prec NEGATIVE        {$$=construct_operation_node(NEGATIVE,1,$2);}  
           /*Mathimatical*/
           | expression '+' expression            {$$=construct_operation_node('+',2,$1,$3);}
           | expression '-' expression            {$$=construct_operation_node('-',2,$1,$3);}
           | expression '*' expression            {$$=construct_operation_node('*',2,$1,$3);}
           | expression '/' expression            {$$=construct_operation_node('/',2,$1,$3);}
           | expression '<' expression          {$$=construct_operation_node('<',2,$1,$3);}
           | expression '>' expression         {$$=construct_operation_node('>',2,$1,$3);}
           /*Logical*/
           | NOT expression                       {$$=construct_operation_node(NOT,2,$2);}
           | expression AND expression        {$$=construct_operation_node(AND,2,$1,$3);}
           | expression OR expression         {$$=construct_operation_node(OR,2,$1,$3);}
           | expression GREATER_EQUAL expression    {$$=construct_operation_node(GREATER_EQUAL,2,$1,$3);}
           | expression LESS_EQUAL expression     {$$=construct_operation_node(LESS_EQUAL,2,$1,$3);}
           | expression EQUAL expression      {$$=construct_operation_node(EQUAL,2,$1,$3);}
           | expression NOTEQUAL expression   {$$=construct_operation_node(NOTEQUAL,2,$1,$3);}
           | '(' expression ')'                   {$$=$2}
           ;
           
%%
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
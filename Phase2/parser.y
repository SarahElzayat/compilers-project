%{

      //INCLUDES
    #include <stdio.h>
    #include "compiler.h"
    #include <stdbool.h>
    //----------------------------------------------
    //Function Prototypes
    extern void log_symbol_table();
    extern void log_errors(int,const char *);
    extern void check_unused();
    //----------------------------------------------
    Node *construct_operation_node(int oper, int nops, ...);
    Node *construct_identifier_node(char*, int = -1, int = -1);
    Node *construct_constant_node(int, int, ...);
    //----------------------------------------------

    void free_node(Node *p);
    int execute_all(Node *p, int = -1, int = -1, int = 0, ...);

    //----------------------------------------------
    int yylex(void);
    void yyerror(const char *emsg);
    extern int line;
    //----------------------------------------------
%}
/* End of Definitions */

/* Part 2 : Unions of yylval */
%union {
  int intValue;                          /* integer  */
  float floatValue;                      /* double   */
  char* stringValue;                     /* string   */
  bool boolValue;                        /* boolean  */

  char *sIndex;                       /* symbol table index */
  char *varType;                      /* variable type      */
  Node *nodePtr;                      /*   node             */
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


/* Data types */
%token <intValue> INTEGER
%token <floatValue> FLOAT
%token <stringValue> STRING
%token <boolValue> BOOL

%token <sIndex> VARIABLE

/* Keywords */
%token IF                                                                /* Keywords for if statement */
%token SWITCH CASE DEFAULT  SWITCH_BODY                                             /* Keywords for switch statement */
%token FOR WHILE DO REPEAT BREAK CONTINUE                                       /* Keywords for loops */
%token CONST INT_TYPE FLOAT_TYPE BOOL_TYPE STRING_TYPE  VOID_TYPE  DECLARE_ONLY           /* Keywords for data types */
%token FUNCTION                                                          /* Keyword for function declaration */
%token PRINT                                                             /* Keyword for print */
%token RETURN 
%token BLOCK

%nonassoc IFX
%nonassoc ELSE

/* End of Tokens */

/* Operators */
/* The order matters as we go down the precedence of the operator increases */
/* left and right keywords gove  */
%right '='
%left OR
%left AND
%left GREATER_EQUAL LESS_EQUAL EQUAL NOT_EQUAL '>' '<'
%left '+' '-'
%left '*' '/' '%'
%right NOT 
%nonassoc NEGATIVE


/* Non Terminal Types */
%type <nodePtr> statement statement_list  expression  rhs_nexted_expression
%type <nodePtr> declaration_statement  assignment_statement functions
%type <nodePtr> for_statement for_declaration for_mid_stmt for_assignment   
%type <nodePtr> while_statement if_statement do_while_statement switch_statement
%type <nodePtr> switch_body cases default_statement case_statement
/* %type <nodePtr> function_declaration parameter_list */
%type <intValue> data_type


/* Part 4 : Production Rules */
%%

program: functions      { /*last thing to finish*/ check_unused_variables();}
        ;

functions: functions statement { execute_all($2); free_node($2); }
          | {$$ = NULL;}
          ;


statement: ';'                                 { $$ = construct_operation_node(';', 2, NULL, NULL); }
          | expression ';'                     { /*std::cout<<"expression "<<std::endl;*/ $$ = $1; }
          | PRINT expression ';'               { /*std::cout<<"PRINT "<<std::endl;*/$$ = construct_operation_node(PRINT, 1, $2); }

          | assignment_statement ';'           { /*std::cout<<"assignment_statement "<<std::endl;*/ $$ = $1; } 
          | declaration_statement ';'          { /*std::cout<<"declaration_statement "<<std::endl;*/ $$ = $1; }
          
          | while_statement                    { /*std::cout<<"while_statement "<<std::endl;*/ $$ = $1; }
          | do_while_statement                 { /*std::cout<<"do_while_statement "<<std::endl;*/ $$ = $1; }
          | for_statement                      { /*std::cout<<"for_statement "<<std::endl;*/ $$ = $1; }
          
          | if_statement                       { /*std::cout<<"if_statement "<<std::endl;*/ $$ = $1; }
          | switch_statement                   { /*std::cout<<"switch_statement "<<std::endl;*/ $$ = $1; }
          | '{' statement_list '}'             { /*std::cout<<"statement_list_block "<<std::endl;*/ $$ = construct_operation_node(BLOCK, 1, $2);; }
          | BREAK ';'                          { /*std::cout<<"BREAK "<<std::endl;*/ $$ = construct_operation_node(BREAK, 1, NULL); }
          | CONTINUE ';'                       { /*std::cout<<"CONTINUE "<<std::endl;*/$$ = construct_operation_node(CONTINUE, 1, NULL); }
          ;

/* Functions */
/* function_declaration: FUNCTION data_type VARIABLE'(' parameter_list')' '{'statement '}'  {$$=construct_operation_node(FUNCTION,4,$2,construct_identifier_node($3),$5,$8);}

parameter_list: declaration_statement ',' parameter_list          {$$=construct_operation_node(COMMA,2,$1,$3);}
              | declaration_statement                              {$$=$1;}
              |{$$=NULL}
              ; */


/* Loops */
while_statement:
  WHILE '(' expression ')' statement { $$ = construct_operation_node(WHILE, 2, $3, $5); }
  ;

do_while_statement: DO statement_list REPEAT expression ';' { $$ = construct_operation_node(DO, 2, $2, $4); }
                  ;

for_statement: FOR '(' for_declaration ';' for_mid_stmt ';' for_assignment ')' '{' statement_list '}' { $$ = construct_operation_node(FOR, 4, $3, $5, $7, $10); }
  ;

/* Conditional Statements */
if_statement: IF '(' expression ')' '{' statement_list '}' %prec IFX { $$ = construct_operation_node(IF, 2, $3, $6); }
            | IF '(' expression ')' '{' statement_list '}' ELSE '{' statement_list '}' { $$ = construct_operation_node(IF, 3, $3, $6, $10); }
            ;

switch_statement: SWITCH '(' expression ')' '{' switch_body '}' { $$ = construct_operation_node(SWITCH, 2, $3, $6); }
                ;

switch_body:
  cases { /*$$ = construct_operation_node(SWITCH_BODY, 1, $1);*/ }
  | cases default_statement { /*$$ = construct_operation_node(SWITCH_BODY, 2, $1, $2);*/ }
  ;

cases:
  CASE INTEGER ':' case_statement cases { $$ = construct_operation_node(CASE, 3, construct_constant_node(INTEGER, INT_TYPE, $2), $4, $5); }
  | CASE BOOL ':' case_statement cases { $$ = construct_operation_node(CASE, 3, construct_constant_node(BOOL, BOOL_TYPE, $2), $4, $5); }
  | { $$ = construct_operation_node(';', 2, NULL, NULL); }
  ;

default_statement:
  DEFAULT ':' case_statement { $$ = construct_operation_node(DEFAULT, 1, $3); }
  ;

case_statement: 
  statement_list { $$ = $1; }
  | { $$ = construct_operation_node(';', 2, NULL, NULL); }
  ;

for_mid_stmt:
  { $$ = construct_operation_node(';', 2, NULL, NULL); }
  | PRINT expression { $$ = construct_operation_node(PRINT, 1, $2); }
  | declaration_statement { $$ = $1; }
  | expression { $$ = $1; }
  ;

assignment_statement: 
  VARIABLE '=' rhs_nexted_expression { $$ = construct_operation_node('=', 2, construct_identifier_node($1), $3); }
  ;

for_assignment:
  { $$ = construct_operation_node(';', 2, NULL, NULL); }
  | assignment_statement { $$ = $1; }
  ;

declaration_statement:
  data_type VARIABLE { $$ = construct_operation_node(DECLARE_ONLY, 1, construct_identifier_node($2, $1)); }
  | data_type VARIABLE '=' rhs_nexted_expression { $$ = construct_operation_node('=', 2, construct_identifier_node($2, $1), $4); }
  | CONST data_type VARIABLE '=' rhs_nexted_expression { $$ = construct_operation_node('=', 2, construct_identifier_node($3, $2, CONST), $5); }
  ;

data_type: INT_TYPE       { $$ = INT_TYPE } 
          | FLOAT_TYPE    { $$ = FLOAT_TYPE }
          | BOOL_TYPE     { $$ = BOOL_TYPE }
          | STRING_TYPE   { $$ = STRING_TYPE }
          | VOID_TYPE     { $$ = VOID_TYPE }
          ;

for_declaration:
  { $$ = construct_operation_node(';', 2, NULL, NULL); }
  | declaration_statement { $$ = $1; }
  ;

rhs_nexted_expression:
  expression { $$ = $1; }
  | VARIABLE '=' rhs_nexted_expression { $$ = construct_operation_node('=', 2, construct_identifier_node($1), $3); }
  | '(' VARIABLE '=' rhs_nexted_expression ')' { $$ = construct_operation_node('=', 2, construct_identifier_node($2), $4); }
  ;

statement_list:
  statement { $$ = $1; }
  | statement_list statement { $$ = construct_operation_node(';', 2, $1, $2); }
  ;

expression: INTEGER { $$ = construct_constant_node(INTEGER, INT_TYPE, $1); }
          | FLOAT { $$ = construct_constant_node(FLOAT, FLOAT_TYPE, $1); }
          | STRING { $$ = construct_constant_node(STRING, STRING_TYPE, $1); }
          | VARIABLE { $$ = construct_identifier_node($1); }
          | BOOL { $$ = construct_constant_node(BOOL, BOOL_TYPE, $1); }
          | '-' expression %prec NEGATIVE { $$ = construct_operation_node(NEGATIVE, 1, $2); }
          | NOT expression { $$ = construct_operation_node(NOT, 1, $2); }
          | expression '+' expression { $$ = construct_operation_node('+', 2, $1, $3); }
          | expression '-' expression { $$ = construct_operation_node('-', 2, $1, $3); }
          | expression '*' expression { $$ = construct_operation_node('*', 2, $1, $3); }
          | expression '/' expression { $$ = construct_operation_node('/', 2, $1, $3); }
          | expression '%' expression { $$ = construct_operation_node('%', 2, $1, $3); }
          | expression '<' expression { $$ = construct_operation_node('<', 2, $1, $3); }
          | expression '>' expression { $$ = construct_operation_node('>', 2, $1, $3); }
          | expression GREATER_EQUAL expression { $$ = construct_operation_node(GREATER_EQUAL, 2, $1, $3); }
          | expression LESS_EQUAL expression { $$ = construct_operation_node(LESS_EQUAL, 2, $1, $3); }
          | expression NOT_EQUAL expression { $$ = construct_operation_node(NOT_EQUAL, 2, $1, $3); }
          | expression EQUAL expression { $$ = construct_operation_node(EQUAL, 2, $1, $3); }
          | expression AND expression { $$ = construct_operation_node(AND, 2, $1, $3); }
          | expression OR expression { $$ = construct_operation_node(OR, 2, $1, $3); }
          | '(' expression ')' { $$ = $2; }
          ;
  /* End of Production Rules */

%%

Node *construct_constant_node(int type, int dataType, ...) {
  va_list ap;
  Node *p;
  size_t nodeSize;

  /* allocate Node */
  nodeSize = SIZEOFNODE + sizeof(ConstantNode);
  if ((p = (Node*)malloc(nodeSize)) == NULL)
    yyerror("out of memory");

  /* copy information */
  p->type = CONSTANT;
  p->con.dataType = dataType;
  va_start(ap, dataType);
  p->con.value = va_arg(ap, ValueType);
  va_end(ap);

  return p;
}

Node *construct_identifier_node(char* i, int dataType, int qualifier) {
  Node *p;
  size_t nodeSize;
  /* allocate Node */
  nodeSize = SIZEOFNODE + sizeof(IdentifierNode);
  if ((p = (Node*)malloc(nodeSize)) == NULL)
    yyerror("out of memory");

  /* copy information */
  p->type = IDENTIFIER;
  p->id.name = strdup(i);
  p->id.dataType = dataType;
  p->id.qualifier = qualifier;
  return p;
}

Node *construct_operation_node(int oper, int nops, ...) {
  va_list ap;
  Node *p;
  size_t nodeSize;
  int i;
  
  /* allocate Node */
  nodeSize = SIZEOFNODE + sizeof(OperationNode) +
    (nops - 1) * sizeof(Node*);
  if ((p = (Node*)malloc(nodeSize)) == NULL)
    yyerror("out of memory");

  /* copy information */
  p->type = OPERATION;
  p->opr.symbol = oper;
  p->opr.nops = nops;
  va_start(ap, nops);
  for (i = 0; i < nops; i++)
    p->opr.op[i] = va_arg(ap, Node*);
  va_end(ap);
  return p;
}

void free_node(Node *p) {
  int i;

  if (!p) return;
  if (p->type == OPERATION) {
    for (i = 0; i < p->opr.nops; i++)
      free_node(p->opr.op[i]);
  }
  free (p);
}

int main(void) {
  yyparse();
  log_symbol_table();
  return 0;
}


void yyerror(const char *emsg) {

  log_errors(line,emsg);
  fprintf(stderr, "Line %d: %s\n", line, emsg);
  log_symbol_table();
  exit(0);

}
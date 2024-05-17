#ifndef COMPILER_H
#define COMPILER_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <string>
#include <stdarg.h>

#include <iostream>

#include <vector>
#include <map>

using namespace std;

/* Add All Types and structs Here*/
#define SIZEOFNODE ((char *)&p->con - (char *)p)

#define ASSIGNMENT   1
#define STATEMENT_LIST  2
#define COMMA 3
#define CALL 4


typedef enum
{
  CONSTANT,
   // VALUE,
  IDENTIFIER,
  OPERATION
} NodeType;


struct ValueType
{
   // int type;
  union
  {
    int intVal;
    double floatVal;
    bool boolVal;
    char* strVal;
  };
};



/* constants */
typedef struct
{
    ValueType value;     /* value */
    int dataType;        /* type */

} ConstantNode;


/* variables */
typedef struct
{
  char* name;        /* name */
  int dataType;      /* type */
  int qualifier;     /* qualifier*/
} IdentifierNode;


/* operators */
typedef struct
{
  int symbol;                     /* symbol */
  int nops;           /* number of operands */
  struct NodeTypeTag* op[1];  /* expandable */
} OperationNode;

typedef struct NodeTypeTag
{
  NodeType type; /* type of Node */

  union
  {
    ConstantNode con;   /* constants */
    IdentifierNode id;  /* identifiers */
    OperationNode opr;  /* operators */
  };
} Node;


/* symbol table entries */
struct SymbolTable
{
  std::string name;       // variable name
  int type;             //DataType:     {int, float, ..}
  int symbolType;       //SymbolType:   {variable, constant,..}
  int scope;            //Scope:        {global:0, local:1}
  int timestamp;        //Timestamp:    {time of creation}
  bool used;            //Used:         {true, false}
  bool isInitialized;   //Initialized:  {true, false}
  bool isFunction;      //isFunction:   {true, false}
  SymbolTable(std::string nm, int ty, int sty, int sc, int ts, bool init, bool func = false)
  {
    name = nm, type = ty, symbolType = sty, scope = sc, timestamp = ts;
    used = false;
    isInitialized = init;
    isFunction = func;
  }
};

static vector<map<string, SymbolTable*> > symbol(1, map<string, SymbolTable*>());
extern Node* construct_constant_node(int value);
extern Node *construct_operation_node(int oper, int nOpers, ...);
extern Node *construct_identifier_node(int oper, int nOpers, ...);


extern void free_node(Node* p);
extern void yyerror(const char* emsg);


extern void check_unused_variables();





#endif
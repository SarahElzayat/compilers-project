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
#define NODESIZE ((char *)&p->con - (char *)p) /* size of largest type, in bytes */

#define ASSIGNMENT   1
#define STATEMENT_LIST  2

typedef enum
{
    CONSTANT,
    // VALUE,
    ID,
    OP
} nodeType;

struct valueType
{
    // int type;
    union
    {
        int intValue;
        float floatValue;
        bool boolValue;
        char *stringValue;
    };
};

/* constants */
typedef struct
{
    valueType value;     /* value */
    int dataType;        /* type */
} constantNode;



/* variables */
typedef struct
{
    char *name;     /* name */
    int dataType;   /* type */
    int qualifier;  /* qualifier*/
} idNode;

/* operators */
typedef struct
{
    int oper;                       /* symbol */
    int nops;                       /* number of operands */
    struct nodeTypeTag *op[1];      /* operands, extended at runtime */
} opNode;

typedef struct nodeTypeTag
{
    nodeType type; /* type of node */

    union
    {
        constantNode con; /* constants */
        idNode id;        /* identifiers */
        opNode opr;       /* operators */
    };
} node;

/* symbol table entries */
struct symbolTable
{
  std::string name;
  int type;             //DataType:     {int, float, ..}
  int symbolType;       //SymbolType:   {variable, constant,..}
  int scope;            //Scope:        {global:0, local:1}
  int timestamp;        //Timestamp:    {time of creation}
  bool used;            //Used:         {true, false}
  bool isInitialized;   //Initialized:  {true, false}

  //Constructor
  symbolTable(std::string name, int type, int sType, int scope, int timeStamp, bool init)
  {
    isInitialized = init;
    used = false;
    name = name, type = type, symbolType = sType, scope = scope, timestamp = timeStamp;
  }
};

//Define Functions prototypes
static vector<map<string, symbolTable*> > symbol(1, map<string, symbolTable*>()); //Map {levels: pointer to a symbolTable object}

extern node* construct_constant_node(int value);
extern node *construct_operation_node(int oper, int nOpers, ...);
extern node *construct_identifier_node(int oper, int nOpers, ...);

extern void get_unused_variables();

extern void free_node(node* p);
extern void yyerror(const char* s);




#endif
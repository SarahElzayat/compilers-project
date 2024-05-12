/* Add Types Here*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <map>
#include <string.h>
#include <string>

using std::string;
using std::vector;
using std::map;

typedef enum
{
    Constant,
    Id,
    Op
} nodeType;

typedef struct
{
    union
    {
        int intValue;
        float floatValue;
        bool boolValue;
        char charValue;
        char *stringValue;
    };
} valueType;

/* constants */
typedef struct
{
    valueType value; /* value of constant */
    char *name;      /* name of constant */
    int type;        /* type of constant */
} constantNode;

/* variables */
typedef struct
{
    char *name; /* name of variable */
    int type;   /* type of id */
} idNode;

/* operators */
typedef struct
{
    int oper;                  /* operator */
    int nops;                  /* number of operands */
    struct nodeTypeTag *op[1]; /* operands, extended at runtime */
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
    name = name, type = type, symbolType = sType, scope = scope, timestamp = timeStamp;
    used = false;
    isInitialized = init;
  }
};

//Define Functions prototypes
static vector<map<string, symbolTable*> > symbol(1, map<string, symbolTable*>()); //Map {name: pointer to a symbolTable object}
extern node* construct_constant_node(int value);
extern void get_unused_variables();

extern void free_node(node* p);
extern void yyerror(const char* s);

/* Add Types Here*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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
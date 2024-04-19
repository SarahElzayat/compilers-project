/* Add Types Here*/

typedef enum { 
    Constant,
    Id,
    Op 
    } nodeType;

struct valueType
{
  union
  {
    int intValue;
    float floatValue;
    bool boolValue;
    char charValue;
  };
};

/* constants */
typedef struct {
    valueType value;            /* value of constant */ 
    int type;                  /* type of constant */
} constantNode;

/* identifiers */
typedef struct {
    char *name;                 /* name of identifier */
    int type;                  /* type of id */
} idNode;

/* operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag *op[1];	/* operands, extended at runtime */
} opNode;

typedef struct nodeTypeTag {
    nodeType type;              /* type of node */

    union {
        constantNode con;        /* constants */
        idNode id;          /* identifiers */
        opNode opr;        /* operators */
    };
} node;
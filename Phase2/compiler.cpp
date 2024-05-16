#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include <sstream>
#include "compiler.h"
#include "parser.tab.h"

static int label = 0;
static int timeStep = 0;
static int level = 0;

static vector<symbolTable*> symbolsTable;

const char* get_data_type(int type){

    switch (type) 
    {
        case INTEGER:
        case INT_TYPE:
            return "int";
        case FLOAT:
        case FLOAT_TYPE:
            return "float";
        case BOOL:
        case BOOL_TYPE:
            return "bool";

        case STRING:
        case STRING_TYPE:
            return "string";
        default:
            return "";
    }
}


node* construct_label_node(int value, char*name){
    node* p;
    size_t nodeSize;

    /* allocate Node */
    nodeSize = SIZEOF_NODETYPE + sizeof(constantNode);
    if ((p = (node*)malloc(nodeSize)) == NULL)
    {
        yyerror("out of memory");
    }

    /* copy information */
    p->type = CONST;
    p->con.name = name;
    p->con.value.intValue = value;
    return p;
}

void export_symbol_table(){
    FILE* fp;
    symbolTable* st;
    int i;

    if ((fp = fopen("./outputs/symbolTable.txt", "w")) == NULL)
    {
        yyerror("cannot open symbolTable.txt");
    }
    else
    {
        fprintf(fp, "Name\t Data Type\t Symbol Type\t Scope\t Time Stamp\t Used\t Initialized\n");
        for (i = 0; i < symbolsTable.size(); i++)
        {
            st = symbolsTable[i];
            fprintf(fp, "%s,%s,%s,%d,%d,%s,%s\n", st->name.c_str(), get_data_type(st->type),
             st->symbolType == CONSTANT ? "Constant" : "Variable", st->scope, st->timestamp, st->used ? "true" : "false", st->isInitialized ? "true" : "false");
        }
        fclose(fp);
    }
    return;
}

symbolTable* get_identifier(node* p, bool isRHS = false) {
    if (p->type != ID) /*Not an identifier*/
    {
        return NULL;
    }
    else if (p->id.dataType == -1) /*Data type not set*/
    {
        return NULL;
    }
    
    for (int i = level; i >= 0; i--) //Search in the current and all parent scopes for assignment RHS
    { 
        //Check if the identifier is in the symbol table
        if (symbol[i].find(p->id.name) != symbol[i].end()) 
        {
            symbolTable* entry = symbol[i][p->id.name];
            if (isRHS && entry->symbolType == CONST) //Check if the identifier is a constant
            {
                char msg[1024];
                sprintf(msg, "ERROR: Can't assign value to constant '%s'", p->id.name);
                yyerror(msg);
                return NULL;
            }
            if (!isRHS && entry->isInitialized == false) //Check if the identifier is initialized
            {
                char msg[1024];
                sprintf(msg, "ERROR: Can't use an uninitialized identifier '%s'", p->id.name);
                yyerror(msg);
                return NULL;
            }
            //Set the identifier as used and return it
            symbol[i][p->id.name]->used = true;
            return symbol[i][p->id.name];
        }
  }

  char msg[1024];
  sprintf(msg, "ERROR: Undefined identifier '%s'", p->id.name);
  yyerror(msg);
  return NULL;  
}

symbolTable* declare_identifier(node* p, bool isRHS = false) {
    if (p->type != ID) /*Not an identifier*/
    {
        return NULL;
    }
    else if (p->id.dataType == -1) /*Data type not set*/
    {
        return get_identifier(p, isRHS);
    }

    else if (symbol[level].count(p->id.name)) /*Identifier already declared*/
    {
        char msg[1024];
        sprintf(msg, "ERROR: Identifier '%s' previously declared", p->id.name);
        yyerror(msg);
        return NULL;
    }
    else
    {
        //Add identifier to symbol table
        symbol[level][p->id.name] = new symbolTable(strdup(p->id.name), p->id.dataType, p->id.qualifier, level, timeStep++, false);
        //Add identifier to the list of symbols
        symbolsTable.push_back(symbol[level][p->id.name]);
        //Return the symbol table entry
        return symbol[level][p->id.name];
    }
}



void add_block_level()
{
    //push entries to the symbol table and increase scope level
    symbol.push_back(map<string, symbolTable*>());
    level++;
    return;
}


void remove_block_level(){
    //pop entries from the symbol table and decrease scope level
    symbol.pop_back();
    level--;
    return;
}

int execute(node* p, int cont= -1, int brk = -1, int args = 0, ...)
{
    va_list ap;
    node* lblNode;
    symbolTable* symbolTableEntry = NULL;

    if(!p)
    return 0;
    
    switch (p->type)
    {
        case CONST: 
            printf("\tpush\t%d\n", p->con.value); 
            break; 

        case VALUE:
            switch (p->value.type)
            {
            case INTEGER:
                printf("\tpush\t%d\n", p->value.intValue);
                break;
            case FLOAT:
                printf("\tpush\t%f\n", p->value.floatValue);
                break;
            case BOOL:
                printf("\tpush\t%f\n", p->value.boolValue);
                break;
            case STRING:
                printf("\tpush\t%s\n", p->value.stringValue);
                break;
            }
            
            break;
        //Identifiers are pushed to the stack and written to symbols table
        case ID:
            symbolTableEntry = get_identifier(p);
            if (symbolTableEntry == NULL)
            {
                return 0;
            }
            printf("\tpush\t%s\n", p->id.name); 
            return symbolTableEntry->type;

        case OP:
            int l1,l2,l3;
            int rhs, lhs;
            switch (p->opr.oper)
            {
                case STATEMENT_LIST:
                    execute(p->opr.op[0]);
                    execute(p->opr.op[1]);
                    break;

                /*WHILE LOOP*/
                case WHILE:
                    add_block_level();

                    printf("L%03d:\n", l1 = label++); //start
                    execute(p->opr.op[0]); //condition
                    printf("\tjz\tL%03d\n", l2 = label++); //if false

                    execute(p->opr.op[1]); //body
                    printf("\tjmp\tL%03d\n", l1); //continue
                    printf("L%03d:\n", l2); //end

                    remove_block_level();
                    break;

                /*IF CONDITIONAL*/
                case IF:
                    add_block_level();
                    std::cout<<"executing if\n";
                    execute(p->opr.op[0]);
                    if (p->opr.nops > 2) {
                        /* if else */
                        printf("\tjz\tL%03d\n", l1 = label++);
                        execute(p->opr.op[1]);
                        printf("\tjmp\tL%03d\n", l2 = label++);
                        printf("L%03d:\n", l1);
                        execute(p->opr.op[2]);
                        printf("L%03d:\n", l2);
                    } else {
                        /* if */
                        printf("\tjz\tL%03d\n", l1 = label++);
                        execute(p->opr.op[1]);
                        printf("L%03d:\n", l1);
                    }
                    remove_block_level();
                    break;

                /*FOR LOOP*/
                case FOR:
                    add_block_level();
                    execute(p->opr.op[0]); //initialize
                    printf("L%03d:\n", l1 = label++);

                    execute(p->opr.op[1]); //condition
                    printf("\tjz\tL%03d\n", l2 = label++);

                    execute(p->opr.op[3], l3 = label++, l2); //body
                    printf("L%03d:\n", l3); //continue

                    execute(p->opr.op[2]); //increment or decrement
                    printf("\tjmp\tL%03d\n", l1);
                    printf("L%03d:\n", l2);

                    remove_block_level();
                    break;

                /*SWITCH CASE*/
                case SWITCH:
                
                return 0;

                /*DO WHILE LOOP*/
                case DO:
                    add_block_level();

                    printf("L%03d:\n", l1 = label++); //start
                    execute(p->opr.op[0]); //body
                    execute(p->opr.op[1]); //condition
                    printf("\tjnz\tL%03d\n", l1); //if true repeat

                    remove_block_level();
                    break;
                
                case '=': //copilot m3rfsh da eh
                    symbolTableEntry = declare_identifier(p->opr.op[0], true);
                    if (symbolTableEntry == NULL)
                    {
                        return 0;
                    }
                    execute(p->opr.op[1]);
                    printf("\tpop\t%s\n", p->opr.op[0]->id.name);
                    symbolTableEntry->isInitialized = true;
                    break;

                case NEGATIVE:
                    lhs = execute(p->opr.op[0]);
                    printf("\tneg\n");
                    return lhs;
                
                case PRINT:         
                    execute(p->opr.op[0]);
                    printf("\tprint\n");
                    break;

                case NOT : 
                    execute(p->opr.op[0]);
                    printf("\tNOT\n");
                    return BOOL_TYPE;

                case ASSIGNMENT:
                    execute(p->opr.op[1]);
                    printf("\tpop\t%s\n", p->opr.op[0]->id.name);
                    break;

                //what about data types
                default:
                //execute the left and right operands they have to be same type

                    rhs = execute(p->opr.op[0]); 
                    lhs = execute(p->opr.op[1]);
                    if(rhs != lhs)
                    {
                        char msg[1024];
                        sprintf(msg, "ERROR: MISMATCH Operands data types");
                        yyerror(msg);
                        return 0;
                    }
                    switch(p->opr.oper) 
                    {
                        case '+':
                        printf("\tadd\n"); 
                        return lhs;

                        case '-':
                        printf("\tsub\n"); 
                        return lhs; 
                        
                        case '*':
                        printf("\tmul\n");
                        return lhs;

                        case '/':
                        printf("\tdiv\n");
                        return lhs;

                        case '<':
                        printf("\tcompLT\n"); 
                        return BOOL_TYPE;
                        
                        case '>':
                        printf("\tcompGT\n"); 
                        return BOOL_TYPE;
                        
                        case GREATER_EQUAL:
                            printf("\tcompGE\n"); 
                            return BOOL_TYPE;
                        
                        case LESS_EQUAL:
                            printf("\tcompLE\n"); 
                            return BOOL_TYPE;
                        
                        case NOTEQUAL:
                            printf("\tcompNE\n"); 
                            return BOOL_TYPE;
                        
                        case EQUAL:
                            printf("\tcompEQ\n"); 
                            return BOOL_TYPE;
                        
                        case OR:
                            printf("\tOR\n"); 
                            return BOOL_TYPE;
                        
                        case AND:
                            printf("\tAND\n"); 
                            return BOOL_TYPE;
                    }
            }
            break;
   
    }
    return 0;
}
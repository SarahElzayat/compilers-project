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
    p->type = CONSTANT;
    p->con.name = name;
    p->con.value.intValue = value;
    return p;
}

void export_symbol_table(){
    FILE* fp;
    symbolTable* st;
    int i;

    if ((fp = fopen("./out/symbolTable.txt", "w")) == NULL)
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

symbolTable* declare_identifier(node* p, bool isRHS = false) {
    return;
}

symbolTable* get_identifier(node* p, bool isRHS = false) {
    return;    
}


void get_unused_variables(){
    return;
}

void add_block_level(){
    return;
}


void remove_block_level(){
    return;
}

int execute(node* p, int cont= -1, int brk = -1, int args = 0, ...)
{
    if(!p)
        return 0;
    
    switch (p->type)
    {
        case CONSTANT: 
            printf("\tpush\t%d\n", p->con.value); 
            break; 
        case ID:
            //TODO: check of exist // add to symbol table
            printf("\tpush\t%s\n", p->id.name); 
            break;;
        case OP:
            switch (p->opr.oper)
            {
                int l1,l2;
                case WHILE:
                    printf("L%03d:\n", l1 = label++);
                    execute(p->opr.op[0]);
                    printf("\tjz\tL%03d\n", l2 = label++);
                    execute(p->opr.op[1]);
                    printf("\tjmp\tL%03d\n", l1);
                    printf("L%03d:\n", l2);
                    break;
                case IF:
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
                    break;
                case SWITCH:return;
                case DO:return;
                case FOR:return;
                case PRINT:         
                    execute(p->opr.op[0]);
                    printf("\tprint\n");
                    break;
                case OR:return;
                case AND:return;
                case GREATER_EQUAL:return;
                case EQUAL:return;
                case LESS_EQUAL:return;
                case NOT : return;
                case NOTEQUAL: return;

                //what about data types
                        default:
                execute(p->opr.op[0]);
                execute(p->opr.op[1]);
                switch(p->opr.oper) {
                case '+':   printf("\tadd\n"); break;
                case '-':   printf("\tsub\n"); break; 
                case '*':   printf("\tmul\n"); break;
                case '/':   printf("\tdiv\n"); break;
                case '<':   printf("\tcompLT\n"); break;
                case '>':   printf("\tcompGT\n"); break;
                case GREATER_EQUAL:    printf("\tcompGE\n"); break;
                case LESS_EQUAL:    printf("\tcompLE\n"); break;
                case NOTEQUAL:    printf("\tcompNE\n"); break;
                case EQUAL:    printf("\tcompEQ\n"); break;
                case OR:    printf("\tcompEQ\n"); break;
                case AND:    printf("\tcompEQ\n"); break;
            }
            }
            break;
   
    }
    return;
}
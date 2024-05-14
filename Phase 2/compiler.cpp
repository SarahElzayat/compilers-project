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
    return;
}
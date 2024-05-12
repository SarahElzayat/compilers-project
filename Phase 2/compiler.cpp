#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include <sstream>
#include "compiler.h"
// #include "parser.tab.h"

static int label = 0;
static int timeStep = 0;
static int level = 0;

static vector<symbolTable*> symbolsTable;

const char* get_data_type(int type){
    return;
}

symbolTable* get_identifier(node* p, bool isRHS = false) {
    return;    
}


void get_unused_variables(){
    return;
}

node* construct_label_node(int value){
    return;
}

void export_symbol_table(){
    return;
}

symbolTable* declare_identifier(node* p, bool isRHS = false) {
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
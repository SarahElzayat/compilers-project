#include <stdio.h>
#include <stdarg.h>

#include <vector>
#include <sstream>

#include "compiler.h"
#include "parser.tab.h"

using namespace std;

static int label = 0;
static int timeStep = 0;
static int level = 0;

#define ERRORLOG 1
extern int line;

static vector<symbolTable*> symbolsTable;


const char* get_data_type(int type){ //return the data type as a string

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
        
        case VOID_TYPE:
            return "void";
        
        default:
            return "";
    }
}

// SCOPES
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

void export_symbol_table(){
    FILE* f;
    symbolTable* st;
    int i;

    if ((f = fopen(".\\outputs\\symbolTable.txt", "w")) == NULL)
    {
        yyerror("can't open file");
    }

    fprintf(f, "Name\t Data Type\t Symbol Type\t Scope\t Time Stamp\t Used\t Initialized\n");
    for (i = 0; i < symbolsTable.size(); i++)
    {
        st = symbolsTable[i];
        fprintf(f, "%s,\t\t%s,\t\t%s,\t\t%d,\t\t%d,\t\t%s,\t\t%s\n", st->name.c_str(), get_data_type(st->type),
        st->symbolType == CONST ? "Constant" : "Variable", st->scope, st->timestamp, st->used ? "true" : "false", st->isInitialized ? "true" : "false");
        free(st);
    }
    fclose(f);
}


void log_errors(int error,int l)
{
    FILE* f;
    if ((f = fopen(".\\outputs\\errors.txt", "w")) == NULL)
    {
        yyerror("can't open file");
    }

    switch(error)
    {
        case 0:
            fprintf(f,"Semantic ERROR: Type mismatch error in line: %d\n", l);
            break;
        case 1:
            fprintf(f, "Semantic ERROR: Undeclared Variable in line:%d\n",l);
            break;
        case 2:
            fprintf(f, "Semantic ERROR: Constant Variable in line:%d\n",l);
            break;
        case 3:
            fprintf(f, "Semantic ERROR: Variable used out of scope in line:%d\n",l);
            break;
        case 4:
            fprintf(f, "Semantic ERROR: Condition must be of type boolean in line:%d\n",l);
            break;
        case 5:
            fprintf(f, "Semantic ERROR: Unused Variable in line:%d\n",l);
            break;
        case 6:
            fprintf(f, "Syntax ERROR: Invalid Syntax in line:%d\n",l);
        default:
            fprintf(f, "ERROR: Unknown error in line: %d\n", l);
            break;
    }
    fclose(f);

}

void check_unused()
{
    std::map<std::string, symbolTable*>::iterator it;
    std::string str = "";

    for (it = symbol[level].begin(); it != symbol[level].end(); it++) {
        if (it->second->used == false) {
        str += it->second->name + " ";
        }
    }

    if (str.length() > 0)
    {
        log_errors(5, line);
        yyerror(("ERROR: Unused Variable(s) " + str + "\n").c_str());
    }    
    return;
}



node* construct_label_node(int value){ //?????????
    node* p;
    size_t nodeSize;

    /* allocate Node */
    nodeSize = NODESIZE + sizeof(constantNode);
    if ((p = (node*)malloc(nodeSize)) == NULL)
    {
        yyerror("out of memory");
    }

    /* copy information */
    p->type = CONSTANT;
    p->con.value.intValue = value;
    return p;
}



symbolTable* get_identifier(node* p, bool isRHS = false) { //get the identifier from the symbol table
    if (p->type != ID || p->id.dataType == -1 ) /*Not an identifier or Data type not set*/
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
                sprintf(msg, "ERROR: Can't Change a CONSTANT '%s'", p->id.name);
                yyerror(msg);
                return NULL;
            }
            if (!isRHS && entry->isInitialized == false) //Check if the identifier is initialized
            {
                char msg[1024];
                sprintf(msg, "ERROR: Using uninitialized identifier '%s'", p->id.name);
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
    
    if (p->id.dataType == -1) /*Data type not set*/
    {
        return get_identifier(p, isRHS);
    }

    if (symbol[level].count(p->id.name)) /*Identifier already declared*/
    {
        char msg[1024];
        sprintf(msg, "ERROR: Identifier '%s' previously declared", p->id.name);
        yyerror(msg);
        return NULL;
    }

    //Add identifier to symbol table
    symbol[level][p->id.name] = new symbolTable(p->id.name, p->id.dataType, p->id.qualifier, level, timeStep++, false);
    //Add identifier to the list of symbols
    symbolsTable.push_back(symbol[level][p->id.name]);
    //Return the symbol table entry
    return symbol[level][p->id.name];
    
}





int execute(node* p, int cont= -1, int brk = -1, int args = 0, ...)
{
    va_list ap;
    vector<node*> argsVector;
    va_start(ap, args);
    for (int i = 0; i < args; i++)
        argsVector.push_back(va_arg(ap, node*));
    va_end(ap);
    
    symbolTable* symbolTableEntry = NULL;

    node *n;
    node *switch_var;

    int l1, l2, l3;
    int rhs, lhs;
    int endLabel, defaultLabel;

    if(!p)
    {
        return 0;
    }
    switch (p->type)
    {
        case CONSTANT: 
            switch (p->con.dataType)
            {
            case INT_TYPE:
            printf("\tpush %s\t%d\n", get_data_type(INT_TYPE), p->con.value.intValue);
            return INT_TYPE;

            case BOOL_TYPE:
            printf("\tpush %s\t%s\n", get_data_type(BOOL_TYPE), p->con.value.boolValue ? "true" : "false");
            return BOOL_TYPE;

            case FLOAT_TYPE:
            printf("\tpush %s\t%f\n", get_data_type(FLOAT_TYPE), p->con.value.floatValue);
            return FLOAT_TYPE;

            case STRING_TYPE:
            printf("\tpush %s\t%s\n", get_data_type(STRING_TYPE), p->con.value.stringValue);
            return STRING_TYPE;
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
            switch (p->opr.oper)
            {
                // case STATEMENT_LIST:
                //     execute(p->opr.op[0]);
                //     execute(p->opr.op[1]);
                //     break;

                /*WHILE LOOP*/
                case WHILE:
                    add_block_level();

                    printf("L%03d:\n", l1 = label++); //start
                    lhs = execute(p->opr.op[0]); //condition
                    if (lhs != BOOL_TYPE) 
                    {
                        yyerror("ERROR: Condition must be a BOOL");
                    }
                    printf("\tjz\tL%03d\n", l2= label++); //if false

                    execute(p->opr.op[1], l1, l2); //body
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
                    //add_block_level();
                    label++;
                    endLabel=11111;
                    defaultLabel=999;
                    // Execute the switch expression
                    switch_var=p->opr.op[0];
                    printf("\tpop %s\t\n",switch_var->id.name);
                    n=p->opr.op[1];
                    // printf("%d",n->opr.op[2]->opr.nops);
                    while(n->opr.oper==CASE){
                        bool last_case=false;
                        if (n->opr.nops==3)
                        {
                            last_case=true;
                        }
                        printf("L%03d:\n", l1=label);
                        printf("\tpush\t%s\n",switch_var->id.name);
                        execute(n->opr.op[0]);
                        printf("\tcompEQ\t\n");
                        if (last_case){
                            if (p->opr.nops==3){
                                printf("\tjz\tL%03d\n",l1=defaultLabel);
                            }else{
                                printf("\tjz\tL%03d\n",l1=endLabel);
                            }  
                        }else {
                            printf("\tjz\tL%03d\n",l1=++label);
                        }
                        execute(n->opr.op[1]);
                        printf("\tjmp\tL%03d\n",endLabel);
                        if(last_case){
                           
                            break;
                        }else{
                            n=n->opr.op[3];
                        }
                        
                    }
                    if (p->opr.nops==3){
                        printf("L%03d:\n", l1=defaultLabel);
                        execute(p->opr.op[2]->opr.op[0]);
                        printf("\tjmp\tL%03d\n",endLabel);
                    }
                    printf("L%03d:\n", l1=endLabel);
                    break;

                /*DO WHILE LOOP*/
                case DO:
                    add_block_level();

                    printf("L%03d:\n", l1 = label++); //start
                    execute(p->opr.op[0]); //body
                    execute(p->opr.op[1]); //condition
                    printf("\tjnz\tL%03d\n", l1); //if true repeat

                    remove_block_level();
                    break;
                
                case '=': 
                    rhs = execute(p->opr.op[1]);
                    if (p->opr.op[1]->type == OP && p->opr.op[1]->opr.oper == '=') // nested assignment
                    {
                        printf("\tpush\t%s\n", p->opr.op[1]->opr.op[0]->id.name);
                    }
                    symbolTableEntry = declare_identifier(p->opr.op[0], true);

                    printf("\tpop\t%s\n", p->opr.op[0]->id.name);
                    symbolTableEntry->isInitialized = true;
                    // return symbolTableEntry->type;
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

                // case ASSIGNMENT:
                //     execute(p->opr.op[1]);
                //     printf("\tpop\t%s\n", p->opr.op[0]->id.name);
                //     break;

                case BREAK:
                    if(brk == -1)
                    {
                        yyerror("ERROR: Break statement not in loop");
                    }
                    printf("\tjmp\tL%03d\n", brk);
                    break;

                case CONTINUE:
                    if(cont == -1)
                    {
                        yyerror("ERROR: Continue statement not in loop");
                    }
                    printf("\tjmp\tL%03d\n", cont);
                    break;

                case ENDLINE:
                    for (int i = 0; i < p->opr.nops; i++)
                        execute(p->opr.op[i]);
                    break;


                //what about data types
                default:
                //execute the left and right operands they have to be same type

                    lhs = execute(p->opr.op[0]); 
                    rhs = execute(p->opr.op[1]);
                    // if(rhs != lhs)
                    // {
                    //     char msg[1024];
                    //     sprintf(msg, "ERROR: MISMATCH Operands data types");
                    //     yyerror(msg);
                    //     return 0;
                    // }
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
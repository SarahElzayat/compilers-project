#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include "compiler.h"
#include "parser.tab.h"
#include <sstream>
#include <fstream>

using std::vector;

static int label, timestep = 0, level = 0;
static vector<SymbolTable*> symbolTable;
Node* construct_label_node(int value);

extern int line;


// Define the global file stream
FILE* assemblyOutFile = NULL;

void open_file()
{
	if(assemblyOutFile==NULL)
	{
		assemblyOutFile = fopen(".\\outputs\\output.txt", "w");
	}
}

void check_unused_variables() {
  std::map<std::string, SymbolTable*>::iterator it;
  std::string str = "";

  for (it = symbol[level].begin(); it != symbol[level].end(); it++) {
    if (it->second->used == false) {
      str += it->second->name + " ";
    }
  }

  if (str.length() > 0)
	{
		yyerror(("Semantic ERROR: Unused Variable(s) " + str + "\n").c_str());	
	}
    
}

const char* get_data_type(int type) {
  switch (type) {
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

SymbolTable* get_function_variable(Node*p)
{
    printf("Function name: %s\n", p->id.name);
    std::cout<<symbol.size()<<std::endl;
    printf("Lttttt %s\n", symbol[0][p->id.name]->name);
    
    for (int i = level; i >= 0; i--) 
    { 
        if (symbol[i].find(p->id.name) != symbol[i].end()) 
        {
            SymbolTable* entry = symbol[i][p->id.name];
            if (entry->isFunction == true) 
            {
                printf("www %s\n", entry->name);
                return entry;
            }
        }
    }
    return NULL;

}

SymbolTable* check_identifier(Node* p, bool isRHS = false) {
  if (p->type != IDENTIFIER) return NULL;
  if (p->id.dataType != -1) {
    return NULL;
  }
  for (int i = level; i >= 0; i--) { // assignment statement
    if (symbol[i].find(p->id.name) != symbol[i].end()) 
    {
      SymbolTable* entry = symbol[i][p->id.name];
      if (isRHS && entry->symbolType == CONST  && entry->isFunction == false) {
        char msg[1024];
        sprintf(msg, "Semantic ERROR: Cannot assign value to a constant variable '%s'", p->id.name);
        yyerror(msg);
        return NULL;
      }
      if (!isRHS && entry->isInitialized == false && entry->isFunction == false) {
        char msg[1024];
        sprintf(msg, "Semantic ERROR: Usage of variable without initializing it '%s'", p->id.name);
        yyerror(msg);
        return NULL;
      }
      symbol[i][p->id.name]->used = true;
      return symbol[i][p->id.name];
    }
  }

  char msg[1024];
  sprintf(msg, "Symantic ERROR: Usage of variable without declaration'%s'", p->id.name);
  yyerror(msg);
  return NULL;
}

SymbolTable* declare_identifier(Node* p, bool isRHS = false) {
  if (p->type != IDENTIFIER) return NULL;
  if (p->id.dataType == -1) {
    return check_identifier(p, isRHS);
  }

  if (symbol[level].count(p->id.name)) {
    char msg[1024];
    sprintf(msg, "Semantic Error: Identifier '%s' already declared", p->id.name);
    yyerror(msg);
    return NULL;
  }
  symbol[level][p->id.name] = new SymbolTable(strdup(p->id.name), p->id.dataType, p->id.qualifier, level, timestep++, false);
  symbolTable.push_back(symbol[level][p->id.name]);
  return symbol[level][p->id.name];
}

void add_block_scope_level() {
  symbol.push_back(map<string, SymbolTable*>());
  level++;
}
void remove_block_scope_level() {
//   check_unused_variables();
  symbol.pop_back();
  level--;
}

int execute_all(Node* p, int cont = -1, int brk = -1, int args = 0, ...)
{
  va_list ap;
  int l1, l2, l3, type1, type2;
  Node* lblNode;

  vector<Node*> argsVector;
  va_start(ap, args);
  for (int i = 0; i < args; i++)
    argsVector.push_back(va_arg(ap, Node*));
  va_end(ap);


  SymbolTable* symbolTableEntry = NULL;
    Node *n;
    Node *switch_var;

    int endLabel, defaultLabel;

  if (!p)
  {
	return 0;
  }

  switch (p->type)
  {
  case CONSTANT:
    switch (p->con.dataType)
    {
    case INT_TYPE:
      printf("\tpush %s\t%d\n", get_data_type(INT_TYPE), p->con.value.intVal);
	  open_file();
	  fprintf(assemblyOutFile, "\tpush %s\t%d\n", get_data_type(INT_TYPE), p->con.value.intVal);
      return INT_TYPE;

    case BOOL_TYPE:
      printf("\tpush %s\t%s\n", get_data_type(BOOL_TYPE), p->con.value.boolVal ? "true" : "false");
	  open_file();
	  fprintf(assemblyOutFile, "\tpush %s\t%s\n", get_data_type(BOOL_TYPE), p->con.value.boolVal ? "true" : "false");
      return BOOL_TYPE;

    case FLOAT_TYPE:
		printf("\tpush %s\t%f\n", get_data_type(FLOAT_TYPE), p->con.value.floatVal);
		open_file();			
		fprintf(assemblyOutFile, "\tpush %s\t%f\n", get_data_type(FLOAT_TYPE), p->con.value.floatVal);							
        return FLOAT_TYPE;

     case STRING_TYPE:
            printf("\tpush %s\t%s\n", get_data_type(STRING_TYPE), p->con.value.strVal);
			open_file();
			fprintf(assemblyOutFile, "\tpush %s\t%s\n", get_data_type(STRING_TYPE), p->con.value.strVal);
            return STRING_TYPE;
    }
    break;


  //Identifiers are pushed to the stack and written to symbols table
  case IDENTIFIER:
    symbolTableEntry = check_identifier(p); 
    if (symbolTableEntry == NULL)
    {
      return 0;
    }
    printf("\tpush\t%s\n", p->id.name);
	open_file();
	fprintf(assemblyOutFile, "\tpush\t%s\n", p->id.name);
    return symbolTableEntry->type;

  case OPERATION:
    switch (p->opr.symbol)
    {
		 // case STATEMENT_LIST:
                //     execute(p->opr.op[0]);
                //     execute(p->opr.op[1]);
                //     break;
		
        case DECLARE_ONLY:
          declare_identifier(p->opr.op[0], true);
          printf("\tpop %s\t%s\n", get_data_type(p->opr.op[0]->id.dataType), p->opr.op[0]->id.name);
		  open_file();
		  fprintf(assemblyOutFile, "\tpop %s\t%s\n", get_data_type(p->opr.op[0]->id.dataType), p->opr.op[0]->id.name);
          break;
		  		
		/*WHILE LOOP*/
        case WHILE:
		  open_file();
          add_block_scope_level();

          printf("L%03d:\n", l1 = label++); //start
		  fprintf(assemblyOutFile, "L%03d:\n", l1);

          type1 = execute_all(p->opr.op[0]); //condition
          if (type1 != BOOL_TYPE) 
		  {
            yyerror("semantic ERROR: Conditions must be of a BOOL Value");
          }
          printf("\tjz\tL%03d\n", l2= label++);  //if false
		  fprintf(assemblyOutFile, "\tjz\tL%03d\n", l2);

          execute_all(p->opr.op[1], l1, l2); //body
          printf("\tjmp\tL%03d\n", l1); //continue
		  fprintf(assemblyOutFile, "\tjmp\tL%03d\n", l1);

          printf("L%03d:\n", l2); //end
		  fprintf(assemblyOutFile, "L%03d:\n", l2);

          remove_block_scope_level();
          break;


        /*IF CONDITIONAL*/
		case IF:
		  open_file();
          add_block_scope_level();
		//    std::cout<<"executing if\n";
          type1 = execute_all(p->opr.op[0]);
          if (type1 != BOOL_TYPE) {
            yyerror("Semantic ERROR: Condition must be of a BOOL Value");
          }
          if (p->opr.nops > 2)
          {
            /* if else */
            printf("\tjz\tL%03d\n", l1 = label++);
            execute_all(p->opr.op[1], cont, brk);
            printf("\tjmp\tL%03d\n", l2 = label++);
            printf("L%03d:\n", l1);
            execute_all(p->opr.op[2], cont, brk);
            printf("L%03d:\n", l2);
          }
          else
          {
            /* if */
            printf("\tjz\tL%03d\n", l1 = label++);
            execute_all(p->opr.op[1], cont, brk);
            printf("L%03d:\n", l1);
          }

          remove_block_scope_level();
          break;

		/*FOR LOOP*/
        case FOR:
					open_file();
          add_block_scope_level();
          execute_all(p->opr.op[0]); //initialize
          printf("L%03d:\n", l1 = label++);

          type1 = execute_all(p->opr.op[1]);            // condition
          if (type1 != BOOL_TYPE) {
            yyerror("Semantic ERROR: Condition must be of a BOOL Value");
          }
          printf("\tjz\tL%03d\n", l2 = label++); 

          execute_all(p->opr.op[3], l3 = label++, l2); //body

          printf("L%03d:\n", l3);   // continue if true

          execute_all(p->opr.op[2]); // next iter inc/dec
          printf("\tjmp\tL%03d\n", l1);
          printf("L%03d:\n", l2);

          remove_block_scope_level();
          break;

      
		 /*SWITCH CASE*/
			case SWITCH:
				open_file();
				//add_block_level();
				label++;
				endLabel=11111;
				defaultLabel=999;
				// Execute the switch expression
				switch_var=p->opr.op[0];
				printf("\tpop %s\t\n",switch_var->id.name);
        fprintf(assemblyOutFile, "\tpop %s\t\n",switch_var->id.name);

				n=p->opr.op[1];
				// printf("%d",n->opr.op[2]->opr.nops);
				while(n->opr.symbol==CASE){
					bool last_case=false;
					if (n->opr.nops==3)
					{
						last_case=true;
					}
					printf("L%03d:\n", l1=label);
          fprintf(assemblyOutFile, "L%03d:\n", l1);

					printf("\tpush\t%s\n",switch_var->id.name);
          fprintf(assemblyOutFile, "\tpush\t%s\n",switch_var->id.name);

					execute_all(n->opr.op[0], cont, brk);
					printf("\tcompEQ\t\n");
          fprintf(assemblyOutFile, "\tcompEQ\t\n");

					if (last_case){
						if (p->opr.nops==3){
							printf("\tjz\tL%03d\n",l1=defaultLabel);
              fprintf(assemblyOutFile, "\tjz\tL%03d\n",l1);

						}else{
							printf("\tjz\tL%03d\n",l1=endLabel);
              fprintf(assemblyOutFile, "\tjz\tL%03d\n",l1);

						}  
					}else {
						printf("\tjz\tL%03d\n",l1=++label);
            fprintf(assemblyOutFile, "\tjz\tL%03d\n",l1);

					}
					execute_all(n->opr.op[1], cont, brk);
					printf("\tjmp\tL%03d\n",endLabel);
          fprintf(assemblyOutFile, "\tjmp\tL%03d\n",endLabel);

					if(last_case){
						
						break;
					}else{
						n=n->opr.op[3];
					}
					
				}
				if (p->opr.nops==3){
					printf("L%03d:\n", l1=defaultLabel);
          fprintf(assemblyOutFile, "L%03d:\n", l1);

					execute_all(p->opr.op[2]->opr.op[0], cont, brk);
					printf("\tjmp\tL%03d\n",endLabel);
          fprintf(assemblyOutFile, "\tjmp\tL%03d\n",endLabel);
				}
				printf("L%03d:\n", l1=endLabel);
        fprintf(assemblyOutFile, "L%03d:\n", l1);
				break;

		/*DO WHILE LOOP*/
			case DO:
				open_file();
				add_block_scope_level();

				printf("L%03d:\n", l1 = label++); //start
        fprintf(assemblyOutFile, "L%03d:\n", l1);

				execute_all(p->opr.op[0], l1, l2 = label++);  //body
				type1 = execute_all(p->opr.op[1]);  //condition
				if (type1 != BOOL_TYPE) {
					yyerror("Semantic ERROR: Condition must be of a BOOL value");
				}
				printf("\tjnz\tL%03d\n", l1); //if true repeat
        fprintf(assemblyOutFile, "\tjnz\tL%03d\n", l1);

				printf("L%03d:\n", l2);
        fprintf(assemblyOutFile, "L%03d:\n", l2);

				remove_block_scope_level();
				break;
        
        case PRINT:
			open_file();
            execute_all(p->opr.op[0], cont, brk);
            printf("\tprint\n");
            fprintf(assemblyOutFile, "\tprint\n");
            break;

        case '=':
		  open_file();
          type1 = execute_all(p->opr.op[1]);
          if (p->opr.op[1]->type == OPERATION && p->opr.op[1]->opr.symbol == '=') // variable assignment
          {
            printf("\tpush\t%s\n", p->opr.op[1]->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tpush\t%s\n", p->opr.op[1]->opr.op[0]->id.name);
          }
          symbolTableEntry = declare_identifier(p->opr.op[0], true);
          if (type1 != symbolTableEntry->type)
          {
            char msg[1024];
            sprintf(msg, "Semantic ERROR: Type mismatch in assignment %s and '%s' %s",
              get_data_type(type1),
              p->opr.op[0]->id.name,
              get_data_type(symbolTableEntry->type));
            yyerror(msg);
          }
          symbolTableEntry->isInitialized = true;
          printf("\tpop %s\t%s\n", get_data_type(symbolTableEntry->type), p->opr.op[0]->id.name);
          fprintf(assemblyOutFile, "\tpop %s\t%s\n", get_data_type(symbolTableEntry->type), p->opr.op[0]->id.name);
          return symbolTableEntry->type;

        case NEGATIVE:
		    open_file();
            type1 = execute_all(p->opr.op[0]);
            printf("\tneg\n");
            fprintf(assemblyOutFile, "\tneg\n");
            return type1;

        case NOT:
					open_file();
          type1 = execute_all(p->opr.op[0]);
          printf("\tnot\n");
          fprintf(assemblyOutFile, "\tnot\n");
          return BOOL_TYPE;

        case BREAK:
					open_file();
          if (brk == -1)
          {
            yyerror("Semantic ERROR: No loop to Break from");
            break;
          }
          printf("\tjmp\tL%03d\n", brk);
          fprintf(assemblyOutFile, "\tjmp\tL%03d\n", brk);
          break;

        case CONTINUE:
					open_file();
          if (cont == -1)
          {
            yyerror("Semantic ERROR: Continue statement not in loop");
            break;
          }
          printf("\tjmp\tL%03d\n", cont);
          fprintf(assemblyOutFile, "\tjmp\tL%03d\n", cont);


        case DEFAULT:
					open_file();
          add_block_scope_level();
          execute_all(p->opr.op[0], cont, brk);
          remove_block_scope_level();
          break;


        case BLOCK:
					open_file();
          add_block_scope_level();
          for (int i = 0; i < p->opr.nops; i++)
            execute_all(p->opr.op[i], cont, brk);
          remove_block_scope_level();
          break;

    /*FUNCTIONS*/
        case FUNCTION:
            open_file();
            add_block_scope_level();
            //std::cout<<"executing a function\n";
            //add name of function to symbol table
            symbolTableEntry = declare_identifier(p->opr.op[0]->opr.op[0], true);
            symbolTableEntry->isFunction = true;
            printf("\tproc\t%s\n",p->opr.op[0]->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tproc\t%s\n",p->opr.op[0]->opr.op[0]->id.name);

            // printf("func type %s\n",get_data_type(symbolTableEntry->type));

            if(p->opr.op[1]){
              execute_all(p->opr.op[1]);
            }
            execute_all(p->opr.op[2]);
            execute_all(p->opr.op[3]);
            remove_block_scope_level();

            
            return symbolTableEntry->type;
            break;

    /*FUNCTION CALL*/
        case CALL :
            execute_all(p->opr.op[1]);
            // while(){

            // }
            //symbolTableEntry = get_function_variable(p->opr.op[0]); 
             open_file();
            //symbolTableEntry = get_function_variable(p->opr.op[0]);
            printf("\tcall\t%s \n",p->opr.op[0]->id.name);
            fprintf(assemblyOutFile, "\tcall\t%s\n",p->opr.op[0]->id.name);
            return 274;
            break;

        case COMMA:
            open_file();
        
                execute_all(p->opr.op[0]);
                execute_all(p->opr.op[1]);
            break;

        case RETURN:

            printf("\tret\t\n");
            fprintf(assemblyOutFile, "\tret\t\n");            
            
            execute_all(p->opr.op[0]);
            printf("\tendproc\t\n");
            fprintf(assemblyOutFile, "\tendproc\t\n");
            break;
            
        /*SemiColon end of line*/
        case ';':
          for (int i = 0; i < p->opr.nops; i++)
            execute_all(p->opr.op[i], cont, brk);
          break;

		//what about other operations
        default:
		  open_file();
		//execute the left and right operands they have to be same type
          type1 = execute_all(p->opr.op[0], cont, brk);
          type2 = execute_all(p->opr.op[1], cont, brk);
          if (type1 != type2)
          {
            char msg[1024];
            sprintf(msg, "Semantic ERROR: MISMATCH Operands data types where operand1 %s and operand2 %s", get_data_type(type1), get_data_type(type2));
            yyerror(msg);
          }

          switch (p->opr.symbol)
          {
			case '+':
				printf("\tadd\n");
				fprintf(assemblyOutFile, "\tadd\n");
				return type1;

			case '-':
				printf("\tsub\n");
				fprintf(assemblyOutFile, "\tsub\n");
				return type1;

			case '*':
				printf("\tmul\n");
				fprintf(assemblyOutFile, "\tmul\n");
				return type1;

			case '/':
				printf("\tdiv\n");
				fprintf(assemblyOutFile, "\tdiv\n");
				return type1;

			case '%':
				printf("\tmod\n");
				fprintf(assemblyOutFile, "\tmod\n");
				return type1;

			case '<':
				printf("\tcompLT\n");
				fprintf(assemblyOutFile, "\tcompLT\n");
				return BOOL_TYPE;

			case '>':
				printf("\tcompGT\n");
				fprintf(assemblyOutFile, "\tcompGT\n");
				return BOOL_TYPE;

			case GREATER_EQUAL:
				printf("\tcompGE\n");
				fprintf(assemblyOutFile, "\tcompGE\n");
				return BOOL_TYPE;

			case LESS_EQUAL:
				printf("\tcompLE\n");
				fprintf(assemblyOutFile, "\tcompLE\n");
				return BOOL_TYPE;

			case NOT_EQUAL:
				printf("\tcompNE\n");
				fprintf(assemblyOutFile, "\tcompNE\n");
				return BOOL_TYPE;

			case EQUAL:
				printf("\tcompEQ\n");
				fprintf(assemblyOutFile, "\tcompEQ\n");
				return BOOL_TYPE;

			case AND:
				printf("\tand\n");
				fprintf(assemblyOutFile, "\tand\n");
				return BOOL_TYPE;

			case OR:
				printf("\tor\n");
				fprintf(assemblyOutFile, "\tor\n");
				return BOOL_TYPE;
          }
        }
  }
  return 0;
}

Node* construct_label_node(int value)
{
  Node* p;
  size_t nodeSize;

  /* allocate Node */
  nodeSize = SIZEOFNODE + sizeof(ConstantNode);
  if ((p = (Node*)malloc(nodeSize)) == NULL)
    yyerror("out of memory");

  /* copy information */
  p->type = CONSTANT;
  p->con.value.intVal = value;
  return p;
}

void log_symbol_table() {
  FILE* f;
  SymbolTable* st;
  int i;

  if ((f = fopen(".\\outputs\\symbolTable.txt", "w")) == NULL)
  {
    yyerror("can't open symbolTable.txt");
  }
    
  fprintf(f, "Name,\tDataType,\tQualifier,\tTimeStep,\tScope,\tInitialized,\tUsed,\t Function\n");
  for (i = 0; i < symbolTable.size(); i++) 
	{
        st = symbolTable[i];
        fprintf(f, "%s,\t\t%s, \t\t%s, \t\t%d, \t\t%d, \t\t%s, \t\t%s, \t\t%s \n", 
            st->name.c_str(), get_data_type(st->type), st->symbolType == CONST ? "Constant" : "Variable", st->timestamp, st->scope, st->isInitialized == true? "True" : "False", st->used== true? "True" : "False", st->isFunction== true? "True" : "False");
        free(st);
    }
  fclose(f);
}

void log_errors(int l, const char *msg)
{
    FILE* f;
    if ((f = fopen(".\\outputs\\errors.txt", "w")) == NULL)
    {
        yyerror("can't open errors.txt");
    }

    fprintf(f,"Line %d:  %s\n", l,msg);

}
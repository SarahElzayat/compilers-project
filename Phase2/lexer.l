/* Part 1 : Definitions */
%{
    #include "compiler.h"
    #include "parser.tab.h"
    #include <stdbool.h>
    void yyerror (const char *msg); 
    int line=1;
%}

%option yylineno

/* End of Definitions */


/* Part 2 : Regular Expressions */
%%
[0-9]+                       { /* INTEGERS */ 
                              yylval.iVal = atoi(yytext); 
                              return INTEGER; }

(0|[1-9][0-9]*)\.[0-9]*     { /* FLOATS */ 
                              char * x = strdup(yytext); // to ensure null-terminated string
                              yylval.fVal = atof(x);
                              return FLOAT; }
"true"                      { /* BOOLS */ 
                              // yylval.bVal = 1;
                               return BOOL; }
"false"                     {/* BOOLS */ 
                              // yylval.bVal = 0;
                               return BOOL; }
                               
"const"                     { return CONST;       }
"int"                       { return INT_TYPE;    }
"float"                     { return FLOAT_TYPE;  }
"string"                    { return STRING_TYPE; }
"bool"                      { return BOOL_TYPE;   }
"void"                      { return VOID_TYPE;   }

"print"                     { return PRINT;  }
"return"                    { return RETURN; }


[-()<>=+*/{}.:;]             { return yytext[0]; }

">="                        { return GREATER_EQUAL; }
"<="                        { return LESS_EQUAL;    }
"=="                        { return EQUAL;         } 
"!="                        { return NOTEQUAL;      }

"and"                       { return AND;           }
"or"                        { return OR;            }
"not"                       { return NOT;           }


 

"for"                       { return FOR;      }

"do"                        { return DO;       }
"while"                     { return WHILE;    }


"if"                        { return IF;       }
"else"                      { return ELSE;     }

"switch"                    { return SWITCH;   }
"case"                      { return CASE;     }

"def"                       { return FUNCTION; }   
"default"                   { return DEFAULT;  }

"break"                     { return BREAK;    }
"continue"                  { return CONTINUE; }

[a-zA-Z_][a-zA-Z0-9_]*      { 
                              yylval.varName = strdup(yytext);
                              return VARIABLE;  }
  
\".*\"                      { 
                              yylval.strVal = strdup(yytext);
                              return STRING;    }

[ \t\r]+  { /* ignore whitespace */ }
\n        { line++; }

"#".*                        { /*Add a Comments*/
                               printf("%s\n", yytext); 
                                if (yytext[yyleng - 1] == '\n') 
                                {
                                    yylineno--;   
                                 }
                                }

.   { 
    char msg[1024];
    sprintf(msg, "Syntax ERROR: Unknown character: %s", yytext);
    yyerror(msg);
  }

%%
/* End of Regular Expressions */

int yywrap(void) {
    return 1;
}





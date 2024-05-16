/* Part 1 : Definitions */
%{
    #include "compiler.h"
    #include "parser.tab.h"
    #include <stdbool.h>
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
                              yylval.fVal = atof(yytext);
                              return FLOAT; }

"print"                     { return PRINT;  }
"return"                    { return RETURN; }

"true"                      { 
                              yylval.boolVal = 1;
                               return BOOL; }
"false"                     { 
                              yylval.boolVal = 0;
                               return BOOL; }

[-()+*/{}<>=.:]             { return yytext[0]; }

">="                        { return GREATER_EQUAL; }
"<="                        { return LESS_EQUAL;    }
"=="                        { return EQUAL;         } 
"!="                        { return NOTEQUAL;      }

"and"                       { return AND;           }
"or"                        { return OR;            }
"not"                       { return NOT;           }

"const"                     { return CONST;       }
"int"                       { return INT_TYPE;    }
"float"                     { return FLOAT_TYPE;  }
"string"                    { return STRING_TYPE; }
"bool"                      { return BOOL_TYPE;   }
 

"for"                       { return FOR;      }

"do"                        { return DO;       }
"while"                     { return WHILE;    }

"break"                     { return BREAK;    }
"continue"                  { return CONTINUE; }

"else"                      { return ELSE;     }
"if"                        { return IF;       }

"switch"                    { return SWITCH;   }
"case"                      { return CASE;     }

"def"                       { return FUNCTION; }   
"default"                   { return DEFAULT;  }



[a-zA-Z_][a-zA-Z0-9_]*      { 
                              yylval.s = strdup(yytext);
                              return VARIABLE;  }
  
\".*\"                      { 
                              yylval.strVal = strdup(yytext);
                              return STRING;    }

[ \t\n]+  { /* ignore whitespace */ }

.   { 
    char msg[1024];
    sprintf(msg, "Unknown character: %s", yytext);
    yyerror(msg);
  }

%%
/* End of Regular Expressions */

int yywrap(void) {
    return 1;
}

void yyerror(const char *s) {
  fprintf(stderr, "Line %d: %s\n", yylineno, s);
  exit(0);
}



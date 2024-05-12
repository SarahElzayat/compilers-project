/* Part 1 : Definitions */
%{
    // #include "parser.tab.h"
    #include "compiler.h"
    #include <stdbool.h>
%}

%option yylineno

/* End of Definitions */


/* Part 2 : Regular Expressions */
%%
[0-9]+                       { /* INTEGERS */ 
                              yylval.i = atoi(yytext); 
                              return INTEGER; }

(0|[1-9][0-9]*)\.[0-9]*     { /* FLOATS */ 
                              char * x = strdup(yytext); // to ensure null-terminated string
                              yylval.f = atof(yytext);
                              return FLOAT; }

"print"                     { return PRINT;  }
"return"                    { return RETURN; }

"true"                      { return BOOL; }
"false"                     { return BOOL; }

[-()+*/{}<>=.^]             { return yytext[0]; }

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
"char"                      { return CHAR_TYPE;   }
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



[A-Z_][A-Z0-9_]*            { return CONSTANT;  }
[a-zA-Z_][a-zA-Z0-9_]*      { 
                              yylval.s = strdup(yytext);
                              return VARIABLE;  }


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

/* Part 3 : Functions and Main*/
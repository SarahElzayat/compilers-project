/* Part 1 : Definitions */
%{
    #include "y.tab.h"
    #include "compiler.h"
%}

%option yylineno

/* End of Definitions */


/* Part 2 : Regular Expressions */
%%
"print"                      { return PRINT; }
"return"                     { return RETURN; }

[-()+*/{}<>=.^]              { return yytext[0]; }


[A-Z_][A-Z0-9_]*            {return CONSTANT;}
[a-zA-Z_][a-zA-Z0-9_]*      {return VARIABLE;}

[0-9]+                      { /* INTEGERS */ 
                              yylval.i = atoi(yytext); 
                              return INTEGER; }

[ \t\n]+  { /* ignore whitespace */ }
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
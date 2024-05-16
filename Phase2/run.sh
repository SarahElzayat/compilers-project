flex lexer.l
bison -d parser.y
g++  compiler.cpp parser.tab.c lex.yy.c -o compiler.exe
./compiler.exe < test.txt


flex NEWlexer.l
bison -d NEWparser.y
g++  compiler.cpp newparser.tab.c lex.yy.c -o compiler.exe
./compiler.exe < test.txt


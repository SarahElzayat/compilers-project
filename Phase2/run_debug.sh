#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Step 1: Generate the lexer and parser
echo "Generating lexer and parser..."
flex lexer.l
bison -d parser.y

# Step 2: Compile the program with debugging information
echo "Compiling the program with debugging information..."
g++ -g -o compiler.exe compiler.cpp parser.tab.c lex.yy.c

# Check if the compilation was successful
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

echo "Compilation successful."

# Step 3: Run the compiled program with gdb for debugging
echo "Running the program with gdb..."
gdb -q -ex "run < test.txt" -ex "bt" -ex "quit" ./compiler.exe

# Check if gdb exited with a segmentation fault
if [ $? -ne 0 ]; then
  echo "Segmentation fault detected. Check the gdb output above for details."
  exit 1
fi

echo "Program executed successfully."

# Step 4: Optionally, run Valgrind to check for memory issues
echo "Running Valgrind to check for memory issues..."
valgrind --leak-check=full ./compiler.exe < test.txt

echo "Valgrind run complete. Check the output above for details."

exit 0

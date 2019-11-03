# Sets default compiler
CC = g++

# Sets flags
CFLAGS = -Wall -Wextra -pedantic -Werror
CFLAGS_LESSER = -Wall -Werror
CVERSION = -std=c++17

# Main
all: maxTester main

# Compiles program
maxTester: maxTester.cpp table.cpp firstGen.cpp inputOutput.cpp 
	# Compiles with flags
	$(CC) $(CVERSION) $(CFLAGS) -o maxTester.o maxTester.cpp table.cpp firstGen.cpp inputOutput.cpp -lcurses 

# Compiles main program
main: main.cpp table.cpp rule.cpp inputOutput.cpp firstGen.cpp error.cpp
	# Compiles with flags
	$(CC) $(CVERSION) $(CFLAGS) -o main.o main.cpp table.cpp rule.cpp inputOutput.cpp firstGen.cpp error.cpp -lcurses

# Deletes unused files
clean :
	-rm $(objects) *.o a.out
# Sets default compiler
CC = g++

# Sets flags
CFLAGS = -Wall -Wextra -pedantic -Werror
CFLAGS_LESSER = -Wall -Werror
CVERSION = -std=c++17

# Main 
all: maxTester main

# Compiles main program
main: main.cpp table.cpp rule.cpp inputOutput.cpp generation.cpp error.cpp
	# Compiles with flags
	$(CC) $(CVERSION) $(CFLAGS) -o main.o main.cpp table.cpp rule.cpp inputOutput.cpp generation.cpp error.cpp -lcurses


# Compiles program
maxTester: maxTester.cpp table.cpp generation.cpp inputOutput.cpp 
	# Compiles with flags
	$(CC) $(CVERSION) $(CFLAGS) -o maxTester.o maxTester.cpp table.cpp generation.cpp inputOutput.cpp -lcurses 

# Deletes unused files
clean:
	-rm $(objects) *.o
# Sets default compiler
CC = g++

# Sets flags
CFLAGS = -Wall -Wextra -pedantic -Werror
CFLAGS_LESSER = -Wall -Werror
CVERSION = -std=c++17

# Main 
all: main maxTester gameOfLife

# Compiles main program
main: main.cpp table.cpp rule.cpp inputOutput.cpp generation.cpp error.cpp
	# Compiles with flags
	$(CC) $(CVERSION) $(CFLAGS) -o main.o main.cpp table.cpp rule.cpp inputOutput.cpp generation.cpp error.cpp gameOfLife.cpp -lcurses

# Compiles max's tester
maxTester: maxTester.cpp table.cpp generation.cpp inputOutput.cpp error.cpp rule.cpp
	# Compiles with flags
	$(CC) $(CVERSION) $(CFLAGS) -o maxTester.o maxTester.cpp table.cpp generation.cpp inputOutput.cpp error.cpp rule.cpp -lcurses

# Compiles vincent's tester
gameOfLife: vincentTester.cpp gameOfLife.cpp inputOutput.cpp error.cpp rule.cpp table.cpp
	# Compiles with flags
	$(CC) $(CVERSION) $(CFLAGS) -o vincentTester.o vincentTester.cpp gameOfLife.cpp inputOutput.cpp error.cpp rule.cpp table.cpp -lcurses

# Deletes unused files
clean:
	-rm $(objects) *.o
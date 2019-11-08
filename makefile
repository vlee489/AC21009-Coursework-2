# Sets default compiler
CC = g++

# Sets flags
CFLAGS = -Wall -Wextra -pedantic -Werror
CFLAGS_LESSER = -Wall -Werror
CVERSION = -std=c++17

# Main 
all: maxTester main gameOfLife langstonsAnt

main: main.cpp table.cpp rule.cpp inputOutput.cpp generation.cpp error.cpp gameOfLife.cpp LangtonsAnt.cpp
	# Compiles main program
	$(CC) $(CVERSION) $(CFLAGS) -o main.o main.cpp table.cpp rule.cpp inputOutput.cpp generation.cpp error.cpp gameOfLife.cpp LangtonsAnt.cpp

maxTester: maxTester.cpp table.cpp generation.cpp inputOutput.cpp error.cpp rule.cpp
	# Compiles max's tester
	$(CC) $(CVERSION) $(CFLAGS) -o maxTester.o maxTester.cpp table.cpp generation.cpp inputOutput.cpp error.cpp rule.cpp

gameOfLife: gameOfLifeTester.cpp gameOfLife.cpp inputOutput.cpp error.cpp rule.cpp table.cpp
	# Compiles game of life tester
	$(CC) $(CVERSION) $(CFLAGS) -o gameOfLife.o gameOfLifeTester.cpp gameOfLife.cpp inputOutput.cpp error.cpp rule.cpp table.cpp

langstonsAnt: LangstonsAntTester.cpp LangtonsAnt.cpp inputOutput.cpp error.cpp rule.cpp table.cpp
	# Compiles langton's ant tester
	$(CC) $(CVERSION) $(CFLAGS) -o langstonsAnt.o LangstonsAntTester.cpp LangtonsAnt.cpp inputOutput.cpp error.cpp rule.cpp table.cpp
clean:
	# Deletes binary files
	-rm $(objects) *.o
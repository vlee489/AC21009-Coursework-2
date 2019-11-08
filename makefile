# Sets default compiler
CC = g++

# Sets flags
CFLAGS = -Wall -Wextra -pedantic -Werror
CFLAGS_LESSER = -Wall -Werror
CVERSION = -std=c++17

# Main 
all: maxTester main gameOfLife langstonsAnt

# Compiles main program
main: main.cpp table.cpp rule.cpp inputOutput.cpp generation.cpp error.cpp gameOfLife.cpp LangtonsAnt.cpp
	# Compiles with flags
	$(CC) $(CVERSION) $(CFLAGS) -o main.o main.cpp table.cpp rule.cpp inputOutput.cpp generation.cpp error.cpp gameOfLife.cpp LangtonsAnt.cpp

# Compiles max's tester
maxTester: maxTester.cpp table.cpp generation.cpp inputOutput.cpp error.cpp rule.cpp
	# Compiles with flags
	$(CC) $(CVERSION) $(CFLAGS) -o maxTester.o maxTester.cpp table.cpp generation.cpp inputOutput.cpp error.cpp rule.cpp

gameOfLife: gameOfLifeTester.cpp gameOfLife.cpp inputOutput.cpp error.cpp rule.cpp table.cpp
	# Compiles with flags
	$(CC) $(CVERSION) $(CFLAGS) -o gameOfLife.o gameOfLifeTester.cpp gameOfLife.cpp inputOutput.cpp error.cpp rule.cpp table.cpp

langstonsAnt: LangstonsAntTester.cpp LangtonsAnt.cpp inputOutput.cpp error.cpp rule.cpp table.cpp
	$(CC) $(CVERSION) $(CFLAGS) -o langstonsAnt.o LangstonsAntTester.cpp LangtonsAnt.cpp inputOutput.cpp error.cpp rule.cpp table.cpp
# Deletes unused files
clean:
	-rm $(objects) *.o
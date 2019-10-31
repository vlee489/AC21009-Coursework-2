# Sets default compiler
CC = g++

# Sets flags
CFLAGS = -Wall -Wextra -pedantic -Werror
CFLAGS_LESSER = -Wall -Werror

# Main
all: maxTester main

# Compiles program
maxTester: maxTester.cpp storage.cpp
	# Compiles with flags
	$(CC) $(CFLAGS) -o maxTester.o maxTester.cpp storage.cpp

# Compiles main program
main: main.cpp storage.cpp rule.cpp
	# Compiles with flags
	$(CC) $(CFLAGS) -o main.o main.cpp storage.cpp rule.cpp

# Deletes unused files
clean :
	-rm $(objects) *.o a.out
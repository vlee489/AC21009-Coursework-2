# Sets default compiler
CC = g++

# Sets flags
CFLAGS = -Wall -Wextra -pedantic -Werror
CFLAGS_LESSER = -Wall -Werror

# Main
all: maxTester

# Compiles program
maxTester: maxTester.cpp storage.cpp
	# Compiles with flags
	$(CC) $(CFLAGS) -o maxTester.o maxTester.cpp stoarge.cpp

# Deletes unused files
clean :
	-rm $(objects) *.o a.out
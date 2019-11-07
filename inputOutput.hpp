#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

// Gets input from the user and validates it as an integer
int getInt();
// Gets an integer from the user and uses a process function pointer to
// interpret it
bool getInt(bool process(int));

// Prompts the user for an integer using a process function pointer and strings
// for a prompt
void promptInt(std::string prompt, bool process(int));
// Prompts the user for an input between a certain range
int promptIntRange(std::string prompt, int min, int max);
// Displays a menu and processes the user's input using function pointers
void menuInt(void displayPrompt(), bool process(int));

// Gets input from the user as a string
std::string getStr();
// Gets a string from the user and uses a process function pointer to
// interpret it
bool getStr(bool process(std::string));
// Prompts the user for a string using a process function pointer and strings
// for a prompt
void promptStr(std::string prompt, bool process(std::string));

// Defines T as a template to be replaced with the type from the parameter
// e.g. int, string
template <typename T>
// Prints an array of any type to the screen
void printArray(T array, int length);
// Prints a vector of booleans to the screen
void printVector(std::vector<bool>* vector);

// Clears the terminal screen
void clearScreen();

#endif
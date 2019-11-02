#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

int getInt();
void* getInt(void* process(int));
void promptInt(std::string prompt, bool* process(int), std::string failMessage);
int promptIntRange(std::string prompt, int min, int max);
void menuInt(void* displayPrompt(), bool* process(int));
template <typename T>
void printArray(T array, int length);
void printVector(std::vector<bool>* vector);
void clearScreen();

#endif
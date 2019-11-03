#include <iostream>
#include <string>
// Used to clear the screen
#include <stdlib.h>
#include <term.h>
#include <unistd.h>

#include "inputOutput.hpp"

using namespace std;

int getInt() {
  int choice;
  cin >> choice;
  cout << endl;
  return choice;
}

// Gets an integer from the user and uses a process function pointer to
// interpret it
void* getInt(void* process(int)) {
  int choice = getInt();
  return process(choice);
}

// Prompts the user for an integer using a process function pointer and strings
// for prompt and fail messages
void promptInt(string prompt, void* process(int), string failMessage) {
  bool valid;
  do {
    cout << prompt << ": ";
    valid = getInt(process);
    if (!valid) {
      cout << failMessage;
    }
  } while (!valid);
}

//
int promptIntRange(string prompt, int min, int max) {
  bool valid;
  int input;
  do {
    cout << prompt << ": ";
    cin >> input;
    cout << endl;
    if (input >= min && input <= max) {
      valid = true;
    } else {
      cout << "Invalid input" << endl;
      cout << "Please enter a whole number between " << min << " and " << max << endl;
    }
  } while (!valid);
  return input;
}

void menuInt(void* displayPrompt(), void* process(int)) {
  bool valid;
  do {
    displayPrompt();
    valid = getInt(process);
    if (!valid) {
      cout << "Invalid input" << endl;
      cout << "Please try again" << endl;
    }
  } while (!valid);
}

template <typename T>
void printArray(T array, int length) {
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  cout << endl;
}

void printVector(vector<bool>* vector) {
  for (int i = 0; i < int(vector->size()); i++) {
    cout << vector->at(i) << " ";
  }
  cout << endl;
}

// Source: http://www.cplusplus.com/articles/4z18T05o/
void clearScreen() {
  if (!cur_term) {
    int result;
    setupterm(NULL, STDOUT_FILENO, &result);
    if (result <= 0)
      return;
  }
  putp(tigetstr("clear"));
}
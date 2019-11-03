#include <iostream>
#include <string>
// Used to clear the screen
#include <stdlib.h>
#include <term.h>
#include <unistd.h>

#include "inputOutput.hpp"

using namespace std;

int getInt() {
  int input;
  bool valid = false;
  do {
    if (!(cin >> input)) {
      cin.clear();
      cin.ignore();
      cout << endl;
      cout << "Please enter an interger: ";
    }
    else {
      valid = true;
      cout << endl;
    }
  } while (!valid);
  return input;
}

// Gets an integer from the user and uses a process function pointer to
// interpret it
bool getInt(bool process(int)) {
  int choice = getInt();
  return process(choice);
}

// Prompts the user for an integer using a process function pointer and strings
// for prompt and fail messages
void promptInt(string prompt, bool process(int), string failMessage) {
  bool valid = false;
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
  bool valid = false;
  int input;
  do {
    cout << prompt << ": ";
    input = getInt();
    if (input >= min && input <= max) {
      valid = true;
    } else {
      cout << "Invalid Input" << endl;
      cout << "Please enter a whole number between " << min << " and " << max
           << endl << endl;
    }
  } while (!valid);
  return input;
}

void menuInt(void displayPrompt(), bool process(int)) {
  bool valid = false;
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
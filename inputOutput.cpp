#include <iostream>
#include <string>

// Used to clear the screen
// #include <stdlib.h>
// #include <term.h>
// #include <unistd.h>

// Used for suboptimal clear screen
#include <cstdlib>
// Imports the header file for this individual source file
#include "inputOutput.hpp"

using namespace std;

// Gets input from the user and validates it as an integer
int getInt() {
  // Stores the user's input as an integer
  int input;
  // Assumes the user's input to be invalid
  bool valid = false;
  do {
    // Attempts to get the user's input as interger and if this fails
    if (!(cin >> input)) {
      // Gets rid of warnings and errors from cin
      cin.clear();
      // Clears cin of any input
      cin.ignore();
      cout << endl;
      cout << "Please enter an interger: ";
    }
    // If the user's input is valid
    else {
      valid = true;
      cout << endl;
    }
  }
  // Runs until the user's input is proven to be valid
  while (!valid);
  return input;
}

// Gets an integer from the user and uses a process function pointer to
// interpret it
bool getInt(bool process(int)) {
  // Gets input from the user and validates it as an integer
  int choice = getInt();
  // Returns the output of the process function
  return process(choice);
}

// Prompts the user for an integer using a process function pointer and strings
// for prompt and fail messages
void promptInt(string prompt, bool process(int)) {
  // Assumes the user's input to be false
  bool valid = false;
  do {
    // Prints the prompt to the console
    cout << prompt << ": ";
    // Gets an integer from the user and uses a process function pointer to
    // interpret it
    valid = getInt(process);
  }
  // Loops until the user's input is valid
  while (!valid);
}

// Prompts the user for an input between a certain range
int promptIntRange(string prompt, int min, int max) {
  // Assumes the user's input to be false
  bool valid = false;
  // Stores the user's input
  int input;
  do {
    // Prints the prompt to the console
    cout << prompt << ": ";
    // Gets input from the user and validates it as an integer
    input = getInt();
    // Checks if the user's input is within the current range
    if (input >= min && input <= max) {
      valid = true;
    } else {
      cout << "Invalid Input" << endl;
      cout << "Please enter a whole number between " << min << " and " << max
           << endl
           << endl;
    }
  }
  // Loops until the user's input is valid
  while (!valid);
  return input;
}

// Displays a menu and processes the user's input using function pointers
void menuInt(void displayPrompt(), bool process(int)) {
  // Assumes the user's input to be false
  bool valid = false;
  do {
    // Displays the menu to the user
    displayPrompt();
    // Gets input from the user and validates it as an integer
    valid = getInt(process);
    // Checks if the user's input was validated
    if (!valid) {
      cout << "Invalid input" << endl;
      cout << "Please try again" << endl;
    }
  }
  // Loops until the user's input is validated
  while (!valid);
}

// Gets input from the user as a string
string getStr() {
  // Stores the user's input as a string
  string input;
  //
  getline(cin, input);
  //
  return input;
}

// Gets a string from the user and uses a process function pointer to
// interpret it
bool getStr(bool process(string)) {
  // Gets input from the user
  string choice = getStr();
  // Returns the output of the process function
  return process(choice);
}

//
void promptStr(string prompt, bool process(string)) {
  // Prints the prompt to the console
  cout << prompt << ": ";
  // Gets a string from the user and uses a process function pointer to
  // interpret it
  getStr(process);
}

// Defines T as a template to be replaced with the type from the parameter
// e.g. int, string
template <typename T>
// Prints an array of any type to the screen
void printArray(T array, int length) {
  // Runs through each item in the array
  for (int i = 0; i < length; i++) {
    // Prints the element to the screen
    cout << array[i] << " ";
  }
  cout << endl;
  cout << endl;
}

// Prints a vector of booleans to the screen
void printVector(vector<bool>* vector) {
  // Runs through each element in the vector
  for (int i = 0; i < int(vector->size()); i++) {
    // Prints the element to the screen
    cout << vector->at(i) << " ";
  }
  cout << endl;
}

// // Clears the terminal screen in Linux
// // Source: http://www.cplusplus.com/articles/4z18T05o/
// void clearScreen() {
//   if (!cur_term) {
//     int result;
//     setupterm(NULL, STDOUT_FILENO, &result);
//     if (result <= 0)
//       return;
//   }
//   putp(tigetstr("clear"));
// }

// Clears the terminal screen in a non-OS specific way
// Source: http://www.cplusplus.com/articles/4z18T05o/
void clearScreen() {
  if (system("clear"))
    system("CLS");
}
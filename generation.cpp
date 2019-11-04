// Imports the header file for this individual source file
#include "generation.hpp"
// Imports error codes
#include "error.hpp"
// Imports methods to handle user input and output
#include "inputOutput.hpp"

// Used to print to the console
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor to set values to defaults
Generation::Generation() {
  // Inititalises a generation pointer
  gen = new vector<bool>();
  // Inititalises an error buffer which will be used to store a message to the
  // user if an error occurs
  errorBuffer = "";
}

// Allows the user to set a first generation
void Generation::firstGenerator() {
  // Assumes the input is false
  bool valid = false;
  do {
    // Displays the menu to the user
    firstGenMenu();
    // Gets user input and validates it as an integer
    int choice = getInt();
    // Processes the users input and validates it fully
    valid = processFirstGen(choice);
    // Checks if the input is invalid
    if (!valid) {
      cout << "Invalid Input entered" << endl
           << "Please try again" << endl
           << endl;
    }
    // Loop until the user's input is valid
  } while (!valid);
  clearScreen();
}

// Displays a menu for choosing how what type of first generation we should use
void Generation::firstGenMenu() {
  cout << "First Generation Select:" << endl;
  cout << "1. Start using a single true element as the first generation"
       << endl;
  cout << "2. Create a custom generation to start from" << endl;
  cout << "0. Exit" << endl;
  cout << "Choose an option from the list: ";
}

// Processes the user's chosen type of first generation
bool Generation::processFirstGen(int choice) {
  switch (choice) {
    case 1:
      // Places a single true element as the first generation vector
      gen->push_back(true);
      return true;
    case 2:
      // Allows the user to create a custom generation
      customGenerator();
      return true;
    case 0:
      // Exits the program without error
      exit(0);
    default:
      cout << "Invalid Input entered" << endl
           << "Please try again" << endl
           << endl;
      return false;
  }
}

// Allows the user to set their own generation
void Generation::customGenerator() {
  // Assumes the user hasn't finished inputing parameters
  bool finished;
  do {
    clearScreen();
    if (errorBuffer.compare("") != 0) {
      cout << errorBuffer << endl;
      errorBuffer = "";
    }
    cout << endl << "Elements:  ";
    printVector(gen);
    customMenu();
    // Gets user input and validates it as an integer
    int choice = getInt();
    finished = processCustom(choice);
  // Loops until we have finished inputting
  } while (finished == false);
}

void Generation::customMenu() {
  cout << endl;
  cout << "Custom Generator Commands: " << endl;
  cout << "1. Add" << endl;
  cout << "2. Remove" << endl;
  cout << "3. Finish" << endl;
  cout << "0. Exit" << endl;
  cout << "Choose an option from the list: ";
}

bool Generation::processCustom(int choice) {
  switch (choice) {
    case 1:
      addToVector();
      break;
    case 2:
      removeFromVector();
      break;
    case 3:
      if (gen->empty()) {
        errorBuffer = "You cannot have a first generation with no values";
        break;
      } else {
        return true;
      }
    case 0:
      exit(0);
    default:
      cout << "Invalid Input entered" << endl
           << "Please try again" << endl
           << endl;
  }
  return false;
}

int Generation::addToVector() {
  if (gen->size() <= 20) {
    bool valid = false;
    do {
      cout
          << "Type in a 1 or 0 to indicate whether the next element is true or "
             "false: ";
      // Gets user input and validates it as an integer
      int choice = getInt();
      if (choice == 0) {
        gen->push_back(false);
        valid = true;
      } else if (choice == 1) {
        gen->push_back(true);
        valid = true;
      } else {
        cout << "Invalid Input entered" << endl;
        cout << "Please try again" << endl << endl;
      }
    } while (valid == false);
  } else {
    errorBuffer = "You can only have a generation up to 20 numbers in length";
    return VECTOR_AT_MAX_SIZE;
  }
  return SUCCESS;
}

int Generation::removeFromVector() {
  if (!gen->empty()) {
    bool valid;
    do {
      displayRemoval();
      // Gets user input and validates it as an integer
      int choice = getInt();
      valid = processRemoval(choice);
    } while (valid == false);
  } else {
    errorBuffer = "You can't delete from an empty generation";
    return INVALID_VECTOR_OPERATION;
  }
  return SUCCESS;
}

void Generation::displayRemoval() {
  cout << "Elements: ";
  printVector(gen);
  cout << "Numbers:  ";
  for (int i = 0; i < int(gen->size()); i++) {
    cout << i << " ";
  }
  cout << endl;
  cout << "Select the number of the element to remove: ";
}

int Generation::processRemoval(int choice) {
  if (choice < int(gen->size())) {
    cout << "Element " << choice << " removed" << endl;
    gen->erase(gen->begin() + choice);
    return true;
  }
  cout << "Invalid Input entered" << endl;
  cout << "Please try again" << endl << endl;
  return false;
}

vector<bool>* Generation::returnGen() {
  return gen;
}
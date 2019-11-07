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
  // Initialises a generation pointer
  gen = new vector<bool>();
  // Initialises an error buffer which will be used to store a message to the
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
    // Checks if the error buffer isn't blank
    if (errorBuffer.compare("") != 0) {
      // Prints the error message to the user
      cout << errorBuffer << endl;
      // Clears the error buffer
      errorBuffer = "";
    }
    cout << endl << "Elements:  ";
    // Prints the current elements in the generation
    printVector(gen);
    // Displays the menu to the user
    customMenu();
    // Gets user input and validates it as an integer
    int choice = getInt();
    // Processes user input
    finished = processCustom(choice);
  // Loops until we have finished inputting
  } while (finished == false);
}

// Displays a menu for editing a custom generation we should use
void Generation::customMenu() {
  cout << endl;
  cout << "Custom Generator Commands: " << endl;
  cout << "1. Add" << endl;
  cout << "2. Remove" << endl;
  cout << "3. Finish" << endl;
  cout << "0. Exit" << endl;
  cout << "Choose an option from the list: ";
}

// Processes the user's chosen operation on their custom generation
bool Generation::processCustom(int choice) {
  switch (choice) {
    case 1:
      // Allows the user to add an element to the generation
      addToVector();
      break;
    case 2:
      // Allows the user to remove an element from the generation
      removeFromVector();
      break;
    case 3:
      // Checks if the generation is empty
      if (gen->empty()) {
        // Sets an error message in the error buffer
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

// Allows the user to add to their custom generation
int Generation::addToVector() {
  // Checks if the generation is not already full
  if (gen->size() <= 20) {
    // Assumes the user's input to be invalid
    bool valid = false;
    do {
      cout
          << "Type in a 1 or 0 to indicate whether the next element is true or "
             "false: ";
      // Gets user input and validates it as an integer
      int choice = getInt();
      // Checks if the user has entered the new element to be false
      if (choice == 0) {
        // Adds a false element to the end of the generation
        gen->push_back(false);
        valid = true;
      }
      // Checks if the user has entered the new element to be true
      else if (choice == 1) {
        // Adds a true element to the end of the generation
        gen->push_back(true);
        valid = true;
      } 
      else {
        cout << "Invalid Input entered" << endl;
        cout << "Please try again" << endl << endl;
      }
    } 
    // Runs while the user's input is false
    while (valid == false);
  } else {
    // Sets an error message in the error buffer
    errorBuffer = "You can only have a generation up to 20 numbers in length";
    return VECTOR_AT_MAX_SIZE;
  }
  return SUCCESS;
}

// Allows the user to remove items from their custom generation
int Generation::removeFromVector() {
  // Checks if the generation is not empty
  if (!gen->empty()) {
    // Assumes the user's input to be false
    bool valid = false;
    do {
      // Displays the removal menu
      displayRemoval();
      // Gets user input and validates it as an integer
      int choice = getInt();
      // Processes the user's input
      valid = processRemoval(choice);
    }
    // Runs while the user's input is false
    while (valid == false);
  } else {
    // Sets an error message in the error buffer
    errorBuffer = "You can't delete from an empty generation";
    return INVALID_VECTOR_OPERATION;
  }
  return SUCCESS;
}

// Displays a menu for removing an element from a custom generation
void Generation::displayRemoval() {
  cout << "Elements: ";
  // Displays all the elements
  printVector(gen);
  cout << "Numbers:  ";
  // Prints an index for the elements displayed
  for (int i = 0; i < int(gen->size()); i++) {
    cout << i << " ";
  }
  cout << endl;
  cout << "Select the number of the element to remove or type -1 to cancel: ";
}

// Removes the user's chosen element or skips the process if the user types in -1
int Generation::processRemoval(int choice) {
  // Checks if the user's input is a valid index
  if (choice < int(gen->size()) && choice >= 0) {
    // Removes the user's chosen element
    gen->erase(gen->begin() + choice);
    return true;
  }
  // Skips this process if the user has entered -1
  else if (choice == -1) {
    return true;
  }
  else {
    cout << "Invalid Input entered" << endl;
    cout << "Please try again" << endl << endl;
    return false;
  }
}

// Returns the generation pointer
vector<bool>* Generation::returnGen() {
  return gen;
}
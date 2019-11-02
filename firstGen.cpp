#include "firstGen.hpp"

#include "error.hpp"
#include "inputOutput.hpp"
// Used to print to the console
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int addToVector(vector<bool>* firstGen) {
  bool valid = false;
  do {
    cout << "Type in a 1 or 0 to indicate whether the next element is true or "
            "false: ";
    int choice = getInt();
    if (choice == 0) {
      firstGen->push_back(false);
      valid = true;
    } else if (choice == 1) {
      firstGen->push_back(true);
      valid = true;
    } else {
      cout << "Invalid Input entered" << endl;
      cout << "Please try again" << endl << endl;
    }
  } while (valid == false);
  return SUCCESS;
}

void displayRemoval(vector<bool>* firstGen) {
  cout << "Elements: ";
  printVector(firstGen);
  cout << "Numbers:  ";
  for (int i = 0; i < int(firstGen->size()); i++) {
    cout << i << " ";
  }
  cout << endl;
  cout << "Select the number of the element to remove: ";
}

int processRemoval(vector<bool>* firstGen, int choice) {
  if (choice < int(firstGen->size())) {
    cout << "Element " << choice << " removed" << endl;
    firstGen->erase(firstGen->begin() + choice);
    return true;
  }
  cout << "Invalid Input entered" << endl;
  cout << "Please try again" << endl << endl;
  return false;
}

int removeFromVector(vector<bool>* firstGen) {
  bool valid;
  do {
    displayRemoval(firstGen);
    int choice;
    cin >> choice;
    valid = processRemoval(firstGen, choice);
  } while (valid == false);
  return SUCCESS;
}

void customMenu() {
  cout << endl;
  cout << "Custom Generator Commands: " << endl;
  cout << "1. Add" << endl;
  cout << "2. Remove" << endl;
  cout << "3. Finish" << endl;
  cout << "0. Exit" << endl;
  cout << "Choose an option from the list: ";
}

bool processCustom(int choice, vector<bool>* firstGen) {
  cout << endl;
  switch (choice) {
    case 1:
      addToVector(firstGen);
      break;
    case 2:
      removeFromVector(firstGen);
      break;
    case 3:
      return true;
    case 0:
      exit(0);
    default:
      cout << "Invalid Input entered" << endl
           << "Please try again" << endl
           << endl;
  }
  return false;
}

void custom(vector<bool>* firstGen) {
  bool finished;
  do {
    clearScreen();
    cout << endl << "Elements:  ";
    printVector(firstGen);
    customMenu();
    int choice;
    cin >> choice;
    finished = processCustom(choice, firstGen);
  } while (finished == false);
}

void displayFirstGenMenu() {
  cout << "First Generation Select:" << endl;
  cout << "1. Start using a single true element as the first generation"
       << endl;
  cout << "2. Create a custom generation to start from" << endl;
  cout << "3. Load the first generation from a saved table" << endl;
  cout << "0. Exit" << endl;
  cout << "Choose an option from the list: ";
}

bool processFirstGen(vector<bool>* firstGen, int choice) {
  switch (choice) {
    case 1:
      firstGen->push_back(true);
      return true;
    case 2:
      // customFirstGen = &custom();
      custom(firstGen);
      return true;
    case 3:
      return true;
    case 0:
      exit(0);
    default:
      cout << "Invalid Input entered" << endl
           << "Please try again" << endl
           << endl;
      return false;
  }
}

void firstGenerator(vector<bool>* firstGen) {
  bool valid = false;

  do {
    displayFirstGenMenu();
    int choice;
    cin >> choice;
    cout << endl;
    valid = processFirstGen(firstGen, choice);
    if (!valid) {
      cout << "Invalid Input entered" << endl
           << "Please try again" << endl
           << endl;
    }
  } while (!valid);

  clearScreen();
}
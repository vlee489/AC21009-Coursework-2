#include "generation.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "error.hpp"
#include "inputOutput.hpp"

using namespace std;

Generation::Generation() {
  gen = new vector<bool>();
}

void Generation::firstGenerator() {
  bool valid = false;
  do {
    firstGenMenu();
    int choice;
    cin >> choice;
    cout << endl;
    valid = processFirstGen(choice);
    if (!valid) {
      cout << "Invalid Input entered" << endl
           << "Please try again" << endl
           << endl;
    }
  } while (!valid);
  clearScreen();
}

// void Generation::firstGenerator() {
//   menuInt(firstGenMenu, processFirstGen);
// }

void firstGenMenu() {
  cout << "First Generation Select:" << endl;
  cout << "1. Start using a single true element as the first generation"
       << endl;
  cout << "2. Create a custom generation to start from" << endl;
  cout << "3. Load the first generation from a saved table" << endl;
  cout << "0. Exit" << endl;
  cout << "Choose an option from the list: ";
}

bool Generation::processFirstGen(int choice) {
  switch (choice) {
    case 1:
      gen->push_back(true);
      return true;
    case 2:
      custom();
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

void Generation::custom() {
  bool finished;
  do {
    clearScreen();
    cout << endl << "Elements:  ";
    printVector(gen);
    customMenu();
    int choice;
    cin >> choice;
    finished = processCustom(choice);
  } while (finished == false);
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

bool Generation::processCustom(int choice) {
  cout << endl;
  switch (choice) {
    case 1:
      addToVector();
      break;
    case 2:
      removeFromVector();
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

int Generation::addToVector() {
  bool valid = false;
  do {
    cout << "Type in a 1 or 0 to indicate whether the next element is true or "
            "false: ";
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
  return SUCCESS;
}

int Generation::removeFromVector() {
  bool valid;
  do {
    displayRemoval();
    int choice;
    cin >> choice;
    valid = processRemoval(choice);
  } while (valid == false);
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
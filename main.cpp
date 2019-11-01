#include <iostream>
#include <sstream>
#include <string>

#include "error.hpp"
#include "rule.hpp"
#include "table.hpp"

using namespace std;

void runProgram();

int main() {
  runProgram();
  return 0;
}

int userNumberInput(int min, int max, string message) {
  int UserInput;
  cout << "\n" + message + ": ";
  while (!(cin >> UserInput) || UserInput < min || UserInput > max) {
    cout << "\nInvalid input\n";
    cout << "Please enter a whole number between " << min << " and " << max;
    cout << endl;
  }
  return UserInput;
}

template <typename T>
void printArray(T array, int length) {
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  cout << endl;
}

void checkValidity(int valid) {
  switch(valid) {
    case SUCCESS:
      break;
    case INVALID_TABLE_PARAMETER:
      cout << "Error: " << endl;
      break;
    case RULE_NUM_OUT_RANGE:
      cout << "Error: " << endl;
      break;
    case DECIMAL_VAL_OUT_OF_RANGE:
      cout << "Error: " << endl;
      break;
    case TABLE_NOT_INITIALISED:
      cout << "Error: Function has been called using an uninitialised table" << endl;
      break;
    case Y_INDEX_OUT_OF_BOUNDS:
      cout << "Error: A value is attempting to be set using a Y co-ordinate that is out of the bounds of the table" << endl;
      break;
    case UNEXPECTED_NULL_POINTER:
      cout << "Error: Function has been called using a null pointer" << endl;
      break;
    default:
      cout << "Error: Invalid Error Code" << endl;
      break;
  }

}

void runProgram() {
  Table *fullTable = new Table();
  Rule *ruleObj = new Rule();

  int rule = userNumberInput(0, 256, "Please enter the desired rule you want to use");
  int generations = userNumberInput(0, 101, "Please enter the desired generations you want");
  
  checkValidity(fullTable->initTable(generations));
  checkValidity(ruleObj->setRule(rule));

  int arrayWidth = fullTable->getArrayWidth();
  for (int row = 1; row < generations; row++) {
    for (int col = 0; col < arrayWidth; col++) {
      bool* neighbourhood = fullTable->getNeighbourhood(col, row);
      bool cell = ruleObj->generateCell(neighbourhood);
      checkValidity(fullTable->setVal(col, row, cell));
      delete neighbourhood;
    }
  }
  cout << endl;
  // cout << "Debug Table Check: ";
  // printArray(fullTable->getPTable(), fullTable->getArraySize());
  fullTable->printTable();
}

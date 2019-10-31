#include <iostream>
#include <sstream>
#include <string>

#include "rule.hpp"
#include "storage.hpp"
using namespace std;

int runProgram();

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

int runProgram() {
  int rule = userNumberInput(0, 256, "Please enter the desired rule you want to use");
  int generations = userNumberInput(0, 101, "Please enter the desired generations you want");
  Table fullTable;
  fullTable.initTable(generations);
  Rule ruleObj;
  ruleObj.setRule(rule);
  int arrayWidth = fullTable.getArrayWidth();
  for (int row = 1; row < generations; row++) {
    for (int col = 0; col < arrayWidth; col++) {
      bool* neighbourhood = fullTable.getNeighbourhood(col, row);
      bool cell = ruleObj.generateCell(neighbourhood);
      fullTable.setVal(col, row, cell);
    }
  }
  fullTable.debugTable();
  return 0;
}
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "error.hpp"
#include "firstGen.hpp"
#include "inputOutput.hpp"
#include "rule.hpp"
#include "table.hpp"

using namespace std;

void runProgram();

int main() {
  runProgram();
  return 0;
}

// int userNumberInput(int min, int max, string message) {
//   int UserInput;
//   cout << "\n" + message + ": ";
//   while (!(cin >> UserInput) || UserInput < min || UserInput > max) {
//     cout << "\nInvalid input\n";
//     cout << "Please enter a whole number between " << min << " and " << max;
//     cout << endl;
//   }
//   return UserInput;
// }

void runProgram() {
  Table* fullTable = new Table();
  Rule* ruleObj = new Rule();

  // int rule =
  //     userNumberInput(0, 256, "Please enter the desired rule you want to
  //     use");
  // int generations =
  //     userNumberInput(0, 101, "Please enter the desired generations you
  //     want");

  clearScreen();
  int rule =
      promptIntRange("Please enter the desired rule you want to use", 0, 255);
  int generations =
      promptIntRange("Please enter the desired generations you want", 0, 100);

  checkValidity(fullTable->initTable(generations));
  checkValidity(ruleObj->setRule(rule));
  vector<bool> firstGen;
  firstGenerator(&firstGen);

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

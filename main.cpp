#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "error.hpp"
#include "generation.hpp"
#include "inputOutput.hpp"
#include "rule.hpp"
#include "table.hpp"

using namespace std;

void runProgram();

int main() {
  runProgram();
  return 0;
}

void runProgram() {
  Table* fullTable = new Table();
  Rule* ruleObj = new Rule();
  Generation* generationObj = new Generation();

  clearScreen();
  int rule =
      promptIntRange("Please enter the desired rule you want to use", 0, 255);
  int generations =
      promptIntRange("Please enter the desired generations you want", 0, 100);

  generationObj->firstGenerator();
  vector<bool>* firstGen = generationObj->returnGen();

  checkValidity(fullTable->initTable(*firstGen, generations));
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

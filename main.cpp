#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Imports error codes
#include "error.hpp"
// Imports methods which allows the user to set their own generation
#include "generation.hpp"
// Imports methods to handle user input and output
#include "inputOutput.hpp"
// Imports methods to generate rules and convert numbers to binary and decimal
#include "rule.hpp"
// Imports merthods for storing a table of values
#include "table.hpp"

using namespace std;

// Stores pointers for objects of classes
Table* fullTable;
Rule* ruleObj;
Generation* generationObj;

// Headers for the methods in this file
void initObjects();
void displayMenu();
bool processMenu(int choice);
void createAutomaton();
void loadAutomaton();

// Main Function
int main() {
  initObjects();
  menuInt(displayMenu, processMenu);
  return 0;
}

// Initialises objects 
void initObjects() {
  fullTable = new Table();
  ruleObj = new Rule();
  generationObj = new Generation();
}

void displayMenu() {
  cout << "Cellular Automaton Program" << endl;
  cout << "Module Code: AC210009" << endl;
  cout << "Assignment 2";
  cout << endl;
  cout << "" << endl;
  cout << "1. Create your own cellular automaton" << endl;
  cout << "2. Load a cellular automaton from a file" << endl;
  cout << "0. Exit" << endl;
  cout << "Choose an option from the list: ";
}

bool processMenu(int choice) {
  switch(choice) {
    case 1:
      createAutomaton();
      break;
    case 2:
      loadAutomaton();
      break;
    default:
      return false;

  }
  return true;
}

void createAutomaton() {
  // Creates the objects of the global object pointers
  Table* fullTable = new Table();
  Rule* ruleObj = new Rule();
  Generation* generationObj = new Generation();

  clearScreen();
  // Gets the rule number from the user
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

void loadAutomaton() {

}


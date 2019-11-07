#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

// Imports error codes
#include "error.hpp"
// Imports the header file for this individual source file
#include "main.hpp"
// Imports methods which allows the user to set their own generation
#include "generation.hpp"
// Imports methods to handle user input and output
#include "inputOutput.hpp"
// Imports methods to generate rules and convert numbers to binary and decimal
#include "rule.hpp"
// Imports methods for storing a table of values
#include "table.hpp"
// Imports game of life
#include "gameOfLife.hpp"

using namespace std;

// Main Function
int main() {
  clearScreen();
  // Keeps running
  while (true) {
    // Initialises objects that are not already initialised
    initObjects(false);
    // Displays the main menu and processes user input
    menuInt(displayMenu, processMenu);
  }
  return 0;
}

// Initialises global objects for each external class
// But only does so, if it is yet uninitialised or the erase flag is turned on
void initObjects(bool erase) {
  if (fullTable == nullptr || erase) {
    fullTable = new Table();
  }

  if (ruleObj == nullptr || erase) {
    ruleObj = new Rule();
  }

  if (generationObj == nullptr || erase) {
    generationObj = new Generation();
  }
}

// Displays the main menu
void displayMenu() {
  cout << "Cellular Automaton Program" << endl;
  cout << "Module Code: AC210009" << endl;
  cout << "Authors: Max Kelly, Vincent Lee and Ramsay Sewell" << endl;
  cout << "Assignment 2";
  cout << endl;
  cout << endl;
  cout << "1. Create your own cellular automaton" << endl;
  cout << "2. Load a cellular automaton from a file" << endl;
  cout << "3. Save a cellular automaton to a file" << endl;
  cout << "4. Conway's Game of Life" << endl;
  cout << "5. Langton's Ant" << endl;
  cout << "0. Exit" << endl;
  cout << "Choose an option from the list: ";
}

// Processes the user's chosen operation
bool processMenu(int choice) {
  switch (choice) {
    case 1:
      createAutomaton();
      break;
    case 2:
      loadAutomaton();
      break;
    case 3:
      saveAutomaton();
      break;
    case 4:
      gameOfLife();
      break;
    case 5:
      langtonsAnt();
      break;
    case 0:
      // Exits the program
      exit(0);
    default:
      return false;
  }
  return true;
}

// Lets the user create and setup their own cellular automaton
void createAutomaton() {
  initObjects(true);
  clearScreen();
  // Gets the rule number from the user
  int rule =
      promptIntRange("Please enter the desired rule you want to use", 0, 255);
  // Gets the number of generations from the user
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

//
void loadAutomaton() {
  clearScreen();
  // Asks the user what file we should load and loads it
  promptStr("What is the path of the file you'd like to load?", processLoad);
  //
  fullTable->printTable();
}

//
bool processLoad(string filename) {
  checkValidity(fullTable->loadTable(filename));
  // if (valid != SUCCESS) {
  //   return false;
  // } else {
  cout << "Loading file successful" << endl;
  // }
  return true;
}

//
void gameOfLife() {
  int width =
      promptIntRange("Please enter the desired width of the grid", 2, 101);
  int height =
      promptIntRange("Please enter the desired height of the grid", 2, 101);
  setupGameOfLife(width, height);
  while (true) {
    // If Escape is held, then exits game of life
    runGameOfLife();
    usleep(500000);
  }
}

//
void saveAutomaton() {
  clearScreen();
  // Asks the user what file we should load and loads it
  promptStr("Where would you like to save?", processSave);
}

//
bool processSave(string filename) {
  checkValidity(fullTable->saveTable(filename));
  cout << "Saving file successful" << endl;
  return true;
}

void langtonsAnt() {}

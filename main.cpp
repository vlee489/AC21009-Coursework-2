// Imports the header file for this individual source file
#include "main.hpp"
// Imports error codes
#include "error.hpp"
// Imports game of life
#include "gameOfLife.hpp"
// Imports methods which allows the user to set their own generation
#include "generation.hpp"
// Imports methods to handle user input and output
#include "inputOutput.hpp"
// Imports Langton's Ant
#include "LangtonsAnt.hpp"
// Imports methods to generate rules and convert numbers to binary and decimal
#include "rule.hpp"
// Imports methods for storing a table of values
#include <iostream>
#include <string>
#include <vector>

#include "table.hpp"
// Used for sleeping
#include <unistd.h>

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
      // Lets the user create and setup their own cellular automaton
      createAutomaton();
      break;
    case 2:
      // Allows the user to load a previously saved cellular automaton
      loadAutomaton();
      break;
    case 3:
      // Allows the user to save their cellular automaton to an external file
      saveAutomaton();
      break;
    case 4:
      // Runs a simulation of Conway's Game of Life
      gameOfLife();
      break;
    case 5:
      LangtonsAnt();
      break;
    case 0:
      // Exits the program
      exit(0);
    default:
      // Runs if the user's input is invalid
      return false;
  }
  // Runs if the user's input is valid
  return true;
}

// Lets the user create and setup their own cellular automaton
void createAutomaton() {
  // Initialises all objects, clearing previous data
  initObjects(true);
  clearScreen();
  // Gets the rule number from the user
  int rule =
      promptIntRange("Please enter the desired rule you want to use", 0, 255);
  // Gets the number of generations from the user
  int generations =
      promptIntRange("Please enter the desired generations you want", 0, 100);

  // Allows the user to set a first generation
  generationObj->firstGenerator();
  // Extracts the first generation the user's set from the generation object
  vector<bool>* firstGen = generationObj->returnGen();

  // checkValidity: Checks if the operation returns an error code, if it does,
  // it prints it to the screen and stops the program

  // Initialises the table with the appropriate first generation and size
  checkValidity(fullTable->initTable(*firstGen, generations));
  // Sets the rule we are using in the rule object
  checkValidity(ruleObj->setRule(rule));
  // Gets the width of the array in the table object
  int arrayWidth = fullTable->getArrayWidth();

  // Counts through each row except the first which already has a first
  // generation
  for (int row = 1; row < generations; row++) {
    // Counts through each column
    for (int col = 0; col < arrayWidth; col++) {
      // Stores the neighbourhood of the current field
      bool* neighbourhood = fullTable->getNeighbourhood(col, row);
      // Calculates the value of the current field based on the neighbourhood
      bool cell = ruleObj->generateCell(neighbourhood);
      // Stores the value in the table
      checkValidity(fullTable->setVal(col, row, cell));
      // Deletes the neighbourhood we extracted
      delete neighbourhood;
    }
  }
  cout << endl;
  // Displays the finished table to the user
  checkValidity(fullTable->printTable());
}

// Allows the user to load a previously saved cellular automaton
void loadAutomaton() {
  // Initialises all objects, clearing previous data
  initObjects(true);
  clearScreen();
  // Asks the user what file we should load and loads it
  promptStr("What is the path of the file you'd like to load?", processLoad);
}

// Processes loading a table from a file
bool processLoad(string filename) {
  // Loads the table from the file and displays an error if this is unsuccessful
  checkValidity(fullTable->loadTable(filename));
  cout << "Loading file successful" << endl << endl;
  // Prints the loaded table to the screen if the table has been initialised
  checkValidity(fullTable->printTable());
  return true;
}

// Allows the user to save their cellular automaton to an external file
void saveAutomaton() {
  clearScreen();
  // Asks the user what file we should load and loads it
  promptStr("Where would you like to save?", processSave);
}

// Processes saving the table to a file
bool processSave(string filename) {
  // Saves the table to the file and displays an error if this is unsuccessful
  checkValidity(fullTable->saveTable(filename));
  cout << "Saving file successful" << endl << endl;
  return true;
}

// Runs a simulation of Conway's Game of Life
void gameOfLife() {
  // Gets the width from the user
  int width =
      promptIntRange("Please enter the desired width of the grid", 2, 101);
  // Gets the height from the user
  int height =
      promptIntRange("Please enter the desired height of the grid", 2, 101);
  // Sets up Game of Life to be used with user's values
  checkValidity(setupGameOfLife(width, height));
  while (true) {
    // If Escape is held, then exits game of life
    checkValidity(runGameOfLife());
    // Refreshes every half second
    usleep(500000);
  }
}

// Runs a simulation of Langton's ant
void LangtonsAnt() {
  // Gets the width from the user
  int width =
      promptIntRange("Please enter the desired width of the grid", 2, 101);
  // Gets the height from the user
  int height =
      promptIntRange("Please enter the desired height of the grid", 2, 101);
  // Sets up Langton's ant to be used with user's values
  checkValidity(setupLangtonsAnt(width, height));
  // Keeps running
  while (true) {
    // Runs the langton's ant simulation
    checkValidity(runLangtonsAnt());
    // Refreshes every half second
    usleep(500000);
  }
}

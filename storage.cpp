// Imports the header file for this individual source file
#include "storage.hpp"
// Used to print to the console
#include <iostream>
using namespace std;

// Table class: Store values of a table for processing and output

// Creates and initialises an array of appropriate length to store the table
void Table::allocTable() {
  // Calculates the number of cells in the table
  arraySize = arrayWidth * arrayHeight;
  // Creates a single dynamic array which will stores all cells in
  // and initialises them to false.
  // This increases efficiency over a traditional 2D Array.
  pTable = new bool[arraySize]{false};
}

// Sets the starting value of the cellular automaton
void Table::setFirstVal() {
  // Sets the middle position of the first line to true
  pTable[arrayWidth / 2] = true;
}

int Table::properMod(int a, int b) {
  return (b + (a % b)) % b;
}

// Creates a table to store all autonoma data
void Table::initTable(int generations) {
  // Calculates the width of the table required to display all the generations
  arrayWidth = (2 * generations) - 1;
  // Stores the the height of the table
  arrayHeight = generations;
  // Creates the array to store the table
  allocTable();
  // Sets the starting value of the cellular automaton
  setFirstVal();
}

// Creates a table to store a line of data during processing
void Table::initLine(int units) {
  // Assigns the tables width and height appropriately
  arrayWidth = units;
  arrayHeight = 1;
  // Creates the array to store the table
  allocTable();
}

// Returns the value of the appropriate index of the table
bool Table::getVal(int x, int y) {
  return pTable[y * arrayHeight + x];
}

bool* Table::getNeighbourhood(int x, int y) {
  bool* neighbourhood = new bool[3];
  for (int i = 0; i < 3; i++) {
    neighbourhood[i] = getVal(properMod(x + i - 1, arrayWidth), y);
  }
  return neighbourhood;
}

// Sets the value of the appropriate index of the table
void Table::setVal(int x, int y, bool val) {
  pTable[y * arrayHeight + x] = val;
}

// Prints out the values of the table in a basic manner for debugging
void Table::debugTable() {
  cout << endl;
  // Counts through each row
  for (int row = 0; row < arrayHeight; row++) {
    // Counts through each column
    for (int col = 0; col < arrayWidth; col++) {
      // Prints the individual value to the screen
      cout << getVal(col, row) << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int Table::getArrayWidth() {
  return arrayWidth;
}

int Table::getArrayHeight() {
  return arrayHeight;
}

int Table::getArraySize() {
  return arraySize;
}
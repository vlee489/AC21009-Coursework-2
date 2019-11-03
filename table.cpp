// Imports the header file for this individual source file
#include "table.hpp"

#include "error.hpp"
// Used to print to the console
#include <iostream>
//
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Table class: Store values of a table for processing and output
// Constructors to set values to defaults
Table::Table() {
  pTable = nullptr;
  init = false;
  arrayWidth = 1;
  arrayHeight = 1;
  arraySize = 1;
}

// Copy constructor
Table::Table(Table& ogTable) {
  // Stores the pointer to the table we're copying
  bool* ogPTable = ogTable.getPTable();
  //
  init = ogTable.getPTable();
  // Copies the array width and height variables
  arrayWidth = ogTable.getArrayWidth();
  arrayHeight = ogTable.getArrayHeight();
  // Creates the array to store the table
  allocTable();
  // Performs a deep copy by copying the value of each element of the array
  for (int i = 0; i < arraySize; i++) {
    pTable[i] = ogPTable[i];
  }
}

// Destructor to delete the table
Table::~Table() {
  delete (pTable);
}

// Creates and initialises an array of appropriate length to store the table
int Table::allocTable() {
  if (arrayHeight < 1 || arrayWidth < 1) {
    return INVALID_TABLE_PARAMETER;
  }
  // Calculates the number of cells in the table
  arraySize = arrayWidth * arrayHeight;
  // Creates a single dynamic array which will stores all cells in
  // and initialises them to false.
  // This increases efficiency over a traditional 2D Array.
  pTable = new bool[arraySize]{false};
  //
  init = true;

  return SUCCESS;
}

// Sets the starting value of the cellular automaton
void Table::setFirstVal() {
  // Sets the middle position of the first line to true
  pTable[arrayWidth / 2] = true;
}

// Creates a table to store all autonoma data
int Table::initTable(int generations) {
  // Calculates the width of the table required to display all the generations
  arrayWidth = (2 * generations) - 1;
  // Stores the the height of the table
  arrayHeight = generations;
  // Creates the array to store the table
  int valid = allocTable();
  if (valid == SUCCESS) {
    // Sets the starting value of the cellular automaton
    setFirstVal();
  }
  return valid;
}

// Creates a table to store all autonoma data incorporating the first generation
// from a vector
int Table::initTable(vector<bool> importVector, int generations) {
  // Calculates the width of the table required to display all the generations
  arrayWidth = (2 * generations) + importVector.size() - 2;
  // Stores the the height of the table
  arrayHeight = generations;
  //
  int firstGenLength = (int) importVector.size();
  // Creates the array to store the table
  int valid = allocTable();

  if (valid == SUCCESS) {
    int counter = 0;
    int middleIndex = arrayWidth / 2;
    int side = (firstGenLength) / 2;
    for (int col = middleIndex - side; col <= middleIndex + side; col++) {
      if (firstGenLength % 2 == 1 || col != middleIndex + side) {
        setVal(col, 0, importVector.at(counter));
        counter++;
      }
    }
  }

  return valid;
}

// Creates a table to store a line of data during processing
int Table::initLine(int units) {
  // Assigns the tables width and height appropriately
  arrayWidth = units;
  arrayHeight = 1;
  // Creates the array to store the table
  return allocTable();
}

// Returns the value of the appropriate index of the table
bool Table::getVal(int x, int y) {
  if (init == 1) {
    return pTable[y * arrayWidth + x];
  }
  return false;
}

// Returns the neighbourhood of a position in the table as an array in order of
// Left, Centre and Right with the point we are getting the position for
// being the position x, y passed in as parameters
bool* Table::getNeighbourhood(int x, int y) {
  int yPoint = y - 1;
  if (init == 1 && yPoint <= arrayHeight && yPoint >= 0) {
    bool* neighbourhood = new bool[3];
    for (int i = 0; i < 3; i++) {
      int xPoint = properMod(x + i - 1, arrayWidth);
      neighbourhood[i] = getVal(xPoint, yPoint);
    }
    return neighbourhood;
  }
  return nullptr;
}

// Sets the value of the appropriate index of the table
int Table::setVal(int x, int y, bool val) {
  if (init == 0) {
    return TABLE_NOT_INITIALISED;
  }

  if (y > arrayHeight || y < 0) {
    return Y_INDEX_OUT_OF_BOUNDS;
  }

  pTable[y * arrayWidth + x] = val;

  return SUCCESS;
}

// Saves the contents of the table to a file
int Table::saveTable(string filename) {
  if (init == 0) {
    return TABLE_NOT_INITIALISED;
  }

  if (filename.length() == 0) {
    return INVALID_FILENAME;
  }

  // Creates the save file's object for writing
  ofstream saveFile;
  saveFile.open(filename);

  if (!saveFile.is_open()) {
    return FILE_NOT_SAVED;
  }

  saveFile << endl;
  // Counts through each row
  for (int row = 0; row < arrayHeight; row++) {
    // Counts through each column
    for (int col = 0; col < arrayWidth; col++) {
      // Prints the individual value to the screen
      saveFile << getVal(col, row) << " ";
    }
    saveFile << endl;
  }
  saveFile << endl;
  saveFile.close();

  return SUCCESS;
}

int Table::loadTable(string filename) {
  if (filename.length() == 0) {
    return INVALID_FILENAME;
  }

  if (filesystem::exists(filename)) {
    return FILE_NOT_FOUND;
  }

  ifstream loadFile;
  loadFile.open(filename);

  if (!loadFile.is_open()) {
    return FILE_NOT_ACCESSIBLE;
  }

  int numbersInLine = 0;
  string line, temp;
  stringstream lineStream;

  getline(loadFile, line);
  lineStream << line;

  while (!lineStream.eof()) {
    lineStream >> temp;
    if (stringstream(temp)) {
      numbersInLine++;
    }
  }

  int generations = (numbersInLine / 2) + 1;
  initTable(generations);

  int x = 0;
  int y = 0;
  bool tempBool;

  while (getline(loadFile, line)) {
    while (!lineStream.eof()) {
      lineStream >> temp;
      if (stringstream(temp) >> tempBool) {
        setVal(x, y, tempBool);
      }
      y++;
    }
    x++;
  }

  loadFile.close();
  return SUCCESS;
}

// Prints out the values of the table in a basic manner for debugging
int Table::debugTable() {
  if (init == 0) {
    return TABLE_NOT_INITIALISED;
  }

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

  return SUCCESS;
}

int Table::printTable() {
  if (init == 0) {
    return TABLE_NOT_INITIALISED;
  }

  int middleIndex = arrayWidth / 2;
  cout << endl;
  // Counts through each row
  for (int row = 0; row < arrayHeight; row++) {
    int fieldsActive = arrayWidth - 2 * (arrayHeight - 1 - row);
    int side = (fieldsActive) / 2;
    for (int col = 0; col < arrayWidth; col++) {
      if (col >= (middleIndex - side) && col <= (middleIndex + side)) {
        cout << getVal(col, row) << " ";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
  cout << endl;

  return SUCCESS;
}

// x86 has a design flaw where the mod operator doesn't work for negative
// numbers This method addresses that to make it akin to what's found in  other
// higher level languages like Java or Python
int Table::properMod(int a, int b) {
  return (b + (a % b)) % b;
}

bool* Table::getPTable() {
  return pTable;
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
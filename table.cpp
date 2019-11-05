// Imports the header file for this individual source file
#include "table.hpp"
// Imports error codes
#include "error.hpp"
// Used to print to the console
#include <iostream>
// Used to check if a file exists
#include <filesystem>
// Used to save and load files
#include <fstream>
// Used to deal with string streams
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Constructor to set values to defaults
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
  // Copies whether the pointer has been initialised or not
  init = ogTable.getInit();
  // Checks if the table is initialised
  if (init) {
    // Copies the array width and height variables
    arrayWidth = ogTable.getArrayWidth();
    arrayHeight = ogTable.getArrayHeight();
    // Creates and initialises an array of appropriate length to store the table
    allocTable();
  } else {
    // Sets the table variables to their default values
    Table();
  };
  // Performs a deep copy by copying the value of each element of the array from
  // the original table
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
  // Checks if a table is being created using invalid dimensions
  if (arrayHeight < 1 || arrayWidth < 1) {
    return INVALID_TABLE_PARAMETER;
  }
  // Calculates the number of cells in the table
  arraySize = arrayWidth * arrayHeight;
  // Creates a single dynamic array which will stores all cells in
  // and initialises them to false.
  // This increases efficiency over a traditional 2D Array.
  pTable = new bool[arraySize]{false};

  // Checks if the array has been successfully allocated
  if (pTable != nullptr) {
    // Sets the table as initialised
    init = true;
    return SUCCESS;
  }
  return UNEXPECTED_NULL_POINTER;
}

// Sets the first generation as a single true element
void Table::setFirstVal() {
  // Sets the middle position of the first line to true
  pTable[arrayWidth / 2] = true;
}

// Creates a table to store all autonoma data using a number of generations
// This sets the first generation as a single true element
int Table::initTable(int generations) {
  // Calculates the width of the table required to display all the generations
  arrayWidth = (2 * generations) - 1;
  // Stores the the height of the table
  arrayHeight = generations;
  // Creates the array to store the table
  int valid = allocTable();
  // Checks if the array has been sucessfully allocated
  if (valid == SUCCESS) {
    // Sets the starting value of the cellular automaton
    setFirstVal();
  }
  return valid;
}

// Creates a table using fixed axises of x and y
int Table::initTable(int x, int y) {
  // Stores the width of the table
  arrayWidth = x;
  // Stores the height of the table
  arrayHeight = y;
  // Creates the array to store the table
  int valid = allocTable();
  return valid;
}

// Creates a table to store all autonoma data incorporating the first generation
// from a vector
int Table::initTable(vector<bool> importVector, int generations) {
  // Calculates the width of the table required to display all the generations
  arrayWidth = (2 * generations) + importVector.size() - 2;
  // Stores the the height of the table
  arrayHeight = generations;
  // Gets the length of the first generation
  int firstGenLength = (int)importVector.size();
  // Creates the array to store the table
  int valid = allocTable();

  // Checks if the array has been sucessfully allocated
  if (valid == SUCCESS) {
    // Stores the number of elements we have put in the array
    int counter = 0;
    // Stores the middle number in the array
    int middleIndex = arrayWidth / 2;
    // Stores how many elements we need to move from the middle index to the
    // first/last processed element
    int side = (firstGenLength) / 2;
    // Stores the index of the first processed element
    int firstIndex = middleIndex - side;
    // Stores the index of the last processed element
    int lastIndex = middleIndex + side;
    // Checks if the first generation's length is an even number
    if (firstGenLength % 2 == 0) {
      // Prevents a trailing element from being processed on the right
      lastIndex--;
    }

    // Runs through each processed element
    for (int col = firstIndex; col <= lastIndex; col++) {
      // Sets the value
      valid = setVal(col, 0, importVector.at(counter));
      // Checks if we successfully set the value
      if (valid == SUCCESS) {
        // Increments the number of elements stored in the array
        counter++;
      }
      // If this was not successfull
      else {
        // Stops looping
        break;
      }
    }
  }

  return valid;
}

// Creates a table to store a line of data for processing
int Table::initLine(int units) {
  // Assigns the tables width and height appropriately
  arrayWidth = units;
  arrayHeight = 1;
  // Creates the array to store the table
  return allocTable();
}

// Returns the value of the appropriate index of the table
bool Table::getVal(int x, int y) {
  // Checks if the table is initialised and the point is valid
  if (init && x < arrayWidth && y < arrayHeight) {
    // Returns the element
    return pTable[y * arrayWidth + x];
  }
  return false;
}

// Returns the neighbourhood of a position in the table as an array in order of
// Left, Centre and Right with the point we are getting the position for
// being the position x, y passed in as parameters
bool* Table::getNeighbourhood(int x, int y) {
  // Moves to the row we are getting values for the neighbourhood
  int yPoint = y - 1;
  // Checks if the pointer is initialised and checks if the yPoint is valid
  if (init == true && yPoint <= arrayHeight && yPoint >= 0) {
    // Allocates memory for the neighbourhood
    bool* neighbourhood = new bool[3];
    // Runs through each item in the neighbourhood
    for (int i = 0; i < 3; i++) {
      // Calculates the x value we are getting
      int xPoint = properMod(x + i - 1, arrayWidth);
      // Gets the current value
      neighbourhood[i] = getVal(xPoint, yPoint);
    }
    return neighbourhood;
  }
  return nullptr;
}

//
int Table::getNumAround(int x, int y) {
  int counter = 0;
  for (int yPoint = y - 1; yPoint <= y + 1; yPoint++) {
    for (int xPoint = x - 1; xPoint <= x + 1; xPoint++) {
      bool val = getVal(xPoint, yPoint);
      if (val && (xPoint != 0 || yPoint != 0)) {
        counter++;
      }
    }
  }
  return counter;
}

// Sets the value of the appropriate index of the table
int Table::setVal(int x, int y, bool val) {
  // Checks if the array has been inititialised
  if (!init) {
    return TABLE_NOT_INITIALISED;
  }

  // Checks if the y index is valid
  if (y > arrayHeight || y < 0) {
    return Y_INDEX_OUT_OF_BOUNDS;
  }

  // Sets the appropriate value
  pTable[y * arrayWidth + x] = val;
  return SUCCESS;
}

// Saves the contents of the table to a file
int Table::saveTable(string filename) {
  // Checks if the array has been inititialised
  if (!init) {
    return TABLE_NOT_INITIALISED;
  }

  // Checks if the filename is valid
  if (filename.length() == 0) {
    return INVALID_FILENAME;
  }

  // Creates the file's object for writing
  ofstream saveFile;
  // Opens the file
  saveFile.open(filename);

  // Checks if the file is writable
  if (!saveFile.is_open()) {
    return FILE_NOT_SAVED;
  }

  saveFile << endl;
  // Counts through each row
  for (int row = 0; row < arrayHeight; row++) {
    // Counts through each column
    for (int col = 0; col < arrayWidth; col++) {
      // Prints the individual value to the file
      saveFile << getVal(col, row) << " ";
    }
    saveFile << endl;
  }
  saveFile << endl;
  // Saves the file
  saveFile.close();

  return SUCCESS;
}

// Loads the contents of the table from a file
int Table::loadTable(string filename) {
  // Checks if the filename is valid
  if (filename.length() == 0) {
    return INVALID_FILENAME;
  }

  // Checks if the file exists
  if (filesystem::exists(filename)) {
    return FILE_NOT_FOUND;
  }

  // Creates the file's object for writing
  ifstream loadFile;
  // Opens the file
  loadFile.open(filename);

  // Checks if the file is accessible
  if (!loadFile.is_open()) {
    return FILE_NOT_ACCESSIBLE;
  }

  // Stores the number of numbers in the top line
  int numbersInLine = 0;
  //
  bool valid = false;
  // Creates strings to store the top line and a number being processed
  string line, temp;
  // Creates a stream for the top line
  stringstream lineStream;

  // Gets the top line from the file
  getline(loadFile, line);
  // Stores the top line in a stream
  lineStream << line;
  //
  vector<bool> firstGen;

  // Loops through the numbers in the top line
  while (!lineStream.eof()) {
    // Stores the next number as temp
    lineStream >> temp;
    // Checks if temp is a valid number
    if (stringstream(temp)) {
      //
      bool tempBool;
      //
      stringstream(temp) >> tempBool;
      //
      firstGen.push_back(tempBool);
      // Increments the numbers in the top line
      numbersInLine++;
      //
      valid = true;
    }
  }

  if (valid != SUCCESS) {
    return valid;
  }

  // Calculates the number of generations required from the top line
  int generations = (numbersInLine / 2) + 1;
  //
  initTable(firstGen, generations);

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

  // Closes the file
  loadFile.close();
  return SUCCESS;
}

// Prints out the values of the table in a basic manner for debugging
int Table::debugTable() {
  // Checks if the array has been inititialised
  if (!init) {
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

// Prints out the values of the table in a triangle form
int Table::printTable() {
  // Checks if the array has been inititialised
  if (!init) {
    return TABLE_NOT_INITIALISED;
  }

  // Calculates the middle x-cordinate in the array
  int middleIndex = arrayWidth / 2;
  cout << endl;
  // Counts through each row
  for (int row = 0; row < arrayHeight; row++) {
    // Calculates how many fields we are using for processing
    int fieldsActive = arrayWidth - 2 * (arrayHeight - 1 - row);
    // Stores how many elements we need to move from the middle index to the
    // first/last processed element
    int side = (fieldsActive) / 2;
    // Counts through each column
    for (int col = 0; col < arrayWidth; col++) {
      // Checks if the column is within the active fields
      if (col >= (middleIndex - side) && col < (middleIndex + side)) {
        // Prints the element to the screen
        cout << getVal(col, row) << " ";
      }
      // Adds one extra active field if the number of elements we're displaying
      // is odd
      else if (col == (middleIndex + side) && fieldsActive % 2 == 1) {
        // Prints the element to the screen
        cout << getVal(col, row) << " ";
      }
      // Runs if the number is outside the active fields
      else {
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

bool Table::getInit() {
  return init;
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
#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>

// Store values of a table for processing and output
class Table {
 private:
  // Pointer to the 1D array we are using to store the table
  bool* pTable;
  // True if the table pointer has been initialised
  bool init;
  // Stores the width of the array
  int arrayWidth;
  // Stores the height of the array
  int arrayHeight;
  // Stores the size of the array
  int arraySize;

  // Creates and initialises an array of appropriate length to store the table
  int allocTable();
  // Sets the first generation as a single true element
  void setFirstVal();
  // Makes modulo work for negative numbers
  int properMod(int a, int b);

 public:
  // Constructor to set values to defaults
  Table();
  // Copy constructor
  Table(Table& table);
  // Destructor
  ~Table();

  // Creates a table to store all autonoma data using a number of generations
  int initTable(int generations);
  // Creates a table using fixed axises of x and y
  int initTable(int x, int y);
  // Creates a table to store all autonoma data incorporating the first
  // generation from a vector
  int initTable(std::vector<bool> importVector, int generations);
  // Creates a table to store a line of data for processing
  int initLine(int width);

  // Returns the value of the appropriate index of the table
  bool getVal(int x, int y);
  // Returns the neighbourhood of a position in the table as an array in order
  // of Left, Centre and Right with the point we are getting the position for
  // being the position x, y passed in as parameters
  bool* getNeighbourhood(int x, int y);
  // Returns the number of true elements that are around a position
  int getNumAround(int x, int y);
    // Sets the value of the appropriate index of the table
  int setVal(int x, int y, bool val);

  // Saves the contents of the table to a file
  int saveTable(std::string filename);
  // Loads the contents of the table from a file
  int loadTable(std::string filename);

  // Prints out the values of the table in a basic manner for debugging
  int debugTable();
  // Prints out the values of the table in a triangle form
  int printTable();
  // Prints out values of table with an icon for the ant
  int antTable(int x, int y, int Direction);

  // Getters
  bool* getPTable();
  bool getInit();
  int getArrayWidth();
  int getArrayHeight();
  int getArraySize();
};

#endif
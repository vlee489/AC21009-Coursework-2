#include <iostream>
#include "storage.hpp"
using namespace std;

  void Table::setTable() {
    // Counts through each row
    for (int row = 0; row < arrayHeight; row++) {
      for (int col = 0; col < arrayWidth; col++) {
        setVal(row, col, false);
      }
    }
  }

  void Table::setFirstVal(bool firstVal) { 
    int middleFirstLineIndex = arrayWidth / 2; 
    pTable[middleFirstLineIndex] = firstVal;
  }

  void Table::initTable() {
    arraySize = arrayWidth * arrayHeight;
    bool table = new bool[arraySize];
    pTable = &table;
    setTable();
  }

  Table::Table(bool firstVal, int generations) {
    arrayWidth = (2 * generations) - 1;
    arrayHeight = generations;
    initTable();
    setFirstVal(firstVal);
  }

  Table::Table(int width) {
    arrayWidth = width;
    arrayHeight = 1;
    initTable();
  }

  bool Table::getVal(int x, int y) { return pTable[y * arrayWidth + x]; }
  void Table::setVal(int x, int y, bool val) { pTable[y * arrayWidth + x] = val; }

  void Table::debugTable() {
    cout << "\n";
    // Counts through each row
    for (int row = 0; row < arrayHeight; row++) {
      for (int col = 0; col < arrayWidth; col++) {
        cout << getVal(row, col);
      }
      cout << "\n";
    }
  }
#include "storage.hpp"
#include <iostream>
using namespace std;

void Table::setTable() {
  // Counts through each row
  for (int row = 0; row < arrayHeight; row++) {
    for (int col = 0; col < arrayWidth; col++) {
      setVal(col, row, false);
    }
  }
}

void Table::setFirstVal() {
  int middleFirstLineIndex = (arrayWidth / 2) * arrayWidth;
  pTable[middleFirstLineIndex] = true;
}

void Table::allocTable() {
  arraySize = arrayWidth * arrayHeight;
  pTable = new bool[arraySize]{false};
  // setTable();
}

void Table::initTable(int generations) {
  arrayWidth = (2 * generations) - 1;
  arrayHeight = generations;
  allocTable();
  setFirstVal();
}

void Table::initLine(int width) {
  arrayWidth = width;
  arrayHeight = 1;
  allocTable();
}

bool Table::getVal(int x, int y) {
  bool val = pTable[y * arrayWidth + x];
  return val;
}

void Table::setVal(int x, int y, bool val) { pTable[y * arrayWidth + x] = val; }

void Table::debugTable() {
  cout << "\n";
  // Counts through each row
  for (int row = 0; row < arrayHeight; row++) {
    for (int col = 0; col < arrayWidth; col++) {
      cout << getVal(row, col) << " ";
    }
    cout << "\n";
  }
}
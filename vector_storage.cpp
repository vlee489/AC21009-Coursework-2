#include <iostream>
#include <vector>
#include "vector_storage.hpp"

using namespace std;

void Table::allocTable() {
  vector<vector<bool>> table (arrayHeight, vector<bool>(arrayWidth, false));
  tableItr = table.data();
}

void Table::setFirstVal() {
  setVal(arrayWidth/2,1,true);
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

bool Table::getVal(int x, int y) { return tableItr[x][y]; }

void Table::setVal(int x, int y, bool val) { tableItr[x][y] = val; }

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
#include <iostream>
using namespace std;

class Table {
private:
  bool *pTable;
  int arrayWidth;
  int arrayLength;

public:
  void initTable(int firstVal, int generations) {
    int arrayLength = generations;
    int arrayWidth = (2 * generations) + 1;
    bool table[arrayWidth][arrayLength];
    pTable = table;
  }

  void initTable(int arrayWidth) { bool table[arrayWidth][1]; }

  int getVal(int x, int y) { return pTable[y][x]; }

  void debugTable() {
    cout << "";
    // Counts through each row
    for (int row = 0; row < arrayLength; row++) {
      for (int col = 0; col < arrayWidth; col++) {
        cout << getVal(row, col);
      }
    }
  }
};
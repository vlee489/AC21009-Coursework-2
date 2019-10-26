#ifndef TABLE_H
#define TABLE_H
#include <vector>

class Table {
private:
  std::vector<bool, std::allocator<bool>> *tableItr;
  int arrayWidth = 1;
  int arrayHeight = 1;
  int arraySize = 1;
  void setTable();
  void setFirstVal();
  void allocTable();

public:
  void initTable(int generations);
  void initLine(int width);
  bool getVal(int x, int y);
  void setVal(int x, int y, bool val);
  void debugTable();
};

#endif
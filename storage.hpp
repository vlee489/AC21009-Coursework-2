#ifndef TABLE_H
#define TABLE_H

class Table {
 private:
  bool* pTable = nullptr;
  int arrayWidth = 1;
  int arrayHeight = 1;
  int arraySize = 1;
  void allocTable();
  void setFirstVal();
  int properMod(int a, int b);

 public:
  void initTable(int generations);
  void initLine(int width);
  bool getVal(int x, int y);
  bool* getNeighbourhood(int x, int y);
  void setVal(int x, int y, bool val);
  void debugTable();
  int getArrayWidth();
  int getArrayHeight();
  int getArraySize();
};

#endif
#ifndef TABLE_H
#define TABLE_H

class Table {
private:
  bool *pTable;
  int arrayWidth;
  int arrayHeight;
  int arraySize;
  void setTable();
  void setFirstVal(bool firstVal);
  void initTable();

public:
  Table(bool firstVal, int generations);
  Table(int arrayWidth);
  bool getVal(int x, int y);
  void setVal(int x, int y, bool val);
  void debugTable();
};

#endif
#ifndef TABLE_H
#define TABLE_H

class Table {
 private:
  bool* pTable;
  int arrayWidth;
  int arrayHeight;
  int arraySize;
  void allocTable();
  void setFirstVal();
  int properMod(int a, int b);

 public:
  Table();
  Table(bool* pTable, int arrayWidth, int arrayHeight, int arraySize);
  ~Table();
  // Copy Constructor
  Table(Table& table);
  void initTable(int generations);
  void initLine(int width);
  bool getVal(int x, int y);
  bool* getNeighbourhood(int x, int y);
  void setVal(int x, int y, bool val);
  void saveTable();
  void debugTable();
  bool* getPTable();
  int getArrayWidth();
  int getArrayHeight();
  int getArraySize();
};

#endif
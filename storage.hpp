#ifndef TABLE_H
#define TABLE_H
#include <string>

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
  ~Table();
  // Copy Constructor
  Table(Table& table);
  void initTable(int generations);
  void initLine(int width);
  bool getVal(int x, int y);
  bool* getNeighbourhood(int x, int y);
  void setVal(int x, int y, bool val);
  void saveTable(std::string filename);
  void loadTable(std::string filename);
  void debugTable();
  void printTable();
  bool* getPTable();
  int getArrayWidth();
  int getArrayHeight();
  int getArraySize();
};

#endif
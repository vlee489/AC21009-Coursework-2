#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <vector>

class Table {
 private:
  bool* pTable;
  bool init;
  int arrayWidth;
  int arrayHeight;
  int arraySize;

  int allocTable();
  void setFirstVal();

  int properMod(int a, int b);

 public:
  Table();
  Table(Table& table);
  ~Table();

  int initTable(int generations);
  int initTable(std::vector<bool> importVector, int generations);
  int initLine(int width);

  bool getVal(int x, int y);
  bool* getNeighbourhood(int x, int y);
  int setVal(int x, int y, bool val);

  int saveTable(std::string filename);
  int loadTable(std::string filename);

  int debugTable();
  int printTable();

  // Getters
  bool* getPTable();
  int getArrayWidth();
  int getArrayHeight();
  int getArraySize();
};

#endif
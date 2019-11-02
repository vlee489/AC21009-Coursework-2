#include <iostream>
#include <vector>

#include "error.hpp"
#include "firstGen.hpp"
#include "table.hpp"

using namespace std;

const int units = 8;
const int generations = 6;

void initialisation(Table** test);
void neighbourhood(Table* test);
void file(Table* test);
void error(Table** test);
void firstGenTest();

int main() {
  // Table *testP = new Table();
  // initialisation(&testP);
  // neighbourhood(testP);
  // file(testP);
  // delete testP;

  // testP = new Table();
  // error(&testP);
  firstGenTest();

  return 0;
}

template <typename T>
void printArray(T array, int length) {
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  cout << endl;
}

void displayTableVal(Table* test) {
  cout << endl;
  cout << "arrayWidth: " << test->getArrayWidth() << endl;
  cout << "arrayHeight: " << test->getArrayHeight() << endl;
  cout << "arraySize: " << test->getArraySize() << endl;
}

void initialisation(Table** test) {
  cout << "Single Line Table Initialisation Test for " << units
       << " units:" << endl;
  cout << "Pass Conditions: all values 0; table is " << units
       << " across and 1 line high" << endl;
  (*test)->initLine(units);
  (*test)->debugTable();

  cout << "Generation Table Initialisation Test for " << generations
       << " generations:" << endl;
  cout << "Pass Conditions: all values 0 apart from middle element in first "
          "row; table is "
       << generations << " across and enough generations high" << endl;
  (*test)->initTable(generations);
  (*test)->debugTable();
}

void neighbourhood(Table* test) {
  int arrayWidth = test->getArrayWidth();
  bool* neighbourhood = test->getNeighbourhood(arrayWidth / 2, 1);

  cout << "First Element Neighbourhood Test using " << generations
       << " generations:" << endl;
  cout << "Pass Conditions: 0 1 0 " << endl;
  printArray<bool*>(neighbourhood, 3);

  cout << "Left Side Element Neighbourhood Test for " << generations
       << " generations:" << endl;
  cout << "Pass Conditions: 1 1 0 " << endl;
  test->setVal(0, 0, true);
  test->setVal(arrayWidth - 1, 0, true);
  displayTableVal(test);
  test->debugTable();
  neighbourhood = test->getNeighbourhood(0, 1);
  printArray<bool*>(neighbourhood, 3);

  cout << "Right Side Element Neighbourhood Test for " << generations
       << " generations:" << endl;
  cout << "Pass Conditions: 0 1 1 " << endl;
  neighbourhood = test->getNeighbourhood(arrayWidth - 1, 1);
  printArray<bool*>(neighbourhood, 3);
}

void file(Table* test) {
  cout << "Save File Test" << endl;
  cout << "Pass Conditions: Look at the file if it matches this it's passed"
       << endl;
  string loc = "files/out.txt";
  test->saveTable(loc);
  test->debugTable();

  cout << "Load File Test" << endl;
  cout << "Pass Conditions: The table matches the table above" << endl;
  test->loadTable(loc);
  test->debugTable();
}

void error(Table** test) {
  cout << "Print Uninitialised Table Test: ";
  if ((*test)->printTable() == TABLE_NOT_INITIALISED) {
    cout << "Test passed";
  }
  cout << "Test failed";
  cout << endl;
}

void firstGenTest() {
  vector<bool> firstGen;
  firstGenerator(&firstGen);
}

#include <iostream>
#include <vector>

#include "error.hpp"
#include "generation.hpp"
#include "inputOutput.hpp"
#include "table.hpp"

using namespace std;

const int units = 8;
const int generations = 3;

void initialisation(Table** test);
void neighbourhood(Table* test);
void file(Table* test);
void error(Table** test);
vector<bool>* firstGenTest();
void customFileTest();
void numAround(Table* test);
void printTest(Table* test);

int main() {
  Table* testP = new Table();
  initialisation(&testP);
  neighbourhood(testP);
  file(testP);
  delete testP;

  testP = new Table();
  error(&testP);
  firstGenTest();

  customFileTest();
  numAround(testP);
  printTest(testP);
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
  string loc = "files/out.txt";

  // cout << "Save File Test" << endl;
  // cout << "Pass Conditions: Look at the file if it matches this it's passed"
  //      << endl;
  // test->saveTable(loc);
  // test->debugTable();

  cout << "Load File Test" << endl;
  cout << "Pass Conditions: The table matches the table above" << endl;
  test->loadTable(loc);
  test->debugTable();
}

void error(Table** test) {
  cout << "Print Uninitialised Table Test: ";
  if ((*test)->printTable() == TABLE_NOT_INITIALISED) {
    cout << "Passed";
  } else {
    cout << "Failed";
  }
  cout << endl << endl;
}

vector<bool>* firstGenTest() {
  cout << "First Generation Test" << endl;
  cout << "Pass Conditions: Printed Vector is custom generation or middle "
          "element in first row is true"
       << endl
       << endl;
  Generation* generationObj = new Generation();
  generationObj->firstGenerator();
  vector<bool>* firstGen = generationObj->returnGen();
  printVector(firstGen);
  cout << endl;
  return firstGen;
}

void customFileTest() {
  // vector<bool>* firstGen = firstGenTest();
  Table* test = new Table();
  // test->initTable(*firstGen, generations);
  string loc = "files/out.txt";

  cout << "Save File Test" << endl;
  cout << "Pass Conditions: Look at the file if it matches this it's passed"
       << endl;
  test->saveTable(loc);
  test->debugTable();

  cout << "Load File Test" << endl;
  cout << "Pass Conditions: The table matches the table above" << endl;
  test->loadTable(loc);
  test->debugTable();
}

void numAround(Table* test) {
  int x = 2;
  int y = 1;
  // vector<bool>* firstGen = firstGenTest();
  // test->initTable(*firstGen, 3);
  test->initTable(3);
  test->setVal(1, 1, true);
  test->setVal(2, 2, true);
  test->setVal(3, 1, true);
  test->setVal(2, 1, true);

  test->setVal(1, 0, true);
  test->setVal(1, 2, true);
  test->setVal(3, 0, true);
  test->setVal(3, 2, true);
  // test->setVal(2, 0, false);

  cout << "Number Around Test" << endl;
  cout << "Pass Conditions: Numbers Around (2,1): 8" << endl;
  test->debugTable();
  int numAround = test->getNumAround(x, y);
  cout << "Numbers Around (" << x << "," << y << "): " << numAround << endl;
}

void printTest(Table* test) {
  cout << "Print Test" << endl;
  cout << "Pass Conditions: Both Table Methods have similar output" << endl;
  test->debugTable();
  test->printTable();
}
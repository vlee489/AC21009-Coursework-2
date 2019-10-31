#include <iostream>

#include "storage.hpp"
using namespace std;

const int units = 8;
const int generations = 6;

void initialisation(Table** test);
void neighbourhood(Table* test);

int main() {
  Table* test;
  initialisation(&test);
  neighbourhood(test);
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
//   cout << "Single Line Table Initialisation Test for " << units
//        << " units:" << endl;
//   cout << "Pass Conditions: all values 0; table is " << units
//        << " across and 1 line high" << endl;
//   (*test)->initLine(units);
//   (*test)->debugTable();

//   cout << "Generation Table Initialisation Test for " << generations
//        << " generations:" << endl;
//   cout << "Pass Conditions: all values 0; table is " << generations
//        << " across and enough generations high" << endl;
  (*test)->initTable(generations);
//   (*test)->debugTable();
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
  displayTableVal(test);
  test->debugTable();
  neighbourhood = test->getNeighbourhood(1, 1);
  printArray<bool*>(neighbourhood, 3);

  cout << "Right Side Element Neighbourhood Test for " << generations
       << " generations:" << endl;
  cout << "Pass Conditions: 0 1 1 " << endl;
  test->setVal(arrayWidth - 1, 0, true);
  test->debugTable();
  neighbourhood = test->getNeighbourhood(arrayWidth, 1);
  printArray<bool*>(neighbourhood, 3);
}
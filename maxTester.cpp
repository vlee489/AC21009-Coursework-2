#include "storage.hpp"
using namespace std;

void initialisation(Table **test);

int main() {
  Table *test;
  initialisation(&test);
  return 0;
}

void initialisation(Table **test) { 
    *test = new Table(1);
    (*test)->debugTable();
}
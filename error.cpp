#include <iostream>
#include "error.hpp"

using namespace std;

void checkValidity(int valid) {
  switch (valid) {
    case SUCCESS:
      break;
    case INVALID_TABLE_PARAMETER:
      cout << "Error: " << endl;
      break;
    case RULE_NUM_OUT_RANGE:
      cout << "Error: " << endl;
      break;
    case DECIMAL_VAL_OUT_OF_RANGE:
      cout << "Error: " << endl;
      break;
    case TABLE_NOT_INITIALISED:
      cout << "Error: Function has been called using an uninitialised table"
           << endl;
      break;
    case Y_INDEX_OUT_OF_BOUNDS:
      cout << "Error: A value is attempting to be set using a Y co-ordinate "
              "that is out of the bounds of the table"
           << endl;
      break;
    case UNEXPECTED_NULL_POINTER:
      cout << "Error: Function has been called using a null pointer" << endl;
      break;
    default:
      cout << "Error: Invalid Error Code" << endl;
      break;
  }
}
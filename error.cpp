// Used to print to the console
#include <iostream>
// Imports error codes
#include "error.hpp"

using namespace std;

// Displays an error message to the user based on the apppropriate error code
// imported
void checkValidity(int valid) {
  switch (valid) {
    case SUCCESS:
      break;

    case UNEXPECTED_NULL_POINTER:
      cout << "Error: Function has been called using a null pointer" << endl;
      break;

    case TABLE_NOT_INITIALISED:
      cout << "Error: Function in a Table object has been called using an "
              "uninitialised table"
           << endl;
      break;
    case INVALID_TABLE_PARAMETER:
      cout << "Error: A table was attempted to have been created using invalid "
              "dimensions"
           << endl;
      break;
    case X_INDEX_OUT_OF_BOUNDS:
      cout << "Error: A value is attempting to be set using a X co-ordinate "
              "that is out of the bounds of the table"
           << endl;
      break;
    case Y_INDEX_OUT_OF_BOUNDS:
      cout << "Error: A value is attempting to be set using a Y co-ordinate "
              "that is out of the bounds of the table"
           << endl;
      break;

    case INVALID_FILE:
      cout << "Error: A file has attempted to be imported that is invalid"
           << endl;
      break;
    case INVALID_FILENAME:
      cout << "Error: The filename passed as a parameter is invalid while "
              "attempting to save or load a file"
           << endl;
      break;
    case FILE_NOT_ACCESSIBLE:
      cout << "Error: A file has attempted to be imported that is not "
              "accessible, this could be an invalid filename or there may be "
              "insufficient permissions for access"
           << endl;
      break;
    case FILE_NOT_FOUND:
      cout << "Error: A file has attempted to be imported that doesn't exixt"
           << endl;
      break;
    case FILE_NOT_SAVED:
      cout << "Error: A file cannot be saved in the location provided, this "
              "could be an invalid filename or there may be insufficient "
              "permissions for access"
           << endl;
      break;

    case RULE_NUM_OUT_RANGE:
      cout << "Error: A rule has attempted to be set in a Rule object outside "
              "of the range of an 8-bit unsigned interger (0 to 255)"
           << endl;
      break;
    case DECIMAL_VAL_OUT_OF_RANGE:
      cout << "Error: A decimal number has attempted to be converted into "
              "binary values, that is outside of the range of an 8-bit "
              "unsigned interger (0 to 255)"
           << endl;
      break;

    default:
      cout << "Error: Error Code is invalid or has not been fully implemented"
           << endl;
      cout << "Error Code Imported: " << valid << endl;
      break;
  }

  // Quits if an error code has occured
  if (valid != SUCCESS) {
    exit(0);
  }
}
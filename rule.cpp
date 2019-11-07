#include "rule.hpp" 
#include "error.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

/**
 * Converts an array of booleans, into Decimal
 * @param binary[] the binary representation
 * @param bits the number of bits 
 * @return returns the decimal conversion
 */
int Rule::toDecimal(bool binary[], int bits) {
  // checks if the array is NULL
  if (binary == NULL) {
    return UNEXPECTED_NULL_POINTER;
  }
  // initialises decimal to 0
  int decimal = 0;

  // calculates the decimal value from binary
  for (int i = bits - 1; i >= 0; i--) {
    if (binary[i] == true) {
      decimal += pow(2, bits - 1 - i);
    }
  }

  // returns decimal
  return decimal;
}

/**
 * Sets the Ruleset for the Cellular Automaton
 * @param ruleNum takes in an inputted rule to set
 * @return returns the validity of the rule
 */
int Rule::setRule(int ruleNum) {
  // validates the ruleNum (8-bit)
  if (ruleNum < 0 || ruleNum > 255) {
    return RULE_NUM_OUT_RANGE;
  }
  // initialises the instance's chosen rule
  this->ruleNum = ruleNum;

  // converts rule num into it's binary representation
  int valid = toBinary(ruleSet, ruleNum);

  return valid;
}

/**
 * Generates the value of a Cell in the Table
 * @param neighbourhood[] the values of the current Cell's neighbourhood
 * @return returns true of false for the generated Cell
 */
bool Rule::generateCell(bool neighbourhood[]) {
  // converts the neighbourhood to decimal for the ruleset
  int index = toDecimal(neighbourhood, 3);

  // makes sure that the neighbourhood was valid
  if (index == UNEXPECTED_NULL_POINTER) {
    return false;
  }

  // returns the value of the ruleset at the specified index
  return ruleSet[7-index];
}

/**
 * Converts a decimal into it's binary representation
 * @param binary[] a pointer to the Ruleset
 * @param decimal the number to be converted
 * @return returns the validity of the conversion
 */
int Rule::toBinary(bool binary[], int decimal) {
  // checks if ruleset is NULL
  if (binary == NULL) {
    return UNEXPECTED_NULL_POINTER;
  }

  // makes sure that the decimal is in range
  if (decimal < 0 || decimal > 255) {
    return DECIMAL_VAL_OUT_OF_RANGE;
  }
  // calculates the binary representation of the decimal
  for (int i = 0; decimal > 0; i++) {
    binary[i] = decimal % 2;
    decimal = decimal/2;
  }

  // Reverses the order
  swap(binary, 8);

  return SUCCESS;
}

/**
 * Reverses order of the binary representation
 * @param arr[] the binary representation
 * @param n the number of bits 
 */
void Rule::swap(bool arr[], int n) {
  reverse(arr, arr + n);
}
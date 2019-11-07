
#include "rule.hpp"

#include <cmath>
#include <iostream>

#include "error.hpp"

using namespace std;

int Rule::toDecimal(bool binary[]) {
  if (binary == NULL) {
    return UNEXPECTED_NULL_POINTER;
  }
  int decimal = 0;
  for (int i = 7; i >= 0; i--) {
    if (binary[i] == true) {
      decimal += pow(2, i);
    }
  }
  return decimal;
}

int Rule::setRule(int ruleNum) {
  if (ruleNum < 0 || ruleNum > 255) {
    return RULE_NUM_OUT_RANGE;
  }
  this->ruleNum = ruleNum;

  int valid = toBinary(ruleSet, ruleNum);

  return valid;
}

bool Rule::generateCell(bool neighbourhood[]) {
  int index = toDecimal(neighbourhood);
  if (index == UNEXPECTED_NULL_POINTER) {
    return false;
  }
  return ruleSet[index];
}

int Rule::toBinary(bool binary[], int decimal) {
  if (binary == NULL) {
    return UNEXPECTED_NULL_POINTER;
  }
  if (decimal < 0 || decimal > 255) {
    return DECIMAL_VAL_OUT_OF_RANGE;
  }

  for (int i = 0; decimal > 0; i++) {
    binary[i] = decimal % 2;
    decimal = decimal/2;
  }


  return SUCCESS;
}
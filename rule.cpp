
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

  int binaryComp[8];

  int index = 0;
  for (int i = 7; i >= 0; i--) {
    binary[i] = 0;
    if (index == 7) {
      binaryComp[index] = 0;
    } else {
      binaryComp[index] = pow(2, i);
    }
    index++;
  }
  printf("binComp\n");
  for (int i = 0; i < 8; i++) {
    printf("%d  ", binaryComp[i]);
  }
  printf("binComp\n");

  for (int i = 0; i < 8; i++) {
    if (decimal >= binaryComp[i]) {
      if (decimal == 0) {
        binary[i] = 0;
      } else {
        binary[i] = 1;
      }
      decimal = decimal - binaryComp[i];
    } else {
      binary[i] = 0;
    }
  }
  return SUCCESS;
}

void Rule::printRule() {
  for (int i = 0; i < 8; i++) {
    printf("%d  ", this->ruleSet[i]);
  }
}

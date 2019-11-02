
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
  // bool temp[8] = {0};
  int valid = toBinary(ruleSet, ruleNum);
  // int index = 0;
  // for (int i = 7; i >= 0; i--) {
  //   ruleSet[index] = temp[i];
  //   printf("%d  ", ruleSet[index]);
  // }
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
  int testingDecimal = decimal;
  int binaryComp[8];
  binaryComp[0] = 0;

  printf("binComp");
  for (int i = 0; i < 8; i++) {
    binary[i] = 0;
    binaryComp[i] = pow(2, i);
    printf("%d   \n", binaryComp[i]);
  }
  printf("END\n");

  printf("Rule %d: ", testingDecimal);
  for (int i = 7; i >= 0; i--) {
    if (decimal >= binaryComp[i]) {
      decimal = decimal - binaryComp[i];
      binary[i] = 1;
    } else {
      binary[i] = 0;
    }
  }

  printf("END\n\n");
  return SUCCESS;
}

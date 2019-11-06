#ifndef RULE_H
#define RULE_H

class Rule {
 private:
  int ruleNum;
  bool ruleSet[8];

 public:
  int toBinary(bool binary[], int decimal);
  int toDecimal(bool binary[]);
  int setRule(int ruleNum);
  bool generateCell(bool neighbourhood[]);
  void printRule();
};

#endif
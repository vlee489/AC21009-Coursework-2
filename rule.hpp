#ifndef RULE_H
#define RULE_H

class Rule {
 private:
  int ruleNum;
  int ruleSet[8];

 public:
  void toBinary(int binary[], int decimal);
  int toDecimal(bool binary[]);
  void setRule(int ruleNum);
  bool generateCell(bool neighbourhood[]);
};

#endif
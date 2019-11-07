#ifndef RULE_H
#define RULE_H

// Rule class will be used to store and calculate the Rule used in the Cellular Automaton
class Rule {
 private:
  // the chosen Rule
  int ruleNum;
  // the binary representation of the Rule
  bool ruleSet[8];

 public:
  // Utility function to convert decimal to Binary
  int toBinary(bool binary[], int decimal);
  // Utility function to convert Binary to decimal
  int toDecimal(bool binary[], int bits);
  // Sets the rule of the Automaton using the Rule
  int setRule(int ruleNum);
  // Calculates the value of the next Cell
  bool generateCell(bool neighbourhood[]);
  // Utility function to reverse the order of the binary representation
  void swap(bool arr[], int n);
};

#endif
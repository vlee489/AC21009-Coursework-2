#ifndef RULE_H
#define RULE_H

class Rule {
  public:
        void toBinary(int binary[], int decimal);
        int toDecimal(bool binary[]);
        // Ruleset = Binary version of the rules desired
        // ruleNum = rule but in int form
        void setRule(int ruleset[], int ruleNum);
        bool generateCell(int ruleset[], bool neighbourhood[]);
};


#endif
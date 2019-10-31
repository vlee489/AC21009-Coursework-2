#ifndef RULE_H
#define RULE_H

class Rule {
  public:
        void toBinary(int binary[], int decimal);
        int toDecimal(bool binary[]);
        void setRule(int ruleset[], int ruleNum);
        bool generateCell(int ruleset[], bool neighbourhood[]);
        bool ruleset[8]{0,0,0,0,0,0,0,0};
};


#endif
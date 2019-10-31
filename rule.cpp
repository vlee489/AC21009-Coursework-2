#include "rule.hpp"
#include <cmath>
using namespace std;

int Rule::toDecimal(bool binary[])
        {
            int decimal = 0;
            for (int i = 7; i >= 0; i--)
            {
                if (binary[i] == true)
                {
                    decimal += pow(2, i);
                }
            }
            return decimal;
        }

void Rule::setRule(int ruleset[], int ruleNum)
        {
            toBinary(ruleset, ruleNum);
        }

bool Rule::generateCell(int ruleset[], bool neighbourhood[])
        {
            int index = toDecimal(neighbourhood);
            return ruleset[index];
        }

void Rule::toBinary(int binary[], int decimal)
        {
            int binaryComp[8];
            binaryComp[0] = 1;

            for (int i = 1; i < 8; i++)
            {
                binary[i] = 0;
                binaryComp[i] = pow(2, i);
            }

            for (int i = 7; i >= 0; i--)
            {
                if (decimal >= binaryComp[i])
                {
                    decimal = decimal - binaryComp[i];
                    binary[i] = 1;
                }
                else
                {
                    binary[i] = 0;
                }
            }
        }


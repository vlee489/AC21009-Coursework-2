#include <cmath>
#include <iostream>
using namespace std;

void toBinary(int binary[], int decimal)
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

    for (int i = 7; i >= 0; i--)
    {
        cout << binary[i];
    }
    cout << "" << endl;
}

int toDecimal(bool binary[])
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

void setRule(int ruleset[], int ruleNum)
{
    toBinary(ruleset, ruleNum);
}

bool generateCell(int ruleset[], bool neighbourhood[])
{
    int index = toDecimal(neighbourhood);
    return ruleset[index];
}

int main()
{
    int ruleset[8];
    setRule(ruleset, 84);
    bool neighbourhood[3] = {1, 0, 0};
    cout << generateCell(ruleset, neighbourhood) << endl;
    return 0;
}

#include <cmath>
#include <iostream>
using namespace std;

void toBinary(int decimal)
{
    bool binary[8];
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

int main()
{
    toBinary(157);
    return 0;
}

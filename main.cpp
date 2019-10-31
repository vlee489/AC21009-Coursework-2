#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() { return 0; }

int userNumberInput(int min, int max, string message){
    int UserInput;
    bool valid = false;
    while (true){
        cout << message + ":";
        cin >> UserInput;
        if (UserInput < max && UserInput > min){
            cout << "/n"
            return UserInput;
        } else {
            cout << "\nInvalid input\n"
            cout << "Please enter a whole number between" + min + " and " + max + "\n"
        }
    }
}



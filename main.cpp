#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() { return 0; }

int userNumberInput(int min, int max, string message){
    int UserInput;
    bool valid = false;
    while (valid == false){
        cout << message + ":";
        cin >> UserInput;
        if (UserInput < max && UserInput > min){
            cout << "/n"
            valid = true;
            return UserInput;
        } else {
            cout << "\nInvalid input\n"
            cout << "Please enter a whole number between" + min + " and " + max + "\n"
        }
    }
}

int runProgram(){
    int rule = userNumberInput(0, 256, "Please enter the desired rule you want to use");
    int generations = userNumberInput(0, 101, "Please enter the desired generations you want");

}



#include <iostream>
#include <sstream>
#include <string>

#include "CalculatorController.h"
#include "CalculatorView.h"

using namespace std;

int main() {
    CalculatorController calc;
    string input;

    CalculatorView::showWelcome();

    while (true) {
        cout << "> ";
        getline(cin, input);

        istringstream iss(input);
        string command;
        double value;

        iss >> command;

        if (command == "exit") {
            break;
        }
        else if (command == "add" && iss >> value) {
            calc.Add(value);
        }
        else if (command == "subtract" && iss >> value) {
            calc.Subtract(value);
        }
        else if (command == "multiply" && iss >> value) {
            calc.Multiply(value);
        }
        else if (command == "divide" && iss >> value) {
            calc.Divide(value);
        }
        else if (command == "result") {
            CalculatorView::displayResult(calc.Result());
        }
        else if (command == "reset") {
            calc.Reset();
        }
        else {
            CalculatorView::showInvalidCommand();
        }
    }

    return 0;
}


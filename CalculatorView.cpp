#include "CalculatorView.h"
#include <iostream>

using namespace std;

void CalculatorView::displayResult(double result) {
    cout << "Result: " << result << endl;
}

void CalculatorView::showWelcome() {
    cout << "Simple CLI Calculator (type 'exit' to quit)\n";
    cout << "Commands: add x, subtract x, multiply x, divide x, result, reset\n";
}

void CalculatorView::showInvalidCommand() {
    cout << "Invalid command. Try again.\n";
}


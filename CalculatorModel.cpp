#include "CalculatorModel.h"
#include <iostream>

using namespace std;

CalculatorModel::CalculatorModel() : result(0) {}

void CalculatorModel::add(double value) {
    result += value;
}

void CalculatorModel::subtract(double value) {
    result -= value;
}

void CalculatorModel::multiply(double value) {
    result *= value;
}

void CalculatorModel::divide(double value) {
    if (value != 0)
        result /= value;
    else
        cout << "Error: Division by zero!" << endl;
}

void CalculatorModel::reset() {
    result = 0;
}

double CalculatorModel::getResult() const {
    return result;
}

#pragma once
#include "CalculatorModel.h"

class CalculatorController {
private:
    CalculatorModel model;
public:
    CalculatorController& Add(double value);
    CalculatorController& Subtract(double value);
    CalculatorController& Multiply(double value);
    CalculatorController& Divide(double value);
    CalculatorController& Reset();
    double Result() const;
};

#include "CalculatorController.h"

CalculatorController& CalculatorController::Add(double value) {
    model.add(value);
    return *this;
}

CalculatorController& CalculatorController::Subtract(double value) {
    model.subtract(value);
    return *this;
}

CalculatorController& CalculatorController::Multiply(double value) {
    model.multiply(value);
    return *this;
}

CalculatorController& CalculatorController::Divide(double value) {
    model.divide(value);
    return *this;
}

CalculatorController& CalculatorController::Reset() {
    model.reset();
    return *this;
}

double CalculatorController::Result() const {
    return model.getResult();
}

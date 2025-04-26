#pragma once

class CalculatorModel {
private:
    double result;
public:
    CalculatorModel();
    void add(double value);
    void subtract(double value);
    void multiply(double value);
    void divide(double value);
    void reset();
    double getResult() const;
};

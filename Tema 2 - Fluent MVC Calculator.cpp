#include <iostream>
using namespace std;

class CalculatorModel {
private:
    double result;
public:
    CalculatorModel() : result(0) {}

    void add(double value) { result += value; }
    void subtract(double value) { result -= value; }
    void multiply(double value) { result *= value; }
    void divide(double value) {
        if (value != 0) result /= value;
        else cout << "Error: Division by zero!" << endl;
    }

    void reset() { result = 0; }
    double getResult() const { return result; }
};

class CalculatorController {
private:
    CalculatorModel model;
public:
    CalculatorController& Add(double value) {
        model.add(value);
        return *this;
    }

    CalculatorController& Subtract(double value) {
        model.subtract(value);
        return *this;
    }

    CalculatorController& Multiply(double value) {
        model.multiply(value);
        return *this;
    }

    CalculatorController& Divide(double value) {
        model.divide(value);
        return *this;
    }

    CalculatorController& Reset() {
        model.reset();
        return *this;
    }

    double Result() const {
        return model.getResult();
    }
};

class CalculatorView {
public:
    static void displayResult(double result) {
        cout << "Result: " << result << endl;
    }
};

int main() {
    CalculatorController calc;

    //Dummy operations, no user input yet. Will add that later on
    calc.Add(10).Multiply(3).Subtract(5).Divide(2);
    CalculatorView::displayResult(calc.Result());

    calc.Reset().Add(100).Divide(4);
    CalculatorView::displayResult(calc.Result());

    return 0;
}

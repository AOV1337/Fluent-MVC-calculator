#include <iostream>
#include <sstream>
#include <string>

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

    static void showWelcome() {
        cout << "Simple CLI Calculator (type 'exit' to quit)\n";
        cout << "Commands: add x, subtract x, multiply x, divide x, result, reset\n";
    }

    static void showInvalidCommand() {
        cout << "Invalid command. Try again.\n";
    }
};

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

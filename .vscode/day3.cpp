#include <iostream>

int main() {
    double num1, num2;
    char operation;

    // Input two numbers and an operator
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Perform the chosen operation
    switch (operation) {
        case '+':
            std::cout << "Result: " << (num1 + num2) << std::endl;
            break;
        case '-':
            std::cout << "Result: " << (num1 - num2) << std::endl;
            break;
        case '*':
            std::cout << "Result: " << (num1 * num2) << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Result: " << (num1 / num2) << std::endl;
            } else {
                std::cout << "Error: Division by zero is undefined." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
    }

    return 0;
}
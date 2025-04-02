#include <iostream>

int main() {
    double num1, num2;

    // Input two numbers
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Perform operations
    std::cout << "Addition: " << (num1 + num2) << std::endl;
    std::cout << "Subtraction: " << (num1 - num2) << std::endl;
    std::cout << "Multiplication: " << (num1 * num2) << std::endl;

    // Handle division by zero
    if (num2 != 0) {
        std::cout << "Division: " << (num1 / num2) << std::endl;
    } else {
        std::cout << "Division: Undefined (cannot divide by zero)" << std::endl;
    }

    return 0;
}
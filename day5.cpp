#include <iostream>
#include <string>

int main() {
    std::string str, reversedStr;

    // Input the string
    std::cout << "Enter a string: ";
    std::cin >> str;

    // Reverse the string
    reversedStr = std::string(str.rbegin(), str.rend());

    // Check if the string is a palindrome
    if (str == reversedStr) {
        std::cout << str << " is a palindrome." << std::endl;
    } else {
        std::cout << str << " is not a palindrome." << std::endl;
    }

    return 0;
}
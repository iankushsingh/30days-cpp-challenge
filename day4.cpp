#include <iostream>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    // Input the number of terms
    std::cout << "Enter the number of terms: ";
    std::cin >> n;

    std::cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        std::cout << t1 << " ";
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}
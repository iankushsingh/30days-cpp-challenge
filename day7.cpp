#include <iostream>
#define MAX 1000 // Maximum size of the stack

class Stack {
    int top;
    int arr[MAX]; // Array to store stack elements

public:
    Stack() { top = -1; } // Constructor to initialize the stack

    // Push an element onto the stack
    bool push(int x) {
        if (top >= (MAX - 1)) {
            std::cout << "Stack Overflow" << std::endl;
            return false;
        } else {
            arr[++top] = x;
            std::cout << x << " pushed into stack" << std::endl;
            return true;
        }
    }

    // Pop an element from the stack
    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow" << std::endl;
            return 0;
        } else {
            int x = arr[top--];
            return x;
        }
    }

    // Peek the top element of the stack
    int peek() {
        if (top < 0) {
            std::cout << "Stack is Empty" << std::endl;
            return 0;
        } else {
            return arr[top];
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << stack.pop() << " popped from stack" << std::endl;

    std::cout << "Top element is: " << stack.peek() << std::endl;

    std::cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << std::endl;

    return 0;
}
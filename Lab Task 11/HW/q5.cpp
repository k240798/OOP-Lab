#include <iostream>
#include <vector>
#include <exception>

class StackUnderflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow: Attempted to pop or access top from an empty stack.";
    }
};

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& value) {
        elements.push_back(value);
    }

    void pop() {
        if (elements.empty()) {
            throw StackUnderflowException();
        }
        elements.pop_back();
    }

    T top() const {
        if (elements.empty()) {
            throw StackUnderflowException();
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    Stack<int> s;

    try {
        std::cout << "Pushing elements: 10, 20, 30\n";
        s.push(10);
        s.push(20);
        s.push(30);

        std::cout << "Top element: " << s.top() << std::endl;

        std::cout << "Popping top element.\n";
        s.pop();
        std::cout << "Top element after pop: " << s.top() << std::endl;

        std::cout << "Popping all elements.\n";
        s.pop();
        s.pop();

        std::cout << "Attempting to pop from empty stack...\n";
        s.pop(); 

    } catch (const StackUnderflowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

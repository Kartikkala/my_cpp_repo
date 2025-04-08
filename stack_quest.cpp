#include <iostream>
#include <stack>

void sortStack(std::stack<int> &original) {
    std::stack<int> sortedStack;

    while (!original.empty()) {
        int temp = original.top();
        original.pop();

        // Move elements from sortedStack back to original if they are greater than temp
        std::cout << "While sorted stack is not empty and temp < sortedStack's top element: "<<std::endl;
        std::cout << "\n";
        while (!sortedStack.empty() && sortedStack.top() > temp) {
            std::cout << "Pushing sorted stack's top element to original: ";
            original.push(sortedStack.top());
            sortedStack.pop();
        }

        sortedStack.push(temp);
    }

    // Transfer back to the original stack (optional)
    while (!sortedStack.empty()) {
        original.push(sortedStack.top());
        sortedStack.pop();
    }
}

void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);
    s.push(5);

    std::cout << "Original Stack: ";
    printStack(s);

    sortStack(s);

    std::cout << "Sorted Stack: ";
    printStack(s);

    return 0;
}

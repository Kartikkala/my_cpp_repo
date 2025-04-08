#include <iostream>
#include <stack>

void sortStack(std::stack<int> &originalStack)
{
    std::stack<int> sorted;

    while(!originalStack.empty())
    {
        int temp = originalStack.top();
        originalStack.pop();
        while(!sorted.empty() && sorted.top() > temp)
        {
            originalStack.push(sorted.top());
            sorted.pop();
        }
        sorted.push(temp);
    }
    while(!sorted.empty())
    {
        std::cout << sorted.top() << std::endl;
        sorted.pop();
    }
}

int main(void)
{
    std::stack<int> original;
    original.push(5);
    original.push(2);
    original.push(6);
    original.push(3);
    original.push(1);

    // 2 5 3 1 6
    sortStack(original);
}
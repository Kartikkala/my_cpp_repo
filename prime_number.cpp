#include <iostream>

bool isPrime(int number)
{
    int half_of_number = number / 2;

    for(int i=2;i<=half_of_number ; i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    std::cout << isPrime(120390123);
}
#include <iostream>

void calculate_range(int a, int b)
{
    int temp = 0;
    
    if(a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    int *(*matrix) = (int **)malloc(sizeof(int) * b-a);
    for(int i=a;i<=b;i++)
    {
        matrix[i - a] = (int*)malloc(sizeof(int) *10);
        for(int j = 1;j<=10 ; j++)
        {
            matrix[i - a][j-1] = i*j;
            std::cout << matrix[i - a][j - 1] << " ";
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    int a = 0;
    int b = 0;
    std::cout << "Enter first value for range (a): ";
    std::cin >> a;
    std::cout << "Enter second value for range (b): ";
    std::cin >> b;
    calculate_range(a, b);
}
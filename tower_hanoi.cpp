#include <iostream>

int hanoi(int n, char source, char target, char auxilary)
{
    static int moves = 0;
    moves++;
    if(n == 1)
    {
        std::cout << "Move disk 1 from " << source << " to " << target <<std::endl;
        return 1;
    }

    hanoi(n - 1, source, auxilary, target);
    
    std::cout << "Move disk "<< n << " from " << source << " to " << target << std::endl;
    
    hanoi(n - 1, auxilary, target, source);

    return moves;
}

int main(void)
{
    int moves = hanoi(3, 'A', 'C', 'B');
    std :: cout << "\nTotal moves taken: " << moves;
}
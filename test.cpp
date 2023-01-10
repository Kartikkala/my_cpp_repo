#include <iostream>
#include <vector>
using namespace std;

void func()
{
    vector<vector<int>> hashTable(10, vector<int> (2, __INT_MAX__));
    hashTable[8][0] = 10;
    std::cout<<hashTable[8][1];
}

int main(void)
{
    // vector<vector<int>> hashTable(10, vector<int> (2, __INT_MAX__));
    // hashTable[8][0] = 10;
    // std::cout<<hashTable[8][1];

    func();
}
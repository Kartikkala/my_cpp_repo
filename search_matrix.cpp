#include <iostream>
#include <vector>
using std::vector;
using std::cout;


bool search(vector<vector<int>> matrix, int key)
{
    int rows = matrix.size();
    int columns = matrix[0].size();

    int start = 0;
    int end = (rows*columns)-1;

    int mid = (start+end)/2;


    while(start<=end)
    {
        std::cout<<mid;
        if(matrix[mid/columns][mid%columns] == key)
        {
            return true;
        }
        else if(matrix[mid/columns][mid%columns]<key)
        {
            start = mid+1;
        }
        else
        {
            end = mid;
        }
        mid = (start+end)/2;
    }
    return false;
}

int main(void)
{
    vector<vector<int>> matrix {{1,2,3}};

    std::cout<<search(matrix,50);
}
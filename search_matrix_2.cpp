#include <iostream>
#include <vector>

using std::vector;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    int row = matrix.size();
    int column = matrix[0].size();
    int total = row*column;
    int i=0;
    int j=column-1;
    
    while(i<row && j>=0)
    {
        if(matrix[i][j] == target)
        {
            return true;
        }
        else if(matrix[i][j]<target)
        {
            i++;
        }
        else if(matrix[i][j]>target)
        {
            j--;
        }
    }
        
    return false;    
}


int main(void)
{
    vector<vector<int>> matrix{{1,1}};

    std::cout<<searchMatrix(matrix,2);
}
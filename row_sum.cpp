#include <iostream>
#include <vector>

using std::vector;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    std::cout<<matrix.size();
    return {0,1};
}


int largest_row_sum(vector<int> &sum_arr)
{
    if(sum_arr.size()==0)
    {
        return -1;
    }
    int row_number=0;
    int largest_sum = sum_arr[0];
    for(int i=0;i<sum_arr.size();i++)
    {
        if(sum_arr[i]>largest_sum)
        {   row_number = i;
            largest_sum = sum_arr[i];
        }
    }
    return row_number;
}

vector<int> row_sum(int arr[][3], int column, int row)
{
    vector<int> sum_arr;
    for(int i=0;i<row;i++)
    {
        int sum=0;
        for(int j=0;j<column;j++)
        {
            sum = sum+arr[i][j];    
        }
        sum_arr.push_back(sum);
    }
    return sum_arr;
}


int main(void)
{
    int matrix[][3] = {{1,2,3},
                       {4,5,6},
                       {7,8,9},
                       {3,2,4}};
    int row = *(&matrix+1)-matrix;
   
    vector<int> sumarr = row_sum(matrix, 3, row);
    std::cout<<largest_row_sum(sumarr)<<"\n";

    for(int i=0;i<row;i++)
    {
        std::cout<<sumarr[i]<<',';
    }
    vector<vector<int>> matrixx {{1,2,3},
                       {4,5,6},
                       {7,8,9},
                       {3,2,4}};

    spiralOrder(matrixx);
}
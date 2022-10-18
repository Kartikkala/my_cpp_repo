#include <iostream>
#include <vector>

using std::vector;
using std::cout;

vector<int> viewSpiral(vector<vector<int>> matrix)
{
    int columns = matrix[0].size();
    int rows = matrix.size();
    int flag=1;
    int times = (rows*columns);

    vector<int> output;
    int j = 0;
    int k=0;
    int m=0;
    int n=1;


    for(int i=0;i<times;)
    {
        if(flag == 1)
        {
            while(j<columns)
            {
                output.push_back(matrix[k][j]);
                j++;
                i++;
            }
            j--;
            flag = 2;
            columns--;
        }
        else if(flag == 2)
        {
            while(k<rows-1)
            {
                k++;
                output.push_back(matrix[k][j]);
                i++;
            }
            flag = 3;
            rows--;
        }
        else if(flag == 3)
        {
            while(j>m)
            {
                j--;
                output.push_back(matrix[k][j]);
                i++;
            }
            flag =4;
            m++;
        }
        else if(flag == 4)
        {
            while(k>n)
            {
                k--;
                output.push_back(matrix[k][j]);
                i++;
            }
            j++;
            flag = 1;
            n++;
        }
    }
    return output;
}

int main(void)
{
    vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> answer = viewSpiral(matrix);
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<"\n";
    }
}
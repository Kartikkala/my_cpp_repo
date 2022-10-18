#include <iostream>
#include <vector>

using std::vector;
using std::cout;

void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

void rotate(vector<vector<int>>& matrix)
{
    int size = matrix.size();
    int i = 0;
    int j = 0;
    int k = 0;
    int l = size-1;
    int m = size-1;
    int n = size-1;
    int o = size-1;
    int p = 0;
    
    int temp = 0;
    int temp2 = 0;
    int waste =((l-i)+(k-j));



    for(int it1 =0;it1<size;it1++)
    {
        for(int it2 = 0;it2<waste;it2++)
        {
            // printf("i,j %d,%d  k,l %d,%d   m,n  %d,%d    o, p %d,%d \n",i,j,k,l,m,n,o,p);

            temp = matrix[k][l];
            matrix[k][l] = matrix[i][j];
            temp2 = matrix[m][n];
            matrix[m][n] = temp;
            temp = matrix[o][p];
            matrix[o][p] = temp2;
            matrix[i][j] = temp;

            j++;
            k++;
            n--;
            o--;

        }

        // cout<<"\n";

        swap(i,o);
        swap(j,p);

        swap(o,k);
        swap(p,l);

        swap(o,m);
        swap(p,n);
        size-=1;

        o--;
        p++;
        i++;
        j++;
        k++;
        l--;
        m--;
        n--;

        waste =((l-i)+(k-j));
    }
}

void printMatrix(vector<vector<int>> &matrix)
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix.size();j++)
        {
            cout<<matrix[i][j]<<"  ";
        }
        cout<<"\n";
    }
}

int main(void)
{
    vector<vector<int>> matrix = {{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36}};
    rotate(matrix);
    printMatrix(matrix);

}
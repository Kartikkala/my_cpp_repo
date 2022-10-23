#include <iostream>
using namespace std;

int find_max_ranged(int *arr, int i, int n)
    {
        int j = 0;
        int k = arr[i];
        int max = arr[i];
        if(i+arr[i]>=n)
        {
            return (n-i);
        }
        for(j = i;j<=(i+arr[i]) && j<n;j++)
        {
            if(arr[j]>max)
            {
                max = arr[j];
                k = j;
            }
        }
        std::cout<<k<<"\n";
        return k;
    }
  
    int minJumps(int arr[], int n){
        
        int jumps = 0;
        
        for(int i=0;i<n;)
        {
            if(arr[i] == 1)
            {
                i++;
            }
            else if(arr[i] == 0)
            {
                return -1;
            }
            else
            {
                i = (i+find_max_ranged(arr, i, n));
            }
            jumps++;
            std::cout<<i<<"\n";
        }
        return jumps;
    }

    int main(void)
    {
        int arr[] = { 1,7,6,5,4,1,2,3,4,1,10};

        cout<<minJumps(arr, 11);
    }
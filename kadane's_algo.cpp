#include <bits/stdc++.h>



long long maxSubarraySum(int arr[], int n){

    /*Algorithm
        1.We have to take atleast one number, thus we took 0th element in sum.
        2.Now we have to take a temp sum variable, which will store the current sum.
        3.Now we will keep adding all the elements to temp sum and max_sum will be max of temp_sum and max_sum.
        4.If temp_sum<0 (negative), we will make temp sum 0.
        5.Continue this process till we traverse the whole array
    */
        
    long long sum = arr[0];
    long long temp_sum = 0;

    for(int i=0;i<n;i++)
    {
        temp_sum+=arr[i];
        sum = std::max(temp_sum, sum);
        if(temp_sum<0)
        {
            temp_sum = 0;
        }
    }

    return sum;
        
}

int main(void)
{

}
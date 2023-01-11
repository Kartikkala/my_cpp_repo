#include <iostream>
#include <unordered_set>

using std::unordered_set;
using std::cin;
using std::cout;


class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists_bruteforce(int arr[], int n)
    {

        // Suffix Sum - No array (Because 0-n addition, 1- n addition, 2 - n addition, ----- , n left )
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum = arr[i];
            for(int j=i+1;j<n;j++)
            {
                if(sum == 0)
                    return true;

                // if(j<n)
                sum += arr[j];           
            }
        }
        return false;
    }

    bool subArrayExists_optimised(int arr[], int n)
    {
        // Expalnation
        // For this problem, we are gonna use a prefix sum set. 
        /*                           
                                      PrefSum2 <----|
                _________________________|_____     |
                |                              |    |
                [a1, a2, a3, a4, a5, a6, a7, a8]    |
                |_________| + |_____| = PrefSum2----|
                  PrefSum1     Sum


                Such that, prefSum1 = a1+a2+a3 and prefSum2 = a6+a7+a8.

                1. Now assume that PrefSum1 = PrefSum2.
                2. Let--->>>    sum = a4+a5
                3. Now if PrefSum1 = PrefSum2, that means, PrefSum1 + Sum = PrefSum2    Where    Sum = 0.

        */


       //Implementation

        unordered_set<int> prefix_sum_set;
        int pref_sum=0;

        for(int i=0;i<n;i++)
        {
            pref_sum+=arr[i];
            if(pref_sum == 0)
                return true;
            
            if(prefix_sum_set.find(pref_sum) !=prefix_sum_set.end())
            {
                return true;
            }
            else
            {
                prefix_sum_set.insert(pref_sum);
            }

        }

        return false;
    }
};

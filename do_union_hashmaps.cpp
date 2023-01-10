#include <iostream>
#include <unordered_set>
#include <vector>

using std::unordered_set;

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> set;

        for(int i=0;i<n;i++)
        {
            // if(set.find(a[i])==set.end())        //Unordered set m elements repeated ni hote
                set.insert(a[i]);
        }
        for(int i=0;i<m;i++)
        {
            // if(set.find(b[i]) == set.end())
                set.insert(b[i]);
        }

        return set.size();
    }
};
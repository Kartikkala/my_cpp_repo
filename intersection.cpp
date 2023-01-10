#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection_kartik(int a[], int b[], int n, int m) {
        int size=0;
        unordered_map<int, int> map;
        
        for(int i=0;i<n;i++)
        {
            if(map.find(a[i])==map.end())
            {
                map[a[i]] = 0;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(map.find(b[i])==map.end())
                map[b[i]] = 3;
            else if(map.find(b[i])!=map.end())
            if(map[b[i]] == 0)
                map[b[i]]++;
        }
        

        for(auto i = map.begin();i!=map.end();i++)
        {
            if(i->second == 1)
                size++;
        }
        
        return size;

    }
    int NumberofElementsInIntersection_ideal(int a[], int b[], int n, int m) {
        int count=0;
        unordered_set<int> set;
        
        for(int i=0;i<n;i++)
        {
            set.insert(a[i]);
        }
        for(int i=0;i<m;i++)
        {
            if(set.find(b[i])!=set.end())               //Ham B ke elements daal hi nahi rahe hain, e.g. if b has 4,4,4,4 and a has 1,2,4, then 4 will be removed from set, and no more 4s will be inserted
            {
                count++;
                set.erase(b[i]);
            }
        }
        return count;

    }
};
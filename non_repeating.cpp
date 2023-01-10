#include <iostream>
#include <unordered_map>
#include <climits>

using std::unordered_map;

class Solution
{
    private:
        unordered_map<int, int> map;

    public:
        int firstNonRepeating(int arr[], int n) 
        { 
            for(int i=0;i<n;i++)
            {
                if(map.find(arr[i]) == map.end())
                    map[arr[i]] = 0;
                else
                    map[arr[i]]++;   
            }

            for(int i=0;i<n;i++)
            {
                if(map[arr[i]] == 0)
                    return arr[i];
            }
            return INT_MAX;
        } 
};

int main(void)
{
    Solution sol;

    int arr[] = {-1 ,-17 ,-12, 8 ,16 ,-17 ,-13 ,-14 ,-3 ,-6 ,-5 ,-11 ,-10 ,-12 ,-5 ,19 ,-17 ,-5 ,-1 ,12};
    int size = *(&arr+1)-arr;
    // std::cout<<"Size: "<<size<<"\n";

    std::cout<<sol.firstNonRepeating(arr, size);

}
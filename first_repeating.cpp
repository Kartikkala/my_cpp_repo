#include <iostream>
#include <unordered_map>
#include <climits>

using std::unordered_map;

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        unordered_map<int, int> map;
        for(int i=0;i<n;i++)
        {
            map[arr[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(map[arr[i]]>1)
                return i+1;
        }
        return -1;
    }
};

int main(void)
{
    Solution sol;

    int arr[] = {1 ,5 ,3 ,4 ,3 ,5 ,6};
    int size = *(&arr+1)-arr;

    std::cout<<sol.firstRepeated(arr, size);
}
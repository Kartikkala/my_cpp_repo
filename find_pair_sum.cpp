#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::pair;

pair<int,int> pair_sum(vector<int> &arr, int sum)
{
    pair<int, int> indices;
    indices.first =-1;
    indices.second = -1; 
    int first = 0;
    int last = arr.size()-1;

    while(first<last)
    {
        if(arr[first]+arr[last] == sum)
        {
            indices.first = first;
            indices.second = last;
            return indices;
        }
        else if(arr[first]+arr[last]> sum)
        {
            last--;
        }
        else
        {
            first++;
        }
    }

    return indices;


}

int main(void)
{
    vector<int> arr {-6,-5,-4,-3,-2,-1,1,1,2,5,6,8,9};
    pair<int,int> indices = pair_sum(arr,11);
    cout<<indices.first<<"\n";
    cout<<indices.second;
}
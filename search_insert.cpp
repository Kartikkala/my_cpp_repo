#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int searchInsert(vector<int>& nums, int target) 
{
    int left = 0;
    int right = nums.size()-1;
    int mid = (left+right)/2;

    while(left<right)
    {
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid]>target)
        {
            right = mid;
        }
        else
        {
            left = mid+1;
        }
        mid = (left+right)/2;
    }

    if(target>nums[mid])
    {
        return left+1;
    }
    else
    {
        return right;
    }
}

int main(void)
{
    vector<int> nums {1,2,4,6,8,11};
    cout<<searchInsert(nums, 3);
}
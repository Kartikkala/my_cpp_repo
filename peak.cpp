#include <iostream>
#include <vector>

using namespace std;

bool isPeak(int index, vector<int>& nums)
{
    if(index == 0)
    {
        if(nums[index] > nums[index+1])
            return true;
        else
            return false;
    }
    else if(index == nums.size()-1)
    {
        if(nums[index] > nums[index-1])
            return true;
        else
            return false;
    }
    else if(nums[index] > nums[index-1] && nums[index] > nums[index+1])
    {
        return true;
    }
    return false;
}

int findPeakElement(vector<int>& nums) {
    for(int i=0;i<nums.size();i++)
    {
        if(isPeak(i, nums))
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    vector<int> nums = {1,2,1,3,5,6,4};
    std::cout << findPeakElement(nums);
}
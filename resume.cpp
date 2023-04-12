#include <iostream>
#include <vector>

using std::vector;

int max(std::vector<int> &arr)
{
    int max = INT32_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

void reverse(std::vector<int> &arr)
{

    for(int start=0, end=arr.size()-1 ; start<=end; start++,end--)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
    return;
}

std::pair<int,int> search2D(std::vector<std::vector<int>> &arr, int key)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            if(arr[i][j] ==key)
                return {i, j};
        }
    }
    return {-1, -1};
}   

bool is_even_number_of_digits(int num)
{   
    int number_of_digits = 0;
    while(num!=0)
    {
        num/=10;
        number_of_digits++;
    }
    if(number_of_digits%2==0)
        return true;
    
    return false;
}

int findNumbers(std::vector<int>& nums) {
    int result = 0;

    for(int i=0;i<nums.size();i++)
    {
        if(is_even_number_of_digits(nums[i]))
            result++;
    }
    return result;
}

int maximumWealth(std::vector<std::vector<int>>& accounts) {
    int sum=0;
    int maxWealth = INT32_MIN;
    for(int i=0;i<accounts.size();i++)
    {
        for(int j=0;j<accounts[i].size();j++)
        {
            sum+=accounts[i][j];
            if(sum>maxWealth)
                maxWealth = sum;
        }
        sum=0;
    }
    return maxWealth;
}

vector<int> buildArray(vector<int>& nums) {
    vector<int> newArray;
    for(int i=0;i<nums.size();i++)
    {
        newArray.push_back(nums[nums[i]]);
    }

    return newArray;
}

vector<int> getConcatenation(vector<int>& nums) {
    int size = nums.size();
    for(int i=0;i<size;i++)
    {
        nums.push_back(nums[i]);
    }
    return nums;
}

int main(void)
{

    std::vector<int> array1 = {1,2,3,4,5,6};
    std::vector<std::vector<int>> array2 = {{1,2,1}, {10,9,8}, {23,5,1}};

    
}
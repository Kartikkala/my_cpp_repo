#include <iostream>
#include <vector>

using std::vector;

void swap(vector<int> &arr, int left, int right)
{
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void move_oneside(vector<int> &arr)
{
    int left =0;
    int right = arr.size()-1;

    while(left<right)
    {
        if(arr[left]<0)
        {
            left++;
        }
        if(arr[right]>=0)
        {
            right--;
        }
        if(arr[left]>0 && arr[right]<0)
        {
            swap(arr, left, right);
            left++;
            right--;
        }
    }
}

int main(void)
{
    vector<int> arr {1,2,-1,5,2,-2,0,-8,-9,2,-10};
    move_oneside(arr);
    for(int i=0;i<arr.size();i++)
    {
        std::cout<<arr[i]<<"\n";
    }

}
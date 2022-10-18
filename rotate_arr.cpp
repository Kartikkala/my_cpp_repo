#include <iostream>
#include <vector>

int mod(int num)
{
    if(num<0)
    {
        return -num;
    }
    else
    {
        return num;
    }
}

std::vector<int> rotate_arr(std::vector<int> &arr, int k)
{
    std::vector<int> new_arr(arr.size());
    int index_to_rotate = mod(arr.size()-k);
    int j=0;

    for(int i=index_to_rotate;j<arr.size();i++,j++)
    {
        if(i == arr.size())
        {
            i=0;
        }
        new_arr[j] = arr[i];
    }
    return new_arr;
}

int main(void)
{
    std::vector<int> arr{9,11,1,7};
    std::vector<int> rotated_arr (rotate_arr(arr,5));
    int i=0;
    while(i<arr.size())
    {
        std::cout<<rotated_arr[i]<<"\n";
        i++;
    }
}
#include <iostream>
#include <vector>

int find_pivot(std::vector<int> &arr)
{
    int i=0;
    while(arr[i]>arr[i-1])
    {
        if(i == arr.size())
        {
            break;
        }
        i++;
    }
    return i;
}

void make_original(std::vector<int> &arr)
{
    int pivot_index = find_pivot(arr);
    std::vector<int> new_arr(arr.size());
    if(pivot_index!=arr.size())
    {
        int j=0;
        for(int i=pivot_index;j<arr.size();i++,j++)
        {
            if(i==arr.size())
            {
                i=0;
            }
            new_arr[j] = arr[i];
        }
        arr = new_arr;
    }
}

bool check(std::vector<int> &arr) 
{
    make_original(arr);

    for(int i=0;i<arr.size();i++)
    {
        std::cout<<"Arr ele: "<<arr[i]<<"\n";
    }
    for(int i=0;i<arr.size();i++)
    {
        if(i==0)
        {
            continue;
        }
        else if(arr[i]>arr[i-1])
        {
            return true;
        }
        else
        {
            break;
        }
    }
    return false;
}

int main(void)
{
    std::vector<int> arr{3,4,5,1,2};
    std::cout<<check(arr);
}


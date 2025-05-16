#include <iostream>
#include <vector>

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    for(int j=low ; j < high;j++)
    {   
        if(arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1],arr[high]);
    return i+1;
}

void quick_sort(std::vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);
        quick_sort(arr, 0, p-1);
        quick_sort(arr, p+1, high);
    }
}

int main(void)
{
    std::vector<int> arr({3, 4, 2, 2, 1});
    quick_sort(arr, 0, arr.size()-1);

    for(int val: arr)
        std::cout << val << " ";
}
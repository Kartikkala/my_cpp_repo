#include <iostream>
#include <vector>
#include <string>

void swap(std::vector<char> &arr, int i, int j)
{
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

std::vector<char> reverse_string(std::vector<char> &arr)
{
    int i=0;
    int j=arr.size()-1;
    std::vector<char> temp(arr);
    while(i<j)
    {
        swap(temp, i, j);
        i++;
        j--;
    }
    return temp;
}



bool check_pali(std::vector<char> &arr)
{
    return (arr == reverse_string(arr));
}



int main(void)
{
    std::string arr{'b','a','b','\0','o','\0'};
    int i=0;
    std::cout<<arr;
}
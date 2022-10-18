#include <iostream>
#include <string>
#include <algorithm>

using std::string;

bool comp_arr(int *arr1, int *arr2, int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr1[i]!=arr2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) 
{

    if(s1.size()>s2.size())
    {
        return false;
    }
    int arr1[26] {0};
    int arr2[26] {0};

    for(int i=0;i<s1.size();i++)
    {
        arr1[s1[i] - 'a']++;
    }

    for(int i=0;i<s1.size();i++)
    {
        arr2[s2[i]-'a']++;
    }

    if(comp_arr(arr1, arr2,26))
    {
        return true;
    }



    for(int i=s1.size();i<s2.size();i++)
    {
        arr2[s2[i]-'a']++;
        arr2[s2[i-s1.size()]-'a']--;
        if(comp_arr(arr1,arr2,26))
        {
            return true;
        }
    }


    return false;


}

int main(void)
{
    string s1, s2;
    s1 = "gc";
    s2 = "fgccfg";
    std::cout<<checkInclusion(s1,s2);
}
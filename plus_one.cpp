#include <iostream>
#include <vector>

using std::vector;
using std::cout;

vector<int> plusOne(vector<int>& digits) 
{
    vector<int> res;
    int size = digits.size();
    // int balance=1;

    for(int i= size-1;i>=0;i--)
    {
        if(digits[i] == 9)
        {
            if(i>0)
            {
                digits[i] = 0;
            }
            else if(i == 0)
            {
                digits[i] = 0;
                res.push_back(1);
                for(int j=0;j<size;j++)
                {
                    res.push_back(digits[j]);
                }
                break;
            }
        }
        else
        {
            digits[i] +=1;
            return digits;
        }
    }  
    return res;  
}

int main(void)
{
    vector<int> digits  {9,9};
    vector<int> hii = plusOne(digits);
    for(int i= 0;i<hii.size();i++)
    {
        std::cout<<hii[i]<<"\n";
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool check(std::string s1, char temp[])
{
    for(int i=0;i<s1.length();i++)
    {
        std::cout<<temp[i];
        if(s1[i] != temp[i])
        {
            return false;
        }
    }
    std::cout<<"\n";
    return true;
}

bool compare(std::string s1, std::string s2)
{
    std::sort(s1.begin(),s1.end());
    if(s1.size()>s2.size())
    {
        return false;
    }
    char temp_s2[3];
    for(int i=0;i<s2.length()-s1.length();i++)
    {
        s2.copy(temp_s2,s1.length(),i);
        std::sort(temp_s2,temp_s2+s1.length());

        if(check(s1,temp_s2))
        {
            return true;
        }
    }
    return false;
}


int main(void)
{
    std::string s1 = "dca";
    std::string s2 = "dcda";
    std::cout<<compare(s1,s2);
}
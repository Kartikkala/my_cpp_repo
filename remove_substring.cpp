#include <iostream>
#include <string>

bool check(std::string s, std::string part, int i)
{
    for(int j=0;j<part.length();j++,i++)
    {
        if(part[j]!=s[i])
        {
            return false;
        }
    }
    return true;
}

void copy_rem(int i,std::string &s,std::string &new_string)
{
    while(i<s.length())
    {
        new_string.push_back(s[i]);
        i++;
    }
    s = new_string;
    new_string.clear();
}

std::string remove_substring(std::string s, std::string part)
{
    std::string new_string;
            
    for(int i=0;i<s.length();i++)
    {
        int ind = s.find(part);
        if(ind !=std::string::npos)
        {
            s.erase(ind,part.length());
            i=-1;
        }
    }
    return s;
}


int main(void)
{
    std::string s = "aabababa";
    std::string part = "aba";
    std::cout<<remove_substring(s,part);
}
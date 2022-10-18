#include <iostream>
#include <string>
#include <string.h>

void replace_spaces(std::string &str)
{
    std::string new_str;
    for(int i=0;i<str.length();i++)
    {
        if((int)str[i] == 32)
        {
            new_str.push_back('@');
            new_str.push_back('4');
            new_str.push_back('0');
            continue;
        }
        new_str.push_back(str[i]);
    }
    str.clear();
    for(int i=0;i<new_str.length();i++)
    {
        str.push_back(new_str[i]);
    }
    return;
}

int main(void)
{
    std::string str = "hii my name is kartik";
    replace_spaces(str);
    std::cout<<str; 
}
#include <iostream>

using std::string;

string removeDuplicates(string s) {
    string s2;
        
        for(int i=0,j=0;i<s.length();i++,j++)
        {
            s2.push_back(s[i]);
            if(j>0)
            {
                if(s2[j] == s2[j-1])
                {
                    s2.erase(j-1,2);
                    j=j-2;
                }
            }
        }

    return s2;
}

int main(void)
{
    string s = "aaaamaaaaam";
    std::cout<<removeDuplicates(s);
}
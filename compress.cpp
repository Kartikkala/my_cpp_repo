#include <iostream>
#include <vector>
#include <string>


//Implement without using additinoal space



using std::string;
using std::vector;

void reverse(vector<char> &s)
{
    vector<char> rev;
    for(int i=s.size()-1;i>=0;i--)
    {
        rev.push_back(s[i]);
    }
    s = rev;
}

int compress(vector<char>& chars) {

   if(chars.size()<=1)
        {
            return chars.size();
        }
        
        string stringhehe;
        vector<char> s; 
        int count =0;

    for(int i=0;i<chars.size();i++)
    {
        if(chars[i] != chars[i+1])
        {
            continue;
        }
        else
        {
            if(i+1>=chars.size())
            {

                break;
            }
            count =0;
            int j;
            for(j=i;j<chars.size();j++)
            {
                if(chars[i]!=chars[j])
                {
                    break;
                }
                count++;
            }
            i++;

            
            
            stringhehe = std::to_string(count);
            int sub_iterate = i;


            for(int m = 0;m<stringhehe.size();m++,sub_iterate++)
            {
                chars[sub_iterate] = stringhehe[m]; 
            }
            stringhehe.clear();
            chars.erase(chars.begin()+sub_iterate, chars.begin()+(j));


            i=sub_iterate-1;
        }

    }

    return chars.size();
        
}


int main(void)
{
    vector<char> chars {'o','o','d','d','b','b','b','w','o','m'};
    compress(chars);
    for(int i=0;i<chars.size();i++)
    {
        std::cout<<chars[i]<<",";
    }
}
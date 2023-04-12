#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>

using std::vector;
using std::string;
using std::unordered_map;
using std::to_string;


class Solution{
  public:

  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {   
        unordered_map<string, int> vote_map;
        int max_votes = INT_MIN;
        for(int i=0;i<n;i++)
        {
            vote_map[arr[i]]++;  
            if(vote_map[arr[i]]>max_votes)
                max_votes = vote_map[arr[i]];  
        }
        vector<string> max_vote_candidates(1);
        for(auto i=vote_map.begin();i!=vote_map.end();i++)
        {
            if(i->second==max_votes && max_vote_candidates.size() ==0)
                max_vote_candidates[0] = i->first;
            else if(i->second == max_votes &&  i->first < max_vote_candidates[0])
                max_vote_candidates[0] = i->first;
        }
        return max_vote_candidates;
    }
};

int main()
{
    Solution sol;
    string arr[] = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john" ,"johnny", "jamie" ,"johnny" ,"john"};
    int size = *(&arr+1)-arr;
    sol.winner(arr,size );
}
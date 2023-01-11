#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::unordered_map;


//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {

        unordered_map<int, int> map;

        for(int i=0;i<n;i++)
        {
            map.insert(std::make_pair(arr[i], i));
        }
        for(int i=0;i<n;i++)
        {
            int complement = x-arr[i];

            if(map.find(complement) != map.end() && map.find(complement)->second !=i)
            {
                return true;
            }
        }
        return false;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
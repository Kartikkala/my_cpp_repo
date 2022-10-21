#include <bits/stdc++.h>

using namespace std;

int min(int a, int b)
  {
      if(a<b)
      {
          return a;
      }
      return b;
  }
  int max(int a, int b)
  {
      if(a>b)
        {return a;}
        
    return b;
  }
  
    int getMinDiff(int arr[], int n, int k) {
        
        sort(arr, arr+n);
        
        int ans = arr[n-1]-arr[0];      //Current Max diff
        int mina;
        int maxa;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]-k<0)
                continue;
            
            mina = min(arr[0]+k, arr[i] - k);       //Subtracting k from whole array, except 0, and comparing it with the min element possible i.e. arr[0]+k (arr[0]+k cuz we need to find an element smaller than this by subtracting which is non negative)
            maxa = max(arr[n-1]-k, arr[i-1]+k);     //Adding k to whole array and finding max with the expected max, i.e. (arr[n-1]-k, finding a max other than this cuz we need the max, (bigger element that this in any scenario))            
            ans = min(ans, maxa-mina);              //Calculating the ans, min between the current ans and current min
        }
        
        return ans;
      
}

int main(void)
{
    int arr[] = {2 ,6 ,3 ,4 ,7 ,2 ,10 ,3 ,2 ,1};
    cout<<getMinDiff(arr, 10, 5);
}
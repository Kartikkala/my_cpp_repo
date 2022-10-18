#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;


int doUnion(int a[], int n, int b[], int m)  {
       vector<int> UnionArr;
       vector<int> NewArr;

    UnionArr.insert(UnionArr.begin(), a,a+n);
    UnionArr.insert(UnionArr.begin()+n, b,b+m);

    std::sort(UnionArr.begin(),UnionArr.end());

 

    NewArr.push_back(UnionArr[0]);
    for(int i=1;i<UnionArr.size();i++)
    {
        if(UnionArr[i] == UnionArr[i-1])
        {
           continue;
        }
        NewArr.push_back(UnionArr[i-1]);
    }
    
    return NewArr.size();
    }


int main(void)
{
    int arr[] {3,5,0,1,4,4};
    int arr2[] {1,5,4,2,4};
    std::cout<<doUnion(arr,6,arr2,5);
    
}
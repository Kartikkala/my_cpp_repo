#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int max(std::vector<int> &arr)
{
    int max = INT32_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

void reverse(std::vector<int> &arr)
{

    for(int start=0, end=arr.size()-1 ; start<=end; start++,end--)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
    return;
}

std::pair<int,int> search2D(std::vector<std::vector<int>> &arr, int key)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            if(arr[i][j] ==key)
                return {i, j};
        }
    }
    return {-1, -1};
}   

bool is_even_number_of_digits(int num)
{   
    int number_of_digits = 0;
    while(num!=0)
    {
        num/=10;
        number_of_digits++;
    }
    if(number_of_digits%2==0)
        return true;
    
    return false;
}

int findNumbers(std::vector<int>& nums) {
    int result = 0;

    for(int i=0;i<nums.size();i++)
    {
        if(is_even_number_of_digits(nums[i]))
            result++;
    }
    return result;
}

int maximumWealth(std::vector<std::vector<int>>& accounts) {
    int sum=0;
    int maxWealth = INT32_MIN;
    for(int i=0;i<accounts.size();i++)
    {
        for(int j=0;j<accounts[i].size();j++)
        {
            sum+=accounts[i][j];
            if(sum>maxWealth)
                maxWealth = sum;
        }
        sum=0;
    }
    return maxWealth;
}

vector<int> buildArray(vector<int>& nums) {
    vector<int> newArray;
    for(int i=0;i<nums.size();i++)
    {
        newArray.push_back(nums[nums[i]]);
    }

    return newArray;
}

vector<int> getConcatenation(vector<int>& nums) {
    int size = nums.size();
    for(int i=0;i<size;i++)
    {
        nums.push_back(nums[i]);
    }
    return nums;
}

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> result(2*n);

   for(int i=0, j=n, k=0;i<n;i++, j++, k++)
   {
    result[k] = nums[i];
    k++;
    result[k] = nums[j];
   } 
   return result;
}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
    vector<bool> result(candies.size());
    int maxi = INT32_MIN;
    for(int i=0;i<candies.size();i++)
    {
        maxi = std::max(maxi, candies[i]);
    }   

    for(int i=0;i<candies.size();i++)
    {
        result[i] = (candies[i]+extraCandies)>=maxi;
    }
    return result;
}

int numIdenticalPairs(vector<int>& nums) {
    int goodPairs = 0;

    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i] == nums[j])
                goodPairs++;
        }
    }

    return goodPairs;
}

vector<int> smallerNumbersThanCurrent1(vector<int>& nums) {
    vector<int> result(nums.size());

    for(int i=0;i<nums.size();i++)
    {
        result[i] = 0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]<nums[i])
            {
                result[i]++;
            }
        }
    }
    return result;
}
vector<int> smallerNumbersThanCurrent2(vector<int>& nums) {
    vector<int> mapi(101, 0);
    vector<int> result(nums.size(), 0);

    for(int i=0;i<nums.size();i++)
    {
        mapi[nums[i]]++;
    }
    for(int i=0;i<nums.size();i++)
    {
        for(int j=nums[i]-1; j>=0;j--)
        {
            result[i]+=mapi[j];
        }
    }

    return result;
}
 vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> mapi(101, 0);
    vector<int> result(nums.size(), 0);

    for(int i=0;i<nums.size();i++)
    {
        mapi[nums[i]]++;
    }

    //Calculating Cumulative Frequency (How many numbers are smaller that mapi[nums[i]])
    // Set sum to 0
    int sum = 0;
    for(int i=0;i<mapi.size();i++)
    {
        // Started from 0 ( no number is smaller than 0 )
        sum += mapi[i];
        // How many numbers are smaller than a number "i" in mapi[i] will be stored in mapi[i-1].
        // Like suppose this is nums array => [1,3,0,0,1,2]. Let's take example of 0
        // Here, two 0s are present. Now mapi[0] is initially 2, which is okay as two 0s are present
        // Now map[0] became 2 and sum became 2, okay?
        mapi[i] = sum;

        // Now, after this we moved to 1. In the example, two 1s are present. Hence mapi[1] = 2
        // Now what we did is sum+ = mapi[i], means sum is 4 now. There are four numbers which are less than 2, okay?
        // Similarly, this mapi table will become a cumulative frequency table, and we can easily get how many numbers
        // are less than j = num[i] by just checking mapi[j - 1] (cuz how many numbers are smaller than j, are present)
        // (in 1 index less than j in mapi) comeon, man, it's common sense, can't you see it? Yeah?
    }
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
            result[i]=0;
        else
            result[i] = mapi[nums[i]-1];
    }

    return result;
}

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> target1(index.size(), -1);
    vector<int> target2(index.size(), -1);

    for(int i=0;i<nums.size();i++)
    {
        if(target1[index[i]] == -1)
            target1[index[i]] = nums[i];
        else
            {
                for(int j=0, k=0;j<target1.size();j++)
                {
                    if(j == index[i])
                        target2[j] = nums[i];
                    else
                    {
                        target2[j] = target1[k];
                        k++;
                    }
                }
                target1 = target2;
            }
    }
    return target1;
}


bool checkIfPangram(string sentence) {
    vector<int> result(27, 0);
    for(int i=0;i<sentence.length();i++)
    {
        result[(int)sentence[i]-60]++;
    }
    for(int i=1;i<result.size();i++)
    {
        if(result[i]==0)
            return false;
    }
    return true;
}

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

    int matches = 0;
    int index = 0;
    if(ruleKey == "type")
    {
        index = 0;
    }
    else if(ruleKey == "color")
    {
        index = 1;
    }
    else
    {
        index = 2;
    }
    for(int i=0;i<items.size();i++)
    {
        if(ruleValue == items[i][index])
            matches++;
    }
    return matches;
}

int largestAltitude(vector<int>& gain) {

    int max = 0;
    int current=0;
    for(int i=0;i<gain.size();i++)
    {
        current+=gain[i];
        max = std::max(current, max);
    }
    return max;
}
void swap(int &a, int &b)
{
    a = a^b;
    b = a^b;
    a=a^b;
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    // vector<vector<int>> inverted_and_reversed(image);
    for(int i=0;i<image.size();i++)
    {
        for(int j=0, k=image[i].size()-1;j<=k;j++, k--)
        {
            //If condition used due to different swap algorithm (contains XOR which makes 0 if a = b)
            if(j!=k)
            {
            swap(image[i][j], image[i][k]);
             image[i][j] = !image[i][j];
            }
            image[i][k] = !image[i][k];
                
           
        }
    }
    return image;
}

int diagonalSum(vector<vector<int>>& mat) {
    long int sum = 0;
    for(int i=0, k=mat[0].size()-1;i<mat[0].size();i++, k--)
    {
        if(i == k)  
        {
            sum+=mat[i][i];
        }
        else
        {
            sum+= mat[i][i] + mat[i][k];
        }
    }
    return sum;
}

 vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int top=0;
    int bottom=matrix.size()-1;
    int left=0;
    int right=matrix[0].size()-1;
    vector<int> result;

    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            {
                result.push_back(matrix[bottom][i]);
            }
        }
            bottom--;
        if(left<=right)
        {
             for(int i=bottom;i>=top;i--)
            {
                result.push_back(matrix[i][left]);
            }
        }
            left++;     
    }
    return result;
}

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>> result(n);
    int top=0;
    int left=0;
    int right=n-1;
    int bottom=n-1;
    int number=1;

    for(int i=0;i<n;i++)
    {
        result[i] = vector<int>(n);
    }

    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
        {
            result[top][i] = number;
            number++;
        }
        top++;
        for(int i=top;i<=bottom;i++)
        {
            result[i][right] = number;
            number++;
        }
        right--;
        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            {
                result[bottom][i] = number;
                number++;
            }
        }
        bottom--;
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                result[i][left] = number;
                number++;
            }
        }
        left++;
    }

    return result;
}


int main(void)
{

    std::vector<int> array1 = {1,2,3,4,5,6};
    std::vector<std::vector<int>> array2 = {{1,2,1}, {10,9,8}, {23,5,1},{1,2,3}};
    int n=6;
    vector<vector<int>> matrix = generateMatrix(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout<<matrix[i][j]<<", ";
        }
        std::cout<<"\n";
    }


}
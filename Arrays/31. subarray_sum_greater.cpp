#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int x=280;
    int n=nums.size()-1;
    int start=0,end=0;
    int currSum=0, minLen=n+1;
    while(start<=end)
    {
        //move end till we get sum>x
        while(currSum<=x && end<n)
            currSum+=nums[end++];
        //now check if length can be decreased by removing starting elements from sum
        while(currSum>x && start<n)
        {
            if(minLen>end-start)
                minLen=end-start;
            currSum-=nums[start++];
            
        }
    }
    cout<<minLen;
    return 0;
}

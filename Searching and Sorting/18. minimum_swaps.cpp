// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
	    vector<int> temp=nums;
	    sort(temp.begin(),temp.end());
	    unordered_map<int,int> mp;
	    int c=0;
	    for(int i=0;i<temp.size();i++)
	        mp[temp[i]]=i;
	    for(int i=0;i<nums.size();)
	    {
	        if(nums[i]!=temp[i])
	        {
	            swap(nums[i],nums[mp[nums[i]]]);
	            c++;
	        }
	        else
	            i++;
	    }
	    return c;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
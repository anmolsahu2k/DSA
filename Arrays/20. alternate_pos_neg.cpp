// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


	void rearrange(vector<int> &nums)
	{
		int c=0;
		for(int i=0;i<nums.size();i++)
		{
			if(i%2==0 && nums[i]<0)
			{
				c=0;
				while(nums[i]<0)
				{
					rotate(nums.begin()+i,nums.begin()+nums.size()-1,nums.end());
					c++;
					if(c>nums.size()-i+1)
						break;
					
				}
			}
			else if(i%2!=0 && nums[i]>0)
			{
				c=0;
				while(nums[i]>0)
				{
					rotate(nums.begin()+i,nums.begin()+nums.size()-1,nums.end());
					c++;
					if(c>nums.size()-i+1)
						break;
					
				}
			}
			if(c>nums.size()-i+1)
				break;
		}
	}

int main() {
	vector<int> nums={1,2,3,-4,-1,4};
	rearrange(nums);
	for(int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
    return 0;
}
  // } Driver Code Ends
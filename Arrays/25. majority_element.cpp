#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int> nums = {3, 1, 2, 2, 1, 2, 3, 3};
    unordered_map<int,int> mp;
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
                mp[nums[i]]++;
            else
                mp.insert({nums[i],1});
        }
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]>n/3){
                mp[nums[i]]=-1;
                v.push_back(nums[i]);
            }
        }
    for(int k:v)
        cout << k << " ";
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
    
int search(vector<int>& nums, int target) {
    int n=nums.size();
    int l=0,h=n-1,mid,prev,next,rot;
    while(l<=h)
    {
        mid=l+(h-l)/2;
        prev=(mid+n-1)%n;
        next=(mid+1)%n;
        if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
        {
            rot=mid;
            break;
        }
        else if(nums[mid]<=nums[h])
            h=mid-1;
        else if(nums[mid]>=nums[l])
            l=mid+1;
        
    }
    //max(BS(arr,0,mid-1),BS(arr,mid+1,n-1))
    //             OR
    int realmid;        
    l=0;
    h=n-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        realmid=(mid+rot)%n;
        if(nums[realmid]==target)
            return realmid;
        else if(nums[realmid]<target)
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}

int main()
{
    vector<int> nums={4,5,6,7,0,1,2};
    int target=0;
    cout<<search(nums,target);
    return 0;
}
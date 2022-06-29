#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findDuplicate(vector<int>& nums) {
    int slow=nums[nums[0]];
    int fast=nums[nums[nums[0]]];
    // https://www.geeksforgeeks.org/how-does-floyds-slow-and-fast-pointers-approach-work/
    /*
    First collision: (when fast meets slow in the cycle) (This will help to find whether cycle exists or not.) 
    fast is just moving twice the speed as slow. slow is moving 1 unit , fast is moving at 2 units. so, fast = 2* slow.  now take some distance n(consider it as a ring road :-p ) 
    To cover distance n , slow needs n units
    fast needs 2n units right (fast =2*slow)
    This mean eventually they are meeting. I hope this makes sense.
    */
    while(slow!=fast)
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    slow=nums[0];
    /*
    Finding where collision occured (the entry point/duplicate number in this case):
    From (1)-> we already know there is some entry point (where cycle starts) & a meeting point (where fast meets slow).
    lets say distance from starting point to entrypoint = d1;
    distance from entrypoint to meetingpoint = d2;
    distance from meetingpoint to entrypoint (which makes cycle) = d3;
    slow covers d1 distance and d2 to reach meeting point, so slow = d1+d2;
    fast covers d1,d2 d3 and again d2 to reach meeting point, so fast = d1+d2+d2+d3 = d1+2d2+d3
    from 1, we know fast = 2* slow
    d1+2d2+d3 = 2(d1+d2) which mean ( d1=d3 )
    It concludes distance between d1 (starting & entry) equals d3(meetingpoint to entrypoint), thats the intuition behind starting fast pointer at head for the second time and moving both 1 unit, at equal distance theyll find the duplicate/entrypoint.
    */
    while(slow!=fast)
    {
        slow=nums[slow];
        fast=nums[fast];
    }
    return fast;
}
int main()
{
    //can use negative marking with extra space
    vector<int> v={2,5,9,6,9,3,8,9,7,1};
    cout <<findDuplicate(v) ;
    return 0;
}
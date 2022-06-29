#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums = {1, 5,8,4,7,6,5,3,1};
    int n = nums.size();
    int j;
    int i = n - 2;
    //traverse right to left till nums[i+1]<=nums[i]
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        j = n - 1;
        //traverse right to left till nums[j]<=nums[i](just larger)
        while (nums[j] <= nums[i]) {
            j--;
        }
        
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin()+i+1,nums.end());
    for(int k:nums)
        cout << k << " ";
    return 0;
}
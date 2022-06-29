#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long int sum=0;
    long long int maxSum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(maxSum<sum)
        {
            maxSum=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return maxSum;
}
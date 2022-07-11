#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr={2,4,8,10,12,14};
    int n=arr.size();
    int diff=(arr[n-1]-arr[0])/n;
    int l=0,h=n-1,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if((arr[mid]-arr[0])/diff==mid)
            l=mid+1;
        else
            h=mid-1;
    }
    cout<<arr[h]+diff;
    return 0;
}
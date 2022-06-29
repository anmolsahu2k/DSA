#include <iostream>
#include <map>
using namespace std;
int getPairsCount(int arr[], int n, int k) {
    map<int,int> mp;
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(mp.count(k-arr[i]))
            c+=mp[k-arr[i]];
        if(mp.count(arr[i]))
            mp[arr[i]]++;
        else
            mp[arr[i]]=1;
    }
    return c;
}
int main()
{
    int arr[]={1, 5, 7, 1};
    int n=4;
    int k=6;
    cout<<getPairsCount(arr,n,k);
    return 0;
}
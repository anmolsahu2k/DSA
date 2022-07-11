#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v={4,5,6,1,2,3};
    int n=v.size();
    int l=0,h=n-1,mid;
    int prev,next,rot;
    while(l<=h)
    {
        mid=(l+h)/2;
        prev=(mid+n-1)%n;
        next=(mid+1)%n;
        if(v[mid]<=v[next] && v[mid]<=v[prev])
        {
            rot=mid;
            break;
        }
        else if(v[mid]<=v[h])
            h=mid-1;
        else if(v[mid]>=v[l])
            l=mid+1;
    }
    cout<<v[prev];
    return 0;
}